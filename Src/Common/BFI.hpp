//#include "Common/DLLReader.h"
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <vector>
//this code was built to fuck your brain haha
#define BEG {
#define END }
#define FROM <<
#define ENDINS ;
#define IS =
#define ISEQ ==
#define ISEQNOT ==
using namespace std ENDINS
#define BREAK break ENDINS
#define THENIF(A) case A:
#define THENIFDEFAULT default:
namespace BRAINFUCK_INTERPRETER
BEG
#define NEWCELL cells.push_back(0) ENDINS
#define THENIF(A) case A:
#define THENIFDEFAULT default:
#define IFCELL0              \
    if (cells[CellPTR] ISEQ 0) \
    BEG
#define IFCELLnot0           \
    if (cells[CellPTR] ISEQNOT 0) \
    BEG
#define MAYBERESETCELL cells[CellPTR] IS (cells[CellPTR] ISEQ 256) ? 0 : cells[CellPTR] ENDINS

#define INS class
    INS Program BEG int IP IS 0 ENDINS
    int CellPTR IS 0 ENDINS
    vector<int> temp ENDINS
    vector<char> cells ENDINS
    map<int, int> Brackets ENDINS
#define NEWCELL        cells.push_back(0) ENDINS

#define IFCELL0    if (cells[CellPTR] ISEQ 0)BEG
#define IFCELLnot0 if (cells[CellPTR] ISEQNOT 0)BEG
#define MAYBERESETCELL cells[CellPTR] IS (cells[CellPTR] ISEQ 256) ? 0 : cells[CellPTR] ENDINS
    public:
    void PreInit(string &Code)
    BEG
        for (int ij IS 0 ENDINS ij < Code.size() ENDINS ij++)
        BEG
            switch (Code[ij])
            BEG
                THENIF('[')
                temp.push_back(ij) ENDINS
                BREAK
                THENIF(']')
                int Opening IS temp[temp.size() - 1] ENDINS
                Brackets[Opening] IS ij ENDINS
                Brackets[ij] IS Opening ENDINS
                temp.pop_back() ENDINS
                BREAK
            END
        END
    END
    void *runBF(string &Code)
    BEG
        PreInit(Code) ENDINS
        NEWCELL
        int CV ENDINS
        while (IP < Code.size())
        BEG 
            switch (Code[IP])
            BEG
                THENIF('+')
                cells[CellPTR]++ ENDINS
                MAYBERESETCELL
                BREAK
                THENIF('-')
                cells[CellPTR]-- ENDINS
                BREAK
                THENIF('.')
                CV IS cells[CellPTR] ENDINS
                cout FROM cells[CellPTR] ENDINS 
                            BREAK
                                THENIF(',')
                                    cells[CellPTR] IS
                    getchar() ENDINS
                BREAK
                THENIF('<')
                CellPTR-- ENDINS
                BREAK
                THENIF('>')
                CellPTR++ ENDINS
                if (cells.size() >= IP)
                    NEWCELL
                BREAK
                THENIF('[')
                IFCELL0
                IP IS Brackets[IP] ENDINS
                END
                    BREAK
                        THENIF(']')
                            IFCELLnot0
                                IP IS Brackets[IP] ENDINS
                END
                    BREAK
                        THENIFDEFAULT
                            BREAK
            END
            IP++ ENDINS
        END
    END
    END ENDINS

END