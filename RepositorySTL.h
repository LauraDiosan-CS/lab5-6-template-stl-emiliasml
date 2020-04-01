#pragma once
#include "Car.h"
#include <vector>

using namespace std;

class RepositorySTL {
private:
	vector<Car> elem;
public:
	RepositorySTL();
	void addElem(Car);
	vector<Car> getAll();
	int dim();
	~RepositorySTL();
};