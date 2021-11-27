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
bool isEqual(unsigned char *i, unsigned char *j, int size)
{
    bool ret = 1;
    for (int h = 0; h < size; h++)
    {
        ret = (ret && (i[h] == j[h]));
    }
    return ret;
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
            LDDynload(Load, p.path().c_str());
            // cout << "Loaded <<" << p.path() << " : " << Load->Inits[Load->Inits.size() - 1] << endl;
        }
    }
    return Load;
}
// executing all init function by passing Abstract
void LDRegisterFromDlls(Loader *load, Abstract *This)
{
    for (int i = 0; i < load->Inits.size(); i++)
    {
        // cout << load->Inits[i] << endl;
        ((Abstract::FNC)load->Inits[i])(This);
    }
}
// close all loaded dll

void LDDynUnload(Loader *LD, Abstract *TAB, string STR)
{
    if (LD->DllMap[STR] != nullptr)
    {
        ((Abstract::FNC)dlsym(LD->DllMap[STR], "destroy"))(TAB);
        for (int i = 0; i < LD->Dlls.size(); i++)
        {
            if (LD->DllMap[STR] == LD->Dlls[i])
                LD->Dlls.erase(LD->Dlls.begin() + i);
        }
        dlclose(LD->DllMap[STR]);
        LD->DllMap.erase(STR);
    }
    else
        cout << "ERROR could not find dll in ram:" << STR << endl;
    return;
}
void LDUnloadAllDlls(Loader *load, Abstract *T)
{
    for (int i = 0; i < load->Dllnames.size(); i++)
        LDDynUnload(load, T, load->Dllnames[i]);
    load->Dllnames.clear();
    return;
}
void LDDynload(Loader *LD, string STR)
{
    LD->Dlls.push_back(dlopen(STR.c_str(), RTLD_NOW));
    LD->Inits.push_back(dlsym(LD->Dlls[LD->Dlls.size() - 1], "init"));
    LD->DllMap[STR] = LD->Dlls[LD->Dlls.size() - 1];
    LD->Dllnames.push_back(STR);
}