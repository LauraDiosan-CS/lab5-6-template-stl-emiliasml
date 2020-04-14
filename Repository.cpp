#include "Repository.h"

Repository::Repository()
{
}

void Repository::addCar(Car car)
{
	repo.push_back(car);
}

int Repository::delCar(Car car)
{
	list<Car>::iterator it;
	it = find(repo.begin(), repo.end(), car);
	if (it != repo.end()) {
		repo.erase(it);
		return 0;
	}
	return -1;
}

int Repository::findCar(Car car)
{
	list <Car>::iterator it;
	it = find(repo.begin(), repo.end(), car);
	if (it != repo.end())
		return distance(repo.begin(), it);
	return -1;
}

int Repository::updateCar(Car car, const char* name, const char* nr, const char* status)
{
	list <Car>::iterator it;
	it = find(repo.begin(), repo.end(), car);
	if (it != repo.end()) {
		(*it).setName(name);
		(*it).setNr(nr);
		(*it).setStatus(status);
		return 0;
	}
	return -1;

}

list <Car> Repository::getAll()
{
	return repo;
}

int Repository::dim()
{
	return repo.size();
}

Repository::~Repository()
{
}