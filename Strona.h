#pragma once
#include <string>
#include <vector>

#include "Firma.h"
#include "SpecyficznaFirma.h"

using namespace std;

class Strona 
{
    public:
        virtual ~Strona (){};
        virtual void set_zbior_firm_ze_strony(string tekst_strony) = 0;
                
    protected:
        string UsunZnakiSpecjalneZeStrony(string tekst_strony);
        
        vector<SpecyficznaFirma> zbior_firm_ze_strony_;
};
