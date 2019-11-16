// Author: Ahmadi, Fida
// MatrikelNummer: 50101292
#include "string.h"
#include <sstream>
#include <iostream>
#include "cassert"
void TestAssignmentOpetator();
void TestStrConcat();
void TestStrAssignConcat();
void TestEqualsOpetator();
void TestOutStream();
void PrintTestResult(bool isTrue, std::string str);
void TestClear();
void TestC_str();
void TestNotEqualsOpetator();
void TestIndexOperator();
int main()
{  

    //TestAssignmentOpetator();
    // TestStrConcat();
    // TestStrAssignConcat();
    // TestC_str();
    //TestNotEqualsOpetator();
    TestIndexOperator();
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
// ==
void TestEqualsOpetator(){
    char chars[] = "Hallo Welt!";//char
    std::string str("Hallo Welt!");//std::string
    util::string str1(chars);//util::string
    util::string str2(chars);//util::string
    bool isEqual = str2 == chars? 1 : 0;
    assert(isEqual== 1);
    isEqual = str2 == str1? 1 : 0;
    assert(isEqual == 1);
    isEqual = str2 == str ? 1 : 0;
    assert(isEqual == 1);
    isEqual = chars == str2 ? 1 : 0;
    assert(isEqual == 1);
    isEqual = str == str2 ? 1 : 0;

    PrintTestResult(isEqual, "==");
}

// !=
void TestNotEqualsOpetator(){
    char chars[] = "Hallo ";//char
    std::string str("Welt!");//std::string
    util::string str1(str);//util::string
    util::string str2("Hello");//util::string
    bool isEqual = str2 == chars? 1 : 0;
    assert(isEqual== 0);
    isEqual = str2 == str1? 1 : 0;
    assert(isEqual == 0);
    isEqual = str2 == str ? 1 : 0;
    assert(isEqual == 0);
    isEqual = chars == str2 ? 1 : 0;
    assert(isEqual == 0);
    isEqual = str == str2 ? 0 : 1;

    PrintTestResult(isEqual, "!=");
}
// Testing []
void TestIndexOperator(){
    char chars[] = "Hello World!";
    assert(chars[0]== 'H');
    PrintTestResult(chars[11]== '!', "[]");
}
// Testing =
void TestAssignmentOpetator(){
    char chars[] = "Hallo Welt!";//char
    std::string str("Hallo");//std::string
    util::string str1(chars);//util::string
    util::string str2(chars);//util::string
    str2=chars;
    assert(str2.length()== 11);
    str2=str1;
    assert(str2.length()== 11);
    str2=str;
    PrintTestResult(str2.length()== 5, "=");
}

// Testing +
void TestStrConcat(){
    char chars[] = "Hallo ";//char
    std::string str("Welt!");//std::string
    util::string str1(chars);//util::string
    util::string str2(chars);//util::string
    str2 = str2+chars;
    assert(str2.length()== 12);
    str2 = str2+str1;
    assert(str2.length()== 18);
    str2 = str2+str;
    PrintTestResult(str2.length()== 23, "+");
}

//+=
void TestStrAssignConcat(){
    char chars[] = "Hallo ";//char
    std::string str("Welt!");//std::string
    util::string str1(chars);//util::string
    util::string str2(chars);//util::string
    str2+=chars;
    assert(str2.length()== 12);
    str2+=str1;
    assert(str2.length()== 18);
    str2+=str;
    PrintTestResult(str2.length()== 23, "+=");
}

void TestC_str(){
    char chars1[] = "Hello World!";
    util::string str(chars1);
    util::string str2(str.c_str());
    assert(str2.length()== 12);
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


void PrintTestResult(bool isTrue, std::string str){
    std::string info(isTrue ? "Successfully tested:     ": "Failed test of:     ");
    cout<<info<<"\""<< str <<"\" operator."<<endl;
}

