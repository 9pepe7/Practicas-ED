SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c
includes = $(INC)/Cola_max.h $(INC)/Cola_max_pila.cpp $(INC)/Cola_max_vd.cpp $(INC)/PilaMax.cpp


all: $(BIN)/pruebacola_max
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/pruebacola_max: $(SRC)/pruebacola_max.cpp $(includes)
	$(CXX) -o $@ $< -I$(INC)

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
