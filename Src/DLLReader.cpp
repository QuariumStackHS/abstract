#include "Common/DLLReader.h"
// Extension by operating system
char *get_DLL_EXT()
{
#ifdef _WIN32
    return ".dll";
#elif _WIN64
    return ".dll";
#elif __APPLE__ || __MACH__
    return ".so";
#elif __linux__
    return ".so";
#elif __FreeBSD__
    return ".so";
#elif __unix || __unix__
    return ".so";
#else
    return ".null";
#endif
}
// create a Loader instance
Loader *LDNew_Loader()
{
    std::string path(DLLFOLDER);
    Loader *Load = new Loader;

    std::string ext(get_DLL_EXT());
    // load every dll in vector
    for (auto &p : fs::recursive_directory_iterator(path))
    {
        if (p.path().extension() == ext)
        {
            Load->Dlls.push_back(dlopen(p.path().c_str(), RTLD_NOW));
            Load->Inits.push_back(dlsym(Load->Dlls[Load->Dlls.size() - 1], "init"));
            Load->DllMap[p.path().c_str()] = Load->Dlls[Load->Dlls.size() - 1];
            cout << "Loaded <<" << p.path() << " : " << Load->Inits[Load->Inits.size() - 1] << endl;
        }
    }
    return Load;
}
// executing all init function by passing Abstract
void LDRegisterFromDlls(Loader *load, Abstract *This)
{
    for (int i = 0; i < load->Inits.size(); i++)
    {
        cout << load->Inits[i] << endl;
        ((Abstract::FNC)load->Inits[i])(This);
    }
}
// close all loaded dll
void LDUnloadAllDlls(Loader *load)
{
    for (int i = 0; i < load->Dlls.size(); i++)
    {
        LDDynUnload(load->Dlls[i]);
    }
}
void LDDynUnload(Loader *LD, string STR)
{
    dlclose(LD->DllMap[STR]);
    for(int i=0;i<LD->Dlls.size();i++){
        if(LD->DllMap[STR]==LD->Dlls[i])
            LD->Dlls.erase(LD->Dlls.begin()+i);
    
    }
    LD->DllMap.erase(STR);
}
void LDDynload(Loader *LD, string STR) {
    LD->Dlls.push_back(dlopen(STR.c_str(), RTLD_NOW));
            LD->Inits.push_back(dlsym(LD->Dlls[LD->Dlls.size() - 1], "init"));
            LD->DllMap[STR] = LD->Dlls[LD->Dlls.size() - 1];
}