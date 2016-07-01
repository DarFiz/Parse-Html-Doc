#include <fstream>
#include "Firma.h"
#include "Strona.h"
#include "SpecyficznaStrona.h"

using namespace std;

int main(int argc, char* argv[])
{
    std::ifstream ifs("strona.html");
    std::string tekst_strony( (std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()) );

    SpecyficznaStrona strona_pojedyncza;
    strona_pojedyncza.set_zbior_firm_ze_strony(tekst_strony);
    strona_pojedyncza.WyswietlStrone();
    
    return 0;
}
