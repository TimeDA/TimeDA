import os
from lxml import etree
ns = {'src': 'http://www.srcML.org/srcML/src'}
doc = None
flag = False
def init_parse(file):
	global doc
	doc = etree.parse(file)
	e = etree.XPathEvaluator(doc, namespaces={'src': 'http://www.srcML.org/srcML/src'})
	return e

def get_for(e):
	return e('//src:for')

def get_init(elem):
	return elem.xpath('src:control/src:init', namespaces=ns)

def get_cond_expr(elem):
	return elem.xpath('src:control/src:condition/src:expr', namespaces=ns)

def get_incr(elem):
	return elem.xpath('src:control/src:incr', namespaces=ns)

def get_block(elem):
	return elem.xpath('src:block/src:block_content', namespaces=ns)
def get_block1(elem):
	return elem.xpath('src:block', namespaces=ns)
def save_tree_to_file(tree, file):
	with open(file, 'w') as f:
		f.write(etree.tostring(tree).decode('utf8'))

def trans_tree(e, ignore_list=[], instances=None):
	global flag
	flag = False
	for_stmts = [get_for(e) if instances is None else (instance[0] for instance in instances)]
	tree_root = e('/*')[0].getroottree()
	new_ignore_list = []
	for item in for_stmts:
		for for_stmt in item:
			for_prev = for_stmt.getprevious()
			for_prev = for_prev if for_prev is not None else for_stmt
			for_prev_path = tree_root.getpath(for_prev)
			if for_prev_path in ignore_list:
				continue
			init = get_init(for_stmt)
			cond_expr = get_cond_expr(for_stmt)
			incr = get_incr(for_stmt)
			if len(init)>=1 and len(cond_expr)>=1 and len(incr)>=1:
				flag = True
				for_stmt.tag = 'while'
				for_stmt.text = 'while '
				init = init[0]
				cond_expr = cond_expr[0]
				incr = incr[0]
				if len(get_block(for_stmt))==0:continue
				for_block = get_block(for_stmt)[0]
				for_block1 = get_block1(for_stmt)[0]
				if for_block1.text is None:
					for_block1.text = '{'
					for_block1.tail = '}'
				if len(init) == 0:
					init.text = ''
				cond_expr.tail = ')'
				if len(incr)>=1:
					incr.tail = ';\n'
				else:
					incr.tail = ''
				for_index = for_stmt.getparent().index(for_stmt)
				for_stmt.getparent().insert(for_index, init)
				for_block.append(incr)
				init_prev = init.getprevious()
				init_prev = init_prev if init_prev is not None else init
				init_prev_path = tree_root.getpath(init_prev)
				new_ignore_list.append(init_prev_path)
	return flag, tree_root, new_ignore_list
def count(e):
	count_num = 0
	for_stmts = get_for(e)
	for for_stmt in for_stmts:
		init = get_init(for_stmt)
		cond_expr = get_cond_expr(for_stmt)
		incr = get_incr(for_stmt)
		if len(init) >= 1 and len(cond_expr) >= 1 and len(incr) >= 1:
			count_num += 1
	return count_num
def get_number(xml_path):
	xmlfilepath = os.path.abspath(xml_path)
	e = init_parse(xmlfilepath)
	return count(e)
def xml_file_path(xml_path):
	global flag
	save_xml_file = './transform_xml_file/for_while'
	transform_java_file = './pre_file/transform_java/for_while'
	if not os.path.exists(transform_java_file):
		os.mkdir(transform_java_file)
	if not os.path.exists(save_xml_file):
		os.mkdir(save_xml_file)
	for xml_path_elem in xml_path:
			xmlfilepath = os.path.abspath(xml_path_elem)
			e = init_parse(xmlfilepath)
			flag = False
			trans_tree(e)
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
