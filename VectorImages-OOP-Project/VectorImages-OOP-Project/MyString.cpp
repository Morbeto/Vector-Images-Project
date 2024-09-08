#include "MyString.h"
#pragma warning (disable : 4996)

MyString::MyString() {
	string = new char[strlen("unknown") + 1];
	strcpy(string, "unknown");
	string[strlen("unknown")] = '\0';
	size = 8;
}

MyString::MyString(const char* _string) {

	string = new char[strlen(_string) + 1];
	strcpy(string, _string);
	string[strlen(_string)] = '\0';
	size = strlen(_string);
}

MyString::MyString(const MyString& m) {
	free();
	copyFrom(m);
}

MyString& MyString::operator=(const MyString& m) {
	if (this != &m) {
		free();
		copyFrom(m);
	}
	return *this;
}

MyString::~MyString() {
	free();
}

const char* MyString::c_str() const {
	return string;
}

size_t MyString::getSize() const {
	return size;
}

char& MyString::operator[](size_t index) {

	return string[index];
}

const char& MyString::operator[](size_t index) const {

	return string[index];
}

std::ostream& operator<<(std::ostream& os, const MyString& m) {
	os << m.string;
	return os;
}

std::istream& operator>>(std::istream& is, MyString& m) {
	char string[1024];
	is >> string;
	size_t size = strlen(string);

	if (m.string != nullptr) {
		delete[] m.string;
		m.string = new char[size + 1];
		strcpy(m.string, string);
		m.string[size] = '\0';
	}
	return is;
}

void MyString::free() {
	delete[] string;
	string = nullptr;
	size = 0;
}

void MyString::copyFrom(const MyString& m) {
	string = new char[strlen(m.string) + 1];
	strcpy(string, m.string);
	string[strlen(m.string)] = '\0';
	size = m.size;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) != 0;
}