g++ Src/STDLL.cpp -o Main.o -std=c++17 -c -Wl,--export-dynamic -fdeclspec
g++ Src/DLLReader.cpp -o DLLReader.o -std=c++17 -c -Wwritable-strings
g++ Src/Abstract.cpp -o Abstract.o -std=c++17 -c
g++ Main.o DLLReader.o Abstract.o sql.o -rdynamic -ldl -o Dlls/STDll.so -shared -Wl
rm Main.o
rm DLLReader.o
rm Abstract.o
