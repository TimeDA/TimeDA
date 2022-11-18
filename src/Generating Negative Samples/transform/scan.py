import os
import subprocess
import re
import sys
cur_path = os.path.abspath('.')
up_path = os.path.dirname(cur_path)
sys.path.append(up_path)
sys.path.append(cur_path)
from test_transform import transform
from test_transform.get_transform import (transform_1, transform_4, transform_5, transform_6, transform_7, transform_8, transform_9,
                           transform_10, transform_11, transform_13, transform_14, transform_15,
                           transform_16, transform_17, transform_18,transform_19)
flag = True
java_cpp_flag = 'c'
def cmd(command):
    global flag
    flag = True
    subp = subprocess.Popen(command,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,encoding="utf-8")
    subp.wait(10)
    if subp.poll() == 0:
        flag = True
    else:
        print("False!")
        flag = False
def transform_java_xml(pre_file, xml_file):
    global java_cpp_flag
    for root, sub_dirs, file in os.walk(pre_file):
        for sub_dir in sub_dirs:
            pre_java = os.path.join(root, sub_dir)
            # 创建对应作者的xml文件目录
            if not os.path.exists(os.path.join(xml_file, sub_dir)):
                os.mkdir(os.path.join(xml_file, sub_dir))
            for root1, sub_dirs1, file1 in os.walk(pre_java):
                for file1_elem in file1:
                    # 获取文件名字（不带后缀名)
                    name = re.findall(r'(.+?)\.', file1_elem)
                    srcml_java_xml(os.path.join(pre_java, file1_elem), os.path.join(xml_file, sub_dir, name[0]))
                    if flag == False:
                        continue

def srcml_java_xml(pre_path, xml_path):
    str = 'srcml \"'+ pre_path +'\" -o \"'+ xml_path +'.xml\" --position --src-encoding UTF-8'
    cmd(str)
def srcml_xml_java(pre_path, xml_path):
    str = "srcml \""+ pre_path +'\" -o \"'+ xml_path +"\" --src-encoding UTF-8"
    cmd(str)
def get_xml(xml_file):
    for root, sub_dirs, files in os.walk(xml_file):
        if len(sub_dirs) == 0:
            break
        for sub_dir in sub_dirs:
            #############################################
            list_4 = {'1.1': 0, '1.2': 0, '1.3': 0, '1.4': 0, '1.5': 0}
            list_5 = {'4.1': 0, '4.2': 0}
            list_6 = {'5.1': 0, '5.2': 0}
            list_7 = {'6.1': 0, '6.2': 0}
            list_8 = {'7.1': 0, '7.2': 0}
            list_9 = {'8.1': 0, '8.2': 0}
            list_10 = {'9.1': 0, '9.2': 0, '9.3': 0, '9.4': 0}
            list_11 = {'10.1': 0, '10.2': 0}
            list_12 = {'11.1': 0, '11.2': 0}
            list_13 = {'13.1': 0, '13.2': 0}
            list_14 = {'14.1': 0, '14.2': 0}
            list_15 = {'15.1': 0, '15.2': 0}
            list_16 = {'16.1': 0, '16.2': 0}
            list_17 = {'17.1': 0, '17.2': 0}
            list_18 = {'18.1': 0, '18.2': 0}
            list_19 = {'19': [0, 0]}
            num_19 = 0
            # 创建作者文件
            f = open(os.path.join('./author_style', sub_dir + '.txt'), 'w')
            for root1, sub_dirs1, files1 in os.walk(os.path.join(root, sub_dir)):
                if len(files1)==0:
                    break
                # 遍历每个xml文件
                for file1 in files1:
                    # 19
                    num_19 += 1
                    # 获得每个xml文件路径tuple
                    xml_file_path = os.path.join(root, sub_dir, file1)
                    # 把作者风格写入每个txt文件
                    print(xml_file_path)
                    style_list = get_style(xml_file_path)
                    #############################################
                    for i in range(3, 19):
                        dict_style = style_list[i]
                        # 针对类别19
                        if i == 18:
                            for j in range(0, 2):
                                list_19['19'][j] += dict_style['19'][j]
                            continue
                        for key in dict_style:
                            eval('list_'+str(i+1))[key] += dict_style[key]
                #
                list_19['19'][0] = round(list_19['19'][0]/num_19, 1)
                list_19['19'][1] = round(list_19['19'][1] / num_19, 1)
                # 计算比例
                #############################################
                for i in range(3, 18):
                    dict_style = eval('list_' + str(i + 1))
                    sum1 = sum(dict_style.values())
                    for key in dict_style:
                        if sum1 != 0:
                            # 类别4
                            if key == '4.1' and dict_style[key] > 0:
                                dict_style[key] = 100.0
                                dict_style['4.2'] = 0.0
                                break
                            # 类别10
                            elif key == '10.1' and dict_style[key] > 0:
                                dict_style[key] = 100.0
                                dict_style['10.2'] = 0.0
                                break
                            # 类别11
                            elif key == '11.1' and dict_style[key] > 0:
                                dict_style[key] = 100.0
                                dict_style['11.2'] = 0.0
                                break
                            else:
                                dict_style[key] = round((dict_style[key] / sum1) * 100, 1)
                print("----------------")
                print("作者" + sub_dir + "的所有程序所占比例:")
                #############################################
                for i in range(3, 19):
                    print(eval('list_'+str(i+1)))
            #############################################
            list_20 = transform.get_style2(author_name=sub_dir,tmp=1)
            list_21 = transform.get_style2(author_name=sub_dir,tmp=2)
            list_22 = transform.get_style12(author_name=sub_dir)
            # if f == '':
            #     continue
            for i in range(3, 22):
                list_elem = eval('list_'+str(i+1))
                f.write(str(list_elem)+'\n')
            f.close()
def get_style(xml_file_path):
    global java_cpp_flag
    # 风格
    #############################################
    style_list = [0, 0, 0]
    # 1
    doc = eval('transform_1')
    style_list.append(doc.get_program_style(xml_file_path))
    # 4
    doc = eval('transform_4')
    style_list.append(doc.get_program_style(xml_file_path))
    # 5
    doc = eval('transform_5')
    style_list.append(doc.get_program_style(xml_file_path))
    # 6
    doc = eval('transform_6')
    style_list.append(doc.get_program_style(xml_file_path))
    # 7
    doc = eval('transform_7')
    style_list.append(doc.get_program_style(xml_file_path))
    # 8
    if java_cpp_flag == 'cpp' or java_cpp_flag == 'c':
        doc = eval('transform_8')
        style_list.append(doc.get_program_style(xml_file_path))
    else:
        style_list.append({'8.1': 0, '8.2': 0})
    # 9
    doc = eval('transform_9')
    style_list.append(doc.get_program_style(xml_file_path))
    # 10
    if java_cpp_flag == 'cpp' or java_cpp_flag == 'c':
        doc = eval('transform_10')
        style_list.append(doc.get_program_style(xml_file_path))
    else:
        style_list.append({'10.1': 0, '10.2': 0})
    # 11
    if java_cpp_flag == 'cpp' or java_cpp_flag == 'c':
        doc = eval('transform_11')
        style_list.append(doc.get_program_style(xml_file_path))
    else:
        style_list.append({'11.1': 0, '11.2': 0})
    for i in range(13, 20):
        if i == 13 and java_cpp_flag == 'java':
            style_list.append({'13.1': 0, '13.2': 0})
            continue
        if i == 14 and java_cpp_flag == 'java':
            style_list.append({'14.1': 0, '14.2': 0})
            continue
        if i == 19 and java_cpp_flag == 'java':
            style_list.append(transform_19.get_program_style_java(xml_file_path))
            #style_list.append({'19': [0, 0]})
            continue
        doc = eval('transform_'+str(i))
        style_list.append(doc.get_program_style(xml_file_path))
    return style_list
if __name__ == '__main__':
    # 未转化之前的java文件
    pre_file = "pre_file/java_cpp_file"
    # srcml java/cpp 的XML文件
    xml_file = "./xml_file"
    # 将java/c文件转化成xml文件
    transform_java_xml(pre_file, xml_file)
    # 获得作者风格
    get_xml(xml_file)
