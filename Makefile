cpp_files = main.cpp Firma.cpp SpecyficznaFirma.cpp Strona.cpp SpecyficznaStrona.cpp
h_files = Firma.h Strona.h SpecyficznaFirma.h SpecyficznaStrona.h

parse.exe: $(cpp_files) $(h_files) Makefile
	g++-4.9 -g -std=c++11  -o parse.exe $(cpp_files)
run:
	./parse.exe
