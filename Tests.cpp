#include "Tests.h"
#include <assert.h>
#include <iostream>
#include "Car.h"
#include "RepositorySTL.h"

void testCar() {
	//constructors and getters
	Car c;
	assert(c.getName() == NULL);
	assert(c.getNr() == 0);
	assert(c.getStatus() == NULL);
	Car cc("Bob", 654, "free");
	assert(strcmp(cc.getName(), "Bob") == 0);
	assert(cc.getNr() == 654);
	assert(strcmp(cc.getStatus(), "free") == 0);
	Car ccc;
	//operator = and ==
	ccc = cc;
	assert(ccc == cc);
	assert(strcmp(ccc.getName(), "Bob") == 0);
	assert(ccc.getNr() == 654);
	assert(strcmp(ccc.getStatus(), "free") == 0);

	//setters
	cc.setName("Marley");
	cc.setNr(100);
	cc.setStatus("taken");
	assert(strcmp(cc.getName(), "Marley") == 0);
	assert(cc.getNr() == 100);
	assert(strcmp(cc.getStatus(), "taken") == 0);
}

void testRepoSTL() {
	Car c1("Bob", 1, "free");
	Car c2("Jane", 22, "taken");
	Car c3("Louisa", 30, "taken");
	RepositorySTL repo;
	//size
	assert(repo.dim() == 0);
	repo.addElem(c1);
	assert(repo.dim() == 1);
	repo.addElem(c2);
	assert(repo.getAll()[1] == c2);
}

void runTests() {
	testCar();
	testRepoSTL();
}