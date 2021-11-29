#include "Common/DLLReader.h"
#include "Common/Sha3/digestpp.hpp"
#include "Common/sqlite3.h"
#include <sstream>
using namespace digestpp;

/*
this dll is to build Abstract and DLLs, could be use for any gcc/g++ task
*/
namespace SQL{
string CreateTables="CREATE TABLE compile ("\
"    lastsha3    BLOB,"\
"    Pathsrc 	TEXT,"\
"    compiler	TEXT DEFAULT 'g++',"\
"    switchs	    TEXT,"\
");"\
"CREATE TABLE Builds ("\
"    Buildname TEXT,"\
"    BinPath	TEXT,"\
"    switchs	TEXT,"\
"    includes	TEXT"\
");";
};
unsigned char *hashF(string f)
{
    ifstream File(f);
    stringstream ss;
    ss<<File.rdbuf();
    unsigned char buf[32];
    //thanks VSC for giving me an error about sha3 and digest you motherfucker
    sha3(256).absorb(ss.str()).digest(buf, sizeof(buf));
    return buf;
    //cout << isEqual(buf, buf2, sizeof(buf)) << endl;
}

void create_DLL_CFG(Abstract *T)
{
    hashF("");
    void *firstparam = AB_ReadNextParam(T);
    if (firstparam)
    {
        string *DLLNAME = (string *)firstparam;
    }
    else
    {
        cout << "\"+DLL\" require at least one more arg\n";
    }
}

DLL_INIT(Abstract *This)
{
    AB_Insert(This, "+DLL", &create_DLL_CFG);
}
// executed when dll is destroy (consider deleting your entry from Abstract)
DLL_EXIT(Abstract *This)
{
    cout << "STDLL Kill" << endl;
}