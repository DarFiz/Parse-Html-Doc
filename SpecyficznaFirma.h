#pragma once
#include <string>
#include "Firma.h"

class SpecyficznaFirma: public Firma
{
    public:
        void set_adres_firmy(string element_listy_html_z_firma);
        void set_mail_firmy(string element_listy_html_z_firma);
        void set_nazwa_firma(string element_listy_html_z_firma);

        void WyswietlNazweAdresMailFirmy();
};
