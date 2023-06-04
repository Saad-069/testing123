#include<string>
#include <iostream>
using namespace std;
class Person {
public:
	string name;
	int age, CNIC;
	void setData(string n, int a, int c);
	void displayData();
	Person();
};
void Person::setData(string n, int a, int c) {
	name = n;
	age = a;
	CNIC = c;
}
void Person::displayData() {
	cout << "Name : " << name << endl;
	cout << "Age : " << age << endl;
	cout << "CNIC : " << CNIC << endl;
}
Person::Person() {
	name = " ";
	age = 0;
	CNIC = 0;
}
//
class Member :public Person {
	int memID, balance, noofCars_bought;
	float amountSpent;
	//Car carsBought[5];
public:
	void setData_mem(int id, float am, int bal, int carsBought, int cnic, int ag, string nam);
	void displayData_mem();
	int getMem_bal();
	int getMem_ID();
	int getMem_noofCars_bought();
	float getMem_amspent();
	Member();
};
//
class Specifications {
public:
	float mileage, kmsDriven;
	int year;
	string engine, color;
	void setData_specs(float m, float k, int y, string e, string c);
	void displayData_specs();
	float getMilage();
	Specifications();
};
float Specifications::getMilage() {
	return mileage;
}
void Specifications::setData_specs(float m, float k, int y, string e, string c) {
	mileage = m;
	kmsDriven = k;
	year = y;
	engine = e;
	color = c;
}
void Specifications::displayData_specs() {

	cout << " Color : " << color << endl<<endl;
	cout << " Engine : " << engine << endl<<endl;
	cout << " Distance driven : " << kmsDriven << " kms" << endl<<endl;
	cout << " Mileage : " << mileage << endl<<endl;
	cout << " Year : " << year << endl<<endl;
}
Specifications::Specifications() {
	color = " ";
	engine = " ";
	kmsDriven = 0.0;
	mileage = 0.0;
	year = 0;
}
//
class Car {
	string brand, model, noPlate;
	Specifications specs;
	int noofUnits;
	float price;
public:
	void setData_car(string brnd, string mdl, string np, string eng, string clr, int nou, float prc, int yr, float ml, float km);
	void displayData_car();
	float getCar_mileage();
	void searchCar_byNoplate(Car car[20]);
	string getCar_model();
	void searchCar_byModel(Car car[20],Member mem[3],int memTem);
	float getCar_price();
	int getCar_noofUnits();
	Car getCar();
	Car();
};
void Car::setData_car(string brnd, string mdl, string np, string eng, string clr, int nou, float prc, int yr, float ml, float km) {
	brand = brnd;
	model = mdl;
	noPlate = np;
	specs.setData_specs(ml, km, yr, eng, clr);
	noofUnits = nou;
	price = prc;

}
void Car::displayData_car() {
	cout << "Brand : " << brand << endl<<endl;
	cout << " Model : " << model << endl<<endl;
	specs.displayData_specs();
	cout << " Number plate : " << noPlate << endl<<endl;
	cout << " Price : " << price << endl<<endl;
	cout << " Available units : " << noofUnits << endl<<endl;
}
void Car::searchCar_byNoplate(Car car[20]) {
	string a;
	cout << "Enter the car's number plate: " << endl;
	cin >> a;
	for (int i = 0; i < 20; i++) {
		if (a == car[i].noPlate) {
			cout << car[i].specs.color << "" << car[i].brand << "" << car[i].model << "" << car[i].specs.year << " " << endl;
		}
		else {
			cout << "No Record Found ." << endl;
		}

	}
}
float Car::getCar_price() {
	return price;
}
float Car::getCar_mileage(){
	return specs.getMilage();
}
int Car::getCar_noofUnits() {
	return noofUnits;
}
string Car::getCar_model() {
	return model;
}
Car Car::getCar() {
	Car c;
	c.brand = brand;
	c.model = model;
	c.noofUnits = noofUnits;
	c.noPlate = noPlate;
	c.price = price;
	c.specs.color = specs.color;
	c.specs.engine = specs.engine;
	c.specs.kmsDriven = specs.kmsDriven;
	c.specs.mileage = specs.mileage;
	c.specs.year = specs.year;
	return  c;
}
void Car::searchCar_byModel(Car car[20],Member mem[3],int memTem) {
	string carName;
	int buy;
	bool chk=false;
	cout << "Enter car model: " << endl;
	cin >> carName;
	for (int i = 0; i < 20; i++) {
		if (carName == car[i].getCar_model()) {
			car[i].displayData_car();
			chk = true;
			cout << "Press 1 to buy this car ." << endl;
			cin >> buy;
			if (buy == 1) {
				cout << "Car bought !!" << endl;
				car[i].getCar_noofUnits() - 1;
				mem[memTem].getMem_noofCars_bought() + 1;
				mem[memTem].getMem_amspent() + car[i].getCar_price();
				mem[memTem].getMem_bal() - car[i].getCar_price();

			}
		}
	}
	if (chk!=true) {
		cout << "Car not found" << endl;
	}
		

}
Car::Car() {
	brand = " ";
	model = " ";
	price = 0;
	noPlate = " ";
	noofUnits = 0;
	specs.color = " ";
	specs.engine = " ";
	specs.kmsDriven = 0;
	specs.mileage = 0;
	specs.year = 0;
}
//
class Employee :public Person {
	int empID;
	string role;
public:
	void setData_emp(int e, int ag, int cnic, string r, string nam);
	void displayData_emp();
	void setCar();
	int getEmployee_id();

	Employee();
};
int Employee::getEmployee_id() {
	return empID;
}
void Employee::setData_emp(int e, int ag, int cnic, string r, string nam) {
	empID = e;
	name = nam;
	age = ag;
	CNIC = cnic;
	role = r;
}
void Employee::displayData_emp() {
	displayData();
	cout << "Employee ID : " << empID << endl;
	cout << "Role : " << role << endl;
}
Employee::Employee() {
	empID = 0;
	role = " ";
}
//

void Member::setData_mem(int id, float am, int bal, int carsBought, int cnic, int ag, string nam) {
	memID = id;
	name = nam;
	age = ag;
	CNIC = cnic;
	amountSpent = am;
	balance = bal;
	noofCars_bought = carsBought;
}
void Member::displayData_mem() {
	displayData();
	cout << "Member ID : " << memID << endl;
	cout << "Total amount spent : " << amountSpent << endl;
	cout << "Balance : " << balance << endl;

}
float Member::getMem_amspent() {
	return amountSpent;
}
int Member::getMem_bal() {
	return balance;
}
int Member::getMem_noofCars_bought() {
	return noofCars_bought;
}
int Member::getMem_ID() {
	return memID;
}
Member::Member() {
	memID = 0;
	balance = 0;
	amountSpent = 0;
	noofCars_bought = 0;
}
//
class ShowRoom {
public:
	Employee emp[2];
	Member mem[5];
	Car cars[20];
	//int revenue;
	void buyCar(Car car[20], int temCar,int temMem,Member mem[3]);
	int returnZero_milage(ShowRoom milage);
	
	void addNew_car(ShowRoom s2);

	ShowRoom();
};
int returnZero_milage(ShowRoom milage) {
	float v;
	v = 3.4;
	int vv;
	bool check = false;
	for (int i = 0; i < 20; i++) {
		if (milage.cars[i].getCar_mileage() == 0)
		{ 
			check = true;
			vv = i;
		}
		
	}
	if (check) {
		return milage.cars[vv].getCar_mileage();
	}
	else
		return vv;

}
void ShowRoom::buyCar(Car car[20], int temCar,int temMem,Member mem[3]) {
	mem[temMem].displayData_mem();
	for (int i = 0; i < 20; i++) {
		if (car[temCar].getCar_noofUnits() > 0) {
			if (mem[temMem].getMem_bal() >= car[temCar].getCar_price()) {
				cout << "Car bought !!" << endl;
				car[temCar].getCar_noofUnits() - 1;
				mem[temMem].getMem_noofCars_bought() + 1;
				mem[temMem].getMem_amspent() + car[i].getCar_price();
				mem[temMem].getMem_bal() - car[i].getCar_price();
				
				break;
			}
			else {
				cout << "Member's balance is insufficient" << endl;
			}
		}
		else {

			cout << "Car out of stock" << endl;
		}
	}mem[temMem].displayData_mem();
}
void ShowRoom::addNew_car(ShowRoom s2) {
	string brnd, mdl, np, eng, clr; 
	int nou, yr;
	float prc, ml, km;
	for (int i = returnZero_milage(s2); i < 20; i++)
	{
		cout << "Enter car brand"<<endl;
		cin >> brnd;
		cout << "Enter car model" << endl;
		cin >> mdl;
		cout << "Enter car number plate" << endl;
		cin >> np;
		cout << "Enter car engine" << endl;
		cin >> eng;
		cout << "Enter car color" << endl;
		cin >> clr;
		cout << "Enter number of car units" << endl;
		cin >> nou;
		cout << "Enter year of registeration " << endl;
		cin >> yr;
		cout << "Enter car price" << endl;
		cin >> prc;
		cout << "Enter car fuel average" << endl;
		cin >> ml;
		cout << "Enter car milage" << endl;
		cin >> km;
		s2.cars[i].setData_car(brnd, mdl, np, eng, clr, nou, prc, yr, ml, km);
	}

}
ShowRoom::ShowRoom() {
	for (int i = 0; i < 2; i++) {
		emp[i].setData_emp(0, 0, 0, " ", " ");
		for (int j = 0; j < 5; j++) {
			mem[i].setData_mem(0, 0, 0, 0, 0, 0, " ");
			for (int k = 0; k < 20; k++) {
				cars[k].setData_car(" ", " ", " ", " ", " ", 0, 0, 0, 0, 0);
			}
		}
	}
}
int main()
{
	ShowRoom s1;
	s1.emp[0].setData_emp(001, 29, 392923223, "SalesPerson", "Ahmad");
	s1.emp[1].setData_emp(003, 33, 234234243, "Manager", "Ali");

	s1.mem[0].setData_mem(002, 0, 1200000, 0, 553242243, 39, "Abdullah");
	s1.mem[1].setData_mem(004, 3000000, 5500000, 6, 455241234, 46, "Saim");
	s1.mem[2].setData_mem(006, 20000, 176000, 1, 436328643, 25, "Saad");

	s1.cars[0].setData_car("Audi", "E-tron GT", "LXL-12", "637 HorsePower", "Silver", 2, 250000, 2020, 475, 190);
	s1.cars[1].setData_car("Ford", "Mustang", "LEC-322", "315 HorsePower ", "Red and black stripes", 1, 50000, 1988, 11.3, 9000);
	s1.cars[2].setData_car("Suzuki", "Mehran", "KBK-677", "37 HorsePower", "white", 67, 2000, 2016, 16.5, 10200);
	s1.cars[3].setData_car("Toyota", "Corolla Altis", "APF-000", "138 HorsePower", "Grey/White", 30, 20000, 2022, 11.0, 0);
	s1.cars[4].setData_car("Honda", "Civic Oriel", "APF-111", "158 HorsePower", "White/Black", 2, 35000, 2022, 9.5, 0);
	s1.cars[5].setData_car("Hyundai", "Sonata", "ICT-666", "191 HorsePower", "Silver", 2, 30000, 2021, 13.0, 500);
	s1.cars[6].setData_car("Toyota", "Mark X", "ICT-302", "256 HorsePower", "White", 1, 25000, 2005, 7, 70000);


	int choice, choice2, choice3, empid, memid, kountMem_tries = 4, kountEmp_tries = 3;
	bool chk1 = false, chk2 = false;
	int n = 0, p = 0;
	cout << endl << endl << endl;
	cout << "                                 Welcome to the ShowRoom! ........" << endl << endl;
	cout << "                1-Scroll as a Member          2.Scroll as a non Member  " << endl;
	cout << endl << endl;
	cout << "                3-Log-in as an Employee                                  " << endl;
	cin >> choice;
	if (choice == 1) {
		do {
			cout << "Enter your Member ID: " << endl;
			cin >> memid;
			for (int m = 0; m < 3; m++) {
				n++;
				if (memid == s1.mem[m].getMem_ID()) {
					chk1 = true;
					cout << "1-View all cars " << endl;
					cout << "2- Search a specifc car" << endl;
					cout << "3-View your past history with us" << endl;
					cin >> choice2;
					if (choice2 == 1) {
							system("CLS");
						for (int c = 0; c < 7; c++) {
							cout << c + 1 << "- ";
							s1.cars[c].displayData_car();
							cout << "Press " << c + 1 << " to buy " << endl;
							cout << endl << endl;
						}cin >> choice3;
						//cout << "choice 3 taken" << endl;
						for (int ch = 0; ch < 7; ch++) {
							//cout << "loop started and is at " << ch << endl;
							if (choice3 == ch) {
								s1.buyCar(s1.cars, choice3, m, s1.mem);
							}
							else {

							}
						}
					}
					else if (choice2 == 2) {
						s1.cars[0].searchCar_byModel(s1.cars, s1.mem, m);

					}
					else if (choice2 == 3) {
						s1.mem[m].displayData_mem();

					}
				}//choise one if after for 

			}//for 
			if (chk1 != true) {
				cout << "Invalid id  ,You have " << kountMem_tries - 1 << " tries left." << endl;

			}
			kountMem_tries--;
			if (kountMem_tries == 0) {
				break;
			}
		} while (memid != s1.mem[n].getMem_ID());
	}// if choice 1 wala
	else if (choice == 2) {
		int j = 0, carChoice;
		for (int i = 0; i < 7; i++) {

			j++;
			cout << j << " -";
			s1.cars[i].displayData_car();
			cout << endl;
			cout << "Press " << j << " to buy this car" << endl;
			cin >> carChoice;
			if (carChoice == i) {
				cout << "Car bought !!" << endl;
				s1.cars[i].getCar_noofUnits() - 1;
			}

		}
	}

	else if (choice == 3) {
		do {
			cout << "Enter your Member ID: " << endl;
			cin >> empid;
			for (int m = 0; m < 3; m++) {
				p++;
				if (empid == s1.emp[m].getEmployee_id()) {
					chk2 = true;
					cout << "1- Remove car " << endl;
					cout << "2- Add car" << endl;
					cout << "3-Add Member" << endl;
				}
					if (chk2 != true) {
						cout << "Invalid id  ,You have " << kountEmp_tries - 1 << " tries left." << endl;

					}
					kountEmp_tries--;
					if (kountEmp_tries == 0) {
						break;
					}

				

			}
		} while (empid != s1.emp[p].getEmployee_id());
	}
}