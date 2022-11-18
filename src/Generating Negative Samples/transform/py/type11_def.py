
import sys
import glob

from lxml.etree import Element

path='.\\projects'#特征作者提取xml文件库
d_path='.\\dest'#替换目标作者xml文件库

from lxml import etree
doc=None
ns = {'src': 'http://www.srcML.org/srcML/src',
   'cpp': 'http://www.srcML.org/srcML/cpp',
   'pos': 'http://www.srcML.org/srcML/position'}

ls=[] #元素为列表[1,2,3] 1宏定义名出现次数 2宏定义名 3宏定义值（不同值只选第一个）

def_Min=2 #设定宏定义阈值

def init_parse(file):
    global doc
    doc=etree.parse(file)
    e=etree.XPathEvaluator(doc,namespaces=ns)
    return e


def get_defines(e):
    return e('//cpp:define')


def get_allname(e):
    return e('//src:literal')
def get_allvarname(e):
    return e('//src:name')


def save_file(doc, f):
    with open(f,'w')as r:
        r.write(etree.tostring(doc).decode('utf-8'))

def trans_define(e,l):
    #获得所有的宏定义标签
    defines=get_defines(e)
    all_names=get_allvarname(e)
    #首先排除已存在的相同define标签
    for name_var in all_names:
        if len(name_var) != 0: continue
        if name_var.text==l[1]:
            return
    for define in defines:
        if define[1][0].text==l[1]:
            return

    #获得所有的name标签 只要name和宏定义的0name相同则替换宏定义中的值
    # names=get_allname(e)
    # for name in names:
    #     if name.text==l[2]:
    #         name.text=l[1]
    #将l作为宏定义加到该文件中
    new_define=Element('define')
    new_define.text='#define '+str(l[1])+' '+str(l[2])+'\n'

    if len(e('//src:using')) != 0:
        elem=e('//src:using')[0]
        des=elem.getparent().index(elem)
        elem.getparent().insert(des+1,new_define)
    else:
        if len(e('//cpp:include'))!=0:
            elem=e('//cpp:include')[-1]
            des=elem.getparent().index(elem)
            elem.getparent().insert(des+1,new_define)
        else:
            des=0
            print("文件既没有using也没有include")
            elem=e('//src:unit')[0]
            if elem.getparent() is not None:
                elem.getparent().insert(des+1,new_define)

def creat_def_list(e):
    global ls
    #获取define标签
    defines=get_defines(e)
    flag=0
    for define in defines:
        if len(define) == 3 and len(define[1]) == 1:
            for l in ls:
                if define[1][0].text==l[1]:  #找到有该宏定义名
                    l[0]+=1
                    flag=1
                    break
            if flag==0:
                ls.append(list([1,define[1][0].text,define[2].text]))
            flag=0
def program_transform(program_path,author_path,ignore_list=[]):
    global ls
    files =[f for f in glob.glob(author_path+"**/*.xml",recursive=True)]
    for f in files:
        #对一个文件列表循环解析
        e = init_parse(f)
        #每循环一个文件记录其中的宏定义
        creat_def_list(e)
    e = init_parse(program_path)
    global flag
    flag=False
    tree_root=e('/*')[0].getroottree()
    new_ignore_list=[]

    for l in ls:
        value_name=l[1]
        if value_name in ignore_list:continue

        #if l[0]>=def_Min:
        trans_define(e, l)
        flag=True
        value_name = l[1]
        # 记录define名字
        new_ignore_list.append(value_name)
    save_file(doc, './style/style.xml')
    ls=[]
    return flag,tree_root,new_ignore_list

    #取超过阈值的宏定义  新增到目标作者的源代码中
    # des=[f for f in glob.glob(d_path+'**/*.xml',recursive=True)]
    # for f in des:
    #     e=init_parse(f)
    #     for l in ls:
    #         if l[0]>=def_Min:
    #             trans_define(e,l,f)

