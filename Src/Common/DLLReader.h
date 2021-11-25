#include <dlfcn.h>
#include "Abstract.h"
#define DLLFOLDER "DLLs/"
struct Loader{
    map<string,void*>DllMap;
    vector<void*>Dlls;
    vector<void*>Inits;
};
extern "C++"
{
    Loader*LDNew_Loader();
    void LDRegisterFromDlls(Loader*,Abstract*);
    void LDUnloadAllDlls(Loader*,Abstract*);
    void LDDynload(Loader*,string);
    void LDDynUnload(Loader *,Abstract*, string );

}