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
    # 获取所都的while
    while_elems = [get_while(e) if instances is None else (instance[0] for instance in instances)]
    #获取树根，后面取路径要用
    tree_root = e('/*')[0].getroottree()
    new_ignore_list = []
    if len(while_elems)>0:
        for item in while_elems:
            for while_elem in item:
                #过滤掉上一轮由for变换成的while
                #因为for转while在while前插入了一条语句，所以没变换的部分是从while语句往上数两个语句
                #进行两次getprevious()，如果while语句前面不足两条语句（getprevious返回None），就保留最后一条不是None的
                while_prev = while_elem.getprevious()
                while_prev_prev = [while_prev.getprevious() if while_prev is not None else while_elem][0]
                while_prev_prev = [while_prev_prev if while_prev_prev is not None else while_prev][0]
                #取路径，看路径是否在传进来的忽略列表里
                while_prev_path = tree_root.getpath(while_prev_prev)
                if while_prev_path in ignore_list:
                    #print('变换过，忽略')
                    continue
                flag = True

                # 得到while的循环条件
                elem_condition = get_condition(while_elem)[0]
                while_elem.text = 'for'
                while_elem.tag = 'for'
                elem_condition.text = '(;'
                elem_condition[-1].tail = ';)'
                #记录这次变换后没变的位置，即while前一条语句位置
                new_ignore_list.append(while_prev_path)
    return flag, tree_root, new_ignore_list
def count(e):
    # 获取所都的while
    while_elems = get_while(e)
    return len(while_elems)
def get_number(xml_path):
    xmlfilepath = os.path.abspath(xml_path)
    # 解析成树
    e = init_parse(xmlfilepath)
    return count(e)
def save_tree_to_file(tree, file):
    with open(file, 'w') as f:
        f.write(etree.tostring(tree).decode('utf8'))

def xml_file_path(xml_path):
    global flag
    # xml_path 需要转化的xml路径
    # sub_dir_list 每个作者的包名
    # name_list 具体的xml文件名
    save_xml_file = './transform_xml_file/while_for'
    transform_java_file = './pre_file/transform_java/while_for'
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

if __name__ == '__main__':
    path = '../demo1.xml'
    e = init_parse(path)
    trans_tree(e)
    save_tree_to_file(doc, '../demo2.xml')
def program_transform(program_path):
    e = init_parse(program_path)
    trans_tree(e)
    save_tree_to_file(doc, './style/style.xml')