#include<iostream>
#include "Tests.h"
#include "Car.h"
#include "Repository.h"
#include "Service.h"
#include"assert.h"
#include<string.h>
#include<list>
using namespace std;

void testCar() {
	Car c;
	Car c1("Bob", "B10BOB", "free");
	// getters
	assert(c.getName() == NULL);
	assert(c.getNr() == NULL);
	assert(c.getStatus() == NULL);
	c = c1;
	assert(c == c1);
	assert(strcmp(c.getName(), "Bob") == 0);
	assert(strcmp(c.getNr(), "B10BOB") == 0);
	assert(strcmp(c.getStatus(), "free") == 0);

	assert(strcmp(c1.getName(), "Bob") == 0);
	assert(strcmp(c1.getNr(), "B10BOB") == 0);
	assert(strcmp(c1.getStatus(), "free") == 0);
	//setters
	c1.setName("Anna"); c1.setNr("B00III"); c1.setStatus("taken");
	assert(strcmp(c1.getName(), "Anna") == 0);
	assert(strcmp(c1.getNr(), "B00III") == 0);
	assert(strcmp(c1.getStatus(), "taken") == 0);
}


void testRepository()
{
	Car c1("Bob", "B10BOB", "free");
	Car c2("Jane", "HD37PPP", "free");
	Car c3("Marley", "CJ00XXX", "taken");
	Car c("John", "XX00VVV", "free");

	Repository cars;
	//dim and add
	assert(cars.dim() == 0);
	cars.addCar(c1);
	assert(cars.dim() == 1);
	cars.addCar(c2);
	assert(cars.dim() == 2);
	cars.addCar(c3);
	assert(cars.dim() == 3);

	Car carList[] = { c1,c2,c3 };
	list <Car> allCars;
	//getAll
	allCars = cars.getAll();
	list <Car>::iterator it;
	int i = 0;
	for (it = allCars.begin(); it != allCars.end() and i < 3; ++it, i++)
		assert(*it == carList[i]);
	assert(allCars.front() == c1);
	assert(allCars.back() == c3);
	//find 
	assert(cars.findCar(c1) == 0);
	assert(cars.findCar(c2) == 1);
	assert(cars.findCar(c3) == 2);
	assert(cars.findCar(c) == -1);
	//update
	assert(cars.updateCar(c1, "Billy", "YY00YYY", "free") == 0);
	assert(cars.updateCar(c, "Bil", "YY00YYY", "taken") == -1);
	//delete
	assert(cars.delCar(c2) == 0);
	assert(cars.delCar(c) == -1); 
	assert(cars.dim() == 2);

}

void testService() {
	Service serv;
	Car c1("Bob", "B10BOB", "free");
	Car c2("Jane", "HD37PPP", "free");
	Car c3("Marley", "CJ00XXX", "taken");
	Car c22("a", "b", "c");
	//dim and add
	assert(serv.dimCar() == 0);
	serv.addCarService(c1);
	assert(serv.dimCar() == 1);
	serv.addCarService(c2);
	assert(serv.dimCar() == 2);
	//delete
	assert(serv.deleteCarService(c1) == 0);
	assert(serv.deleteCarService(c3) == 2);
	//find
	assert(serv.findCarService(c1) == -1);
	assert(serv.findCarService(c2) == 0);
	assert(serv.findCarService(c3) == -1);
	//update
	assert(serv.updateCarService(c3, "a", "b", "c") == -1);
	assert(serv.updateCarService(c2, "a", "b", "c") == 0);

	serv.addCarService(c1); serv.addCarService(c2); serv.addCarService(c3);
	//get all
	list <Car> carsServ;
	list <Car>::iterator it;
	carsServ = serv.getAllCar();
	Car carArray[] = { c22, c1, c2, c3 };
	int i;
	for (it = carsServ.begin(), i = 0; it != carsServ.end(); it++, i++)
		assert(*it == carArray[i]);

}

void runTests() {
	testCar();
	testRepository();
	testService();
}