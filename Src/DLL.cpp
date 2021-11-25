#include "Common/Abstract.h"
//exemple of a dll function
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
//                                                       |-------------as well as DLL_EXIT----_------------|
//when your dll is loaded this is the first function run it take a Abstract* (as context) and output nothing
DLL_INIT(Abstract *This)
{
    AB_Insert(This, "+src", &addSrcto);
    AB_Insert(This, "-src", &rmSrcfrom);
}
//executed when dll is destroy (consider deleting your entry from Abstract)
DLL_EXIT(Abstract *This){
    cout<<"DLL Kill"<<endl; 
}
