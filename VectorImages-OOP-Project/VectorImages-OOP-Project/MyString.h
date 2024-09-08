#include<iostream>
#pragma once
class MyString
{
private:
    char* string;
    size_t size;
public:
    MyString();
    MyString(const char*);

    MyString(const MyString&);
    MyString& operator=(const MyString&);
    ~MyString();

    size_t getSize() const;

    const char* c_str() const;

    char& operator[](size_t);
    const char& operator[](size_t) const;

    friend std::ostream& operator<<(std::ostream&, const MyString&);
    friend std::istream& operator>>(std::istream&, MyString&);
private:
    void free();
    void copyFrom(const MyString& other);
};


bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
