#include "Common/Abstract.h"

void addSrcto(Abstract *AB)
{
    void *ptr = AB_ReadNextParam(AB);
    cout << "DLL" << endl;
    if (ptr == nullptr)
    {
        cout << "no arg spec" << endl;
    }
    else
    {
        string *param = (string *)ptr;
        cout << *param << endl;
    }
};
void rmSrcfrom(Abstract *AB)
{
    cout << "!Hello From DLL" << endl;
};
DLL_INIT(Abstract *This)
{
    AB_Insert(This, "+src", &addSrcto);
    AB_Insert(This, "-src", &rmSrcfrom);
}
DLL_EXIT(Abstract *This){
    cout<<"DLL Kill"<<endl; 
}
