#!/usr/bin/lua  
-- 以上指示了lua解释器的目录,使得该脚本可执行，必须放在首行
-- 使得./会自动寻找lua的解释器
-- #代表解释器会忽略掉

print("hello world!\n")
print("欢迎来到lua语言的学习\n")
print("lua -i 代表交互式编程\nlua helloworld.lua 代表脚本式编程\n")
print("#!/usr/bin/lua 指示了lua解释器的目录\n必须放在首行")
print("使得./会根据目录来寻找lua解释器\n")
print("print函数会在打印完要输出的内容后自动打印一个换行符\n")
print("注释")
print("--代表单行注释")
print("--[[\n	多行注释\n	多行注释\n--]]\n")
--[[
	print("注释内容")
	print("注释内容")
--]]
print("标识符")
print("lua标识符区别大小写，由大小写英文字母，数字，下划线(_)")
print("不能以数字开头，最好不要使用下划线(_)加大写字母的标识符，这很有可能是保留字\n")
print("以下是lua中的关键字：")
print("and break do else")
print("elseif end false for")
print("function if in local")
print("nil not or repeat")
print("return then true until")
print("while goto\n")
print("变量")
print("默认下变量总是全局的，变量不需要声明")
print("赋值即创建，赋值为nil即删除(变量不存在)")
b=10
print(b)
b=nil
print(b)
