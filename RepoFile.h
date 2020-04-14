#pragma once
//#include "Repository.h"
#include "RepoTemplate.h"
#include "Car.h"
class RepoFile :
	//public Repository
	public RepoTemplate<Car>
{
private:
	const char* fis;
public:
	RepoFile();	
	RepoFile(const char* fileName);
	void loadFromFile(const char* fileName);
	void saveToFile();
	~RepoFile();
	int addCar(Car);
	int delCar(Car);
	void updateCar(Car, const char*, const char*, const char*);
	list <Car> getAll();
	int dim();
};

