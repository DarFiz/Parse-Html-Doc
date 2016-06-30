#pragma once
#include <string>

using namespace std;

class Firma 
{
    public:
        Firma();
        ~Firma ();
        string get_mail_firmy();
        string get_adres_firmy() ;
        string get_nazwa_firmy() ;
        
        virtual void set_adres_firmy(string element_listy_html_z_firma)=0;
        virtual void set_mail_firmy(string element_listy_html_z_firma)=0;
        virtual void set_nazwa_firma(string element_listy_html_z_firma)=0;

        virtual void WyswietlNazweAdresMailFirmy() = 0;
        
    protected:
        string mail_firmy_;
        string nazwa_firmy_;
        string adres_firmy_;
};

class SpecyficznaFirma: public Firma
{
    public:
        SpecyficznaFirma();
        ~SpecyficznaFirma ();
        
        void set_adres_firmy(string element_listy_html_z_firma);
        void set_mail_firmy(string element_listy_html_z_firma);
        void set_nazwa_firma(string element_listy_html_z_firma);
        
        void WyswietlNazweAdresMailFirmy();
};
