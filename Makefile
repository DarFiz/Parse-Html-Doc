parse.exe: main.cpp Firma.cpp Firma.h Strona.cpp Strona.h Makefile
	g++-4.9 -g -std=c++11  -o parse.exe main.cpp Firma.cpp Strona.cpp
