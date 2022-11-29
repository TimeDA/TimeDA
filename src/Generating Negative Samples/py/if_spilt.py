import os
from lxml import etree
from lxml.etree import Element

ns = {"src": "http://www.srcML.org/srcML/src"}
doc = None
flag = False
def init_parse(file):
    global doc
    doc = etree.parse(file)
    e = etree.XPathEvaluator(doc,namespaces={'src': 'http://www.srcML.org/srcML/src'})
    return e
def get_if(e):
    return e('//src:if')
def get_expr(elem):
    return elem.xpath('src:condition/src:expr', namespaces=ns)
def get_block_content(elem):
    return elem.xpath('src:block', namespaces=ns)
def get_stmt(elem):
    return elem.xpath('src:block_content',namespaces=ns)
def save_tree_to_file(tree,file):
    with open(file, 'w') as f:
        f.write(etree.tostring(tree).decode('utf8'))

def trans_1(elem, expr, if_elem):
    if len(get_block_content(if_elem))>0:
        block = get_block_content(if_elem)[0]
        condition_index = expr.index(elem)
        expr.remove(elem)
        second_expr = expr[condition_index:]
        second_expr[-1].tail = ')'
        if len(get_stmt(block)) != 0:
            stmt = get_stmt(block)[0]
        else:
            stmt = Element('block_content')
            stmt.tail = '}'
            stmt.append(block[0])
        if len(stmt)>0:
            stmt[-1].tail = '}'
        node = Element('if')
        node.text = 'if'
        block.insert(0, node)
        node = Element('condition')
        node.text = '('
        block[0].append(node)
        for elem in second_expr:
            block[0][0].append(elem)
        node = Element('block')
        node.text = '{'
        block[0].append(node)
        block[0][1].append(stmt)
def trans_2(elem, expr, if_elem):
    condition_index = expr.index(elem)
    expr.remove(elem)
    second_expr = expr[condition_index:]
    second_expr[-1].tail = ')'
    block_content = get_block_content(if_elem)[0]
    stmt = get_stmt(block_content)[0]
    stmt.tail = '}'
    elseif_node = Element('if')
    elseif_node.text = 'else if('
    elseif_node.attrib == {'type': 'elseif'}
    for elem in second_expr:
        elseif_node.append(elem)
    block_content = Element('block')
    block_content.text = '{'
    elseif_node.append(block_content)
    if_index = if_elem.getparent().index(if_elem)
    if_elem.getparent().insert(if_index+1, elseif_node)

def trans_tree(e, ignore_list=[], instances=None):
    global flag
    flag = False
    tree_root = e('/*')[0].getroottree()
    new_ignore_list = []
    if_elems = [get_if(e) if instances is None else (instance[0] for instance in instances)]
    for item in if_elems:
        for if_elem in item:
            #
            if_elem_prev = if_elem.getprevious()
            if_elem_prev = if_elem_prev if if_elem_prev is not None else if_elem
            if_elem_prev_path = tree_root.getpath(if_elem_prev)
            if if_elem_prev_path in ignore_list:
                continue

            if_stmt = if_elem.getparent()
            if len(if_stmt) == 1:
                if len(get_expr(if_elem))==0:continue
                expr = get_expr(if_elem)[0]
                flag_elem = True
                for elem in expr:
                    if elem.text =='||' or elem.text == '|':
                        flag_elem = False
                        break
                if flag_elem == True:
                    for elem in expr:
                        if elem.text == '&&':
                            #
                            new_ignore_list.append(if_elem_prev_path)
                            #
                            flag = True
                            trans_1(elem, expr, if_elem)
                            break
    return flag, tree_root, new_ignore_list
def count(e):
    count_num = 0
    if_elems = get_if(e)
    for if_elem in if_elems:
        if_stmt = if_elem.getparent()
        if len(if_stmt) == 1:
            if len(get_expr(if_elem)) == 0:continue
            expr = get_expr(if_elem)[0]
            flag_elem = True
            for elem in expr:
                if elem.text == '||' or elem.text == '|':
                    flag_elem = False
                    break
            if flag_elem == True:
                for elem in expr:
                    if elem.text == '&&':
                        count_num += 1
    return count_num
def get_number(xml_path):
    xmlfilepath = os.path.abspath(xml_path)
    e = init_parse(xmlfilepath)
    return count(e)
def xml_file_path(xml_path):
    global flag
    save_xml_file = './transform_xml_file/if_split'
    transform_java_file = './pre_file/transform_java/if_split'
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
if __name__ == '__main__':
    e = init_parse('../demo1.xml')
    trans_tree(e)
    save_tree_to_file(doc, '../demo2.xml')
