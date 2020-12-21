#include "Person.h"

Person::Person(const char* name, int id)
{
	strcpy(this->name, name);
	this->id = id;
}

Person::Person(const Person& other) 
{
	*this = other;
}

int Person::getId() const
{
	return this->id;
}

void Person::setId(int id)
{
	this->id = id;
}

const char* Person::getname() const
{
	return this->name;
}

void Person::setName(const char* name)
{
	strcpy(this->name, name);
}

const Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		strcpy(this->name, other.name);
		this->id = other.id;
	}
	return *this;
}