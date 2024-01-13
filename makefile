make: compiler.l compiler.y
	bison -d compiler.y   
	flex compiler.l
	g++ -Wno-register -O0 compiler.tab.c lex.yy.c -o compiler -g 