# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import os
import sys

from lxml import etree
from lxml.etree import Element

flag = False
ns = {'src': 'http://www.srcML.org/srcML/src',
   'cpp': 'http://www.srcML.org/srcML/cpp',
   'pos': 'http://www.srcML.org/srcML/position'}

save_xml_file = './transform_xml_file/ini_var_muti'
transform_java_file = './pre_file/transform_java/ini_var_muti'
doc=None



def init_parser(file):
    global doc
    doc=etree.parse(file)
    e=etree.XPathEvaluator(doc,namespaces=ns)
    return e


def get_b_cont(e):
    return e('//src:block_content')


def get_decl_s(elem):
    return elem.xpath('src:decl_stmt',namespaces=ns)


def get_decl_type(elem):
    return elem.xpath('src:decl/src:type/src:name',namespaces=ns)

def get_allnames(decl):
    return decl.xpath('.//src:name', namespaces=ns)

def tramsform(e, ignore_list=[], instances=None):
    global flag
    flag = False
    block_contents = [get_b_cont(e) if instances is None else (instance[0] for instance in instances)]
    tree_root = e('/*')[0].getroottree()
    new_ignore_list = []
    #获取所有的block_content标签 即{}中的语句块
    #遍历其中的每一个{}语句块找到单独的赋值初始化语句
    for item in block_contents:
        for block_content in item:
            #获得block_content下的所有初始化语句
            decl_stmts=[]
            vars_names = []
            #用一个列表来保留唯一一个类型
            for dec_stmt in block_content:
                if dec_stmt.tag!='{http://www.srcML.org/srcML/src}decl_stmt':
                    ls=[]
                    for decl_stmt in decl_stmts:
                        decl_stmt_prev = decl_stmt.getprevious()
                        decl_stmt_prev = decl_stmt_prev if decl_stmt_prev is not None else decl_stmt
                        decl_stmt_prev_path = tree_root.getpath(decl_stmt_prev)
                        if decl_stmt_prev_path in ignore_list:
                            continue
                        key=0
#------------------------------------排除合并的时候前边有使用过的变量-----------
                        rep_var_flag = False
                        curr_names = get_allnames(decl_stmt)
                        for curr_name in curr_names:

                            if len(curr_name) == 0:
                                currname_var = ''.join(curr_name.itertext())
                                # print(currname_var)
                                if currname_var in vars_names:
                                    rep_var_flag = True

                                    break

                        for d in decl_stmt:
                            if d.tag == '{http://www.srcML.org/srcML/src}comment': continue
                            if len(d[1]) == 0:
                                vars_names.append("".join(d[1].itertext()))
                            else:
                                vars_names.append("".join(d[1][0].itertext()))
                        if rep_var_flag == True: continue
                        #----------------------------------end--------------------
                        #---------------处理type存在多类型的情况---------
                        for decl in decl_stmt:
                            if len(decl) == 2 or len(decl) == 3:  # and decl[2][0][0].tag=='{http://www.srcML.org/srcML/src}literal'):
                                modifier_num = decl[0].xpath("src:modifier", namespaces=ns)
                                if len(modifier_num) != 0:
                                    first_mod_index=decl[0].index(modifier_num[0])
                                    modifier = Element('modifier')
                                    modifier.text = ''
                                    for modi in decl[0][first_mod_index:]:
                                        modifier.text += modi.text
                                        decl[0].remove(modi)
                                    modifier.text+=' '
                                    decl.insert(1, modifier)
                        #----------------------------------end---------
                        if len(decl_stmt)!=0 and len(decl_stmt[0])!=0 and len(decl_stmt[0][0])!=0 and len(decl_stmt[0][0][0])==0:
                            for l in ls:
                                if ''.join(decl_stmt[0][0].itertext()).replace(' ', '') == ''.join(l[0][0].itertext()).replace(' ',''):  # and decl_stmt[0][0][0].text==l[0][0][0].text:
                                    flag = True
                                    # if len(l[0][0]) == 1:
                                    #     if len(decl_stmt[0][0])==1:
                                    #         decl_stmt.getchildren()[0].remove(decl_stmt.getchildren()[0].getchildren()[0])
                                    #     else:
                                    #         decl_stmt[0][0].remove(decl_stmt[0][0][0])
                                    # else:
                                    decl_stmt[0].remove(decl_stmt[0][0])
                                    # decl_stmt[0][0].remove(get_decl_type(decl_stmt)[0])
                                    l.getchildren()[-1].tail=','
                                    decl_stmt.getchildren()[0].tail=''
                                    for children in decl_stmt.getchildren():
                                        children.tail=''
                                        l.append(children)
                                        l.getchildren()[-1].tail=','
                                    l.getchildren()[-1].tail = ';'
                                    key=1
                                    break
                            if key==0:
                                #flag用于标志是否有新的类型 加入列表
                                ls.append(decl_stmt)
                            if flag:
                                new_ignore_list.append(decl_stmt_prev_path)
                    decl_stmts=[]
                else:
                    decl_stmts.append(dec_stmt)
    return flag, tree_root, new_ignore_list


def save_file(doc, file):
    with open(file,'w')as f:
        f.write(etree.tostring(doc).decode('utf-8'))


def get_style(e):
    num=0
    block_contents = get_b_cont(e)
    # 遍历其中的每一个{}语句块找到单独的赋值初始化语句
    for block_content in block_contents:
        # 获得block_content下的所有初始化语句
        decl_stmts = []
        # 用一个列表来保留唯一一个类型
        for decl_stmt in block_content:
            if decl_stmt.tag != '{http://www.srcML.org/srcML/src}decl_stmt':
                ls = []
                for decl_stmt in decl_stmts:
                    key = 0
                    if len(decl_stmt)!=0 and len(decl_stmt[0])!=0 and len(decl_stmt[0][0]) != 0 and len(decl_stmt[0][0][0]) == 0:
                        for l in ls:
                            if len(get_decl_type(decl_stmt))==0 or len(get_decl_type(l))==0:continue
                            if get_decl_type(decl_stmt)[0].text == get_decl_type(l)[0].text:
                                num+=1
                                key = 1
                                break
                        if key == 0:
                            # flag用于标志是否有新的类型 加入列表
                            ls.append(decl_stmt)
                decl_stmts = []
            else:
                decl_stmts.append(decl_stmt)
    return ["7.2",num]

def xml_file_path(xml_path):
    global flag
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
        tramsform(e)
        if flag == True:
            str = xml_path_elem.split('\\')[-1]
            sub_dir = xml_path_elem.split('\\')[-2]
            if not os.path.exists(os.path.join(save_xml_file, sub_dir)):
                os.mkdir(os.path.join(save_xml_file, sub_dir))
            save_file(doc, os.path.join(save_xml_file, sub_dir, str))
    return save_xml_file, transform_java_file
def program_transform(program_path):
    e = init_parser(program_path)
    tramsform(e)
    save_file(doc,'./style/style.xml')
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
