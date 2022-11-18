import os
import sys
cur_path = os.path.abspath('.')
up_path = os.path.dirname(cur_path)
sys.path.append(up_path)
sys.path.append(cur_path)
import traceback
from test_transform import transform
from test_transform import scan

def scan_style(program_path, author_path):
    for root, sub_dirs, files in os.walk(program_path):
        for sub_dir in sub_dirs:
            sub_path = os.path.join(root, sub_dir)
            file_list = os.listdir(sub_path) if os.path.isdir(sub_path) else [sub_path]
            for file_name in file_list:
                # 文件路径hh
                file_path = os.path.join(root, sub_dir, file_name)
                author_list = os.listdir(author_path) if os.path.isdir(author_path) else [author_path]
                for author_name in author_list:
                    if not author_name.endswith('.txt'): continue
                    author_name = author_name.split('.')[0]
                    # 如果两个作者名字一样，则表示同一个程序，不用转化
                    if sub_dir == author_name: continue
                    # try:
                    transform.scan_trans(file_path, author_name)
                    # except Exception as ex:
                    #     f = open('./Exception/Exception.txt', 'a')
                    #     f.write(traceback.format_exc() + '\n\n')
                    #     scan.cmd('rm -rf ./style/transform/*')
                    #     continue
                    #把生成的文件移动到相应的作者目录下
                    move_change(file_name, sub_dir, author_name)
                    
def move_change(file_name, pre_author_name, author_name):
    path = './pre_file/transform_file/'+author_name
    program_name = ''
    if file_name.endswith('cpp'):
        program_name = file_name.split('_')[0]+'_'+file_name.split('_')[1] + \
                      '_'+pre_author_name+'_'+author_name+'.'+file_name.split('.')[-1]
        change_name = 'mv '+path+'/'+file_name+' '+path+'/'+program_name

    if file_name.endswith('.c') or file_name.endswith('.java'):
        program_name = file_name.split('.')[0]+'##'+pre_author_name+'***'+author_name+\
                      '.'+file_name.split('.')[-1]
        change_name = 'mv '+path+'/'+file_name+' '+path+'/'+program_name
    f = open(os.path.join('./pre_file/program_style/'+author_name, program_name.split('.')[0]+'.txt'), 'w')
    for elem in transform.style_list:
        if elem == 0 : continue
        f.write(str(elem)+'\n')
    if not os.path.exists(path):
        os.mkdir(path)
    scan.cmd(command='mv ./style/transform/* '+path)
    scan.cmd(change_name)
if __name__ == '__main__':
    # 作者program文件
    program_path = './pre_file/java_cpp_file'
    # 作者的风格文件
    author_path = './author_style'
    # 转化后的作者program文件
    transform_file = './pre_file/transform_file'
    scan_style(program_path, author_path)
