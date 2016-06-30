#include "Strona.h"

#include <iostream>
#include <regex>
#include <sstream>


using namespace std;

Strona::Strona()
{
    //EMPTY BODY
}

Strona ::~Strona()
{
    //EMPTY BODY
}

string Strona::UsunZnakiSpecjalneZeStrony(string tekst_strony)
{
    regex reg(R"([\n])");
    string tekst_strony_bez_znakow_specjalnych=regex_replace(tekst_strony, reg, R"()");
    reg=(R"([\r])");
    tekst_strony_bez_znakow_specjalnych = regex_replace(tekst_strony_bez_znakow_specjalnych, reg, R"()");
    
    return tekst_strony_bez_znakow_specjalnych;
}

StronaSpecyficzna::StronaSpecyficzna()
{
    //EMPTY BODY
}

StronaSpecyficzna::~StronaSpecyficzna()
{
    //EMPTY BODY
}

void StronaSpecyficzna::set_zbior_firm_ze_strony(string tekst_strony)
{
    string tekst_strony_bez_znakow_specjalnych = UsunZnakiSpecjalneZeStrony(tekst_strony);
    zbior_firm_ze_strony_ = WyluskajFirmyZeStronyWWW(tekst_strony_bez_znakow_specjalnych);
}

vector<SpecyficznaFirma> StronaSpecyficzna::get_zbior_firm_ze_strony()
{
    return zbior_firm_ze_strony_;
}

void StronaSpecyficzna::WyswietlStrone()
{
    vector<SpecyficznaFirma> zbior_firm_strony = get_zbior_firm_ze_strony();

    for (unsigned int it_int_kom = 0; it_int_kom < zbior_firm_strony.size(); it_int_kom++)
    {
        zbior_firm_strony[it_int_kom].WyswietlNazweAdresMailFirmy();
        cout << endl;	
    }
}

vector<SpecyficznaFirma> StronaSpecyficzna::WyluskajFirmyZeStronyWWW(string tekst_strony)
{
    regex reg_element_listy_html(R"(<li cnt=\"[1-9]+\".+?</li>)");
    sregex_iterator it(tekst_strony.begin(), tekst_strony.end(), reg_element_listy_html);
    sregex_iterator reg_end_it;
    SpecyficznaFirma pojedyncza_firma;
    vector<SpecyficznaFirma> zbior_firm;
    
    for (; it != reg_end_it; it++)
    {
        pojedyncza_firma.set_mail_firmy(it->str());
        pojedyncza_firma.set_nazwa_firma(it->str());
        pojedyncza_firma.set_adres_firmy(it->str());
        zbior_firm.push_back(pojedyncza_firma);
    }
    
    return zbior_firm;
}