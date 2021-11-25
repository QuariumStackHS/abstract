g++ Src/Main.cpp -o Main.o -std=c++17 -c -w
g++ Src/DLLReader.cpp -o DLLReader.o -std=c++17 -c -Wwritable-strings -w
g++ Src/Abstract.cpp -o Abstract.o -std=c++17 -c -w
g++ Main.o DLLReader.o Abstract.o -rdynamic -ldl -o Abstract -w
rm Main.o
rm DLLReader.o
rm Abstract.o
sh BuildDll.sh