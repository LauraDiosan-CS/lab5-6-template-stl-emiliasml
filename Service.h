#pragma once
#include "RepoFile.h"
#include "Car.h"

class Service {
private:
	RepoFile repo;
	int X, parked, free, extraParked;
	//free - locurile din parcare libere
	//parked - masini in parcare
	//extraParked - masini cu status "parked" care nu au loc in parcare
public:
	Service();
	Service(const RepoFile&);
	void setRepo(const RepoFile&);
	int addCarService(Car&);
	void deleteCarService(Car&);
	int findCarService(Car);
	void updateCarService(Car, const char*, const char*, const char*);
	list <Car> getAllCar();
	int dimCar();
	~Service();
	int parkedSize();
	int freeSize();
	int XSize();
	int extraParkedSize();
	void exit(Car& c);
	void entry(Car& c);
	void setNumbers(int, int, int, int);
};