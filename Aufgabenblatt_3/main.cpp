/* Author: Ahmadi, Fida
 * MatrikelNummer: 50101292
 */
#include <iostream>
#include "string.h"
using namespace std;
void TestStrcat();
int main()
{

    //char chars[] = "Moin";
    char chars2[] = "Test fff Test";
    util::string str2(chars2);
    util::string str3(str2);
     ;
    str2 +=str2;
    //str2.strcat(chars2,chars);

   // str2 +=chars2;
    cout <<"Vor clear "<< str2.length() <<endl;

    str2.clear();

    cout <<"Nach clear "<< str2.length() <<endl;

    // cout << "Hello World!" << "\n"<< chars << endl;
    return 0;
}

void TestStrcat(){
    char chars[] = "Moin ";
     char chars2[] = "Test fff Test";
    util::string str2(chars);
     str2.strcat(chars,chars2);
}
