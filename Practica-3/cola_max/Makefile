SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c
includes = $(INC)/Cola_max.h $(INC)/Cola_max_pila.h


all: $(BIN)/pruebacola_max
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/pruebacola_max: $(OBJ)/pruebacola_max.o $(OBJ)/Cola_max_pila.o
	$(CXX) -o $@ $^ -I$(INC)

$(OBJ)/pruebacola_max.o: $(SRC)/pruebacola_max.cpp $(includes)
	$(CXX) $(CPPFLAGS) -o $@ $<

$(OBJ)/Cola_max_pila.o: $(SRC)/Cola_max_pila.cpp $(INC)/Cola_max_pila.h
	$(CXX) $(CPPFLAGS) -o $@ $<



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
