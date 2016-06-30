#pragma once
#include <string>
#include <vector>

#include "Firma.h"

using namespace std;

class Strona 
{
    public:
        Strona ();
        ~Strona ();
        virtual void set_zbior_firm_ze_strony(string tekst_strony)=0;
                
    protected:
        string UsunZnakiSpecjalneZeStrony(string tekst_strony);
        
        vector<SpecyficznaFirma> zbior_firm_ze_strony_;
};

class StronaSpecyficzna:public Strona
{
    public:
        StronaSpecyficzna();
        ~StronaSpecyficzna();
        vector<SpecyficznaFirma> get_zbior_firm_ze_strony();
        void set_zbior_firm_ze_strony(string tekst_strony);
        
        void WyswietlStrone();

    private:
        vector<SpecyficznaFirma> WyluskajFirmyZeStronyWWW(string tekst_strony);
};