#include "RepositorySTL.h"
#include <iostream>

RepositorySTL::RepositorySTL() {
}

void RepositorySTL::addElem(Car c) {
	cout << "k3";
	elem.push_back(c);
	cout << "3k";
}

vector<Car> RepositorySTL::getAll() {
	return elem;
}

int RepositorySTL::dim() {
	return elem.size();
}

RepositorySTL::~RepositorySTL() {
}


