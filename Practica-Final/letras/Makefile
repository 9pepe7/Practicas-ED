BIN = ./bin
INC = ./include
OBJ = ./obj
SRC = ./src
LIB = ./lib
CXX = g++
CPPFLAGS = -Wall -g -c -o
ARFLAGS = rs
.PHONY: all documentacion clean mrproper

all: $(BIN)/testlista_palabras $(BIN)/letras $(BIN)/cantidad_letras

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
# 1. testlista_palabras
$(BIN)/testlista_palabras: $(OBJ)/testlista_palabras.o $(LIB)/liblistapalabras.a
	@echo Creando ejecutable $@
	@$(CXX) -o $@ $< -L$(LIB) -llistapalabras

$(OBJ)/testlista_palabras.o: $(SRC)/testlista_palabras.cpp $(INC)/lista_palabras.h
	@$(CXX) $(CPPFLAGS) $@ $< -I$(INC)

# 2. letras
$(BIN)/letras: $(OBJ)/letras.o $(LIB)/libbolsa_letras.a $(LIB)/liblistapalabras.a
	@echo Creando ejecutable $@
	@$(CXX) -o $@ $< -L$(LIB) -lbolsa_letras -llistapalabras

$(OBJ)/letras.o: $(SRC)/letras.cpp $(INC)/bolsa_letras.h $(INC)/lista_palabras.h $(INC)/conjunto_letras.h
	@$(CXX) $(CPPFLAGS) $@ $< -I$(INC)

# 3. cantidad_letras
$(BIN)/cantidad_letras: $(OBJ)/cantidad_letras.o $(LIB)/libbolsa_letras.a
	@echo Creando ejecutable $@
	@$(CXX) -o $@ $< -L$(LIB) -lbolsa_letras

$(OBJ)/cantidad_letras.o: $(SRC)/cantidad_letras.cpp $(INC)/conjunto_letras.h
	@$(CXX) $(CPPFLAGS) $@ $< -I$(INC)

# 4. lib lista_palabras
$(LIB)/liblistapalabras.a: $(OBJ)/lista_palabras.o $(OBJ)/comp.o
	@echo Creando biblioteca $@
	@ar $(ARFLAGS) $@ $^
$(OBJ)/lista_palabras.o: $(SRC)/lista_palabras.cpp $(INC)/lista_palabras.h $(INC)/comp.h
	@$(CXX) $(CPPFLAGS) $@ $< -I$(INC)

# 5. lib bolsa_letras
$(LIB)/libbolsa_letras.a: $(OBJ)/bolsa_letras.o $(OBJ)/conjunto_letras.o $(OBJ)/letra.o $(OBJ)/comp.o
	@echo Creando biblioteca $@
	@ar $(ARFLAGS) $@ $^

$(OBJ)/bolsa_letras.o: $(SRC)/bolsa_letras.cpp $(INC)/bolsa_letras.h $(INC)/conjunto_letras.h $(INC)/letra.h $(INC)/lista_palabras.h
	@$(CXX) $(CPPFLAGS) $@ $< -I$(INC)

$(OBJ)/conjunto_letras.o: $(SRC)/conjunto_letras.cpp $(INC)/conjunto_letras.h $(INC)/letra.h
	@$(CXX) $(CPPFLAGS) $@ $< -I$(INC)

$(OBJ)/letra.o: $(SRC)/letra.cpp $(INC)/letra.h $(INC)/comp.h
	@$(CXX) $(CPPFLAGS) $@ $< -I$(INC)

# 6. struct comp.h que va (según parece) en las bibliotecas
$(OBJ)/comp.o: $(SRC)/comp.cpp $(INC)/comp.h
	@$(CXX) $(CPPFLAGS) $@ $< -I$(INC)


# ************ Limpieza ************
clean :
	@echo Borrando los ficheros .o y los temporales
	@-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	@echo Borrando ejecutable y documentacion
	@-rm $(BIN)/* doc/html/*
