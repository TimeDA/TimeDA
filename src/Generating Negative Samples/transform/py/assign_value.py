import copy
import os
from lxml import etree
from lxml.etree import Element
flag = True
doc = None
ns = {'src':'http://www.srcML.org/srcML/src'}
def init_parse(e):
    global doc
    doc = etree.parse(e)
    e = etree.XPathEvaluator(doc, namespaces={'src':'http://www.srcML.org/srcML/src'})
    return e
def get_pxpr(e):
    return e('//src:expr')
def trans_tree(e, ignore_list=[], instances=None):
    global flag
    flag = False
    # 得到所有的expr
    expr_elems = [get_pxpr(e) if instances is None else (instance[0] for instance in instances)]
    tree_root = e('/*')[0].getroottree()
    new_ignore_list = []

    for item in expr_elems:
        for expr_elem in item:
            #
            expr_elem_prev = expr_elem.getprevious()
            expr_elem_prev = expr_elem_prev if expr_elem_prev is not None else expr_elem
            expr_elem_prev_path = tree_root.getpath(expr_elem_prev)
            if expr_elem_prev_path in ignore_list:
                continue

            # 对expr循环，查找name,operator,operator,name
            # temp = ++i;
            if len(expr_elem) >= 4:
                tag = etree.QName(expr_elem.getparent())
                if tag.localname == 'condition':
                    continue
                var = []
                a_flag = True
                for elem in expr_elem[:-1]:
                    if elem.text == '+' or elem.text == '-' or elem.text == '*' or elem.text == '/':
                        a_flag = False
                        break
                if a_flag == False:
                    continue
                for elem in expr_elem:
                    if elem.text == '=':
                        index = elem.getparent().index(elem)
                        parent = elem.getparent()
                        if parent[index+1].text == '++' or parent[index+1].text == '--':
                            block = parent.getparent().getparent().getparent()
                            if not block.text:
                                block.text = '{'
                                block_content = parent.getparent().getparent()
                                block_content.tail = '}'
                            for var_elem in expr_elem[index+2:]:
                                var.append(copy.deepcopy(var_elem))
                            var[-1].tail = ';'
                            parent.insert(0, parent[index+1])
                            node = Element("call")
                            for var_e in var:
                                node.append(var_e)
                            parent.insert(1, node)
                            flag = True
                            #
                            new_ignore_list.append(expr_elem_prev_path)
            # temp = i++;
            if len(expr_elem) >= 4:
                tag = etree.QName(expr_elem.getparent())
                if tag.localname == 'condition':
                    continue
                var = []
                for elem in expr_elem:
                    if elem.text == '=':
                        index = elem.getparent().index(elem)
                        if expr_elem[-1].text == '++' or expr_elem[-1].text == '--':
                            block = parent.getparent().getparent().getparent()
                            if not block.text:
                                block.text = '{'
                                block_content = parent.getparent().getparent()
                                block_content.tail = '}'
                            for var_elem in expr_elem[index + 1:-1]:
                                var.append(copy.deepcopy(var_elem))
                            var[-1].tail = ';'
                            node = Element("call")
                            for var_e in var:
                                node.append(var_e)
                            expr_elem.insert(index+1, node)
                            flag = True
                            #
                            new_ignore_list.append(expr_elem_prev_path)
    return flag, tree_root, new_ignore_list
def save_tree_to_file(tree, path):
    with open(path, 'w') as f:
        f.write(etree.tostring(tree).decode('utf8'))

def count(e):
    count_num = 0
    # 得到所有的expr
    expr_elems = get_pxpr(e)
    for expr_elem in expr_elems:
        # 对expr循环，查找name,operator,operator,name
        # temp = ++i;
        if len(expr_elem) >= 4:
            tag = etree.QName(expr_elem.getparent())
            if tag.localname == 'condition':
                continue
            a_flag = True
            for elem in expr_elem[:-1]:
                if elem.text == '+' or elem.text == '-' or elem.text == '*' or elem.text == '/':
                    a_flag = False
                    break
            if a_flag == False:
                continue
            for elem in expr_elem:
                if elem.text == '=':
                    index = elem.getparent().index(elem)
                    parent = elem.getparent()
                    if parent[index + 1].text == '++' or parent[index + 1].text == '--':
                        count_num += 1
        if len(expr_elem) >= 4:
            tag = etree.QName(expr_elem.getparent())
            if tag.localname == 'condition':
                continue
            var = []
            for elem in expr_elem:
                if elem.text == '=':
                    index = elem.getparent().index(elem)
                    if expr_elem[-1].text == '++' or expr_elem[-1].text == '--':
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
    save_xml_file = './transform_xml_file/assign_value'
    transform_java_file = './pre_file/transform_java/assign_value'
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