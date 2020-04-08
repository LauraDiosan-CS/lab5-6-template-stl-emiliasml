#include "Service.h"

Service::Service() {
	Repository repo;
}

Service::Service(const Repository& r) {
	repo = r;
}

Service::~Service() {
}

void Service::setRepo(const Repository& r) {
	repo = r;
}

void Service::addCarService(Car& p) {
	repo.addCar(p);
}

int Service::deleteCarService(Car& p) {
	return repo.delCar(p);
}

int Service::updateCarService(Car car, const char* name, const char* nr, const char* status){
	return repo.updateCar(car, name, nr, status);
	
}

int Service::findCarService(Car car) {
	return repo.findCar(car);
}

list <Car> Service::getAllCar() {
	return repo.getAll();
}

int Service::dimCar() {
	return repo.dim();
}

