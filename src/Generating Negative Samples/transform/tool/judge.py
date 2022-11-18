# 判断两个节点是否完全相等（包括节点内部）

temp = True
def judge(root1, root2):
    global temp
    if len(root1) != len(root2):
        temp = False
        return
    if len(root1) == 0:
        if root1.tag != root2.tag or root1.text != root2.text:
            temp = False
            return
    else:
        for i in range(0, len(root1)):
            if root1[i].tag != root2[i].tag or root1[i].text != root2[i].text:
                temp = False
                return
            if len(root1[i]) >= 1 and len(root2[i]) >= 1:
                judge(root1[i], root2[i])