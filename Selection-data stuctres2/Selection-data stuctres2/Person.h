#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning (disable:4996)

const int MAX_SIZE = 20;

class Person
{
private:
	char name[MAX_SIZE];
	int id;

public:
	Person()=default;
	Person(const char* name,int id);
	Person(const Person& other);
	
	int getId() const;
	void setId(int id);

	const char* getname() const;
	void setName(const char* name);

	const Person& operator=(const Person& other);
};

#endif // !_PERSON_H