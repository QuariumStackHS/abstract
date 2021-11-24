#ifndef ABSTRACT
#define ABSTRACT
#include <cstring>
#include <iostream>
#include <map>
#include <memory.h>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;


/*definition for Main and Dlls of Abstract Structure*/
struct Abstract
{
    typedef struct Abstract Ab_stract;
    /*definition of type "Function by Dlls"*/
    typedef void (*FNC)(Abstract *);
    /*Function added by Dlls*/

    map<string, FNC> DllFuncs;
    //param could be anything
    vector<void*>Param;

};


/*everything here is define in Src/Abstract.cpp*/
extern "C++"
{
    Abstract *AB_New();
    void AB_Insert(Abstract *, string, Abstract::FNC);
    void AB_Dump(Abstract *);
}


/*use DLLEXPORT as a keyword see Src/DLL.cpp*/
#ifndef DLLEXPORT
#define DLLEXPORT extern "C" __declspec(dllexport)
#endif
#endif