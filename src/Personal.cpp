#include "Personal.h"

Personal::Personal(int id, const std::string& name, int worktime, int salary, Position position) : Employee(id, name, worktime, position), salary(salary) {};

int Personal::calcBase(int salary, int worktime) {
	return salary * worktime;
}

int Personal::getSalary() const {
	return salary;
}

void Personal::setSalary(int salary) {
	this->salary = salary;
}

void Personal::printInfo() {
	std::cout << this->Employee::getId() << " " << this->Employee::getName() << " " << this->Employee::getPosition() << " " << this->Employee::getPosition() << this->Employee::getWorkTime() << " " << this->getSalary() << " " << "\n";
}

Cleaner::Cleaner(int id, const std::string& name, int worktime, int salary, Position position) : Personal(id, name, worktime, salary, position) {};

void Cleaner::calc() {
	int payment = this->calcBase(this->getSalary(), this->getWorkTime());
	this->setPayment(payment);
}

int Cleaner::calcBonus() {
	return 0;
}

void Cleaner::printInfo() {
	std::cout << "ID: " << this->Employee::getId() << std::endl;
	std::cout << "Name: " << this->Employee::getName() << std::endl;
	std::cout << "Position: cleaner" << std::endl;
	std::cout << "Worktime: " << this->Employee::getWorkTime() << std::endl;
	std::cout << "Salary: " << this->Cleaner::getSalary() << " " << std::endl;
	std::cout << "Payment: " << this->Employee::getPayment() << std::endl;
}

Driver::Driver(int id, const std::string& name, int worktime, int salary, int nightWorkTime, Position position) : Personal(id, name, worktime, salary, position), nightWorkTime(nightWorkTime) {};

void Driver::calc() {
	int payment = calcBase(this->getSalary(), this->getWorkTime()) + this->calcBonus();
	this->setPayment(payment);
}

int Driver::calcBonus() {
	return this->getNightWorkTime() * this->getSalary() * 2;
}

int Driver::getNightWorkTime() const {
	return nightWorkTime;
}

void Driver::setNightWorkTime(int time) {
	nightWorkTime = time;
}

void Driver::printInfo() {
	std::cout << "ID: " << this->Employee::getId() << std::endl;
	std::cout << "Name: " << this->Employee::getName() << std::endl;
	std::cout << "Position: driver" << std::endl;
	std::cout << "Worktime: " << this->Employee::getWorkTime() << std::endl;
	std::cout << "Salary: " << this->Driver::getSalary() << std::endl;
	std::cout << "Night work time: " << this->Driver::getNightWorkTime() << " " << std::endl;
	std::cout << "Payment: " << this->Employee::getPayment() << std::endl;
}

