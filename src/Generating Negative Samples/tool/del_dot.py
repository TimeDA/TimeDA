import os
import subprocess
root_path='./test'

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

if __name__=="__main__":

    # for root,dirnames,filenames in os.walk(root_path):
    #     for dirname in dirnames:
    #         oldname = dirname
    #         newname = dirname.replace('.', '')
    #         os.rename(root_path+'/'+dirname,root_path+'/'+newname)

    for root,dirnames,filenames in os.walk(root_path):
        for filename in filenames:
            #if not filename.endswith('.c'):
            newname=filename[0:-5].replace('.','')+filename[-5:]
            os.rename(os.path.join(root,filename),os.path.join(root,newname))

    for dir in os.listdir(root_path):
        files_path = os.path.join(root_path, dir)
        if len(os.listdir(files_path)) < 15:
            print(files_path)
            command = 'rm -rf \"' + files_path + '\"'
            cmd(command)

        # for filename in os.listdir(files_path):
        #     filename_path = os.path.join(files_path, filename)
        #     size = os.path.getsize(filename_path)
        #     if size == 0:
        #         print(filename)
        #         command = 'rm -rf \"' + filename_path + '\"'
        #         cmd(command)
        #     if not filename.endswith('.c'):
        #         print(filename)
        #         command = 'rm -rf \"'+filename_path+'\"'
        #         cmd(command)
        #     if len(open(filename_path).readlines())>=500:
        #         print(filename)
        #         command = 'rm -rf \"' + filename_path + '\"'
        #         cmd(command)
