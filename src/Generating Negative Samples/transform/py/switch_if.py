import copy
import os

from lxml import etree
from lxml.etree import Element

ns = {'src': "http://www.srcML.org/srcML/src"}
doc = None
flag_switch = True
flag = True
def init_parse(path):
    global doc
    doc = etree.parse(path)
    e = etree.XPathEvaluator(doc, namespaces={'src': 'http://www.srcML.org/srcML/src'})
    return e
def get_switch(e):
    return e("//src:switch")
def get_variable(elem):
    return elem.xpath('src:condition', namespaces=ns)
def get_case(elem):
    return elem.xpath('src:block/src:block_content/src:case', namespaces=ns)
def get_block_content(elem):
    return elem.xpath("src:block/src:block_content", namespaces=ns)
def get_default(elem):
    return elem.xpath("src:block/src:block_content/src:default", namespaces=ns)
def transform_default(default_elem):
    if len(default_elem) > 0:
        default_elem[0].tag = 'else'
        default_elem[0].text = 'else'
        index = default_elem[0].getparent().index(default_elem[0])
        node = default_elem[0].getparent()[index + 1]
        tag = etree.QName(node)
        if tag.localname != 'block':
            node_elem = Element('block')
            node_elem.text = '{'
            for elem in default_elem[0].getparent()[index:]:
                tag = etree.QName(elem)
                if tag.localname == 'expr_stmt':
                    node_elem.append(elem)
                if elem.text == 'break;':
                    elem_index = elem.getparent().index(elem)
                    del elem.getparent()[elem_index]
                    break
            node_elem.tail  = '\n}'
            default_elem[0].getparent().insert(index+1, node_elem)
def transform_case(case_elems, var):
    # 先转化第一个case
    case_first = case_elems[0]
    case_first.tag = 'if'
    case_first.text = 'if'
    transform_case_content(case_first, var)
    # 从第二个case开始转化
    for elem in case_elems[1:]:
        elem.tag = 'if'
        elem.text = 'else if'
        transform_case_content(elem, var)
def transform_case_content(case_elem, var):
    global flag
    # 深拷贝一个变量
    var_elem = copy.deepcopy(var)
    # 将==号增加到变量后面
    operate_elem = Element('operate')
    operate_elem.text = '=='
    var_elem.append(operate_elem)
    # 讲 case 的值增加到条件里面
    for case_child in case_elem:
        var_elem.append(case_child)
    # 把“：”去掉
    var_elem[-1].tail = ')'
    # 将条件放到if后面
    case_elem.append(var_elem)
    # 修改case后面的执行语句
    index = case_elem.getparent().index(case_elem)
    node = case_elem.getparent()[index + 1]
    tag = etree.QName(node)
    if tag.localname != 'block':
        node_elem = Element('block')
        node_elem.text = '{'
        for elem in case_elem.getparent()[index+1:]:
            tag = etree.QName(elem)
            node_elem.append(elem)
            if elem.text == 'break;':
                elem_index = elem.getparent().index(elem)
                del elem.getparent()[elem_index]
                break
        node_elem.tail = '\n}'
        case_elem.getparent().insert(index + 1, node_elem)
def judge_transform(switch_elem):
    global flag_switch
    # 判断default
    default_elem = get_default(switch_elem)
    if len(default_elem) > 0:
        index = default_elem[0].getparent().index(default_elem[0])
        if len(default_elem[0].getparent()) <= index+1:
            flag_switch = False
            return
        node = default_elem[0].getparent()[index + 1]
        tag = etree.QName(node)
        if tag.localname == 'block':
            if len(node)!=0 and len(node[0])!=0 and node[0][-1].text != 'break;':
                flag_switch = False
                return
        else:
            if default_elem[0].getparent()[-1].text != 'break;':
                flag_switch = False
                return

    # 判断case
    case_elems = get_case(switch_elem)
    if len(case_elems)>0:
        for case_elem in case_elems:
            index = case_elem.getparent().index(case_elem)
            if len(case_elem.getparent()) <= index+1:
                flag_switch = False
                return
            node = case_elem.getparent()[index + 1]
            tag = etree.QName(node)
            if tag.localname == 'block':
                if node[0][-1].text != 'break;':
                    flag_switch = False
                    return
            else:
                for elem in case_elem.getparent()[index + 1:]:
                    tag = etree.QName(elem)
                    if tag.localname != 'break':
                        flag_switch = False
                    if tag.localname == 'break':
                        flag_switch = True
                        break
                    if tag.localname == 'case' or tag.localname == 'default':
                        flag_switch = False
                        return
    else:
        flag_switch = False
def trans_tree(e):
    global flag
    global flag_switch
    # 得到每个switch
    switch_elems = get_switch(e)
    for switch_elem in switch_elems:
        # 判断switch是否可以转化
        flag_switch = True
        judge_transform(switch_elem)
        if flag_switch == False:
            continue
        # 获取每个case
        case_elems = get_case(switch_elem)
        # 得到switch里的变量
        var = get_variable(switch_elem)[0]
        var[-1].tail = ''
        # 获得default
        default_elem = get_default(switch_elem)
        # 对default进行转化
        transform_default(default_elem)
        # 对每个case进行转化
        transform_case(case_elems, var)

        var_index = var.getparent().index(var)
        del var.getparent()[var_index]

        # 获得swich里的所有执行语句，移到switch前面
        block_content = get_block_content(switch_elem)[0]
        block_content.tail = ''
        get_switch_index = switch_elem.getparent().index(switch_elem)
        switch_elem.getparent().insert(get_switch_index, block_content)
        # 删除switch
        index = switch_elem.getparent().index(switch_elem)
        del switch_elem.getparent()[index]
        flag = True
def save_tree_to_file(tree,path):
    with open(path, 'w') as f:
        f.write(etree.tostring(tree).decode('utf8'))


def count(e):
    count_num = 0
    global flag_switch
    # 得到每个switch
    switch_elems = get_switch(e)
    for switch_elem in switch_elems:
        flag_switch = True
        judge_transform(switch_elem)
        if flag_switch == True:
            count_num += 1
    return count_num
def get_number(xml_path):
    xmlfilepath = os.path.abspath(xml_path)
    # 解析成树
    e = init_parse(xmlfilepath)
    return count(e)
def xml_file_path(xml_path):
    global flag
    # xml_path 需要转化的xml路径
    # sub_dir_list 每个作者的包名
    # name_list 具体的xml文件名
    save_xml_file = './transform_xml_file/switch_if'
    transform_java_file = './pre_file/transform_java/switch_if'
    if not os.path.exists(transform_java_file):
        os.mkdir(transform_java_file)
    if not os.path.exists(save_xml_file):
        os.mkdir(save_xml_file)
    for xml_path_elem in xml_path:
        xmlfilepath = os.path.abspath(xml_path_elem)
        # 解析成树
        e = init_parse(xmlfilepath)
        # 转换
        flag = False
        trans_tree(e)
        # 保存文件
        if flag == True:
            str = xml_path_elem.split('/')[-1]
            sub_dir = xml_path_elem.split('/')[-2]
            if not os.path.exists(os.path.join(save_xml_file, sub_dir)):
                os.mkdir(os.path.join(save_xml_file, sub_dir))
            save_tree_to_file(doc, os.path.join(save_xml_file, sub_dir, str))
    return save_xml_file, transform_java_file
def program_transform(program_path):
    e = init_parse(program_path)
    trans_tree(e)
    save_tree_to_file(doc, './style/style.xml')