#pragma once
#include <string>
#include <vector>

#include "Firma.h"
#include "SpecyficznaFirma.h"
#include "Strona.h"

using namespace std;


class SpecyficznaStrona: public Strona
{
    public:
        vector<SpecyficznaFirma> get_zbior_firm_ze_strony();
        void set_zbior_firm_ze_strony(string tekst_strony);

        void WyswietlStrone();

    private:
        vector<SpecyficznaFirma> WyluskajFirmyZeStronyWWW(string tekst_strony);
};
