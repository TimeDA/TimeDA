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


def get_include(e):
    return e('//src:import')
def get_unit(e):
    return e('//src:unit')
def save_tree_to_file(tree, file):
    with open(file, 'w') as f:
        f.write(etree.tostring(tree).decode('utf8'))


# 找到include中的函数
def hunt(e):
    name_list = []
    get_elements = get_include(e)
    for get_element in get_elements:
        if len(get_element)==0:continue
        element = ''.join(get_element.itertext())
        name_list.append(element)
    return name_list


# 作者包里找出库函数使用次数最高的五个
def countnum(xml_path):
    xmlfilepath = os.path.abspath(xml_path)
    # 创建字典
    d = {}
    ele_list = []
    # os.walk 遍历作者包
    for root, sub_dirs, files in os.walk(xmlfilepath):
        # 遍历每个作者包下的程序，files是程序名
        for file1 in files:
            # 绝对路径
            file = os.path.join(root, file1)
            e = init_parser(file)
            get_elements = get_include(e)
            for get_element in get_elements:
                element = ''.join(get_element.itertext())
                if element in ele_list:continue
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
    # 传入数据包统计的数据
    res = countnum(author_path)
    auth_list_keys = []
    # 转换成list形式 list(res.keys())
    auth_list_keys = res
    # 如果作者包里的库函数数量大于8，则取使用频率最高的前8个
    # 解析给定的程序
    pro_list_keys = []
    if program_path != '':
        e = init_parser(program_path)
        # 得到给定程序中使用的库函数
        pro_list_keys = hunt(e)
    #
    len1 = len(pro_list_keys)
    pro_list_key = pro_list_keys
    # 如果pro_list_keys中没有auth_list_keys中的库函数，则加在pro_list_keys中
    for element in pro_list_keys :
        if element not in auth_list_keys:
            flag = 1
            auth_list_keys.append(element)
    return auth_list_keys, len1, flag, auth_list_keys, pro_list_key
# 在给定程序的xml中加入少的库函数
def transform1(program_path, author_path):
    new_ignore_list = []
    pro_list_keys, len1, flag, auth_list_keys, pro_list_key= transform_include(program_path, author_path)
    e = init_parser(program_path)
    include_first = get_include(e)


    includes = get_include(e)
    for include in includes:
        index = include.getparent().index(include)
        del include.getparent()[index]

    # if len(include_first) == 0:
    #     unit_elem = get_unit(e)[0]
    #     for elem in pro_list_keys[len1:]:
    #         node1 = Element('import')
    #         node1.text = 'import '+elem+";\n"
    #         unit_elem.insert(0, node1)
    # else:
    #     unit_elem = get_unit(e)[0]
    #     for elem in pro_list_keys[len1:]:
    #         node1 = Element('import')
    #         node1.text = 'import '+elem+";\n"
    #         unit_elem.insert(0, node1)
    unit_elem = get_unit(e)[0]
    node = Element('import')
    unit_elem.insert(0, node)
    for elem in pro_list_keys:
        node1 = Element('name')
        node1.text = elem
        node1.tail = '\n'
        node.append(node1)
        flag = True
    return flag, new_ignore_list
def xml_file_path(xml_path):
    global flag
    # xml_path 需要转化的xml路径
    # sub_dir_list 每个作者的包名
    # name_list 具体的xml文件名
    # 转换后的xml文件
    save_xml_file = './transform_xml_file/import'
    # 转换后的C++文件
    transform_java_file = './pre_file/transform_c/import'

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

def program_transform(program_path, author_path):
    transform1(program_path, author_path)
    save_tree_to_file(doc, './style/style.xml')
if __name__ == '__main__':
    path1 = '../demo1.xml'
    path2 = '../xml_file/emigonza'
    program_transform(os.path.abspath(path1),path2)