SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebadiccionario
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile -s


# ************ Compilación de módulos ************
$(BIN)/pruebadiccionario: $(OBJ)/pruebadiccionario.o $(OBJ)/Diccionario.o $(OBJ)/Termino.o
	$(CXX) -o $(BIN)/pruebadiccionario $(OBJ)/*.o -I$(INC)

$(OBJ)/pruebadiccionario.o : $(SRC)/pruebadiccionario.cpp $(INC)/Termino.h $(INC)/Diccionario.h $(INC)/Vector_Dinamico.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebadiccionario.o $(SRC)/pruebadiccionario.cpp


$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp $(INC)/Termino.h $(INC)/Diccionario.h $(INC)/Vector_Dinamico.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Diccionario.o $(SRC)/Diccionario.cpp

$(OBJ)/Termino.o : $(SRC)/Termino.cpp $(INC)/Termino.h $(INC)/Vector_Dinamico.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Termino.o $(SRC)/Termino.cpp

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
