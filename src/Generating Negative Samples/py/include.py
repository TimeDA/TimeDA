import operator
import sys
import os 
from lxml import etree
from lxml.etree import Element

ns = {'src': 'http://www.srcML.org/srcML/src',
      'cpp': 'http://www.srcML.org/srcML/cpp',
      'pos': 'http://www.srcML.org/srcML/position'}
doc = None


def init_parser(file):
    global doc
    doc = etree.parse(file)
    e = etree.XPathEvaluator(doc)
    for k, v in ns.items():
        e.register_namespace(k, v)
    return e


def get_expr_stmt(e):
    return e('//src:expr_stmt')


def get_expr(elem):
    return elem.xpath('src:expr', namespaces=ns)


def get_exprs(e):
    exprs = []
    expr_stmts = get_expr_stmt(e)
    for expr_stmt in expr_stmts:
        expr_list = get_expr(expr_stmt)
        for expr in expr_list:
            exprs.append(expr)
    return exprs


def get_block(e):
    return e('//src:block')


def get_call(e):
    return e.xpath('.//src:call', namespaces=ns)


def get_return(e):
    return e.xpath('.//src:return', namespaces=ns)


def get_newcall(e):
    calls = []
    blocks = get_block(e)
    for block in blocks:
        call_list = get_call(block)
        for call in call_list:
            calls.append(call)
    return calls


def get_newreturn(e):
    returns = []
    blocks = get_block(e)
    for block in blocks:
        return_list = get_return(block)
        for return_ele in return_list:
            returns.append(return_ele)
    return returns


def get_include(e):
    return e('//cpp:include')


def get_unit(e):
    return e('//src:unit')


def save_tree_to_file(tree, file):
    with open(file, 'w') as f:
        f.write(etree.tostring(tree).decode('utf8'))

def hunt3(e):
    flag_freopen = False
    calls = []
    text = ''
    text_list = []
    blocks = get_block(e)
    # for block in blocks:
    #     call_list = get_call(block)
    #     for call in call_list:
    #         calls.append(call)
    # for call_ele in calls:
    #     if call_ele.text == 'freopen':
    #         text = ''.join(call_ele.itertext()).replace('\n', '').replace(' ', '')
    #         text_list.append(text)
    #         flag_freopen = True

    for block in blocks:
        call_list = get_call(block)
        for call in call_list:
            if len(call) == 0: continue
            if call[0].text == 'freopen':
                text = ''.join(call.itertext()).replace('\n', '').replace(' ', '')
                text_list.append(text)
                flag_freopen = True
    return flag_freopen, text_list


def hunt4(e):
    flag_return = False
    returns = []
    s = ''
    blocks = get_block(e)
    for block in blocks:
        pre = block.getprevious()
        if pre is not None:
            if pre.getprevious() is not None:
                if pre.getprevious().text == 'main':
                    return_list = get_return(block)
                    for return_ele in return_list:
                        if return_ele.text.replace('\n', '').replace(' ', '') == 'return':
                            if return_ele[0][0].text == '0':
                                flag_return = True
                                s = return_ele
                            elif len(return_ele[0])>=2 and return_ele[0][1].text == '0':
                                flag_return = True
                                s = return_ele
    return flag_return, s


def hunt1(e):
    name_list = []
    get_elements = get_include(e)
    for get_element in get_elements:
        element = get_element[1].text
        name_list.append(element)
    return name_list


def hunt5(e):
    namespaces = []
    names = []
    get_names = e('//src:namespace/src:name')
    for name in get_names:
        names.append(name.text)
        namespaces.append(name.getparent().getparent())
    return names, namespaces


def hunt2(e, pro=2):
    flag2 = False
    exprs = get_exprs(e)
    text = ''
    for expr in exprs:
        text = ''.join(expr.itertext()).replace('\n', '').replace(' ', '')
        if text == 'ios::sync_with_stdio(0)':
            flag2 = True
            break
        elif text == 'ios_base::sync_with_stdio(false)':
            flag2 = True
            break
        elif text == 'ios::sync_with_stdio(false)':
            flag2 = True
            break
        if pro == 1 and flag2 == True:
            expr.getparent().remove(expr)
    return flag2, text

def find_ios(xml_path):
    xmlfilepath = os.path.abspath(xml_path)
    flag = False
    text = []

    text = []
    for root, sub_dirs, files in os.walk(xmlfilepath):
        for file1 in files:
            file = os.path.join(root, file1)
            e = init_parser(file)
            flag, text = hunt2(e)
            if flag == True:
                break
    return flag, text


def find_namespace(xml_path):
    xmlfilepath = os.path.abspath(xml_path)
    namespaces = []
    names = []
    auth_flag = False
    for root, sub_dirs, files in os.walk(xmlfilepath):
        for file in files:
            file = os.path.join(root, file)
            e = init_parser(file)
            get_name = e('//src:namespace/src:name')
            for name in get_name:
                if name.text not in names:
                    names.append(name.text)
                    namespaces.append(name.getparent().getparent())
                    auth_flag = True
    return namespaces, auth_flag


def find_freopen(xml_path):
    xmlfilepath = os.path.abspath(xml_path)
    flag = False
    text = []
    for root, sub_dirs, files in os.walk(xmlfilepath):
        for file1 in files:
            file = os.path.join(root, file1)
            e = init_parser(file)
            flag, text = hunt3(e)
            if flag == True:
                break
    return flag, text


def find_return(xml_path):
    xmlfilepath = os.path.abspath(xml_path)
    flag = False
    for root, sub_dirs, files in os.walk(xmlfilepath):
        for file1 in files:
            file = os.path.join(root, file1)
            e = init_parser(file)
            flag, s = hunt4(e)
            if flag == True:
                break
    return flag


def put_return(program_path, author_path):
    auth_flag = find_return(author_path)
    pro_file_path = os.path.abspath(program_path)
    e = init_parser(pro_file_path)
    pro_flag, s = hunt4(e)
    if auth_flag == False:
        pass
    if auth_flag == True:
        if pro_flag == True:
            pass
        else:
            blocks = get_block(e)
            for block in blocks:
                pre = block.getprevious()
                if pre is not None:
                    if pre.getprevious() is not None:
                        if pre.getprevious().text == 'main':
                            block_content = block[0]
                            if len(block_content) > 0:
                                node = Element('return')
                                node.text = 'return 0;'
                                block_content.append(node)
                            else:
                                node = Element('return')
                                node.text = 'return 0;'
                                block_content.insert(0, node)


def put_namespace(program_path, author_path):
    auth_namespaces, auth_flag = find_namespace(author_path)
    pro_file_path = os.path.abspath(program_path)
    e = init_parser(pro_file_path)
    include = e('//src:include')
    pro_names, pro_namespaces = hunt5(e)
    pro_namespace = []
    if auth_flag == False:
        pass
    elif auth_flag == True:
        for auth_namespace in auth_namespaces:
            if auth_namespace[0][0].text not in pro_names:
                pro_namespace.append(auth_namespace)
        for namespace in pro_namespace:
            if include != []:
                next_ele = include[-1].getnext()
                index_next = next_ele.getparent().index(next_ele)
                next_ele.getparent().insert(index_next, namespace)
            else:
                unit = e('//src:unit')[0]
                unit.insert(0, namespace)


def put_freopen(program_path, author_path):
    auth_flag, text = find_freopen(author_path)
    pro_file_path = os.path.abspath(program_path)
    e = init_parser(pro_file_path)
    pro_flag, pro_text = hunt3(e)
    if auth_flag == True:
        if pro_flag == True:
            pre_freopens = e('//src:call/src:name')
            for pre_freopen in pre_freopens:
                if pre_freopen.text == 'freopen':
                    pre_freopen.getparent().getparent().tail = ''
                    pre_freopen.getparent().getparent().remove(pre_freopen.getparent())
                    pro_flag = False
        if pro_flag == False:
            blocks = get_block(e)
            for block in blocks:
                pre = block.getprevious()
                if pre is None: continue
                if pre.getprevious() is not None:
                    if pre.getprevious().text == 'main':
                        if len(text) == 1:
                            node1 = Element('call')
                            node1.text = text[0] + ';' + '\n'
                            block[0].insert(0, node1)
                        elif len(text) == 2:
                            node1 = Element('call')
                            node1.text = text[0] + ';' + '\n'
                            block[0].insert(0, node1)
                            node2 = Element('call')
                            node2.text = text[1] + ';' + '\n'
                            block[0].insert(1, node2)
    if auth_flag == False:
        if pro_flag == False:
            pass
        else:
            pre_freopens = e('//src:call/src:name')
            for pre_freopen in pre_freopens:
                if pre_freopen.text == 'freopen':
                    pre_freopen.getparent().getparent().tail = ''
                    pre_freopen.getparent().getparent().remove(pre_freopen.getparent())

def put_ios(program_path, author_path):
    program_file_path = os.path.abspath(program_path)
    auth_flag, auth_text = find_ios(author_path)
    e = init_parser(program_file_path)
    hunt2(e, pro=1)
    if auth_flag == True:
        blocks = get_block(e)
        for block in blocks:
            pre = block.getprevious()
            if pre is None: continue
            if pre.getprevious() is not None:
                if pre.getprevious().text == 'main':
                    node = Element('expr')
                    node.text = auth_text
                    node.tail = ';\n'
                    block[0].insert(0, node)

def countnum(xml_path):
    xmlfilepath = os.path.abspath(xml_path)
    d = {}
    ele_list = []
    for root, sub_dirs, files in os.walk(xml_path):
        for file1 in files:
            file = os.path.join(root, file1)
            e = init_parser(file)
            get_elements = get_include(e)
            for get_element in get_elements:
                element = get_element[1].text
                ele_list.append(element)
    return ele_list


def transform_include(program_path, author_path):
    flag = 0
    res = countnum(author_path)
    auth_list_keys = res
    pro_list_keys = []
    if program_path != '':
        e = init_parser(program_path)
        pro_list_keys = hunt1(e)

    len1 = len(pro_list_keys)
    pro_list_key = pro_list_keys
    for element in auth_list_keys:
        if element not in pro_list_keys:
            flag = 1
            pro_list_keys.append(element)
    return pro_list_keys, len1, flag, auth_list_keys, pro_list_key


def transform1(program_path, author_path, ignore_list):
    new_ignore_list = []
    flag = False
    pro_list_keys, len1, flag, auth_list_keys, pro_list_key = transform_include(program_path, author_path)
    e = init_parser(program_path)
    include_first = get_include(e)
    includes = get_include(e)
    for include in includes:
        index = include.getparent().index(include)
        del include.getparent()[index]

    pro_list_keys.sort()

    unit_elem = get_unit(e)[0]
    node = Element('include')
    unit_elem.insert(0, node)
    for elem in pro_list_keys:
        node1 = Element('directive')
        node1.text = '#include '
        node2 = Element('file')
        node2.text = elem
        node2.tail = '\n'
        node.append(node1)
        node.append(node2)
        new_ignore_list.append(elem)
        flag = True
    return flag, new_ignore_list


def xml_file_path(xml_path):
    global flag
    save_xml_file = './transform_xml_file/include'
    transform_java_file = './pre_file/transform_c/include'

    if not os.path.exists(transform_java_file):
        os.mkdir(transform_java_file)
    if not os.path.exists(save_xml_file):
        os.mkdir(save_xml_file)
    for xml_path_elem in xml_path:
        xmlfilepath = os.path.abspath(xml_path_elem)
        e = init_parser(xmlfilepath)
        flag = False
        if flag == True:
            str = xml_path_elem.split('\\')[-1]
            sub_dir = xml_path_elem.split('\\')[-2]
            path = os.path.join(save_xml_file, sub_dir)

            if not os.path.exists(os.path.join(save_xml_file, sub_dir)):
                os.mkdir(os.path.join(save_xml_file, sub_dir))
            save_tree_to_file(doc, os.path.join(path, str))
    return save_xml_file, transform_java_file


def program_transform(program_path, author_path, ignore_list=[]):
    flag, new_ignore_list = transform1(program_path, author_path, ignore_list)
    save_tree_to_file(doc, './style/style.xml')
    put_freopen('./style/style.xml', author_path)
    save_tree_to_file(doc, './style/style.xml')
    put_namespace('./style/style.xml', author_path)
    save_tree_to_file(doc, './style/style.xml')
    put_ios('./style/style.xml', author_path)
    save_tree_to_file(doc, './style/style.xml')
    put_return('./style/style.xml', author_path)
    save_tree_to_file(doc, './style/style.xml')
    return flag, doc, new_ignore_list


if __name__ == '__main__':
    path1 = '../demo1.xml'
    path2 = '../xml_file/amneiht'
    put_return(path1, path2)
    save_tree_to_file(doc, '../style1.xml')

