import os
import subprocess
# -*- coding: utf-8 -*-
def delblankline(infile, outfile):
    infopen = open(infile, 'r', encoding="utf-8")
    outfopen = open(outfile, 'w',encoding='utf-8')
    lines = infopen.readlines()
    for line in lines:
        line = line.strip()
        if len(line) != 0:
            outfopen.writelines(line)
            outfopen.write('\n')
    infopen.close()
    outfopen.close()
def cmd(command):
    print(command)
    global flag
    flag = True
    subp = subprocess.Popen(command,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,encoding="utf-8")
    subp.wait(10)
    if subp.poll() == 0:
        flag = True
    else:
        print("False!")
        flag = False

def get_name(file):
    file_name = file.split('.c')[0]
    name = ''
    if file_name[-1].isdigit():
        if file_name[-2].isdigit():
            name = file_name[:-2]
        else:
            name = file_name[:-1]
    return name
def compare(pre_file, last_file):
    with open(pre_file, 'rb') as f1:
        pre_lines = f1.readlines()
    with open(last_file, 'rb') as f2:
        last_lines = f2.readlines()
    count = 0
    # for i in range(0, len(pre_lines)):
    #     if i<len(last_lines):
    #         if pre_lines[i]==last_lines[i]:
    #          count+=1
    for pre_line in pre_lines:
        for last_line in last_lines:
            if pre_line == last_line:
                count +=1
                break
    # print("~~~~~~")
    # print("作者：",len(pre_lines))
    # print("~~~~~~")
    # print(count)

    if count / len(pre_lines) > 0.5:
        return True
    # else:
    #     if count / len(last_lines) > 0.6:
    #         return True

    # if count/len(pre_lines)>0.7 or count/len(last_lines)>0.7:
    #     return True
    # elif len(pre_lines) > 300 and count > 50 or len(last_lines) > 300 and count > 50:
    #     return True
if __name__ == '__main__':
    path = './test'
    for dirs in os.listdir(path):
        file_list = []
        files_path = os.path.join(path, dirs)
        pre_file = ''
        for file in os.listdir(files_path):
            file_name = get_name(file)
            if file_name != '':
                file_list.append(os.path.join(files_path, file))
        last_file = []
        for file in file_list:
            file_name = get_name(file)
            if file_name in last_file:continue
            for file_elem in file_list:
                if file != file_elem:
                    file_elem_name = get_name(file_elem)
                    if file_name == file_elem_name:
                        delblankline(file, './1.txt')
                        delblankline(file_elem, './2.txt')
                        if compare('./1.txt', './2.txt'):
                            command = 'rm -rf '+file_elem
                            cmd(command)
            last_file.append(file_name)









