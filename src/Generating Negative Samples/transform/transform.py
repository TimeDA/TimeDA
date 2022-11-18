import os
# 输入作者A和作者B的姓名，和程序P的路径
import re
from test_transform import scan
from test_transform.get_transform import transform_13
from test_transform.py import (if_spilt, if_combine, switch_if, ternary, while_for, for_while, assign_value, assign_combine,
                if_switch, re_temp, temporary_var, init_declaration,java_split_function,java_merge_function,
                var_init_split, array_to_pointer, pointer_to_array,java_import,tmp_in_name,
                static_dyn_mem, dyn_static_mem, cpp_lib_to_c, c_lib_to_cpp,
                typedef, type11_def, type_define, retypedef, const_vars, incr_opr_prepost,
                var_init_pos, var_init_merge,var_name_style,select_tmp_id_names,select_nontmp_id_names,split_function,include)
A_name = ''
path_program = ''
change_file = 'srcml ./style/a.'+path_program.split('.')[-1]+' -o '
style_list = []
def get_input(path_program, A_name, style_path):
    #3333333333333333
    if not os.path.exists('./pre_file/program_style/'+A_name):
        os.mkdir(os.path.join('./pre_file/program_style/', A_name))

    # print("△△△△△△△△△△△△△△△△△△△△△△△")
    print("-----------------------")
    print("作者的名字：", A_name)
    print("程序的名字: ", path_program.split('/')[-1].split('.')[0])
    #print("程序的名字: ", path_program.split('\\')[-1].split('.')[0])

    print("-----------------------")
    # print("△△△△△△△△△△△△△△△△△△△△△△△")
    for root, sub_dirs, files in os.walk(style_path):
        A_file = ''
        for file in files:
            name = re.findall(r'(.+?)\.', file)[0]
            if A_name == name:
                A_file = os.path.join(root, file)
        # 得到作者的风格
        if A_file != '':
            list_a = get_author_style(A_file)
            compare_P_to_A(list_a, path_program)


def get_input1(style_path):
    global A_name, path_program
    A_name = input("请输入作者A:")
    path_program = input("请输入程序P路径:")
    for root, sub_dirs, files in os.walk(style_path):
        A_file = ''
        for file in files:
            name = re.findall(r'(.+?)\.', file)[0]
            if A_name == name:
                A_file = os.path.join(root, file)
        # 得到作者的风格
        if A_file != '':
            list_a = get_author_style(A_file)
            compare_P_to_A(list_a, path_program)
def get_author_style(A_file):
    f_A = open(A_file, 'r')
    data_A = f_A.readlines()
    # list_A 作者A的主流风格
    list_A = []
    #############################################################
    for i in range(0, 16):
        dict_A = eval(data_A[i])
        # 其他类别需要另外判断的可以再写一个函数
        stype_1(dict_A, list_A)
    #print("-----------------------")
    print("作者的风格："+str(list_A))
    return list_A
# 输入程序P，得到程序P和目标作者B的风格差异


def get_style2(author_name='', tmp=1):
    if tmp == 1:
        path_author = get_author_path(author_name)
        #
        return select_tmp_id_names.get_vars_cnt_by_author(path_author, tmp_only=True)
    elif tmp == 2:
        path_author = get_author_path(author_name)
        #
        return select_tmp_id_names.get_vars_cnt_by_author(path_author,tmp_only=False)
def get_style12(path_program='', author_name = ''):
    path_author = get_author_path(author_name)
    a, b, c, auth_list_keys1, d = include.transform_include(path_program, path_author)
    a, b, c ,auth_list_keys2,d = java_import.transform_include(path_program, path_author)
    return auth_list_keys1 if auth_list_keys2 == [] else auth_list_keys2

def compare_P_to_A(list_a, path_program):
    # 得到程序P的风格
    list_p = []
    list_p_main = []
    # 获取程序名字
    if path_program.endswith('.cpp'):
        scan.java_cpp_flag = 'cpp'
    if path_program.endswith('.java'):
        scan.java_cpp_flag = 'java'
    program_name = path_program.split('/')[-1]
    #program_name = path_program.split('\\')[-1]
    scan.srcml_java_xml(path_program, './style/style')

    if scan.flag == False:
        return

    # 获取作者A的路径
    path_author = get_author_path(A_name)
    print("-----------------------")
    print("输入程序的风格为：")
    global style_list
    style_list = scan.get_style('./style/style.xml')
    scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
    # # 获取程序p的风格比例
    # get_precent(style_list)
    #############################################################
    for i in range(3, 19):
        stype_2(style_list[i], list_p)

    for elem_p in list_p:
        str_p = [0]
        if type(elem_p) == str:
            str_p = elem_p.split('.')
        # 类别17
        if elem_p == '17.1':
            list_p_main.append('17.1')
        if elem_p == '17.2':
            list_p_main.append('17.2')
        for elem_a in list_a:
            str_a = [0]
            if type(elem_a) == str:
                str_a = elem_a.split('.')
            # 针对类别1
            if str_p[0] == '1' and str_p[0] == str_a[0] and str_p[1] != str_a[1]:
                scan.srcml_java_xml(os.path.join('./style/transform', program_name),'./style/style')
                var_name_style.program_transform('./style/style.xml', elem_p, elem_a)
                scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
                list_p_main.append(str_p[0])
            # 针对类别4
            elif elem_p == '4.1' or elem_p == '4.2':
                if elem_a == '4.1' and elem_a == elem_p:
                    list_p_main.append(elem_p)
            # 针对类别9
            elif str_p[0] == '9' and str_p[0] == str_a[0] and str_p[1] != str_a[1]:
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                incr_opr_prepost.program_transform('./style/style.xml', elem_p, elem_a)
                scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
                list_p_main.append(str_p[0])
            # 针对类别19
            
            elif type(elem_p) == dict and type(elem_a) == dict:
                if abs(elem_p['19'][0] - elem_a['19'][0]) >= 10:
                    pass
                    '''
                    list_p_main.append('19')
                    scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                    if program_name.endswith('.java'):
                        java_split_function.transform_by_line_cnt('./style/style.xml', path_author,
                                                         srccode_path=os.path.join('./style/transform', program_name),
                                                         save_to='./style/transform.xml')

                    if program_name.endswith('.cpp') or program_name.endswith('.c'):
                        split_function.transform_by_line_cnt('./style/style.xml', path_author,
                                                         srccode_path=os.path.join('./style/transform', program_name),
                                                         save_to='./style/transform.xml')
                    scan.srcml_xml_java('./style/transform.xml', os.path.join('./style/transform', program_name))
                    '''
                elif abs(elem_p['19'][1] - elem_a['19'][1]) >= 0.5:
                    pass
                    # list_p_main.append('19')
                    # scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                    # if program_name.endswith('.java'):
                    #     java_split_function.transform_by_nesting_level('./style/style.xml', path_author,
                    #                                           srccode_path=os.path.join('./style/transform',
                    #                                                                     program_name),
                    #                                           save_to='./style/transform.xml')
                    # if program_name.endswith('.cpp') or program_name.endswith('.c'):
                    #     split_function.transform_by_nesting_level('./style/style.xml', path_author,
                    #                                           srccode_path=os.path.join('./style/transform',
                    #                                                                     program_name),
                    #                                           save_to='./style/transform.xml')
                    # scan.srcml_xml_java('./style/transform.xml', os.path.join('./style/transform', program_name))
            # 10
            elif str_p[0] == '10' and str_a[0] == '10' and str_p[1] == str_a[1] =='1':
                list_p_main.append('10.2')
            # 针对其他类别
            elif str_p[0] == str_a[0] and str_p[1] != str_a[1]:
                if str_p[0] == '4' or str_p[0] == '5' or str_p[0] == '7' or str_p[0] == '9' or str_p[0] == '11' or str_p[0] == '12' or str_p[0] == '19' or str_p[0] == '14' or str_p[0] == '15' or str_p[0] == '16' or str_p[0] == '18':continue
                if str_p[0] == '17':continue

                list_p_main.append(elem_p)
            # 针对类别17
            if elem_a == '17.1':
                if '17.1' in list_p_main:
                    list_p_main.remove('17.1')
            if elem_a == '17.2':
                if '17.2' in list_p_main:
                    list_p_main.remove('17.2')
    # 针对类别13.3
    if '13.1' in list_p and '13.1' not in list_a and '13.2' not in list_a:
        cpp_lib_to_c.program_transform('./style/style.xml','13.1','13.3')
    elif '13.2' in list_p and '13.1' not in list_a and '13.2' not in list_a:
        cpp_lib_to_c.program_transform('./style/style.xml', '13.2', '13.3')
    elif '13.1' in list_a and '13.1' not in list_p and '13.2' not in list_p:
        cpp_lib_to_c.program_transform('./style/style.xml', '13.3', '13.1')
    elif '13.2' in list_a and '13.1' not in list_p and '13.2' not in list_p:
        cpp_lib_to_c.program_transform('./style/style.xml', '13.3', '13.2')
    # 针对类别12
    scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
    a_12, b_12, c_12,auth_list_keys, pro_list_key= include.transform_include('./style/style.xml', path_author)
    c_12 = 1
    a_12_java,b_12_java,c_12_java,auth_list_keys_java,pro_list_key_java = java_import.transform_include('./style/style.xml', path_author)
    
    # c++
    if scan.java_cpp_flag == 'cpp' or scan.java_cpp_flag == 'c':
        list_p_main.append('12.1')
        style_list.append(pro_list_key)

    # java
    if scan.java_cpp_flag == 'java':
        list_p_main.append('12.2')
        style_list.append(pro_list_key_java)
    ###########针对类别2
    list_p_main.append('2')
    list_p_main.append('3')
    if len(list_p_main) > 0:
        print(list_p_main)
        # for 循环
        py_list = get_eval(list_p_main)
        for elem in py_list:
            # 针对类别1
            if elem == 'var_name_style':
                #scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
                continue
            # 针对类别2
            elif elem == 'select_tmp_id_names':
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                if select_tmp_id_names.is_transformable('./style/style.xml', path_author):
                    # scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
                    # scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                    #
                    style_list.append(select_tmp_id_names.get_vars_cnt_by_author('./style/style.xml',tmp_only=True))
                    select_tmp_id_names.transform_tmp_id_names('./style/style.xml', path_author, ignore_list= [], save_to= './style/transform.xml')
                    scan.srcml_xml_java('./style/transform.xml', os.path.join('./style/transform', program_name))
                else:
                    list_p_main.remove('2')
            # 针对类别3
            elif elem == 'select_nontmp_id_names':
                #scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                if select_nontmp_id_names.is_transformable('./style/style.xml', path_author):
                    # scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
                    scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                    #
                    style_list.append(select_tmp_id_names.get_vars_cnt_by_author('./style/style.xml',tmp_only=False))
                    #
                    select_nontmp_id_names.transform_nontmp_id_names('./style/style.xml', path_author, save_to='./style/transform.xml')
                    scan.srcml_xml_java('./style/transform.xml', os.path.join('./style/transform', program_name))
                    #scan.srcml_xml_java('./style/transform.xml', os.path.join('./style/transform', program_name))
                else:
                    list_p_main.remove('3')
            # 针对类别4
            elif elem == 'const_vars':
                continue
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                eval(elem).program_transform('./style/style.xml', path_author)
                scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
            # 针对类别9
            elif elem == 'incr_opr_prepost':
                continue
            # 针对类别10
            elif elem == 'retypedef':
                retypedef.ls.clear()
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                eval(elem).program_transform('./style/style.xml', path_author)
                scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
            # 针对类别11
            elif elem == 'type11_def':
                continue
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                eval(elem).program_transform('./style/style.xml', path_author)
                scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
            # 针对类别12 c++
            elif elem == 'include':
                continue
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                eval(elem).program_transform('./style/style.xml', path_author)
                scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
            # 针对类别12 java
            elif elem == 'java_import':
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                eval(elem).program_transform('./style/style.xml', path_author)
                scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
            # 针对类别19
            elif elem == 'split_function':
                continue
            else:
                continue
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                eval(elem).program_transform('./style/style.xml')
                scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
        #scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
        # 222222
        scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
        tmp_in_name.trans_tree('./style/style.xml', path_author)
        scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
        if len(list_p_main)!=0:
            print("需要转化的风格为：")
            print(list_p_main)
            print("-----------------------")
            print("转化成功！！")
    if len(list_p_main)== 0:
        print("-----------------------")
        print("此程序没有风格可以转化！")

# 获取作者的路径
def get_author_path(A_name):
    path = './xml_file'
    for root, sub_dirs, files in os.walk(path):
        for sub_dir in sub_dirs:
            if A_name == sub_dir:
                return os.path.join(path, sub_dir)
# 获取比例
def get_precent(style_list):
    #############################################################
    for i in range(3, 18):
        dict_style = style_list[i]
        sum1 = sum(dict_style.values())
        for key in dict_style:
            if sum1 != 0:
                dict_style[key] = round((dict_style[key] / sum1) * 100, 1)
def stype_2(dict,list):
    for key in dict:
        # 针对类别17
        if key == '17.1' or key == '17.2':
            if dict[key] > 0:
                list.append(key)
        elif key == '19':
            list.append({'19':dict[key]})
        elif len(dict) == 2:
            if dict[key] > 0:
                list.append(key)
        else:
            if dict[key] > 0 and dict[key] == max(dict.values()):
                list.append(key)
# 获取作者风格
def stype_1(dict,list):
    for key in dict:
        # 针对类别17
        if key == '17.1' or key == '17.2':
            if dict[key] > 0:
                list.append(key)
        elif key == '19':
            list.append({'19':dict[key]})
        elif len(dict) == 2:
            if dict[key] >= 70:
                list.append(key)
        ###########大于两个的，分开讨论
        elif len(dict) == 4:
            if dict[key] >= 50:
                list.append(key)
        elif len(dict) == 5:
            if dict[key] >= 50:
                list.append(key)
# 获取对象
def get_eval(list_p):
    py_list = []
    f = open('./style/style.txt', 'r')
    style_list =eval(f.readline())
    for key in list_p:
        py_list.append((style_list[key]))
    return py_list
def scan_trans(program_path, author_name):
    style_path = './author_style'
    global A_name, path_program
    path_program = program_path
    A_name = author_name
    get_input(path_program, A_name, style_path)

if __name__ == '__main__':
    style_path = './author_style'
    get_input1(style_path)

#3264486_5736519012712448_ihahi
#ibrahim5253

#xyiyy
# L3Sota
# 5304486_5760761888505856_imulan