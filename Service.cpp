#include "Service.h"

Service::Service() {
	RepoFile repo;
}

Service::Service(const RepoFile& r) {
	repo = r;
}

Service::~Service() {
}

void Service::setRepo(const RepoFile& r) {
	repo = r;
}

void Service::addCarService(Car& p) {
	repo.addCar(p);
}

int Service::deleteCarService(Car& p) {
	if (strcmp(p.getStatus(), "taken") == 0) return 2;
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

