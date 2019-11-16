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
void TestSubstr();
void TestLength();
int main()
{  
    // Operators
    TestOutStream();
    TestEqualsOpetator();
    TestAssignmentOpetator();
    TestStrConcat();
    TestStrAssignConcat();
    TestNotEqualsOpetator();
    TestIndexOperator();

    // Functions
    TestClear();
    TestC_str();
    TestSubstr();
    TestLength();
    return 0;
}
using namespace std;
void TestOutStream(){
    char chars[] = "Hello World! from overlaoded \"<< Operator\"";
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
    char chars12[] = "Hallo ";//char
    std::string str12("Welt!");//std::string
    util::string str11(chars12);//util::string
    util::string str22(chars12);//util::string
    str22 = str22+chars12;
    assert(str22.length()== 12);
    util::string str33(str22);
    assert(str33.length()== 12);
    util::string str44("");
    str44 = str22+str12;
    PrintTestResult(str44.length()== 17, "+");

}

//+=
void TestStrAssignConcat(){
    char chars[] = "Hallo Welt!";//char
    std::string str("Welt!");//std::string
    util::string str1(chars);//util::string
    util::string str2(chars);//util::string
    str2+=chars;
    assert(str2.length()== 22);

    util::string str3(str1);
    str3 +=str2;
    assert(str3.length() == 33);
    str2+=str;
    PrintTestResult(str2.length()== 27, "+=");
}
void TestSubstr(){
    char chars1[] = "Hallo Welt!";
    util::string str(chars1);
    util::string str2(str.substr(6,5));
    assert(str2 == "Welt!" && str.length()== 5);
    cout<< "Successfully tested util::string::substr()"<<endl;
}
void TestLength(){
    char chars1[] = "Hallo Welt!";
    util::string str(chars1);
    util::string str2(str.c_str());
    assert(str.length()== 11);
    cout<< "Successfully tested util::string::length()"<<endl;
}
void TestC_str(){
    char chars1[] = "Hello World!";
    util::string str(chars1);
    util::string str2(str.c_str());
    assert(str2.length()== 12);
    cout<< "Successfully tested util::string::c_str()"<<endl;
}
void TestClear(){
    char chars[] = "Hello World!";
    util::string str2(chars);
    assert(str2.length() == 12);
    str2.clear();
    assert(str2.length() == 0);
    cout<< "Successfully tested util::string::clear()"<<endl;
}


void PrintTestResult(bool isTrue, std::string str){
    std::string info(isTrue ? "Successfully tested:     ": "Failed test of:     ");
    cout<<info<<"\""<< str <<"\" operator."<<endl;
}

