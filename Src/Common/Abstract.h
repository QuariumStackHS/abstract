#ifndef ABSTRACT
#define ABSTRACT
#include <sstream>
#include <cstring>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;
#include <fstream>
#include <iostream>
#include <map>
#include <memory.h>
#include <string>
#include <vector>


/*definition for Main and Dlls of Abstract Structure*/
struct Abstract
{
    typedef struct Abstract Ab_stract;
    /*definition of type "Function by Dlls"*/
    typedef void (*FNC)(Abstract *);
    /*Function added by Dlls*/

    map<string, FNC> DllFuncs;
    // param could be anything but it should be a string
    vector<void *> Param;
    int ParamIndex=0;
};

/*everything here is define in Src/Abstract.cpp*/
extern "C++"
{
    Abstract *AB_New();
    void AB_Insert(Abstract *, string, Abstract::FNC);
    void AB_PushParam(Abstract*,void*);
    void AB_BuildParamfromchar(Abstract*,char**,int);
    void* AB_PopParam(Abstract*);
    void* AB_ReadNextParam(Abstract*);
    void AB_Dump(Abstract *);
    void AB_Cycle(Abstract*);
    void AB_Exe(Abstract*,string);
}

/*use DLLEXPORT as a keyword see Src/DLL.cpp
  or use macros DLL_INIT & DLL_EXIT 
*/
namespace ClientAbstractDLL{
    #ifndef DLLEXPORT
        #define DLLEXPORT extern "C" __declspec(dllexport)
    #endif
    #ifndef DLLFNCHANDLE
    #define DLLFNCHANDLE
    /*      Keyword  <Value... Abstract::FNC>*/
    #define DLL_INIT DLLEXPORT void init // DLL_INIT(Abstract*){...}
    #define DLL_EXIT DLLEXPORT void destroy //DLL_EXIT(Abstract*){...}
    #endif
}
#endif