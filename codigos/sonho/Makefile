LIBS=-lsfml-system -lsfml-graphics -lsfml-window
DIR=farm/

all: learncodecpp clean

learncodecpp: main.o personagemfactory.o componente.o componentemovel.o escritor.o imagemanager.o interface.o $(DIR)constantes.h $(DIR)comando.h
	g++ main.o personagemfactory.o componente.o componentemovel.o escritor.o imagemanager.o interface.o -o main $(LIBS)

personagemfactory.o: $(DIR)personagemfactory.cpp $(DIR)personagemfactory.h
	g++ -c $(DIR)personagemfactory.cpp $(LIBS)

interface.o: $(DIR)interface.cpp $(DIR)interface.h $(DIR)componente.h
	g++ -c $(DIR)interface.cpp $(LIBS)

componente.o: $(DIR)componente.cpp $(DIR)componente.h
	g++ -c $(DIR)componente.cpp $(LIBS)
	
componentemovel.o: $(DIR)componentemovel.h $(DIR)componentemovel.cpp
	g++ -c $(DIR)componentemovel.cpp $(LIBS)

escritor.o: $(DIR)escritor.cpp $(DIR)escritor.h
	g++ -c $(DIR)escritor.cpp $(LIBS)

imagemanager.o: $(DIR)imagemanager.cpp $(DIR)imagemanager.h
	g++ -c $(DIR)imagemanager.cpp $(LIBS)

main: main.cpp
	g++ -c $(DIR)main.cpp $(LIBS)

clean: 
	rm -rf *.o

run:
	./main

