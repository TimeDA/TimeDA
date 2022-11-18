import operator
import sys
import os  # 加上
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


# 找到block下的call，call里面的freopen ,找到flag为True
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


# 找到main函数下的return 0 ,找到flag为True
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


# 找到include中的函数
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


# 找到ios::sync_with_stdio(0); flag为 true
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


# 判断作者是否喜欢用ios::sync_with_stdio(0);
def find_ios(xml_path):
    xmlfilepath = os.path.abspath(xml_path)
    flag = False
    text = []
    # os.walk 遍历作者包
    text = []
    for root, sub_dirs, files in os.walk(xmlfilepath):
        # 遍历每个作者包下的程序，files是程序名
        for file1 in files:
            # 绝对路径
            file = os.path.join(root, file1)
            e = init_parser(file)
            flag, text = hunt2(e)
            if flag == True:
                break
    return flag, text


# 遍历作者包，把作者用的命名空间的节点放进一个列表
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


# 判断作者是否喜欢用freopen
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


# 判断作者是否喜欢用return 0
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


# 把return 0 加到程序里
def put_return(program_path, author_path):
    auth_flag = find_return(author_path)
    pro_file_path = os.path.abspath(program_path)
    e = init_parser(pro_file_path)
    # s是return的节点
    pro_flag, s = hunt4(e)
    if auth_flag == False:
        pass
    if auth_flag == True:
        if pro_flag == True:
            pass
        # 作者有，程序没有，给程序加进去
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


# 给程序加命名空间
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
        # 给程序插入，插到头文件后面
        for namespace in pro_namespace:
            #include = e('//cpp:include')
            # 有头文件
            if include != []:
                next_ele = include[-1].getnext()
                index_next = next_ele.getparent().index(next_ele)
                next_ele.getparent().insert(index_next, namespace)
            # 没有头文件
            else:
                unit = e('//src:unit')[0]
                unit.insert(0, namespace)

# 把freopen加到程序里
def put_freopen(program_path, author_path):
    auth_flag, text = find_freopen(author_path)
    pro_file_path = os.path.abspath(program_path)
    e = init_parser(pro_file_path)
    pro_flag, pro_text = hunt3(e)
    # 如果作者喜欢用freopen，就复制到程序中
    if auth_flag == True:
        if pro_flag == True:
            pre_freopens = e('//src:call/src:name')
            for pre_freopen in pre_freopens:
                if pre_freopen.text == 'freopen':
                    pre_freopen.getparent().getparent().tail = ''
                    pre_freopen.getparent().getparent().remove(pre_freopen.getparent())
                    pro_flag = False
        if pro_flag == False:
            # 程序里没有就加进去
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
        # 删掉程序里的
        else:
            pre_freopens = e('//src:call/src:name')
            for pre_freopen in pre_freopens:
                if pre_freopen.text == 'freopen':
                    pre_freopen.getparent().getparent().tail = ''
                    pre_freopen.getparent().getparent().remove(pre_freopen.getparent())


# 加入ios::sync_with_stdio(0);
def put_ios(program_path, author_path):
    program_file_path = os.path.abspath(program_path)
    auth_flag, auth_text = find_ios(author_path)
    e = init_parser(program_file_path)
    hunt2(e, pro=1)
    if auth_flag == True:
        # # 程序没有，作者有，加入程序里面
        # node_std = Element('using')
        # node_std.text = 'using namespace std;'
        # node_std.tail = '\n'
        # # 加到include后面
        # include = e('//cpp:include')
        # # 有头文件
        # if include != []:
        #     next_ele = include[-1].getnext()
        #     index_next = next_ele.getparent().index(next_ele)
        #     next_ele.getparent().insert(index_next, node_std)
        # # 没有头文件
        # else:
        #     unit = e('//src:unit')[0]
        #     unit.insert(0, node_std)
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


# 作者包里找出库函数
def countnum(xml_path):
    xmlfilepath = os.path.abspath(xml_path)
    # 创建字典
    d = {}
    ele_list = []
    # os.walk 遍历作者包
    for root, sub_dirs, files in os.walk(xml_path):
        # 遍历每个作者包下的程序，files是程序名
        for file1 in files:
            # 绝对路径
            file = os.path.join(root, file1)
            e = init_parser(file)
            get_elements = get_include(e)
            for get_element in get_elements:
                element = get_element[1].text
                ele_list.append(element)
            # break：只查找作者包里第一个程序
            # break

    #             flag = False
    #             # 遍历字典，d.keys 字典的键
    #             for key in d.keys():
    #                 if element == key:
    #                     flag = True
    #                     # 统计次数
    #                     d[key] += 1
    #             # 字典中没有该键就添加新的 键-值对
    #             if flag == False:
    #                 d.update({element: 1})
    # # 函数使用次数按从高到低排序(按值排序)，reverse=True 降序，False升序
    # # 用此方法得到的res还是字典
    # res = dict(sorted(d.items(), key=operator.itemgetter(1), reverse=True))
    # return res
    return ele_list


def transform_include(program_path, author_path):
    flag = 0
    # # 传入数据包统计的数据
    res = countnum(author_path)
    #
    auth_list_keys = res

    # auth_list_keys = []
    # # 转换成list形式 list(res.keys())
    # auth_list_keys = list(res.keys())
    # # 如果作者包里的库函数数量大于8，则取使用频率最高的前8个
    # if len(auth_list_keys) >= 8:
    #     auth_list_keys = auth_list_keys[0:8]
    # 解析给定的程序
    pro_list_keys = []
    if program_path != '':
        e = init_parser(program_path)
        # 得到给定程序中使用的库函数
        pro_list_keys = hunt1(e)

    len1 = len(pro_list_keys)
    pro_list_key = pro_list_keys
    # 如果pro_list_keys中没有auth_list_keys中的库函数，则加在pro_list_keys中
    for element in auth_list_keys:
        if element not in pro_list_keys:
            flag = 1
            pro_list_keys.append(element)
    return pro_list_keys, len1, flag, auth_list_keys, pro_list_key


# 在给定程序的xml中加入少的库函数
def transform1(program_path, author_path, ignore_list):
    new_ignore_list = []
    flag = False
    pro_list_keys, len1, flag, auth_list_keys, pro_list_key = transform_include(program_path, author_path)
    e = init_parser(program_path)
    include_first = get_include(e)
    # 先删去原程序里的库函数
    includes = get_include(e)
    for include in includes:
        index = include.getparent().index(include)
        del include.getparent()[index]

    # 按字母升序排序
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
    # xml_path 需要转化的xml路径
    # sub_dir_list 每个作者的包名
    # name_list 具体的xml文件名
    # 转换后的xml文件
    save_xml_file = './transform_xml_file/include'
    # 转换后的C++文件
    transform_java_file = './pre_file/transform_c/include'

    if not os.path.exists(transform_java_file):
        os.mkdir(transform_java_file)
    if not os.path.exists(save_xml_file):
        os.mkdir(save_xml_file)
    for xml_path_elem in xml_path:
        xmlfilepath = os.path.abspath(xml_path_elem)
        # 解析成树
        e = init_parser(xmlfilepath)
        # 转换
        flag = False
        # transform(e)
        # 保存文件
        if flag == True:
            # str.split() 分割
            # str 输出的是每个作者的xml文件
            str = xml_path_elem.split('\\')[-1]
            # sub_dir 输出的是作者包名
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
    # path1 = './3333.xml'
    # path2 = './xml_file/123ankitagr'
    # program_transform(os.path.abspath(path1), path2)
    put_return(path1, path2)
    save_tree_to_file(doc, '../style1.xml')
    # put_ios(path1, path2)
    # save_tree_to_file(doc, './style1.xml')
    # put_freopen(path1, path2)
    # save_tree_to_file(doc, './style3.xml')
    # put_return(path1, path2)
    # save_tree_to_file(doc, './style4.xml')
    # put_namespace(path1, path2)
    # save_tree_to_file(doc, './style2.xml')
