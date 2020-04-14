#include "Service.h"

Service::Service() {
	RepoFile repo;
	int X = 0, parked = 0, free = 0, extraParked = 0;
}

Service::Service(const RepoFile& r) {
	repo = r;
}

Service::~Service() {
	X = 0;
}

int Service::parkedSize(){
	return parked;
}

int Service::freeSize(){
	return free;
}

int Service::XSize(){
	return X;
}

int Service::extraParkedSize(){
	return extraParked;
}

void Service::exit(Car& c)
{
	if (strcmp(c.getStatus(), "free") == 0) 
		throw exception("Cannot exit because the car is not in the parking lot");
	repo.updateCar(c, c.getName(), c.getNr(), "free");
	free++;
	parked--;
	repo.saveToFile();
}

void Service::entry(Car& c)
{
	if (strcmp(c.getStatus(), "taken") == 0)
		throw exception("Cannot entry because the car is already in the parking lot");
	repo.updateCar(c, c.getName(), c.getNr(), "taken");
	parked++;
	free--;
	repo.saveToFile();
}

void Service::setNumbers(int newX, int newParked, int newFree, int newExtraParked)
{
	X = newX;
	parked = newParked;
	free = newFree;
	extraParked = newExtraParked;
}


void Service::setRepo(const RepoFile& r) {
	repo = r;
}

int Service::addCarService(Car& p) {
	list<Car> el;
	el = repo.getAll();
	list<Car>::iterator it;
	for (it = el.begin(); it != el.end(); ++it) {
		if (strcmp((*it).getNr(), p.getNr()) == 0) {
			throw exception("Duplicate number");
		}
	}
	return repo.addCar(p);
}

void Service::deleteCarService(Car& p) {
	if (strcmp(p.getStatus(), "taken") == 0)
		throw exception("Cannot delete a car from the parking lot");
	else if (repo.delCar(p) == -1) throw exception("The car doesn't exist!");
}

void Service::updateCarService(Car car, const char* name, const char* nr, const char* status){
	list<Car> el;
	el = repo.getAll();
	list<Car>::iterator it;
	for (it = el.begin(); it != el.end(); ++it) {
		if (strcmp((*it).getNr(), nr) == 0) {
			throw exception("Duplicate number");
		}
	}
	repo.updateCar(car, name, nr, status);
}

int Service::findCarService(Car car) {
	return repo.findEl(car);
}

list <Car> Service::getAllCar() {
	return repo.getAll();
}

int Service::dimCar() {
	return repo.dim();
}


