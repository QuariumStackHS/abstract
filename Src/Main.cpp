#include "Common/Abstract.h"
#include "Common/DLLReader.h"
int main(int argc,char**argv)
{
    Abstract::Ab_stract *This = AB_New();
    Loader*Load=LDNew_Loader();
    /*Initialise all dlls*/
    cout<<"Registering.."<<endl;
    LDRegisterFromDlls(Load,This);

    AB_Dump(This);

    LDUnloadAllDlls(Load);
    
}