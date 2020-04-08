#include "RepoFile.h"
#include <fstream>
#include <string>
using namespace std;

RepoFile::RepoFile()
{
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


