LUAJIT_INC = ../../../luajit/include/luajit-2.1
LUAJIT_LIB = ../../../luajit/lib
all:
	gcc -o libluaipip.so -shared -fPIC -g luaipip.c  ipip.c    -I$(LUAJIT_INC)
	gcc -g -o ipip_test test.c ipip.c

install:
	install libluaipip.so    ../../../lualib

clean:
	rm -rf libluaipip.so ipip_test
