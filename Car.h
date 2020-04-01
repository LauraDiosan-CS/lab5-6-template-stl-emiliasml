#pragma once
#include <string>
#include <iostream>
using namespace std;

//Masina(numePosesor, nrInmatriculare, status)
class Car {
private:
	char* name;
	int nr;
	char* status;
public:
	Car();
	Car(const char*, int, const char*);
	Car(const Car&);
	char* getName();
	int getNr();
	char* getStatus();
	void setName(const char*);
	void setNr(int);
	void setStatus(const char* );
	Car& operator=(const Car&);
	bool operator==(const Car&);
	friend ostream& operator<<(ostream& os, Car c);
	friend istream& operator>>(istream&, Car&);
	Car(string);
	~Car();
};