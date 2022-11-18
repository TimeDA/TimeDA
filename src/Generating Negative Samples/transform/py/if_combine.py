import os
from lxml import etree
from lxml.etree import Element

ns = {'src': 'http://www.srcML.org/srcML/src'}
doc = None
flag = True
str = '{http://www.srcML.org/srcML/src}'
def init_parse(file):
    global doc
    doc = etree.parse(file)
    e = etree.XPathEvaluator(doc, namespaces={'src': 'http://www.srcML.org/srcML/src'})
    return e
def get_if_stmt(e):
    return e('//src:if_stmt')
def get_secondIf(elem):
    return elem.xpath('src:if/src:block/src:block_content/src:if_stmt', namespaces=ns)
def get_condition2(elem):
    return elem.xpath('src:if/src:condition/src:expr', namespaces=ns)
def get_condition1(elem):
    return elem.xpath('src:if/src:condition/src:expr',namespaces=ns)
def get_content(elem):
    return elem.xpath('src:if/src:block/src:block_content', namespaces=ns)
def get_block(elem):
    return elem.xpath('src:if/src:block/src:block_content', namespaces=ns)
def save_tree_to_file(tree, file):
    with open(file, 'w') as f:
        f.write(etree.tostring(tree).decode('utf8'))

def trans_tree(e, ignore_list=[], instances=None):
    global flag
    flag = False
    #获取树根，后面取路径要用
    tree_root = e('/*')[0].getroottree()
    new_ignore_list = []
    # 获得所有的if_stmt语句
    if_stmts = [get_if_stmt(e) if instances is None else (instance[0] for instance in instances)]
    for item in if_stmts:
        for if_stmt in item:
            #
            if_stmt_prev = if_stmt.getprevious()
            if_stmt_prev = if_stmt_prev if if_stmt_prev is not None else if_stmt
            if_stmt_prev_path = tree_root.getpath(if_stmt_prev)
            if if_stmt_prev_path in ignore_list:
                continue

            # 判断是否符合转换条件:if语句里只能有一个if语句,不能有其他语句
            if len(get_block(if_stmt))>0:
                block = get_block(if_stmt)[0]
                if len(block.getchildren()) == 1 and block.getchildren()[0].tag == str+'if_stmt':
                    if_second = block.getchildren()[0]
                    if len(if_second) == 1 and if_second[0].text.strip() == 'if':
                            # 得到第二个执行条件
                            If2_condition = get_condition2(if_second)[0]
                            # 得到第一个if条件
                            If1_condition = get_condition1(if_stmt)[0]
                            condition_flag = True
                            for expr_e in If2_condition:
                                if expr_e.text == '||' or expr_e.text == '|':
                                    condition_flag = False
                            for expr_e in If1_condition:
                                if expr_e.text == '||' or expr_e.text == '|':
                                    condition_flag = False
                            if condition_flag == False:
                                break

                            #
                            new_ignore_list.append(if_stmt_prev_path)
                            #

                            # 得到执行语句
                            content = get_content(if_second)[0]
                            content.tail = ''
                            If1_condition.tail = ''
                            # 增加操作符
                            opreater = Element('operator')
                            opreater.text = '&&'
                            # 将&&和第二个条件加到第一个if条件里
                            If1_condition.append(opreater)
                            If1_condition.append(If2_condition)
                            # 将执行语句增加到第一个执行块中
                            block.append(content)
                            # 删除第二个if
                            block.remove(if_second)
                            flag = True
    return flag, tree_root, new_ignore_list
def count(e):
    count_num = 0
    if_second = None
    # 获得所有的if_stmt语句
    if_stmts = get_if_stmt(e)
    for if_stmt in if_stmts:
        # 判断是否符合转换条件:if语句里只能有一个if语句,不能有其他语句
        if len(get_block(if_stmt))>0:
            block = get_block(if_stmt)[0]
            if len(block.getchildren()) == 1 and block.getchildren()[0].tag == str+'if_stmt':
                if_second = block.getchildren()[0]
                if len(if_second) == 1 and if_second[0].text.strip() == 'if':
                        # 得到第二个执行条件
                        If2_condition = get_condition2(if_second)[0]
                        # 得到第一个if条件
                        If1_condition = get_condition1(if_stmt)[0]
                        condition_flag = True
                        for expr_e in If2_condition:
                            if expr_e.text == '||' or expr_e.text == '|':
                                condition_flag = False
                        for expr_e in If1_condition:
                            if expr_e.text == '||' or expr_e.text == '|':
                                condition_flag = False
                        if condition_flag == False:
                            break
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
    save_xml_file = './transform_xml_file/if_combine'
    transform_java_file = './pre_file/transform_java/if_combine'
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