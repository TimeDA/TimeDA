import os
from lxml import etree
from lxml.etree import Element
flag = True
ns = {'src': 'http://www.srcML.org/srcML/src'}
doc = None
str = '{http://www.srcML.org/srcML/src}'
def init_parse(file):
    global doc
    doc = etree.parse(file)
    return etree.XPathEvaluator(doc, namespaces={'src': 'http://www.srcML.org/srcML/src'})
def get_if(e):
    return e('//src:if_stmt')
def get_condition(elem):
    return elem.xpath('src:if/src:condition/src:expr', namespaces=ns)
def get_if_block(elem):
    return elem.xpath('src:if/src:block/src:block_content/src:expr_stmt/src:expr', namespaces=ns)
def get_else_block(elem):
    return elem.xpath('src:else/src:block/src:block_content/src:expr_stmt/src:expr', namespaces=ns)
def save_tree_to_file(tree, file):
    with open(file, 'w') as f:
        f.write(etree.tostring(tree).decode('utf8'))

def trans_tree(e):
    global flag
    if_stmts = get_if(e)
    for if_stmt in if_stmts:
        if len(if_stmt) > 2:
            if if_stmt[0].tag == str + 'if' and if_stmt[1].tag == str + 'else':
                if_condition = get_condition(if_stmt)[0]
                if_expr = get_if_block(if_stmt)
                else_expr = get_else_block(if_stmt)
                if len(if_expr)==1 and len(else_expr)==1:
                    if len(if_expr[0]) and len(else_expr[0]) >=3:
                        if if_expr[0][0].text == else_expr[0][0].text and if_expr[0][1].text == '=' and else_expr[0][1].text == '=':
                            del if_expr[0][0], if_expr[0][0]
                            node_1 = Element('ternary')
                            node_1.append(else_expr[0][0])
                            node_1.append(else_expr[0][0])
                            if_condition.tail = '?'
                            node_1.append(if_condition)
                            node_2 = Element('then')
                            if_expr[0].tail = ''
                            node_2.append(if_expr[0])
                            node_1.append(node_2)
                            node_3 = Element('else')
                            node_3.text = ':'
                            node_3.append(else_expr[0])
                            node_1.append(node_3)
                            del if_stmt[0], if_stmt[0]
                            if_stmt.append(node_1)
                            flag = True


def count(e):
    count_num = 0
    return count_num
def get_number(xml_path):
    xmlfilepath = os.path.abspath(xml_path)
    e = init_parse(xmlfilepath)
    return count(e)
def xml_file_path(xml_path):
    global flag
    save_xml_file = './transform_xml_file/con_ternary'
    transform_java_file = './pre_file/transform_java/con_ternary'
    if not os.path.exists(transform_java_file):
        os.mkdir(transform_java_file)
    if not os.path.exists(save_xml_file):
        os.mkdir(save_xml_file)
    for xml_path_elem in xml_path:
        xmlfilepath = os.path.abspath(xml_path_elem)
        e = init_parse(xmlfilepath)
        flag = False
        trans_tree(e)
        if flag == True:
            str = xml_path_elem.split('/')[-1]
            sub_dir = xml_path_elem.split('/')[-2]
            if not os.path.exists(os.path.join(save_xml_file, sub_dir)):
                os.mkdir(os.path.join(save_xml_file, sub_dir))
            save_tree_to_file(doc, os.path.join(save_xml_file, sub_dir, str))
    return save_xml_file, transform_java_file
