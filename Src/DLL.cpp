#include "Common/Abstract.h"

void addSrcto(Abstract*AB){
    cout<<"Hello From DLL"<<endl;
};
void rmSrcfrom(Abstract*AB){
    cout<<"!Hello From DLL"<<endl;
};
DLLEXPORT
void init(Abstract*This){
    AB_Insert(This,"+src",&addSrcto);
    AB_Insert(This,"-src",&rmSrcfrom);

}