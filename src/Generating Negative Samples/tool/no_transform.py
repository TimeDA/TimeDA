import os
import re
import scan
from py import (if_spilt, if_combine, switch_if, ternary, while_for, for_while, assign_value, assign_combine,
                if_switch, re_temp, temporary_var, init_declaration,
                var_init_split, array_to_pointer, pointer_to_array,
                static_dyn_mem, dyn_static_mem, cpp_lib_to_c, c_lib_to_cpp,
                typedef, type11_def, type_define, retypedef, const_vars, incr_opr_prepost,
                var_init_pos, var_init_merge,var_name_style,select_tmp_id_names,select_nontmp_id_names,split_function,include)
A_name = ''
path_program = ''
change_file = 'srcml ./style/a.'+path_program.split('.')[-1]+' -o '
style_list = []
def get_input(path_program, A_name, style_path):
    if not os.path.exists('./pre_file/program_style/'+A_name):
        os.mkdir(os.path.join('./pre_file/program_style/', A_name))

    for root, sub_dirs, files in os.walk(style_path):
        A_file = ''
        for file in files:
            name = re.findall(r'(.+?)\.', file)[0]
            if A_name == name:
                A_file = os.path.join(root, file)
        if A_file != '':
            list_a = get_author_style(A_file)
            compare_P_to_A(list_a, path_program)


def get_input1(style_path):
    global A_name, path_program
    A_name = input("Please enter author A:")
    path_program = input("Please enter the program P path:")
    for root, sub_dirs, files in os.walk(style_path):
        A_file = ''
        for file in files:
            name = re.findall(r'(.+?)\.', file)[0]
            if A_name == name:
                A_file = os.path.join(root, file)
        if A_file != '':
            list_a = get_author_style(A_file)
            compare_P_to_A(list_a, path_program)
def get_author_style(A_file):
    f_A = open(A_file, 'r')
    data_A = f_A.readlines()
    list_A = []
    #############################################################
    for i in range(0, 16):
        dict_A = eval(data_A[i])
        stype_1(dict_A, list_A)
    return list_A


def get_style2(author_name='', tmp=1):
    if tmp == 1:
        path_author = get_author_path(author_name)
        #
        return select_tmp_id_names.get_vars_cnt_by_author(path_author, tmp_only=True)
    elif tmp == 2:
        path_author = get_author_path(author_name)
        #
        return select_tmp_id_names.get_vars_cnt_by_author(path_author,tmp_only=False)
def get_style12(author_name = ''):
    path_author = get_author_path(author_name)
    a, b, c, auth_list_keys, d = include.transform_include('', path_author)
    return auth_list_keys
def compare_P_to_A(list_a, path_program):
    list_p = []
    list_p_main = []
    program_name = path_program.split('/')[-1]
    scan.srcml_java_xml(path_program, './style/style')
    path_author = get_author_path(A_name)
    global style_list
    style_list = scan.get_style('./style/style.xml')
    scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
    get_precent(style_list)
    #############################################################
    for i in range(3, 19):
        stype_1(style_list[i], list_p)
    for elem_p in list_p:
        str_p = [0]
        if type(elem_p) == str:
            str_p = elem_p.split('.')
        if elem_p == '17.1':
            list_p_main.append('17.1')
        if elem_p == '17.2':
            list_p_main.append('17.2')
        for elem_a in list_a:
            str_a = [0]
            if type(elem_a) == str:
                str_a = elem_a.split('.')
            if str_p[0] == '1' and str_p[0] == str_a[0] and str_p[1] != str_a[1]:
                scan.srcml_java_xml(os.path.join('./style/transform', program_name),'./style/style')
                var_name_style.program_transform('./style/style.xml', elem_p, elem_a)
                scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
                list_p_main.append(str_p[0])
            elif elem_p == '4.1' or elem_p == '4.2':
                if elem_a == '4.1' and elem_a == elem_p:
                    list_p_main.append(elem_p)
            elif str_p[0] == '9' and str_p[0] == str_a[0] and str_p[1] != str_a[1]:
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                incr_opr_prepost.program_transform('./style/style.xml', elem_p, elem_a)
                print(elem_p,elem_a)
                scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
                list_p_main.append(str_p[0])
            elif type(elem_p) == dict and type(elem_a) == dict:
                if program_name != '8294486_5681755159789568_imulan.cpp' and A_name != 'bigelephant29':
                    if abs(elem_p['19'][0] - elem_a['19'][0]) >= 10:
                        list_p_main.append('19')
                        scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                        split_function.transform_by_line_cnt('./style/style.xml', path_author, srccode_path=path_program, save_to='./style/transform.xml')
                        scan.srcml_xml_java('./style/transform.xml', os.path.join('./style/transform', program_name))
                    elif abs(elem_p['19'][1] - elem_a['19'][1]) >= 1:
                        list_p_main.append('19')
                        scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                        split_function.transform_by_nesting_level('./style/style.xml', path_author, srccode_path=path_program, save_to= './style/transform.xml')
                        scan.srcml_xml_java('./style/transform.xml', os.path.join('./style/transform', program_name))
            elif str_p[0] == str_a[0] and str_p[1] != str_a[1]:
                list_p_main.append(elem_p)
            if elem_a == '17.1':
                if '17.1' in list_p_main:
                    list_p_main.remove('17.1')
            if elem_a == '17.2':
                if '17.2' in list_p_main:
                    list_p_main.remove('17.2')
    scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
    a_12, b_12, c_12,auth_list_keys, pro_list_key= include.transform_include('./style/style.xml', path_author)
    if c_12 == 1:
        list_p_main.append('12')
        style_list.append(pro_list_key)

    list_p_main.append('2')
    list_p_main.append('3')
    if len(list_p_main) > 0:
        py_list = get_eval(list_p_main)
        for elem in py_list:
            if elem == 'var_name_style':
                #scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
                continue
            elif elem == 'select_tmp_id_names':
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                if select_tmp_id_names.is_transformable('./style/style.xml', path_author):
                    #
                    style_list.append(select_tmp_id_names.get_vars_cnt_by_author('./style/style.xml',tmp_only=True))

                    select_tmp_id_names.transform_tmp_id_names('./style/style.xml', path_author, ignore_list= [], save_to= './style/transform.xml')
                    scan.srcml_xml_java('./style/transform.xml', os.path.join('./style/transform', program_name))
                else:
                    list_p_main.remove('2')
            elif elem == 'select_nontmp_id_names':
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                if select_nontmp_id_names.is_transformable('./style/style.xml', path_author):
                    #
                    style_list.append(select_tmp_id_names.get_vars_cnt_by_author('./style/style.xml',tmp_only=False))
                    #
                    select_nontmp_id_names.transform_nontmp_id_names('./style/style.xml', path_author, save_to='./style/transform.xml')
                    scan.srcml_xml_java('./style/transform.xml', os.path.join('./style/transform', program_name))
                else:
                    list_p_main.remove('3')
            elif elem == 'const_vars':
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                eval(elem).program_transform('./style/style.xml', path_author)
                scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
            elif elem == 'incr_opr_prepost':
                continue
            elif elem == 'retypedef':
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                eval(elem).program_transform('./style/style.xml', path_author)
                scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
            elif elem == 'type11_def':
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                eval(elem).program_transform('./style/style.xml', path_author)
                scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
            elif elem == 'include':
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                eval(elem).program_transform('./style/style.xml', path_author)
                scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
            elif elem == 'split_function':
                continue
            else:
                scan.srcml_java_xml(os.path.join('./style/transform', program_name), './style/style')
                eval(elem).program_transform('./style/style.xml')
                scan.srcml_xml_java('./style/style.xml', os.path.join('./style/transform', program_name))
        if len(list_p_main)!=0:
            print(list_p_main)
            print("Succeed")
    if len(list_p_main)== 0:
        print("-----------------------")
        print("Failed")
def get_author_path(A_name):
    path = './xml_file'
    for root, sub_dirs, files in os.walk(path):
        for sub_dir in sub_dirs:
            if A_name == sub_dir:
                return os.path.join(path, sub_dir)
def get_precent(style_list):
    #############################################################
    for i in range(3, 18):
        dict_style = style_list[i]
        sum1 = sum(dict_style.values())
        for key in dict_style:
            if sum1 != 0:
                dict_style[key] = round((dict_style[key] / sum1) * 100, 1)
def stype_1(dict,list):
    for key in dict:
        if key == '17.1' or key == '17.2':
            if dict[key] > 0:
                list.append(key)
        elif key == '19':
            list.append({'19':dict[key]})
        elif len(dict) == 2:
            if dict[key] >= 70:
                list.append(key)
        elif len(dict) == 4:
            if dict[key] >= 50:
                list.append(key)
        elif len(dict) == 5:
            if dict[key] >= 50:
                list.append(key)
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

