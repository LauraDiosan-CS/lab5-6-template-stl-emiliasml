#include "UI.h"
#include <iostream>
#include <exception>
using namespace std;

void printMenu() {
	cout << endl;
	cout << "OPTIONS" << endl;
	cout << "1. Add car" << endl;
	cout << "2. Delete car" << endl;
	cout << "3. Update car" << endl;
	cout << "4. Show cars" << endl;
	cout << "5. Find a car" << endl;
	cout << "6. Enter the parking" << endl;
	cout << "7. Exit the parking" << endl;
	cout << "8. Number of cars" << endl;
	cout << "0. Exit" << endl;
}

void addUI(Service& serv) {
	Car car;
	cout << "Give a car:" << endl;
	cin >> car;
	int i = strcmp(car.getStatus(), "free");
	int j = strcmp(car.getStatus(), "taken");
	if (i != 0 && j != 0)
		cout << "Wrong status! Choose between *taken* and *free*!" << endl;
	else try { serv.addCarService(car); cout << "The car was added succesfully" << endl;
	}
			catch (exception  e) { cout << e.what(); }
}

void deleteUI(Service& serv) {
	cout << "Give the car to delete:" << endl;
	Car car;
	cin >> car;
	try {
		serv.deleteCarService(car); cout << "The car was deleted successfully!" << endl;
	}
	catch (exception e) { cout << e.what(); }
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
		if (k == 1)
			try {
				serv.updateCarService(car, c.getName(), c.getNr(), c.getStatus());
				cout << "The car was updated successfully!" << endl;
			}
			catch (exception e) { cout << e.what() << endl; }
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

void enter(Service& serv) {
	cout << "Give the number of the car you want to enter the parking:";
	char* nr = new char[10];
	cin >> nr;
	int k = 0;
	list <Car> carsServ;
	list <Car>::iterator it;
	carsServ = serv.getAllCar();
	for (it = carsServ.begin(); it != carsServ.end(); it++)
		if (strcmp((*it).getNr(), nr) == 0) {
			Car c = *it;
			try { serv.entry(c); cout << "Success!" << endl; }
			catch (exception e) { cout << e.what(); }
			k = 1;
		}
	if (k == 0)
	 cout << "The number doesn't exist!" << endl;
}

void exitUI(Service& serv) {
	cout << "Give the number of the car you want to exit the parking:";
	char* nr = new char[10];
	cin >> nr;
	int k = 0;
	list <Car> carsServ;
	list <Car>::iterator it;
	carsServ = serv.getAllCar();
	for (it = carsServ.begin(); it != carsServ.end(); it++)
		if (strcmp((*it).getNr(), nr) == 0) {
			Car c = *it;
			try { serv.exit(c); cout << "Success!" << endl; }
			catch (exception e) { cout << e.what(); }
			k = 1;
		}
	if (k == 0) cout << "The number doesn't exist!" << endl;
}

void setNumbersUI(Service& serv, int x) {
	//free - locurile din parcare libere
	//parked - masini in parcare
	//extraParked - masini cu status "parked" care nu au loc in parcare
	int free = x, parked = 0, extraParked = 0;
	list <Car> carsServ;
	list <Car>::iterator it;
	carsServ = serv.getAllCar();
	for (it = carsServ.begin(); it != carsServ.end(); it++)
		if (strcmp((*it).getStatus(), "taken") == 0)
			if (free == 0)
				extraParked++;
			else {
				free--; parked++;
			}
	serv.setNumbers(x, parked, free, extraParked);
}

void numberUI(Service& serv) {
	cout << "Parking capacity = " << serv.XSize() << endl;
	cout << "Parked cars = " << serv.parkedSize() << endl;
	cout << "Free places in parking = " << serv.freeSize() << endl;
	cout << "Cars parked that can't enter the parking = " << serv.extraParkedSize() << endl;
}

void showUI(Service& serv) {
	int op, x;
	bool val = true;
	cout << "Give the number of parking spaces:";
	cin >> x;
	setNumbersUI(serv, x);
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
		case 6: {enter(serv); break; }
		case 7: {exitUI(serv); break;}
		case 8: {setNumbersUI(serv, x); numberUI(serv); break; }
		case 0: {cout << "Bye!"; val = false; break; }
		default: cout << "Try again!" << endl;
		}
	}
}

//==================================================================================
/*
void addUIT(ServiceRepoTemplate& serv) {
	Car car;
	cout << "Give a car:" << endl;
	cin >> car;
	int i = strcmp(car.getStatus(), "free");
	int j = strcmp(car.getStatus(), "taken");
	if (i != 0 && j != 0)
		cout << "Wrong status! Choose between *taken* and *free*!" << endl;
	else try {
		serv.addCarService(car); cout << "The car was added succesfully" << endl;
	}
	catch (exception  e) { cout << e.what(); }
}

void deleteUIT(ServiceRepoTemplate& serv) {
	cout << "Give the car to delete:" << endl;
	Car car;
	cin >> car;
	try {
		serv.deleteCarService(car); cout << "The car was deleted successfully!" << endl;
	}
	catch (exception e) { cout << e.what(); }
}

void updateUIT(ServiceRepoTemplate& serv) {
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
		if (k == 1)
			try {
			serv.updateCarService(car, c.getName(), c.getNr(), c.getStatus());
			cout << "The car was updated successfully!" << endl;
		}
		catch (exception e) { cout << e.what() << endl; }
	}
}

void getAllUIT(ServiceRepoTemplate& serv) {
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

void findUIT(ServiceRepoTemplate& serv) {
	cout << "Give the car:";
	Car car;
	cin >> car;
	if (serv.findCarService(car) == -1) cout << "The car does't exist!" << endl;
	else cout << "The car is in positon " << serv.findCarService(car) << endl;
}

void enterT(ServiceRepoTemplate& serv) {
	cout << "Give the number of the car you want to enter the parking:";
	char* nr = new char[10];
	cin >> nr;
	int k = 0;
	list <Car> carsServ;
	list <Car>::iterator it;
	carsServ = serv.getAllCar();
	for (it = carsServ.begin(); it != carsServ.end(); it++)
		if (strcmp((*it).getNr(), nr) == 0) {
			Car c = *it;
			try { serv.entry(c); cout << "Success!" << endl; }
			catch (exception e) { cout << e.what(); }
			k = 1;
		}
	if (k == 0)
		cout << "The number doesn't exist!" << endl;
}

void exitUIT(ServiceRepoTemplate& serv) {
	cout << "Give the number of the car you want to exit the parking:";
	char* nr = new char[10];
	cin >> nr;
	int k = 0;
	list <Car> carsServ;
	list <Car>::iterator it;
	carsServ = serv.getAllCar();
	for (it = carsServ.begin(); it != carsServ.end(); it++)
		if (strcmp((*it).getNr(), nr) == 0) {
			Car c = *it;
			try { serv.exit(c); cout << "Success!" << endl; }
			catch (exception e) { cout << e.what(); }
			k = 1;
		}
	if (k == 0) cout << "The number doesn't exist!" << endl;
}

void setNumbersUIT(ServiceRepoTemplate& serv, int x) {
	//free - locurile din parcare libere
	//parked - masini in parcare
	//extraParked - masini cu status "parked" care nu au loc in parcare
	int free = x, parked = 0, extraParked = 0;
	list <Car> carsServ;
	list <Car>::iterator it;
	carsServ = serv.getAllCar();
	for (it = carsServ.begin(); it != carsServ.end(); it++)
		if (strcmp((*it).getStatus(), "taken") == 0)
			if (free == 0)
				extraParked++;
			else {
				free--; parked++;
			}
	serv.setNumbers(x, parked, free, extraParked);
}

void numberUIT(ServiceRepoTemplate& serv) {
	cout << "Parking capacity = " << serv.XSize() << endl;
	cout << "Parked cars = " << serv.parkedSize() << endl;
	cout << "Free places in parking = " << serv.freeSize() << endl;
	cout << "Cars parked that can't enter the parking = " << serv.extraParkedSize() << endl;
}

void showUIT(ServiceRepoTemplate& servT) {
	int op, x;
	bool val = true;
	cout << "Give the number of parking spaces:";
	cin >> x;
	setNumbersUIT(servT, x);
	while (val) {
		printMenu();
		cout << "Choose operation:";
		cin >> op;
		switch (op) {
		case 1: {addUIT(servT); break; }
		case 2: {deleteUIT(servT); break; }
		case 3: {updateUIT(servT); break; }
		case 4: {getAllUIT(servT); break; }
		case 5: {findUIT(servT); break; }
		case 6: {enterT(servT); break; }
		case 7: {exitUIT(servT); break; }
		case 8: {setNumbersUIT(servT, x); numberUIT(servT); break; }
		case 0: {cout << "Bye!"; val = false; break; }
		default: cout << "Try again!" << endl;
		}
	}
}
*/