# 这是注释的符号
# 只会编译修改过的文件 节约时间

#第一行是最后执行 想要生成testq可执行文件需要queue.o 和testq.c 两个文件
testq : queue.o testq.c
	#生成testq可执行文件的命令
	gcc queue.o testq.c -o testq
#生成queue.o 需要queue.c 文件
queue.o : queue.c
	#生成queue.o的命令
	gcc -c queue.c


