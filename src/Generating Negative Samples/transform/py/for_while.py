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
	# 标记，表示for可以进行转化
	global flag
    #先设置flag表示尚未变换
	flag = False
	#获取所有for
	for_stmts = [get_for(e) if instances is None else (instance[0] for instance in instances)]
    #获取树根，后面取路径要用
	tree_root = e('/*')[0].getroottree()
	new_ignore_list = []
	for item in for_stmts:
		for for_stmt in item:
			#过滤掉上一轮由while变换成的for
			#while转for没插入语句，所以没变换的部分就是for前一条语句
			for_prev = for_stmt.getprevious()
			for_prev = for_prev if for_prev is not None else for_stmt
	        #取路径，看路径是否在传进来的忽略列表里
			for_prev_path = tree_root.getpath(for_prev)
			if for_prev_path in ignore_list:
				print('变换过，忽略')
				continue
			#获取for里的初始化部分
			init = get_init(for_stmt)
			#获取循环条件
			cond_expr = get_cond_expr(for_stmt)
			#获取循环增量
			incr = get_incr(for_stmt)
			if len(init)>=1 and len(cond_expr)>=1 and len(incr)>=1:
				flag = True
				# 对每个for，先把源代码和xml标签都改成while
				for_stmt.tag = 'while'
				for_stmt.text = 'while '
				init = init[0]
				cond_expr = cond_expr[0]
				incr = incr[0]
				#获取for语句块
				if len(get_block(for_stmt))==0:continue
				for_block = get_block(for_stmt)[0]
				for_block1 = get_block1(for_stmt)[0]
				if for_block1.text is None:
					for_block1.text = '{'
					for_block1.tail = '}'
				# 如果初始化为空，那么去掉‘；’
				if len(init) == 0:
					init.text = ''
				#去掉循环条件后的分号
				cond_expr.tail = ')'
				#因为循环增量也要单独提出来，所以后面加上分号和换行
				if len(incr)>=1:
					incr.tail = ';\n'
				else:
					incr.tail = ''
				for_index = for_stmt.getparent().index(for_stmt)
				#把初始化语句插入到for循环之前
				for_stmt.getparent().insert(for_index, init)
				#把增量语句插入到for语句块最后
				for_block.append(incr)
	            #记录这次变换后没变的位置，即for语句往上数两条语句位置
				init_prev = init.getprevious()
				init_prev = init_prev if init_prev is not None else init
				init_prev_path = tree_root.getpath(init_prev)
				new_ignore_list.append(init_prev_path)
	return flag, tree_root, new_ignore_list
def count(e):
	count_num = 0
	for_stmts = get_for(e)
	for for_stmt in for_stmts:
		# 获取for里的初始化部分
		init = get_init(for_stmt)
		# 获取循环条件
		cond_expr = get_cond_expr(for_stmt)
		# 获取循环增量
		incr = get_incr(for_stmt)
		if len(init) >= 1 and len(cond_expr) >= 1 and len(incr) >= 1:
			count_num += 1
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
	save_xml_file = './transform_xml_file/for_while'
	transform_java_file = './pre_file/transform_java/for_while'
	if not os.path.exists(transform_java_file):
		os.mkdir(transform_java_file)
	if not os.path.exists(save_xml_file):
		os.mkdir(save_xml_file)
	for xml_path_elem in xml_path:
			xmlfilepath = os.path.abspath(xml_path_elem)
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