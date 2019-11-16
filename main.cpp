// Author: Ahmadi, Fida
// MatrikelNummer: 50101292
#include "string.h"
#include <sstream>
#include <iostream>
#include "cassert"
//using namespace std;
void TestStrCat();
void TestClear();
void TestC_str();
void TestAssignmentOpetator();
void TestEqualsOpetator();
void TestOutStream();
int main()
{  
   // char chars[] = "Hallo Welt!";
   // util::string str(chars);
    //cout << str.c_str()[0]<<end
    TestOutStream();
    TestEqualsOpetator();
    return 0;
}
using namespace std;
void TestOutStream(){
    char chars[] = "Hallo Welt!";
    util::string str2(chars);
    std::stringstream strout;
    strout << str2;
    cout << strout.str()<< endl;

}
void TestEqualsOpetator(){
    char chars[] = "Hallo Welt!";
    char chars2[] = "Hallo Welt!";
    util::string str(chars);
    util::string str2(chars2);

     cout << (str2==str ) << endl;
   // assert( );
}
void TestAssignmentOpetator(){
    char chars[] = "Hallo Welt!";
    std::string str("Hallo");
    util::string str2(chars);
    //str2=str;
    assert(str2.length()== 5);
}
void TestC_str(){
    char chars1[] = "Hello World!";
    util::string str(chars1);
    util::string str2(str.c_str());

    assert(str.length()== 12);
    for (int var = 0; var < str.length(); ++var) {
        cout << str.c_str()[var]<<endl;
    }
}
void TestClear(){
    char chars[] = "Hello World!";
    util::string str2(chars);
    cout <<"Vor clear "<< str2.length() <<endl;
    assert(str2.length() == 12);
    str2.clear();
    assert(str2.length() == 0);
    cout <<"Nach clear "<< str2.length() <<endl;
}

//+=
void TestStrCat(){
    char chars[] = "Hallo";
    //char chars2[] = "world!";
    util::string str2(chars);
    std::string str("Sun shine");
    //str2+=str;
    cout<< "str2.length "<< str2.length() << endl;
}
