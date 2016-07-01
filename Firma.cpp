#include <iostream>
#include <regex>
#include <string>
#include "Firma.h"

using namespace std;

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

