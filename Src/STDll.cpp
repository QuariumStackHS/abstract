#include "Common/DLLReader.h"
#include "Common/Sha3/digestpp.hpp"
#include "Common/sqlite3.h"
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
char *hashF(string f)
{
    char *c = "lol";
    unsigned char buf[32];
    unsigned char buf2[32];
    sha3(256).absorb("The quick brown fox jumps over the lazy dog").digest(buf, sizeof(buf));
    sha3(256).absorb("The quick brown fox jumps over the lazy dog").digest(buf2, sizeof(buf2));
    cout << isEqual(buf, buf2, sizeof(buf)) << endl;
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