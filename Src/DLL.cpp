#include "Common/Abstract.h"
#include "Common/BFI.hpp"
#include <cstring>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;
using namespace BRAINFUCK_INTERPRETER;
// exemple of a dll function
void BFI(Abstract *This)
{
    void *p = AB_ReadNextParam(This);
    if (p)
    {
        stringstream ss;
        ifstream F(*((string *)p));
        ss << F.rdbuf();
        Program*brainfuck=new Program;
        string code=ss.str();
        brainfuck->runBF(code);
        delete brainfuck;
    }
    else
    {
    }
}
//                                                       |-------------as well as DLL_EXIT----_------------|
// when your dll is loaded this is the first function run it take a Abstract* (as context) and output nothing
DLL_INIT(Abstract *This)
{
    AB_Insert(This, "-bfi", &BFI);
    AB_Insert(This, "-BFI", &BFI);
}
// executed when dll is destroy (consider deleting your entry from Abstract)
DLL_EXIT(Abstract *This)
{
    cout << "DLL Kill" << endl;
}
