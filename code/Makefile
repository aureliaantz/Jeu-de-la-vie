CC = gcc
CFLAGS = -Wall
IFLAGS = -Iinclude
CPPFLAGS += -Iinclude -I/usr/include/cairo
LDFLAGS += -lcairo -lm -lX11
ifeq ($(MODE),TEXTE)
	OBJETS = $(OBJ)/$(EXEC).o $(OBJ)/io.o $(LIB)/libjeu.a
else
	OBJETS = $(OBJ)/$(EXEC).o $(OBJ)/io_cairo.o $(LIB)/libjeu.a
endif
EXEC = main

BIN = bin
OBJ = obj
LIB = lib

NAME = AntzAurelia
VERSION = v5.2

vpath %.c src/
vpath %.h include/
vpath %.o obj/
vpath %.a lib/
vpath $(EXEC) bin/

$(EXEC) : $(OBJETS) | $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^ $(LDFLAGS)

$(OBJ)/%.o : %.c | $(OBJ)
ifeq ($(MODE),TEXTE)
	$(CC) $(CFLAGS) -DINC=\"io.h\" -o $@ -c $< $(IFLAGS)
else
	$(CC) $(CFLAGS) -DINC=\"io_cairo.h\" -o $@ -c $< $(CPPFLAGS)
endif

$(LIB)/libjeu.a : $(OBJ)/jeu.o $(OBJ)/grille.o | $(LIB)
	ar -crv $@ $(OBJ)/jeu.o $(OBJ)/grille.o
	ranlib $@

$(OBJ) :
	mkdir $@ 

$(BIN) :
	mkdir $@

$(LIB):
	mkdir $@

doc : 
	doxygen Doxyfile

dist : 
	tar --lzma -cf $(NAME)-GoL-$(VERSION).tar.xz src/ include/ Makefile ../README.md Doxyfile

docclean : 
	rm -rf doc/*

distclean : 
	rm -rf *.tar.xz

clean : 
	rm -rf $(BIN)/ $(OBJ)/ $(LIB)