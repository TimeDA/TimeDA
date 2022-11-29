import os
from lxml import etree
ns = {'src': 'http://www.srcML.org/srcML/src'}
doc = None
flag = False
def init_parse(file):
    global doc
    doc = etree.parse(file)
    e = etree.XPathEvaluator(doc, namespaces=ns)
    return e
def get_while(e):
    return e('//src:while')
def get_condition(elem):
    return elem.xpath('src:condition', namespaces=ns)
def trans_tree(e, ignore_list=[], instances=None):
    global flag
    flag = False
    while_elems = [get_while(e) if instances is None else (instance[0] for instance in instances)]
    tree_root = e('/*')[0].getroottree()
    new_ignore_list = []
    if len(while_elems)>0:
        for item in while_elems:
            for while_elem in item:
                while_prev = while_elem.getprevious()
                while_prev_prev = [while_prev.getprevious() if while_prev is not None else while_elem][0]
                while_prev_prev = [while_prev_prev if while_prev_prev is not None else while_prev][0]
                while_prev_path = tree_root.getpath(while_prev_prev)
                if while_prev_path in ignore_list:
                    continue
                flag = True
                elem_condition = get_condition(while_elem)[0]
                while_elem.text = 'for'
                while_elem.tag = 'for'
                elem_condition.text = '(;'
                elem_condition[-1].tail = ';)'
                new_ignore_list.append(while_prev_path)
    return flag, tree_root, new_ignore_list
def count(e):
    while_elems = get_while(e)
    return len(while_elems)
def get_number(xml_path):
    xmlfilepath = os.path.abspath(xml_path)
    e = init_parse(xmlfilepath)
    return count(e)
def save_tree_to_file(tree, file):
    with open(file, 'w') as f:
        f.write(etree.tostring(tree).decode('utf8'))

def xml_file_path(xml_path):
    global flag
    save_xml_file = './transform_xml_file/while_for'
    transform_java_file = './pre_file/transform_java/while_for'
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

if __name__ == '__main__':
    path = '../demo1.xml'
    e = init_parse(path)
    trans_tree(e)
    save_tree_to_file(doc, '../demo2.xml')
def program_transform(program_path):
    e = init_parse(program_path)
    trans_tree(e)
    save_tree_to_file(doc, './style/style.xml')
