#include "Car.h"
#include <sstream>
#include <string.h>

//Constructors
Car::Car()
{
	name = NULL;
	nr = NULL;
	status = NULL;
}

Car::Car(const char* n, const char* p, const char* s)
{
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
	this->nr = new char[strlen(p) + 1];
	strcpy_s(this->nr, strlen(p) + 1, p);
	this->status = new char[strlen(s) + 1];
	strcpy_s(this->status, strlen(s) + 1, s);
}

Car::Car(const Car& car)
{
	this->name = new char[strlen(car.name) + 1];
	strcpy_s(this->name, strlen(car.name) + 1, car.name);
	this->nr = new char[strlen(car.nr) + 1];
	strcpy_s(this->nr, strlen(car.nr) + 1, car.nr);
	this->status = new char[strlen(car.status) + 1];
	strcpy_s(this->status, strlen(car.status) + 1, car.status);
}

Car::Car(string linie)
{
	std::istringstream iss(linie);
	string tok1, tok2, tok3;
	iss >> tok1 >> tok2 >> tok3;
	name = new char[tok1.length() + 1];
	strcpy_s(name, tok1.length() + 1, tok1.c_str());
	nr = new char[tok1.length() + 1];
	strcpy_s(nr, tok1.length() + 1, tok1.c_str());
	status = new char[tok1.length() + 1];
	strcpy_s(status, tok1.length() + 1, tok1.c_str());
}


//getters
char* Car::getName()
{
	return name;
}
char* Car::getNr()
{
	return nr;
}
char* Car::getStatus()
{
	return status;
}


//setters
void Car::setName(const char* n)
{
	if (name) delete[] name;
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}
void Car::setNr(const char* p)
{
	if (nr) delete[] nr;
	nr = new char[strlen(p) + 1];
	strcpy_s(nr, strlen(p) + 1, p);
}
void Car::setStatus(const char* s)
{
	if (status) delete[] status;
	status = new char[strlen(s) + 1];
	strcpy_s(status, strlen(s) + 1, s);
}


//operator =
Car& Car::operator=(const Car& car)
{
	if (this == &car) return *this;
	if (car.name)
	{
		if (name) delete[] name;
		name = new char[strlen(car.name) + 1];
		strcpy_s(name, strlen(car.name) + 1, car.name);
	}
	if (car.nr)
	{
		if (nr) delete[] nr;
		nr = new char[strlen(car.nr) + 1];
		strcpy_s(nr, strlen(car.nr) + 1, car.nr);
	}
	if (car.status)
	{
		if (status) delete[] status;
		status = new char[strlen(car.status) + 1];
		strcpy_s(status, strlen(car.status) + 1, car.status);
	}
	return *this;
}

//operator ==
bool Car::operator==(const Car& car)
{
	return(strcmp(name, car.name) == 0) and (strcmp(nr, car.nr) == 0) and \
		(strcmp(status, car.status) == 0);
}

//Deconstructor
Car::~Car()
{
	if (name) delete[] name;
	name = NULL;
	if (nr) delete[] nr;
	nr = NULL;
	if (status) delete[] status;
	status = NULL;
}

//operator << (print a car)
ostream& operator<<(ostream& os, Car car)
{
	os << car.getName() << " " << car.getNr() << " " << car.getStatus() << endl;
	return os;
}

//operator >> (read a car)
istream& operator>>(istream& is, Car& car)
{
	cout << endl << "name=";
	char* name = new char[10];
	is >> name;
	cout << endl << "nr=";
	char* nr = new char[9];
	char* status = new char[10];
	is >> nr;
	cout << endl << "status=";
	is >> status;
	car.setName(name);
	car.setNr(nr);
	car.setStatus(status);
	delete[]status;
	delete[]nr;
	delete[]name;
	return is;
}
