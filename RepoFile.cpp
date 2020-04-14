#include <fstream>
#include <string>
#include "RepoFile.h"
using namespace std;

RepoFile::RepoFile()
{
	fis = "";
}

RepoFile::RepoFile(const char* fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* nume = new char[10];
	char* nr = new char[10];
	char* status = new char[9];
	while (!f.eof()) {
		f >> nume >> nr >> status;
		if (nume != ""/* && nr != "" && status != ""*/) {
			Car c(nume, nr, status);
			repo.push_back(c);
		}
	}
	delete[] status;
	delete[] nr;
	delete[] nume;
	f.close();
}

void RepoFile::loadFromFile(const char* fileName)
{
	repo.clear();
	fis = fileName;
	ifstream f(fileName);
	char* nume = new char[10];
	char* nr = new char[10];
	char* status = new char[9];
	while (!f.eof()) {
		f >> nume >> nr >> status;
		if (nume != "" && nr != "" && status != "") {
			Car c(nume, nr, status);
			repo.push_back(c);
		}
	}
	delete[] status;
	delete[] nr;
	delete[] nume;
	f.close();
}

void RepoFile::saveToFile()
{
	ofstream f(fis);
	list <Car> carsRepo;
	list <Car>::iterator it;
	carsRepo = repo;
	for (it = carsRepo.begin(); it != carsRepo.end(); it++)
		f << (*it).getName() << " " << (*it).getNr() << " " << (*it).getStatus() <<" ";
	f.close();
}

RepoFile::~RepoFile()
{
}

int RepoFile::addCar(Car c) {
	list<Car>::iterator it;
	int ok = 1;
	for (it = repo.begin(); it != repo.end(); it++)
		if (strcmp((*it).getNr(), c.getNr()) == 0)
			ok = 0;
	it = find(repo.begin(), repo.end(), c);
	if (it == repo.end() and ok == 1)
	{
		repo.push_back(c);
		saveToFile();
		return 1;
	}
	return 0;
}

int RepoFile::delCar(Car c) {
	list<Car>::iterator it;
	it = find(repo.begin(), repo.end(), c);
	if (it != repo.end())
	{
		repo.erase(it);
		saveToFile();
		return 0;
	}
	else
		return -1;
}
void RepoFile::updateCar(Car car, const char* name, const char* nr, const char* status)
{
	list <Car>::iterator it;
	it = find(repo.begin(), repo.end(), car);
	if (it != repo.end()) {
		(*it).setName(name);
		(*it).setNr(nr);
		(*it).setStatus(status);
		saveToFile();
	}
}

list<Car> RepoFile::getAll()
{
	return repo;
}

int RepoFile::dim()
{
	return repo.size();
}


