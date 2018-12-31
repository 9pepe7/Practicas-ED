BIN = bin
INC = include
OBJ = obj
SRC = src
CXX = g++
CPPFLAGS = -Wall -g -c


all: $(BIN)/testlista_palabras $(BIN)/letras

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/testlista_palabras: $(OBJ)/testlista_palabras.o $(OBJ)/lista_palabras.o
	$(CXX) -o $@ $^ -I$(INC)

$(OBJ)/testlista_palabras.o: $(SRC)/testlista_palabras.cpp $(INC)/lista_palabras.h
	$(CXX) $(CPPFLAGS) -o $@ $< -I$(INC)

$(OBJ)/lista_palabras.o: $(SRC)/lista_palabras.cpp $(INC)/lista_palabras.h
	$(CXX) $(CPPFLAGS) -o $@ $< -I$(INC)

$(BIN)/letras: $(OBJ)/letras.o $(OBJ)/conjunto_letras.o $(OBJ)/letra.o $(OBJ)/lista_palabras.o
	$(CXX) -o $@ $^ -I$(INC)

$(OBJ)/letras.o: $(SRC)/letras.cpp
	$(CXX) $(CPPFLAGS) -o $@ $< -I$(INC)

$(OBJ)/conjunto_letras.o: $(SRC)/conjunto_letras.cpp $(INC)/conjunto_letras.h $(INC)/letra.h
	$(CXX) $(CPPFLAGS) -o $@ $< -I$(INC)

$(OBJ)/letra.o: $(SRC)/letra.cpp $(INC)/letra.h
	$(CXX) $(CPPFLAGS) -o $@ $< -I$(INC)

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
