#include "UI.h"
#include <iostream>
using namespace std;

void printMenu() {
	cout << "OPTIONS" << endl;
	cout << "11. Give the number of parking spaces" << endl;
	cout << "22. Number of parking spaces" << endl;
	cout << "1. Add car" << endl;
	cout << "2. Delete car" << endl;
	cout << "3. Update car" << endl;
	cout << "4. Show cars" << endl;
	cout << "5. Find a car" << endl;
	cout << "0. Exit" << endl;
}

int addUI(Service& serv) {
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
		if (strcmp(car.getStatus(), "taken") == 0) k = 2;
	}
	else cout << "Try again" << endl;
	return k;
}

int deleteUI(Service& serv) {
	cout << "Give the car to delete:" << endl;
	Car car;
	cin >> car;
	int i = serv.deleteCarService(car);
	if (i == 0) {
		cout << "The car was deleted successfully!" << endl; return 1;
	}
	else if (i == 2)cout << "You can't delete this car!";
		else cout << "Delete failed" << endl;
	return 0;
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
	int X = serv.dimCar(), parked = 0, left = 1;
	list <Car> carsServ;
	list <Car>::iterator it;
	carsServ = serv.getAllCar();
	for (it = carsServ.begin(); it != carsServ.end(); it++)
		if (strcmp((*it).getStatus(), "taken") == 0) parked++;
	left = X - parked;
	bool val = true;
	while (val) {
		printMenu();
		cout << "Choose operation:";
		cin >> op;
		switch (op) {
		case 11: { cout << "X="; cin >> X; left = X;  break;  }
		case 22: { cout << "TOTAL=" << X << endl << "FREE=" << left << endl << "TAKEN=" << parked << endl; break; }
		case 1: {if (parked == X) cout << "The parking is full!" << endl;
			  else {
			if (addUI(serv) == 2) { parked++; left--;
			}
		}
			  break; }
		case 2: {if (deleteUI(serv) == 1) parked--; left++; break; }
		case 3: {updateUI(serv); break; }
		case 4: {getAllUI(serv); break; }
		case 5: {findUI(serv); break; }
		case 0: {cout << "Bye!"; val = false; break; }
		default: cout << "Try again!" << endl;
		}
	}
}