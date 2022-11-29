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
        for elem in if_stmt[:-1]:
            if name == '' and elem[0][0][1].text == '==':
                name = elem[0][0][0].text
            else:
                if name == elem[0][0][0].text and elem[0][0][1].text == '==':
                    elem.tag = 'case'
                    elem.text ='case '
                    elem[0].text = ''
                    elem[0][0].tail = ':'
                    elem[1].text = ''
                    elem[1][0].tail = 'break;'
                    del elem[0][0][0], elem[0][0][0]
                    flag = True
        if flag == True:
            value = if_stmt[0][0][0][0]
            if_stmt[0].tag = 'case'
            if_stmt[0].text = 'case '
            if_stmt[0][0].text = ''
            if_stmt[0][0][0].tail = ':'
            if_stmt[0][1].text = ''
            if_stmt[0][1][0].tail = '\nbreak;'
            del if_stmt[0][0][0][1]

            if if_stmt[-1].text.strip() == 'else':
                if_stmt[-1].tag = 'default'
                if_stmt[-1].text = 'default:'
                if_stmt[-1][0].text = ''
                if_stmt[-1][0][0].tail = 'break;\n}'
            else:
                if_stmt[-1].tag = 'case'
                if_stmt[-1].text = 'case '
                if_stmt[-1][0].text = ''
                if_stmt[-1][0][0].tail = ':'
                if_stmt[-1][1].text = ''
                if_stmt[-1][1][0].tail = 'break;\n}'
                del if_stmt[-1][0][0][0], if_stmt[-1][0][0][0]
        node = Element('switch')
        node.text = 'switch'
        node1 = Element('condition')
        node1.text = '('
        node1.tail = ')'
        node1.append(value)
        node.append(node1)
        node2 = Element('block')
        node2.text = '{'
        node.append(node2)
        node.append(node2)
        index = if_stmt.getparent().index(if_stmt)
        if_stmt.getparent().insert(index,node)
        node2.append(if_stmt)
def save_tree_to_file(tree, file):
    with open(file, 'w') as f:
        f.write(etree.tostring(tree).decode('utf8'))

def count(e):
    count_num = 0
    return count_num
def get_number(xml_path):
    xmlfilepath = os.path.abspath(xml_path)
    e = init_parse(xmlfilepath)
    return count(e)

def xml_file_path(xml_path):
    global flag
    save_xml_file = './transform_xml_file/if_switch'
    transform_java_file = './pre_file/transform_java/if_switch'
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
def program_transform(program_path):
    e = init_parse(program_path)
    trans_tree(e)
    save_tree_to_file(doc, './style/style.xml')
