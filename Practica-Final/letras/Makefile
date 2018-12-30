BIN = bin
INC = include
OBJ = obj
SRC = src
CXX = g++
INCLUDES = $(INC)/Diccionario.h $(INC)/Termino.h
CPPFLAGS = -Wall -g -c


all: $(BIN)/

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
