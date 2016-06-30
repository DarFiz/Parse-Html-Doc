#include "Firma.h"

#include <iostream>
#include <regex>
#include <string>

using namespace std;

Firma::Firma()
{
    //EMPTY BODY
}

Firma ::~Firma()
{
    //EMPTY BODY
}

string Firma::get_mail_firmy()
{
    return mail_firmy_;
}

string Firma::get_adres_firmy()
{
    return adres_firmy_;
}

string Firma::get_nazwa_firmy()
{
    return nazwa_firmy_;
}

SpecyficznaFirma::SpecyficznaFirma()
{
    //EMPTY BODY
}

SpecyficznaFirma ::~SpecyficznaFirma()
{
    //EMPTY BODY
}

void SpecyficznaFirma::set_mail_firmy(string element_listy_html_z_firma)
{
    regex reg_mailto(R"(mailto)");

    if (regex_search(element_listy_html_z_firma, reg_mailto))
    {
        regex reg_usun_mail(R"(.+mailto:([\w._%+-]+@[\w.-]+\.[\w]{2,4})\".+)");   
        mail_firmy_ = regex_replace(element_listy_html_z_firma, reg_usun_mail, R"($1)");                
    }
    else
    {        
        mail_firmy_ =  "brak emaila";
    }
}

void SpecyficznaFirma::WyswietlNazweAdresMailFirmy()
{
    cout << nazwa_firmy_ << " || " << adres_firmy_ << " || " << mail_firmy_;
}

void SpecyficznaFirma::set_nazwa_firma(string element_listy_html_z_firma)
{
    regex reg_usun_mail(R"(.+company_name_click\">(.+?)</a>.+)");

    nazwa_firmy_ = regex_replace(element_listy_html_z_firma, reg_usun_mail, string(R"($1)"));
}

void SpecyficznaFirma::set_adres_firmy(string element_listy_html_z_firma)
{
    regex reg_tel(R"(<a href=\"tel)");
    regex reg_contact_cross(R"(<div class=\"contacts cross\">)");

    if (regex_search(element_listy_html_z_firma,reg_contact_cross))
    {
        regex reg_adres(R"(.+?<span class=\"crossAddressCompany\">[\s]*(.+?)[\s]*</span>.+)");
        adres_firmy_ =  regex_replace(element_listy_html_z_firma, reg_adres, R"($1)");
    }
    else if (regex_search(element_listy_html_z_firma, reg_tel))
    {
        regex reg_usun_mail(R"(.+?<div class=\"contacts \">[\s]+<a href=\"tel.+?</a><br />[\s]+(.+?)[\s]+</div>.+)");
        adres_firmy_ =  regex_replace(element_listy_html_z_firma, reg_usun_mail, R"($1)");
    }
    else 
    {
        regex reg_usun_mail(R"(.+?<div class=\"contacts \">[\s]+(.+?)[\s]+</div>.+)");
        adres_firmy_ =  regex_replace(element_listy_html_z_firma, reg_usun_mail, R"($1)");
    }         
}