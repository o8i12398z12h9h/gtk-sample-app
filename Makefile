PKGS=gtk+-3.0 glib-2.0 gmodule-2.0
CFLAGS=-g3 `pkg-config --cflags $(PKGS)`
LDLIBS=`pkg-config --libs $(PKGS)`
CC=gcc

main: main.o callbacks.o app.o
	$(CC) -o $@ $^ $(LDLIBS)
	

