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
    # 得到if执行块
    if len(get_block_content(if_elem))>0:
        block = get_block_content(if_elem)[0]
        condition_index = expr.index(elem)
        # 删除&&符号
        expr.remove(elem)
        # 把第二个条件拿出来
        second_expr = expr[condition_index:]
        # 条件末尾加上 ）
        second_expr[-1].tail = ')'
        # 获得if的执行语句
        if len(get_stmt(block)) != 0:
            stmt = get_stmt(block)[0]
        else:
            stmt = Element('block_content')
            stmt.tail = '}'
            stmt.append(block[0])
        if len(stmt)>0:
            stmt[-1].tail = '}'
        # 往执行块增加If语句
        node = Element('if')
        node.text = 'if'
        block.insert(0, node)
        # 往第二个If增加条件
        node = Element('condition')
        node.text = '('
        block[0].append(node)
        # 把第二个条件放到第二个if（）里
        for elem in second_expr:
            block[0][0].append(elem)
        # 给第二个if增加执行块
        node = Element('block')
        node.text = '{'
        block[0].append(node)
        # 把执行语句插入到第二个If的执行块里
        block[0][1].append(stmt)
def trans_2(elem, expr, if_elem):
    condition_index = expr.index(elem)
    # 删除||符号
    expr.remove(elem)
    # 把第二个条件拿出来
    second_expr = expr[condition_index:]
    # 条件末尾加上 ）
    second_expr[-1].tail = ')'
    # 得到if执行块
    block_content = get_block_content(if_elem)[0]
    # 获得if的执行语句
    stmt = get_stmt(block_content)[0]
    stmt.tail = '}'
    # 创建else if标签
    elseif_node = Element('if')
    elseif_node.text = 'else if('
    elseif_node.attrib == {'type': 'elseif'}
    # 把第二个条件之后的条件全部放到else if 条件里
    for elem in second_expr:
        elseif_node.append(elem)
    # 将执行语句赋值，再插入到elseif语句中?????????
    block_content = Element('block')
    block_content.text = '{'
    elseif_node.append(block_content)
    # 得到If语句下标
    if_index = if_elem.getparent().index(if_elem)
    # 把elseif 插入到if后面
    if_elem.getparent().insert(if_index+1, elseif_node)

def trans_tree(e, ignore_list=[], instances=None):
    global flag
    flag = False
    #获取树根，后面取路径要用
    tree_root = e('/*')[0].getroottree()
    new_ignore_list = []
    # 获得每个if语句
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
                # 得到If语句（）里面的条件，判断是否需要拆分
                if len(get_expr(if_elem))==0:continue
                expr = get_expr(if_elem)[0]
                # 对（）里的内容循环判断是否有&&符号
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
                            # 只拆开第一个条件（&&）
                            break
    return flag, tree_root, new_ignore_list
def count(e):
    count_num = 0
    # 获得每个if语句
    if_elems = get_if(e)
    for if_elem in if_elems:
        if_stmt = if_elem.getparent()
        if len(if_stmt) == 1:
            # 得到If语句（）里面的条件，判断是否需要拆分
            if len(get_expr(if_elem)) == 0:continue
            expr = get_expr(if_elem)[0]
            # 对（）里的内容循环判断是否有&&符号
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
    # 解析成树
    e = init_parse(xmlfilepath)
    return count(e)
def xml_file_path(xml_path):
    global flag
    # xml_path 需要转化的xml路径
    # sub_dir_list 每个作者的包名
    # name_list 具体的xml文件名
    save_xml_file = './transform_xml_file/if_split'
    transform_java_file = './pre_file/transform_java/if_split'
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
if __name__ == '__main__':
    e = init_parse('../demo1.xml')
    trans_tree(e)
    save_tree_to_file(doc, '../demo2.xml')