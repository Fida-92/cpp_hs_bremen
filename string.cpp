// Author: Ahmadi, Fida
// MatrikelNummer: 50101292
#include "string.h"
bool areEqual(const char* lhs,const char* rhs);
int length_char(const char* characters);
util::string::string():len(this->DEFAULT_SIZE), chars(new char[len]){
}

util::string::~string(){
    delete[] this->chars;
}

util::string::string(const char* characters) :len(util::string::DEFAULT_SIZE), chars(new char[len])
{
    if(characters){
        unsigned n_chars=  length_char(characters);
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

util::string::string(const std::string& str){
    this->len = str.length();
    this->chars  = new char[len];
    this->strcpy(this->chars,str.c_str());
}
int util::string::length() const{
    if (chars) {
        unsigned n_chars = length_char(chars);
        return n_chars;
    }
    return 0;
}

void util::string::clear(){
    if (chars) {
        chars[0]= '\0';
    }
}
const util::string util::string::substr(int pos,int length) {
    char* tmp = new char[length];
    if (pos + length > this->length()) {
        tmp[0]='\0';
        this->chars= tmp;
        return *this;
    }
    for (int var = pos; var < pos+length; var++) {
        tmp[var-pos] = chars[var];
    }
    this->chars = tmp;
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
    int totalLen = this->length() + str.length();
    char* charactersArr = new char[totalLen];
    this->strcpy(charactersArr,this->chars);
    for (int j=0; j < str.length(); j++){
        charactersArr[this->length()+j] = str.chars[j];
    }
    delete []chars;
    this->len = totalLen;
    this->chars = charactersArr;
    return *this;
}
// +=
util::string util::string::operator+=(const char* chararacters){
    this->strcat(chars,chararacters);
    return *this;
}
// +=
util::string util::string::operator+=(const std::string& s ){
    this->strcat(chars,s.c_str());
    return *this;
}

//==
bool util::operator== (const string& lhs, const string& rhs){
    return  areEqual(lhs.c_str(),rhs.c_str());
}
//==
bool util::operator== (const string& lhs, const char* characters){
    return  areEqual(lhs.c_str(),characters);
}
//==
bool util::operator== (const util::string& lhs, const std::string& rhs ){
    return areEqual(lhs.c_str(),rhs.c_str());
}
//==
bool util::operator== (const char* lhs,const string& rhs ){
    return areEqual(lhs,rhs.c_str());
}
//==
bool util::operator== (const std::string& lhs ,const string& rhs){
    return areEqual(lhs.c_str(),rhs.c_str());
}

// !=
bool util::operator!= (const string& lhs, const string& rhs){
    return !(lhs == rhs);
}
// !=
bool util::operator!= (const string& lhs, const char* rhs){
    return !(lhs == rhs);
}
// !=
bool util::operator!= (const util::string& lhs, const std::string& rhs ){
    return !(lhs == rhs);
}
bool util::operator!= (const char* lhs,const string& rhs){
    return !(lhs == rhs);
}
bool util::operator!= (const std::string& lhs,const string& rhs){
    return !(lhs == rhs);
}
//[]
char util::string::operator[] (unsigned int index) const{
    return chars[index];
}
// <<
std::ostream& util::operator<< (std::ostream& os, const util::string& str){
    if (str.length() > 0)
    {
        for (int index=0; index < str.length(); index++)
            os << str[index];
    } else os << "";
    return os;
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


int  length_char(const char* characters){
    unsigned n_chars=0;
    while (characters[n_chars] !='\0') {
        n_chars++;
    }
    return n_chars;
}
/**
 * @brief areEqual compares to char*-array
 * @param lhs
 * @param rhs
 * @return true if equal
 */
bool  areEqual(const char* lhs,const char* rhs){
    int lhs_length= length_char(lhs);
    int rhs_length= length_char(rhs);
    int index = 0;
    if (lhs_length != rhs_length) {
        return false;
    }
    while (index < lhs_length){
        if ( lhs[index] != rhs[index]) {
            return false;
        }
        index++;
    }
    return true;
}

