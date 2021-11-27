
#include "Common/Abstract.h"
Abstract *AB_New() { return new Abstract::Ab_stract; }

void AB_Insert(Abstract *This, string i, Abstract::FNC j)
{
    This->DllFuncs[i] = j;
}
void AB_Dump(Abstract *This)
{
    map<string, Abstract::FNC>::iterator it;

    for (it = This->DllFuncs.begin(); it != This->DllFuncs.end(); it++)
    {
        This->DllFuncs[it->first](This);
        std::cout << it->first // string (key)
                  << ':'
                  << it->second // string's value
                  << std::endl;
    }
}
void AB_Exe(Abstract *This, string str)
{
    Abstract::FNC ADDR_PTR = This->DllFuncs[str];
    if (ADDR_PTR)
    {
        ADDR_PTR(This);
    }
}
void AB_Cycle(Abstract *This)
{
    int thisint = 0;
    while ((This->Param.size() > thisint + 1))
    {
        This->ParamIndex = thisint + 1;
        AB_Exe(This, *(string *)This->Param[++thisint]);
    }
}
void AB_BuildParamfromchar(Abstract *This, char **Argv, int argc)
{
    for (int i = 0; i < argc; i++)
    {
        AB_PushParam(This, (void *)new string(Argv[i]));
    }
}
void AB_PushParam(Abstract *This, void *ptr) { This->Param.push_back(ptr); }
void *AB_ReadNextParam(Abstract *This) { return (This->Param.size() > This->ParamIndex + 1) ? This->Param[++This->ParamIndex] : nullptr; }

void *AB_PopParam(Abstract *This)
{
    void *ptr = This->Param[This->Param.size() - 1];
    This->Param.pop_back();
    return ptr;
}