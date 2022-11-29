import sys
from lxml import etree
from test_transform.py import c_lib_to_cpp

ns = {'src': 'http://www.srcML.org/srcML/src',
    'cpp': 'http://www.srcML.org/srcML/cpp',
    'pos': 'http://www.srcML.org/srcML/position'}
doc = None

def init_parser(file):
    global doc
    doc = etree.parse(file)
    e = etree.XPathEvaluator(doc)
    for k,v in ns.items():
        e.register_namespace(k, v)
    return e

def get_functions(e):
    return e('//src:function/src:block/src:block_content')

def get_typename(elem):
    if elem is None: return None
    elem_type = elem.xpath('src:type', namespaces=ns)
    if len(elem_type) == 0 or elem[0].get('ref') == 'prev':
        return get_typename(elem.getprevious())
    return elem.xpath('src:type/src:name', namespaces=ns)

def get_vars_and_types(func):
    var_list = {}
    decls = func.xpath('.//src:decl', namespaces=ns)
    decls += func.xpath('/src:unit/src:decl_stmt/src:decl', namespaces=ns)
    for decl in decls:
        name = decl.xpath('src:name', namespaces=ns)
        if len(name)==0:continue
        decl_name = ''.join(name[0].itertext())
        typename = get_typename(decl)
        if typename is None or len(typename) == 0: continue
        decl_type = ''.join(typename[0].itertext())
        var_list[decl_name] = decl_type
    return var_list

def get_expr_stmts(func):
    return func.xpath('.//src:expr_stmt/src:expr', namespaces=ns)

def get_expr_name(func):
    return func.xpath('src:expr/src:name', namespaces=ns)

def get_type(func):
    return func.xpath('src:type', namespaces=ns)

def get_name(func):
    return func.xpath('src:name', namespaces=ns)

def get_arg0(func):
    return func.xpath('src:argument_list/src:argument', namespaces=ns)

def get_cout(func):
    cout_stmts = []
    for expr_stmt in get_expr_stmts(func):
        children = expr_stmt.xpath('child::node()', namespaces=ns)
        try:
            if children[0].text != 'cout': continue
        except AttributeError:
            continue
        cout_stmts.append(expr_stmt)
    return cout_stmts
def get_number(xml_path):
    e = init_parser(xml_path)
    functions = get_functions(e)
    total = 0
    for func in functions:
        total += len(get_cout(func)) + len(get_cin(func))
    return total
def get_cin(func):
    cin_stmts = []
    for expr_stmt in get_expr_stmts(func):
        children = expr_stmt.xpath('child::node()', namespaces=ns)
        try:
            if children[0].text != 'cin': continue
        except AttributeError:
            continue
        cin_stmts.append(expr_stmt)
    return cin_stmts

def get_fout(func, ofs_names):
    fout_stmts = []
    for expr_stmt in get_expr_stmts(func):
        children = expr_stmt.xpath('child::node()', namespaces=ns)
        try:
            if children[0].text not in ofs_names: continue
        except AttributeError:
            continue
        fout_stmts.append(expr_stmt)
    return fout_stmts

def get_fin(func, ifs_names):
    fin_stmts = []
    for expr_stmt in get_expr_stmts(func):
        children = expr_stmt.xpath('child::node()', namespaces=ns)
        try:
            if children[0].text not in ifs_names: continue
        except AttributeError:
            continue
        fin_stmts.append(expr_stmt)
    return fin_stmts

def transform_freopen_stdin(func):
    freopen_names = func.xpath('.//src:call/src:name[text()="freopen"]', namespaces=ns)
    if len(freopen_names) == 0: return False

    for freopen_name in freopen_names:
        freopen_call = freopen_name.getparent()
        if freopen_call is None: continue

        call_text = ''.join(freopen_call.itertext())
        if 'stdin' in call_text:
            argument_list = freopen_call.xpath('src:argument_list', namespaces=ns)
            if argument_list is None or len(argument_list) == 0: continue
            filename = ''.join(argument_list[0][0].itertext())
            fin_stmt = etree.Element('decl_stmt')
            fin_stmt_text = 'ifstream fin(' + filename + ')'
            fin_stmt.text = fin_stmt_text
            freopen_call.getparent().replace(freopen_call, fin_stmt)
    return True

def transform_freopen_stdout(func):
    freopen_names = func.xpath('.//src:call/src:name[text()="freopen"]', namespaces=ns)
    if len(freopen_names) == 0: return False

    for freopen_name in freopen_names:
        freopen_call = freopen_name.getparent()
        if freopen_call is None: continue

        call_text = ''.join(freopen_call.itertext())
        if 'stdout' in call_text:
            argument_list = freopen_call.xpath('src:argument_list', namespaces=ns)
            if argument_list is None or len(argument_list) == 0: continue
            filename = ''.join(argument_list[0][0].itertext())
            fout_stmt = etree.Element('decl_stmt')
            fout_stmt_text = 'ofstream fout(' + filename + ')'
            fout_stmt.text = fout_stmt_text
            freopen_call.getparent().replace(freopen_call, fout_stmt)
    return True

def transform_stdin_freopen(func):
    ifs_names = []
    decl_type_names = func.xpath('.//src:decl/src:type/src:name[text()="ifstream"]', namespaces=ns)
    if len(decl_type_names) == 0: return False

    for decl_type_name in decl_type_names:
        decl = decl_type_name.getparent()
        if decl is None: continue
        decl = decl.getparent()
        if decl is None: continue
        decl_type = get_type(decl)
        decl_name = get_name(decl)
        arg0 = get_arg0(decl)
        if len(decl_type) * len(decl_name) == 0: continue
        if len(arg0) == 0: continue
        decl.remove(decl_type[0])
        ifs_names.append(decl_name[0].text)
        decl_name[0].text = 'freopen'
        new_arg = etree.Element('argument')
        new_arg.text = ',"r",stdin'
        arg0[0].append(new_arg)
    return ifs_names

def transform_stdout_freopen(func):
    ofs_names = []
    decl_type_names = func.xpath('.//src:decl/src:type/src:name[text()="ofstream"]', namespaces=ns)
    if len(decl_type_names) == 0: return False

    for decl_type_name in decl_type_names:
        decl = decl_type_name.getparent()
        if decl is None: continue
        decl = decl.getparent()
        if decl is None: continue
        decl_type = get_type(decl)
        decl_name = get_name(decl)
        arg0 = get_arg0(decl)
        if len(decl_type) * len(decl_name) == 0: continue
        if len(arg0) == 0: continue
        decl.remove(decl_type[0])
        ofs_names.append(decl_name[0].text)
        decl_name[0].text = 'freopen'
        new_arg = etree.Element('argument')
        new_arg.text = ',"w",stdout'
        arg0[0].append(new_arg)
    return ofs_names

def save_tree_to_file(tree, file):
    with open(file, 'w') as f:
        f.write(etree.tostring(tree).decode('utf8'))

fmt_spec_dict = {'int': '%d', 'long int': '%ld', 'long long': '%lld', 'char': '%c', 'float': '%f',
                'double': '%f', 'lli': '%lld'}

def transform_fout_to_cout(func, var_list, tree_root, ignore_list=[]):
    flag = False
    new_ignore_list = []
    ofs_names = transform_stdout_freopen(func)
    if ofs_names == False: return flag, new_ignore_list

    fout_stmts = get_fout(func, ofs_names)
    for fout_stmt in fout_stmts:
        fout_stmt_prev = fout_stmt.getprevious()
        fout_stmt_prev = fout_stmt_prev if fout_stmt_prev is not None else fout_stmt
        fout_stmt_prev_path = tree_root.getpath(fout_stmt_prev)
        if fout_stmt_prev_path in ignore_list:
            continue
        fout_stmt[0].text = 'cout'
        flag = True
        new_ignore_list.append(fout_stmt_prev_path)
    return flag, new_ignore_list

def transform_fin_to_cin(func, var_list, tree_root, ignore_list=[]):
    flag = False
    new_ignore_list = []
    ifs_names = transform_stdin_freopen(func)
    if ifs_names == False: return flag, new_ignore_list

    fin_stmts = get_fin(func, ifs_names)
    for fin_stmt in fin_stmts:
        fin_stmt_prev = fin_stmt.getprevious()
        fin_stmt_prev = fin_stmt_prev if fin_stmt_prev is not None else fin_stmt
        fin_stmt_prev_path = tree_root.getpath(fin_stmt_prev)
        if fin_stmt_prev_path in ignore_list:
            continue
        fin_stmt[0].text = 'cin'
        flag = True
        new_ignore_list.append(fin_stmt_prev_path)
    return flag, new_ignore_list

def transform_cout_to_fout(func, var_list, tree_root, ignore_list=[]):
    flag = False
    new_ignore_list = []
    if not transform_freopen_stdout(func): return flag, new_ignore_list

    cout_stmts = get_cout(func)
    for cout_stmt in cout_stmts:
        cout_stmt_prev = cout_stmt.getprevious()
        cout_stmt_prev = cout_stmt_prev if cout_stmt_prev is not None else cout_stmt
        cout_stmt_prev_path = tree_root.getpath(cout_stmt_prev)
        if cout_stmt_prev_path in ignore_list:
            continue
        cout_stmt[0].text = 'fout'
        flag = True
        new_ignore_list.append(cout_stmt_prev_path)
    return flag, new_ignore_list

def transform_cin_to_fin(func, var_list, tree_root, ignore_list=[]):
    flag = False
    new_ignore_list = []
    if not transform_freopen_stdin(func): return flag, new_ignore_list

    cin_stmts = get_cin(func)
    for cin_stmt in cin_stmts:
        cin_stmt_prev = cin_stmt.getprevious()
        cin_stmt_prev = cin_stmt_prev if cin_stmt_prev is not None else cin_stmt
        cin_stmt_prev_path = tree_root.getpath(cin_stmt_prev)
        if cin_stmt_prev_path in ignore_list:
            continue
        cin_stmt[0].text = 'fin'
        flag = True
        new_ignore_list.append(cin_stmt_prev_path)
    return flag, new_ignore_list

def transform_cout_to_printf(func, var_list, tree_root, ignore_list=[]):
    flag = False
    new_ignore_list = []
    cout_stmts = get_cout(func)
    for cout_stmt in cout_stmts:
        cout_stmt_prev = cout_stmt.getprevious()
        cout_stmt_prev = cout_stmt_prev if cout_stmt_prev is not None else cout_stmt
        cout_stmt_prev_path = tree_root.getpath(cout_stmt_prev)
        if cout_stmt_prev_path in ignore_list:
            continue

        should_skip = False
        has_name = False
        children = cout_stmt.getchildren()
        fmt_str = ''
        params_list = ''
        for child in children[2:]:
            tag = etree.QName(child)
            if tag.localname == 'literal':
                fmt_str += child.text[1:-1]
            elif tag.localname == 'name':
                if child.text == 'endl':
                    fmt_str += '\\n'
                    continue
                var_type = var_list.get(child.text, '')
                if var_type == '':
                    should_skip = True
                    continue
                fmt_spec = fmt_spec_dict.get(var_type, '')
                if fmt_spec == '':
                    should_skip = True
                    continue
                fmt_str += fmt_spec
                params_list += child.text + ','
                has_name = True
        if should_skip: continue
        params_list = params_list[:-1]
        printf_stmt = 'printf("' + fmt_str + '"'
        if has_name: printf_stmt += ',' + params_list
        printf_stmt += ');'
        new_printf_node = etree.Element('call')
        new_printf_node.text = printf_stmt
        cout_stmt.getparent().replace(cout_stmt, new_printf_node)
        flag = True
        new_ignore_list.append(cout_stmt_prev_path)
    return flag, new_ignore_list

def transform_cin_to_scanf(func, var_list, tree_root, ignore_list=[]):
    flag = False
    new_ignore_list = []
    cin_stmts = get_cin(func)
    for cin_stmt in cin_stmts:
        cin_stmt_prev = cin_stmt.getprevious()
        cin_stmt_prev = cin_stmt_prev if cin_stmt_prev is not None else cin_stmt
        cin_stmt_prev_path = tree_root.getpath(cin_stmt_prev)
        if cin_stmt_prev_path in ignore_list:
            continue

        should_skip = False
        has_name = False
        children = cin_stmt.getchildren()
        fmt_str = ''
        params_list = ''
        for child in children[2:]:
            tag = etree.QName(child)
            if tag.localname == 'literal':
                fmt_str += child.text[1:-1]
            elif tag.localname == 'name':
                if child.text == 'endl':
                    fmt_str += '\\n'
                    continue
                var_type = var_list.get(child.text, '')
                if var_type == '':
                    should_skip = True
                    continue
                fmt_spec = fmt_spec_dict.get(var_type, '')
                if fmt_spec == '':
                    should_skip = True
                    continue
                fmt_str += fmt_spec
                params_list += '&' + child.text + ','
                has_name = True
        if should_skip: continue
        params_list = params_list[:-1]
        printf_stmt = 'scanf("' + fmt_str + '"'
        if has_name: printf_stmt += ',' + params_list
        printf_stmt += ');'
        new_printf_node = etree.Element('call')
        new_printf_node.text = printf_stmt
        cin_stmt.getparent().replace(cin_stmt, new_printf_node)
        flag = True
        new_ignore_list.append(cin_stmt_prev_path)
    return flag, new_ignore_list

def get_include(e):
    return e.xpath('//cpp:include', namespaces=ns)
def get_unit(e):
    return e.xpath('//src:unit', namespaces=ns)

def hunt(e):
    name_list = []
    get_elements = get_include(e)
    for get_element in get_elements:
        element = get_element[1].text
        name_list.append(element)
    return name_list

def add_include(e):
    include_list = hunt(e)
    if '<stdio.h>' not in include_list and '<bits/stdc++.h>' not in include_list:
        unit_elem = get_unit(e)[0]
        node_include = etree.Element('{http://www.srcML.org/srcML/cpp}include')
        node_include.text = '#'
        node1 = etree.Element('{http://www.srcML.org/srcML/cpp}directive')
        node1.text = 'include '
        node2 = etree.Element('{http://www.srcML.org/srcML/cpp}file')
        node2.text = '<stdio.h>'
        node2.tail = '\n'
        node_include.append(node1)
        node_include.append(node2)
        unit_elem.insert(0, node_include)

def cpp_lib_to_c(e, src_style, dst_style, ignore_list=[], instances=None):
    global flag
    flag = False
    functions = [get_functions(e) if instances is None else (instance[0] for instance in instances)]
    tree_root = e('/*')[0].getroottree()
    new_ignore_list = []
    for item in functions:
        for func in item:
            var_list = get_vars_and_types(func)
            if src_style == '13.1':
                if dst_style != '13.3':
                    flag1, new_ignore_list1 = transform_cout_to_printf(func, var_list, tree_root, ignore_list)
                    flag2, new_ignore_list2 = transform_cin_to_scanf(func, var_list, tree_root, ignore_list)
                else:
                    flag1, new_ignore_list1 = transform_cout_to_fout(func, var_list, tree_root, ignore_list)
                    flag2, new_ignore_list2 = transform_cin_to_fin(func, var_list, tree_root, ignore_list)
            elif src_style == '13.3':
                if dst_style == '13.1':
                    flag1, new_ignore_list1 = transform_fout_to_cout(func, var_list, tree_root, ignore_list)
                    flag2, new_ignore_list2 = transform_fin_to_cin(func, var_list, tree_root, ignore_list)
                else:
                    flag1, new_ignore_list1 = transform_fout_to_cout(func, var_list, tree_root, ignore_list)
                    flag2, new_ignore_list2 = transform_fin_to_cin(func, var_list, tree_root, ignore_list)
                    if not flag1 or not flag2: continue
                    flag1, new_ignore_list1 = transform_cout_to_printf(func, var_list, tree_root, ignore_list)
                    flag2, new_ignore_list2 = transform_cin_to_scanf(func, var_list, tree_root, ignore_list)
            elif src_style == '13.2':
                flag1, tree_root1, new_ignore_list1 = c_lib_to_cpp.cpp_lib_to_c(e, ignore_list, instances)
                if not flag1: continue
                flag1, new_ignore_list1 = transform_cout_to_fout(func, var_list, tree_root, ignore_list)
                flag2, new_ignore_list2 = transform_cin_to_fin(func, var_list, tree_root, ignore_list)
            if flag1:
                flag = True
                new_ignore_list += new_ignore_list1
            if flag2:
                flag = True
                new_ignore_list += new_ignore_list2
    if flag and dst_style == '13.2': add_include(e('/*')[0])
    return flag, tree_root, new_ignore_list

if __name__ == '__main__':
    e = init_parser(sys.argv[1])
    cpp_lib_to_c(e, '13.2', '13.3')
    save_tree_to_file(doc, './cpp_lib_to_c.xml')

def program_transform(program_path, style1='13.1', style2='13.2'):
    e = init_parser(program_path)
    cpp_lib_to_c(e, style1, style2)
    save_tree_to_file(doc, './style/style.xml')
