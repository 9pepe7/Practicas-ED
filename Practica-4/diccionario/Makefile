BIN = bin
INC = include
OBJ = obj
SRC = src
CXX = g++
INCLUDES = $(INC)/Diccionario.h $(INC)/Termino.h
CPPFLAGS = -Wall -g -c


all: $(BIN)/pruebadiccionario
	
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/pruebadiccionario: $(OBJ)/pruebadiccionario.o $(OBJ)/Diccionario.o $(OBJ)/Termino.o
	$(CXX) -o $@ $^ -I$(INC)

$(OBJ)/pruebadiccionario.o : $(SRC)/pruebadiccionario.cpp $(INCLUDES)
	$(CXX) $(CPPFLAGS) -o $@ $< -I$(INC)

$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp $(INCLUDES)
	$(CXX) $(CPPFLAGS) -o $@ $< -I$(INC)

$(OBJ)/Termino.o : $(SRC)/Termino.cpp $(INC)/Termino.h
	$(CXX) $(CPPFLAGS) -o $@ $< -I$(INC)


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
