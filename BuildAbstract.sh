g++ Src/Main.cpp -o Main.o -std=c++17 -c
g++ Src/DLLReader.cpp -o DLLReader.o -std=c++17 -c -Wwritable-strings
g++ Src/Abstract.cpp -o Abstract.o -std=c++17 -c
g++ Main.o DLLReader.o Abstract.o -rdynamic -ldl -o Abstract
rm Main.o
rm DLLReader.o
rm Abstract.o