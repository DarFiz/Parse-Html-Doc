#include <iostream>
#include <regex>
#include <sstream>
#include "Strona.h"

using namespace std;

string Strona::UsunZnakiSpecjalneZeStrony(string tekst_strony)
{
    regex reg(R"([\n])");
    string tekst_strony_bez_znakow_specjalnych = regex_replace(tekst_strony, reg, R"()");
    reg=(R"([\r])");
    tekst_strony_bez_znakow_specjalnych = regex_replace(tekst_strony_bez_znakow_specjalnych, reg, R"()");
    
    return tekst_strony_bez_znakow_specjalnych;
}
