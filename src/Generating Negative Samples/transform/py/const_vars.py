import glob

from lxml.etree import Element
from copy import deepcopy


path='.\\consts'#特征作者提取xml文件库
d_path='.\\des_con'#替换目标作者xml文件库

from lxml import etree
doc=None
ns = {'src': 'http://www.srcML.org/srcML/src',
   'cpp': 'http://www.srcML.org/srcML/cpp',
   'pos': 'http://www.srcML.org/srcML/position'}

ls=[] #作者风格记录
des_ls=[]#转换目标程序风格记录

def_Min=1 #设定宏定义阈值

def init_parse(file):
    global doc
    doc=etree.parse(file)
    e=etree.XPathEvaluator(doc,namespaces=ns)
    return e



def get_consts(e):
    elem=e('//src:unit')[0]
    return elem.xpath('src:decl_stmt',namespaces=ns)


def get_allname(e):
    return e('//src:name')

def save_file(doc, f):
    with open(f,'w')as r:
        r.write(etree.tostring(doc).decode('utf-8'))


# def trans_define(e,l,f):
#     #获得所有的宏定义标签
#     consts=get_consts(e)
#     #首先排除已存在的相同define标签
#     for const in consts:
#         for i in range(len(const)):
#             if const[i][1].text==l[1]:
#                 return
#
#     #获得所有的name标签 只要name和宏定义的0name相同则替换宏定义中的值
#
#     elem=e('//src:using')[0]
#     des=elem.getparent().index(elem)
#     elem.getparent().insert(des+1,l[2])
#     save_file(doc, f)

def creat_def_list(e,cons_ls):
    #获取define标签
    consts=get_consts(e)
    flag=0
    for const in consts:
        if const[0][0][0].text=='const':
            for i in range(len(const)):

                if len(const[i][1]) != 0 and const[i][1][0].tag=='{http://www.srcML.org/srcML/src}name':
                    var_name=const[i][1][0].text
                elif len(const[i][1])==0:
                    var_name=const[i][1].text
                else:
                    continue
                if var_name=='count':continue
                for l in cons_ls:
                    if var_name==l[1]:
                        l[0]+=1
                        flag=1
                        break
                if flag==0:
                    cons_ls.append(list([1,var_name]))
                flag=0

def change_var_name(var_a, var_b, des_e,program_path):
    names=get_allname(des_e)
    flag_var_a=False
    for name in names:
        if len(name)!=0:continue
        if name.text==var_a:
            flag_var_a=True
            break
    if flag_var_a==False:
        for name in names:
            if len(name)!=0:continue
            if name.text==var_b:
                name.text=var_a
    save_file(doc, program_path)

def program_transform(program_path,author_path,ignore_list=[]):
    ls = []  # 作者风格记录
    des_ls = []  # 转换目标程序风格记录

    global flag
    files = [f for f in glob.glob(author_path + "**/*.xml", recursive=True)]
    for f in files:
        #对一个文件列表循环解析
        e = init_parse(f)
        #每循环一个文件记录其中的宏定义
        creat_def_list(e,ls)
    des_e = init_parse(program_path)
    creat_def_list(des_e,des_ls)
    lss=sorted(ls,key=lambda x:x[0],reverse=True)
    des_lss=sorted(des_ls,key=lambda x:x[0],reverse=True)
    if len(lss)<len(des_lss):
        min_len=len(lss)
    else:
        min_len=len(des_lss)
    for l in range(min_len):
        change_var_name(lss[l][1],des_lss[l][1],des_e,'./style/style.xml')


    flag=False
    tree_root = des_e('/*')[0].getroottree()
    new_ignore_list = []


    for l in range(min_len):
        if lss[l][1] in ignore_list:continue
        flag=True
        new_ignore_list.append(lss[l][1])
    return flag, tree_root, new_ignore_list

def get_style(program_path):
    e = init_parse(program_path)
    consts = get_consts(e)
    num=False
    for const in consts:
        if const[0][0][0].text == 'const':
            num=True
    return num



