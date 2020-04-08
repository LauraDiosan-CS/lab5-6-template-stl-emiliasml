#pragma once
#include "RepoFile.h"
#include "Car.h"

class Service {
private:
	RepoFile repo;
public:
	Service();
	Service(const RepoFile&);
	void setRepo(const RepoFile&);
	void addCarService(Car&);
	int deleteCarService(Car&);
	int findCarService(Car);
	int updateCarService(Car, const char*, const char*, const char*);
	list <Car> getAllCar();
	int dimCar();
	~Service();
};