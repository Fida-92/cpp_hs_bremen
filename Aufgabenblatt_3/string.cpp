/* Author: Ahmadi, Fida
 * MatrikelNummer: 50101292
 */

#include "string.h"
#include <iostream>


util::string::string():len(10), chars(new char[len]){
}

util::string::~string(){
    //  delete[] chars;
}

util::string::string(const char* characters) :len(10), chars(new char[len])
{
    if(characters){
        unsigned n_chars= length(characters);
        // falls characters zu groß
        if (n_chars > len) {
            len = n_chars;
        }

        chars = new char[n_chars];
        for ( unsigned i = 0; i < n_chars; ++i) {
            chars[i]= characters[i];
        }
    }
}
util::string::string(const string& str){

    len = str.length();
    chars  = new char[len];
    for (unsigned j=0; j < len; j++)
        chars[j] = str.chars[j];
    //cout << str.chars << length()<< endl;
}
int util::string::length() const{

    if (chars) {
        unsigned n_chars=length(chars);
        return n_chars;
    }
    return 0;
}

int util::string::length(const char* characters) const{

    unsigned n_chars=0;
    while (characters[n_chars] !='\0') {
        n_chars++;
    }
    return n_chars;
}

void util::string::clear(){
    if (chars) {
        // das 1. Zeichen auf \0
        chars[0]= '\0';
    }
}
util::string util::string::substr(int pos,int length){
    //char* tmp[] = new char[10];

    // util::string str(chars);
    return *this;
}

// Operators:
// =
util::string util::string::operator= (const char* str){

    delete []chars;
    // len = util::string::length();
    chars = new char[len];
    for ( unsigned i = 0; i < len; ++i) {
        chars[i]= str[i];
    }
    return *this;
}
// +=
util::string util::string::operator+=(const string& str){
    int totalLen = len + str.length();
    char* charactersArr = new char[totalLen];

    for (unsigned i=0; i < len; i++){
        charactersArr[i] = chars[i];
    }
    for (int j=0; j < str.length(); j++){
        charactersArr[len+j] = str.chars[j];
    }
    delete chars;
    len = totalLen;
    chars   = charactersArr;
    cout << "str " << str.length() << len <<endl;
    return *this;
}
// +=
util::string util::string::operator+=(const char* chararacters){
    strcat(chars,chararacters);
    return *this;
}

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
    return chars;
}
