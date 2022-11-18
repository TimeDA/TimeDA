import os
import subprocess


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


def separate(test_path, train_path):
    for dir in os.listdir(test_path):
        dir_path = os.path.join(test_path, dir)
        fs = os.listdir(dir_path)
        # if len(fs) < 10:
        #     command = 'rm -rf \"'+dir_path+'\"'
        #     cmd(command)
        # else:
        le = int(len(fs) * 0.9)
        for file in fs[0:3]:
            train_dir = os.path.join(train_path, dir)
            if not os.path.exists(train_dir):
                os.mkdir(train_dir)
            command = 'mv \"' + os.path.join(dir_path, file) + '\" \"' + train_dir + '\"'
            cmd(command)
if __name__ == '__main__':
    test_path = './test'
    train_path = './train'
    separate(test_path,train_path)
