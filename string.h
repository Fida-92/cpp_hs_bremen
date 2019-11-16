/* Author: Ahmadi, Fida
 * MatrikelNummer: 50101292
 */

#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;
namespace util{
class string
{
private:
    // attributes
    unsigned len;
    char* chars;
public:
    const static int DEFAULT_SIZE=10;
    // declarations
    // ctors
    // for emtpy init
    string();
    ~string();
    // Copy-ctor (for deep Copy)
    string(const string& str);
    // ctor(const char *character)
    string(const char *characters);
    // std::string
    string (const std::string &str);
    // functions
    void clear();
    string substr(int,int);
    int length() const;
    const char* c_str() const;
     char* strcpy(char*, const char*);
     char* strcat(char*,const char*);
    // operators
    // 2nd param is this in member functions
    friend const string operator+(const string&, const string&);
    friend const string operator+(const string&, const char*);
    friend const string operator+(const string&, const std::string&) ;

    string operator+=(const util::string& s);
    string operator+=(const char* s);
    string operator+=(const std::string& s) ;

    string operator=(const string&);
    string operator=(const char*);
    string operator=(const std::string&);

    friend bool operator== (const string&, const  string&);
    friend bool operator== (const string&, const char*);
    friend bool operator== (const string&, const std::string&);
    friend bool operator== (const char*,const string&);
    friend bool operator== (const std::string&,const string&);

    friend bool operator!= (const string&, const string&);
    friend bool operator!= (const string&, const char*);
    friend bool operator!= (const string&, const std::string&);
    friend bool operator!= (const char*,const string&);
    friend bool operator!= (const std::string&,const string&);
    //[]
     char operator[] (unsigned int) const ;
    // <<
    friend std::ostream& operator<< (std::ostream&, const string&);

    friend int length_char(const char*);
    friend bool areEqual(const char*,const char*);
};
// Help Functions
int length_char(const char* characters){
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
bool areEqual(const char* lhs,const char* rhs){
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

}
#endif // STRING_H
