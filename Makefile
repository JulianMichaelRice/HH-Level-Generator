#MAKEFILE FOR LEVEL GENERATOR
#JULIAN RICE

default: main.cpp Set.cpp BoardSize.cpp Level.cpp Random.cpp
	g++ -o Level-Generator main.cpp Set.cpp BoardSize.cpp Level.cpp Random.cpp

clean:
	rm -f Level-Generator

dist:
	g++ -o Level-Generator main.cpp Set.cpp BoardSize.cpp Level.cpp Random.cpp
	tar -zvcf Harvey_Generator.tar.gz main.cpp Set.cpp Set.h BoardSize.cpp BoardSize.h Level.cpp Level.h Random.h Random.cpp Level-Generator
