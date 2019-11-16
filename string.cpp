/* Author: Ahmadi, Fida
 * MatrikelNummer: 50101292
 */

#include "string.h"
#include <iostream>
util::string::string():len(this->DEFAULT_SIZE), chars(new char[len]){
}

util::string::~string(){
    delete[] this->chars;
    cout << "~string"<<endl;
}

util::string::string(const char* characters) :len(util::string::DEFAULT_SIZE), chars(new char[len])
{
    if(characters){
        unsigned n_chars= util::length_char(characters);
        // if the length of characters is too big
        if (n_chars > this->DEFAULT_SIZE) {
            this->len = n_chars;
            this->chars = new char[n_chars];
        }
        this->strcpy(chars,characters);
    }
}
util::string::string(const string& str){
    this->len = str.length();
    this->chars  = new char[len];
    this->strcpy(chars,str.chars);
}

int util::string::length() const{
    if (chars) {
        unsigned n_chars = util::length_char(chars);
        return n_chars;
    }
    return 0;
}

void util::string::clear(){
    if (chars) {
        chars[0]= '\0';
    }
}
util::string util::string::substr(int pos,int length){
    char* tmp = new char[length];
    if (pos + length > this->length()) {
        tmp[0]='\0';
        this->chars= tmp;
        cout << "Index(pos + length > chars.length) is out of bound"<< endl;
        return *this;
    }
    cout <<"before substr "<< this->length()<<endl;
    for (int var = pos; var < pos+length; var++) {
        tmp[var-pos] = chars[var];
    }
    this->chars=tmp;
    cout<< "after substr " << this->length()<< endl;
    return *this;
}

// Operators:

//+
const util::string util::operator+(const string& lhs, const string& rhs){

    return string(lhs)+=rhs;
}
//+
const util::string util::operator+(const string& lhs, const char* rhs){
    return string(lhs)+=rhs;

}
//+
const util::string util::operator+(const string& lhs, const std::string& rhs){
    return string(lhs)+=rhs;
}

// =
util::string util::string::operator=(const char* characters){
    if (this->len > this->DEFAULT_SIZE) {
        delete []this->chars;
        this->chars = new char[len];
    }
    this->strcpy(chars,characters);
    return *this;
}
// =
util::string util::string::operator=(const string& str){

    if (this == &str ) {
        return *this;
    }

    if ((int)str.length() > this->length()) {
        this->len = str.length();
        delete []this->chars;
        chars = new char[len];
    }
    this->strcpy(chars,str.c_str());
    return *this;
}
// =
util::string util::string::operator=(const std::string& str){
    if ((int) str.length() > this->length()) {
        delete []this->chars;
        this->len = str.length();
        chars = new char[this->len];
    }
    this->strcpy(chars,str.c_str());
    return *this;
}
// +=
util::string util::string::operator+=(const string& str){
    int totalLen = len + str.length();
    char* charactersArr = new char[totalLen];
    this->strcpy(charactersArr,this->chars);
    for (int j=0; j < str.length(); j++){
        charactersArr[len+j] = str.chars[j];
    }
    cout << "Total length "<< str.length() << "+"<< this->length();
    delete []chars;
    len = totalLen;
    this->chars = charactersArr;
    return *this;
}
// +=
util::string util::string::operator+=(const char* chararacters){
    cout <<"Length before += " <<this->length() << endl;
    this->strcat(chars,chararacters);
    cout <<"Length after += "<< this->length()<<endl;
    return *this;
}
// +=
util::string util::string::operator+=(const std::string& s ){
    cout <<"std::string before += " <<this->length() << endl;
    this->strcat(chars,s.c_str());
    cout <<"after += "<< this->length()<<endl;
    return *this;
}

//==
bool util::operator== (const string& lhs, const string& rhs){
    return util::areEqual(lhs.c_str(),rhs.c_str());
}
//==
bool util::operator== (const string& lhs, const char* characters){
    return util::areEqual(lhs.c_str(),characters);
}
//==
bool util::operator== (const util::string& lhs, const std::string& rhs ){
    return util::areEqual(lhs.c_str(),rhs.c_str());
}
//==
bool util::operator== (const char* lhs,const string& rhs ){
    return util::areEqual(lhs,rhs.c_str());
}
//==
bool util::operator== (const std::string& lhs ,const string& rhs){
    return util::areEqual(lhs.c_str(),rhs.c_str());
}

//!=
bool util::operator!= (const string& lhs, const string& rhs){
    return !(lhs == rhs);
}
//!=
bool util::operator!= (const string& lhs, const char* rhs){
    return !(lhs == rhs);
}
//!=
bool util::operator!= (const util::string& lhs, const std::string& rhs ){
    return !(lhs == rhs);
}

//[]
char util::string::operator[] (unsigned int index) const{
    return chars[index];
}

// Help Functions

char* util::string::strcpy(char * dest, const char* src){
    if((NULL != dest) && (NULL != src))
    {
        while ('\0' != *src)
        {
            *dest++ = *src++;
        }
        *dest = '\0';
    }
    return dest;
}

char* util::string::strcat(char* dest,const char * src){
    if((NULL != dest) && (NULL != src))
    {
        while('\0' != *dest)
        {
            dest++;
        }
        while('\0' != *src)
        {
            *dest++ = *src++;
        }
        *dest = '\0';
    }

    return dest;
}

const char* util::string::c_str() const {
    return this->chars;
}
