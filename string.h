// Author: Ahmadi, Fida
// MatrikelNummer: 50101292
#ifndef STRING_H
#define STRING_H
#include <iostream>
namespace util{
class string
{
private:
    // attributes
    unsigned len;
    char* chars;
public:
    const static int DEFAULT_SIZE=10;
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
    const string substr(int,int);
    int length() const;
    const char* c_str() const;
    char* strcpy(char*, const char*);
    char* strcat(char*,const char*);
    // operators
    string operator+=(const util::string& s);
    string operator+=(const char* s);
    string operator+=(const std::string& s) ;

    string operator=(const string&);
    string operator=(const char*);
    string operator=(const std::string&);

    friend const string operator+(const string&, const string&);
    friend const string operator+(const string&, const char*);
    friend const string operator+(const string&, const std::string&) ;
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
};

}
#endif // STRING_H
