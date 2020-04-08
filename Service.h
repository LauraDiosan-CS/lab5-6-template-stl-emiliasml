#pragma once
#include "Repository.h"
#include "Car.h"

class Service {
private:
	Repository repo;
public:
	Service();
	Service(const Repository&);
	void setRepo(const Repository&);
	void addCarService(Car&);
	int deleteCarService(Car&);
	int findCarService(Car);
	int updateCarService(Car, const char*, const char*, const char*);
	list <Car> getAllCar();
	int dimCar();
	~Service();
};