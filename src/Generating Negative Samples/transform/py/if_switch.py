import os
from lxml import etree
from lxml.etree import Element

ns = {'src': 'http://www.srcML.org/srcML/src'}
doc = None
def init_parse(file):
    global doc
    doc = etree.parse(file)
    return etree.XPathEvaluator(doc, namespaces={'src': 'http://www.srcML.org/srcML/src'})
def get_if_stmt(e):
    return e('//src:if_stmt')
def trans_tree(e):
    if_stmts = get_if_stmt(e)
    for if_stmt in if_stmts:
        flag = False
        name = ''
        # 判断if_stmt  里的结构是否可以转换成switch
        for elem in if_stmt[:-1]:
            # 判断条件变量是否相同
            if name == '' and elem[0][0][1].text == '==':
                name = elem[0][0][0].text
            else:
                if name == elem[0][0][0].text and elem[0][0][1].text == '==':
                    # 可以转化为switch
                    elem.tag = 'case'
                    elem.text ='case '
                    # 去掉 if条件的括号，加上case 常量后面的：
                    elem[0].text = ''
                    elem[0][0].tail = ':'
                    # 去掉执行语句里的 {}
                    elem[1].text = ''
                    elem[1][0].tail = 'break;'
                    # 删除 变量 和 ==
                    del elem[0][0][0], elem[0][0][0]
                    flag = True
        # 表示可以转化成switch，而且除了第一个if语句以后，其他的都转化完成
        if flag == True:
            value = if_stmt[0][0][0][0]
            if_stmt[0].tag = 'case'
            if_stmt[0].text = 'case '
            # 去掉 ()
            if_stmt[0][0].text = ''
            if_stmt[0][0][0].tail = ':'
            # 去掉 {
            if_stmt[0][1].text = ''
            if_stmt[0][1][0].tail = '\nbreak;'
            del if_stmt[0][0][0][1]

            # 如果最后是else则需要转为default
            if if_stmt[-1].text.strip() == 'else':
                if_stmt[-1].tag = 'default'
                if_stmt[-1].text = 'default:'
                # 去掉 {
                if_stmt[-1][0].text = ''
                if_stmt[-1][0][0].tail = 'break;\n}'
            else:
                if_stmt[-1].tag = 'case'
                if_stmt[-1].text = 'case '
                # 去掉 if条件的括号，加上case 常量后面的：
                if_stmt[-1][0].text = ''
                if_stmt[-1][0][0].tail = ':'
                # 去掉执行语句里的 {
                if_stmt[-1][1].text = ''
                if_stmt[-1][1][0].tail = 'break;\n}'
                # 删除 变量 和 ==
                del if_stmt[-1][0][0][0], if_stmt[-1][0][0][0]
        # 增加switch结构
        node = Element('switch')
        node.text = 'switch'
        node1 = Element('condition')
        # 增加switch的条件括号
        node1.text = '('
        node1.tail = ')'
        # 将变量增加到条件里
        node1.append(value)
        # 将条件增加到switch里
        node.append(node1)
        # 构造switch的执行语句
        node2 = Element('block')
        node2.text = '{'
        # 将执行块增加到switch里
        node.append(node2)
        node.append(node2)
        index = if_stmt.getparent().index(if_stmt)
        # 将switch插入到此if的位置
        if_stmt.getparent().insert(index,node)
        # 将整个转化的case语句增加到switch的执行块里
        node2.append(if_stmt)
def save_tree_to_file(tree, file):
    with open(file, 'w') as f:
        f.write(etree.tostring(tree).decode('utf8'))

def count(e):
    count_num = 0
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
    save_xml_file = './transform_xml_file/if_switch'
    transform_java_file = './pre_file/transform_java/if_switch'
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