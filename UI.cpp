#include "UI.h"

#include <iostream>
using namespace std;

void printMenu() {
	cout << "OPTIONS" << endl;
	cout << "1. Add car" << endl;
	cout << "2. Delete car" << endl;
	cout << "3. Update car" << endl;
	cout << "4. Show cars" << endl;
	cout << "5. Find a car" << endl;
	cout << "0. Exit" << endl;
}

void addUI(Service& serv) {
	Car car;
	cout << "Give a car:" << endl;
	cin >> car;
	int k = 1;
	int i = strcmp(car.getStatus(), "free");
	int j = strcmp(car.getStatus(), "taken");
	if (i != 0 && j != 0) {
		k = 0;
		cout << "Wrong status! Choose between *taken* and *free*!" << endl;
	}
	list <Car> carsServ;
	Car c;
	list <Car>::iterator it;
	carsServ = serv.getAllCar();
	for (it = carsServ.begin(); it != carsServ.end(); it++)
	{
		c = *it;
		if (strcmp(c.getNr(), car.getNr()) == 0) { k = 0; cout << "Duplicate number!" << endl; }
	}
	if (k == 1) {
		serv.addCarService(car);
		cout << "The car was added succesfully" << endl;
	}
	else cout << "Try again" << endl;
}

void deleteUI(Service& serv) {
	cout << "Give the car to delete:" << endl;
	Car car;
	cin >> car;
	if (serv.deleteCarService(car) == 0) cout << "The car was deleted successfully!" << endl;
	else cout << "Delete failed" << endl;
}

void updateUI(Service& serv) {
	Car car, c;
	cout << "Give the car to update:";
	cin >> car;
	if (serv.findCarService(car) == -1) cout << "The car doesn't exist!" << endl;
	else {
		cout << "Give other parameters:";
		cin >> c;
		int k = 1;
		int i = strcmp(c.getStatus(), "free");
		int j = strcmp(c.getStatus(), "taken");
		if (i != 0 && j != 0) {
			k = 0;
			cout << "Wrong status! Choose between *taken* and *free*!" << endl;
		}
		list <Car> carsServ;
		Car cc;
		list <Car>::iterator it;
		carsServ = serv.getAllCar();
		for (it = carsServ.begin(); it != carsServ.end(); it++)
		{
			cc = *it;
			if (strcmp(cc.getNr(), car.getNr()) == 0) { k = 0; cout << "Duplicate number!" << endl; }
		}
		if (k == 1)
		{
			if (serv.updateCarService(car, c.getName(), c.getNr(), c.getStatus()) == 0)
				cout << "The car was updated successfully!" << endl;
		}
		else cout << "Try again!" << endl;
	}
}

void getAllUI(Service& serv) {
	if (serv.dimCar() == 0) cout << "There are no cars!" << endl;
	else {
		cout << "------------Cars-------------" << endl;
		list <Car> carsServ;
		list <Car>::iterator it;
		carsServ = serv.getAllCar();
		for (it = carsServ.begin(); it != carsServ.end(); it++)
		 cout << *it << endl;
		cout << "--------------------------" << endl;
	}
}

void findUI(Service& serv) {
	cout << "Give the car:";
	Car car;
	cin >> car;
	if (serv.findCarService(car) == -1) cout << "The car does't exist!" << endl;
	else cout << "The car is in positon " << serv.findCarService(car) << endl;
}

void showUI(Service& serv) {
	int op;
	bool val = true;
	while (val) {
		printMenu();
		cout << "Choose operation:";
		cin >> op;
		switch (op) {
		case 1: {addUI(serv); break; }
		case 2: {deleteUI(serv); break; }
		case 3: {updateUI(serv); break; }
		case 4: {getAllUI(serv); break; }
		case 5: {findUI(serv); break; }
		case 0: {cout << "Bye!"; val = false; break; }
		default: cout << "Try again!" << endl;
		}
	}
}