import copy
import os
from lxml import etree
from lxml.etree import Element

doc = None
ns = {'src': 'http://www.srcML.org/srcML/src'}
str = '{http://www.srcML.org/srcML/src}'
flag = True


def init_parse(file):
    global doc
    doc = etree.parse(file)
    e = etree.XPathEvaluator(doc, namespaces={'src': 'http://www.srcML.org/srcML/src'})
    return e


def get_ternary(e):
    return e('//src:ternary')


def get_condition(elem):
    return elem.xpath('src:condition', namespaces=ns)


def get_expr1(elem):
    return elem.xpath('src:then/src:expr', namespaces=ns)


def get_expr2(elem):
    return elem.xpath('src:else/src:expr', namespaces=ns)


def trans_tree(e):
    global flag
    # 得到所有的三元运算 ternary
    ternary_elems = get_ternary(e)
    for ternary_elem in ternary_elems:
        # 判断是否属于三元运算
        if ternary_elem.getparent().tag == str + 'expr' and ternary_elem.getparent().getparent().tag == str + 'expr_stmt':
            index = ternary_elem.getparent().index(ternary_elem)
            if (ternary_elem.getparent()[index-1].text == '=') or (ternary_elem.getparent()[index-1].text == '(' and ternary_elem.getparent()[index-2].text == '='):
                # 得到条件
                condition = get_condition(ternary_elem)[0]
                if condition[0][0].text != '(' or condition[0][-1].text != ')':
                    condition.text = '('
                    condition[0][-1].tail = ')'
                condition[0].tail = ''
                # 得到变量和‘=’
                expr = ternary_elem.getparent()
                expr_node = Element('expr')
                for expr_e in expr:
                    if expr_e.tag == str + 'ternary':
                        break
                    expr_node.append(expr_e)
                text = ''.join(expr_node.itertext()).replace('\n','').replace(' ','')
                text_list = list(text)
                if text_list[-1] == '(':
                    del text_list[-1]
                    text = ''.join(text_list)
                expr_node1 = Element('expr')
                expr_node2 = Element('expr')
                expr_node1.text = text
                expr_node2.text = text
                # 得到表达式1 和 表达式2
                elem_1 = get_expr1(ternary_elem)[0]
                elem_1.tail = ';\n}'
                if len(get_expr2(ternary_elem)) == 0: continue
                elem_2 = get_expr2(ternary_elem)[0]

                elem_2.tail = ';\n}'
                # 构造if else
                if_node = Element('if')
                if_node.text = 'if'
                # 增加条件
                if_node.append(condition)
                # 增加If的执行块
                if_block = Element('block')
                if_block.text = '{'
                if_node.append(if_block)
                # 将true执行语句增加到执行块里
                if_block.append(expr_node1)
                if_block.append(elem_1)
                # 构造else
                else_node = Element('else')
                else_node.text = 'else'
                # 增加else的执行块
                else_block = Element('block')
                else_block.text = '{'
                else_node.append(else_block)
                # 将执行语句增加到执行块里
                else_block.append(expr_node2)
                else_block.append(elem_2)
                # 得到expr的父节点
                expr_stmt = expr.getparent()
                index = expr_stmt.getparent().index(expr_stmt)
                # 将if else插入到三元运算的后面
                expr_stmt.getparent().insert(index + 1, if_node)
                expr_stmt.getparent().insert(index + 2, else_node)

                # 删除三目运算
                del expr_stmt.getparent()[index]
                flag = True
        # if ternary_elem.getparent().tag == str + 'expr' and ternary_elem.getparent().getparent().tag == str + 'init':
        #     index = ternary_elem.getparent().index(ternary_elem)
        #     if (ternary_elem.getparent()[index - 1].text == '=') or (
        #             ternary_elem.getparent()[index - 1].text == '(' and ternary_elem.getparent()[index - 2].text == '='):
        #         # 得到条件
        #         condition = get_condition(ternary_elem)[0]
        #         if condition[0][0].text != '(' or condition[0][-1].text != ')':
        #             condition.text = '('
        #             condition[0][-1].tail = ')'
        #         condition[0].tail = ''
        #         init = ternary_elem.getparent().getparent()
        #         init_parent = init.getparent()
        #         init_parent.tail = ''
        #         for elem in init_parent:
        #             tag = etree.QName(elem)
        #             if tag.localname == 'name':
        #                 expr_node1 = copy.deepcopy(elem)
        #                 elem.tail = ';\n'
        #                 expr_node2 = Element('operator')
        #                 expr_node2.text = '= '
        #                 # 得到表达式1 和 表达式2
        #                 if len(get_expr1(ternary_elem)) == 0: continue
        #                 elem_1 = get_expr1(ternary_elem)[0]
        #                 elem_1.tail = ';\n}'
        #                 elem_2 = get_expr2(ternary_elem)[0]
        #                 elem_2.tail = ';\n}'
        #                 # 构造if else
        #                 if_node = Element('if')
        #                 if_node.text = 'if'
        #                 # 增加条件
        #                 if_node.append(condition)
        #                 # 增加If的执行块
        #                 if_block = Element('block')
        #                 if_block.text = '{'
        #                 if_node.append(if_block)
        #                 if_block.append(expr_node1)
        #                 if_block.append(expr_node2)
        #                 if_block.append(elem_1)
        #                 expr_node3 = copy.deepcopy(expr_node1)
        #                 expr_node4 = copy.deepcopy(expr_node2)
        #                 # 构造else
        #                 else_node = Element('else')
        #                 else_node.text = 'else'
        #                 # 增加else的执行块
        #                 else_block = Element('block')
        #                 else_block.text = '{'
        #                 else_node.append(else_block)
        #                 # 将执行语句增加到执行块里
        #                 else_block.append(expr_node3)
        #                 else_block.append(expr_node4)
        #                 else_block.append(elem_2)
        #                 # 得到expr的父节点
        #                 index = init_parent.index(init)
        #                 # 将if else插入到三元运算的后面
        #                 init_parent.insert(index + 1, if_node)
        #                 init_parent.insert(index + 2, else_node)
        #                 # 删除三目运算
        #                 del init_parent[index]
        #                 flag = True
def save_tree_to_file(tree, path):
    with open(path, 'w') as f:
        f.write(etree.tostring(tree).decode('utf8'))



def count(e):
    count_num = 0
    # 得到所有的三元运算 ternary
    ternary_elems = get_ternary(e)
    for ternary_elem in ternary_elems:
        # 判断是否属于三元运算
        if ternary_elem.getparent().tag == str + 'expr' and ternary_elem.getparent().getparent().tag == str + 'expr_stmt':
            index = ternary_elem.getparent().index(ternary_elem)
            if (ternary_elem.getparent()[index-1].text == '=') or (ternary_elem.getparent()[index-1].text == '(' and ternary_elem.getparent()[index-2].text == '='):
                count_num += 1
        # if ternary_elem.getparent().tag == str + 'expr' and ternary_elem.getparent().getparent().tag == str + 'init':
        #     index = ternary_elem.getparent().index(ternary_elem)
        #     if (ternary_elem.getparent()[index - 1].text == '=') or (
        #             ternary_elem.getparent()[index - 1].text == '(' and ternary_elem.getparent()[
        #         index - 2].text == '='):
        #         count_num += 1
    return count_num


def get_number(xml_path):
    xmlfilepath = os.path.abspath(xml_path)
    # 解析成树
    e = init_parse(xmlfilepath)
    return count(e)


def xml_file_path(xml_path):
    global flag
    # xml_path 需要转化的xml路径
    # sub_dir_list 每个作者的包名
    # name_list 具体的xml文件名
    save_xml_file = './transform_xml_file/ternary'
    transform_java_file = './pre_file/transform_java/ternary'
    if not os.path.exists(transform_java_file):
        os.mkdir(transform_java_file)
    if not os.path.exists(save_xml_file):
        os.mkdir(save_xml_file)
    for xml_path_elem in xml_path:
        xmlfilepath = os.path.abspath(xml_path_elem)
        # 解析成树
        e = init_parse(xmlfilepath)
        # 转换
        flag = False
        trans_tree(e)
        # 保存文件
        if flag == True:
            str = xml_path_elem.split('/')[-1]
            sub_dir = xml_path_elem.split('/')[-2]
            if not os.path.exists(os.path.join(save_xml_file, sub_dir)):
                os.mkdir(os.path.join(save_xml_file, sub_dir))
            save_tree_to_file(doc, os.path.join(save_xml_file, sub_dir, str))
    return save_xml_file, transform_java_file


def program_transform(program_path):
    e = init_parse(program_path)
    trans_tree(e)
    save_tree_to_file(doc, './style/style.xml')
if __name__ == '__main__':
    e = init_parse('../demo1.xml')
    trans_tree(e)
    save_tree_to_file(doc, '../demo2.xml')