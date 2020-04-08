#pragma once
#include<iostream>
#include<string>
using namespace std;

class Car
{
private:
	char* name;
	char* nr;
	char* status;
public:
	Car();
	Car(const char*, const char*, const char*);
	Car(const Car&);
	Car(string);
	char* getName();
	char* getNr();
	char* getStatus();
	void setName(const char*);
	void setNr(const char*);
	void setStatus(const char*);
	Car& operator=(const Car&);
	bool operator==(const Car&);
	~Car();
	friend ostream& operator<<(ostream& os, Car car);
	friend istream& operator>>(istream& is, Car& car);
};