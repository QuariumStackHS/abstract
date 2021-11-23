
#include "Common/Abstract.h"
Abstract *AB_New() { return new Abstract::Ab_stract; }

void AB_Insert(Abstract *This, string i, Abstract::FNC j)
{
    This->DllFuncs[i] = j;
}
void AB_Dump(Abstract*This){
map<string, Abstract::FNC>::iterator it;

for (it = This->DllFuncs.begin(); it != This->DllFuncs.end(); it++)
{
    This->DllFuncs[it->first](This);
    std::cout << it->first    // string (key)
              << ':'
              << it->second   // string's value 
              << std::endl;
}
}