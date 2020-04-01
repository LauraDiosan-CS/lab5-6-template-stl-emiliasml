#include "Car.h"
#include <string.h>
#include <sstream>
#include <iostream>
//Masina(numePosesor, nrInmatriculare, status)


// constructor
Car::Car() {
	name = NULL;
	nr = 0;
	status = NULL;
}

// constructor with parameters
Car::Car(const char* name, int nr, const char* status) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->nr = nr;
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);
}

// copy constructor
Car::Car(const Car& c) {
	this->name = new char[strlen(c.name + 1)];
	strcpy_s(this->name, strlen(c.name) + 1, c.name);
	this->nr = c.nr;
	this->status = new char[strlen(c.status + 1)];
	strcpy_s(this->status, strlen(c.status) + 1, c.status);
	cout << "ok";

}

//getters
char* Car::getName() {
	return name;
}
int Car::getNr() {
	return nr;
}
char* Car::getStatus() {
	return status;
}

//setters

void Car::setName(const char* n) {
	if (name) delete[]name;
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}
void Car::setNr(int n) {
	nr = n;
}
void Car::setStatus(const char* s) {
	if (status) delete[]status;
	status = new char[strlen(s) + 1];
	strcpy_s(status, strlen(s) + 1, s);
}

Car& Car::operator=(const Car& c) {
	if (this == &c) return *this;
	if (name) delete[] name;
	name = new char[strlen(c.name) + 1];
	strcpy_s(name, strlen(c.name) + 1, c.name);
	nr = c.nr;
	if (status) delete[] status;
	status = new char[strlen(c.status) + 1];
	strcpy_s(status, strlen(c.status) + 1, c.status);
	return *this;
}

bool Car::operator==(const Car& c) {
	return (strcmp(name, c.name) == 0)  and (nr == c.nr) and (strcmp(status, c.status) == 0);
}

//to string 
Car::Car(string linie) {
	std::istringstream iss(linie);
	string tok1, tok2, tok3;
	iss >> tok1 >> tok2 >> tok3;
	name = new char[tok1.length() + 1];
	strcpy_s(name, tok1.length() + 1, tok1.c_str());
	nr = stoi(tok2);
	status = new char[tok3.length() + 1];
	strcpy_s(status, tok3.length() + 1, tok3.c_str());
}

//deconstructor
Car::~Car() {
	if (name) delete[]name;
	name = NULL;
	nr = 0;
	if (status) delete[]status;
	status = NULL;
}

ostream& operator<<(ostream& os, Car c) {
	os << c.name << " " << c.nr << " " << c.status << endl;
	return os;
}

istream& operator>>(istream& is, Car& c) {
	cout << "Name:";
	char* name = new char[20];
	is >> name;
	cout << "Nr:";
	int nr;
	cin >> nr;
	cout << "Status(free, taken):";
	char* status = new char[6];
	cin >> status;
	c.setName(name);
	c.setNr(nr);
	c.setStatus(status);
	delete[]status;
	delete[]name;
	return is;
}
