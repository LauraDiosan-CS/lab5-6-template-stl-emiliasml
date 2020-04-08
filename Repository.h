
#pragma once
#include<iostream>
#include<list>
#include<iterator>
#include<string>
#include"Car.h"
using namespace std;

class Repository
{
private:
	list <Car> repo;
public:
	Repository();
	void addCar(Car);
	int delCar(Car);
	int findCar(Car);
	int updateCar(Car, const char*, const char*, const char*);
	list <Car> getAll();
	int dim();
	~Repository();
};