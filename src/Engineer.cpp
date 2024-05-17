#include "Engineer.h"

Engineer::Engineer(int id, const std::string& name, int worktime, int salary, Position position, Project* project) : Personal(id, name, worktime, salary, position), project(project) {} ;

double Engineer::calcBudgetPart(double part, int budget) {
	return part * budget;
}

Project* Engineer::getProject() const {
	return project;
}

void Engineer::setProject(Project* project) {
	this->project = project;
}


Programmer::Programmer(int id, const std::string& name, int worktime, int salary, Position position, int numHoursBeforeDeadline) : Engineer(id, name, worktime, salary, position, project), numHoursBeforeDeadline(numHoursBeforeDeadline) {};

int Programmer::calcBonus() {
	return 0;
}

int Programmer::getNumHoursBeforeDeadline() const {
	return numHoursBeforeDeadline;
}

void Programmer::setNumHoursBeforeDeadline(int num) {
	numHoursBeforeDeadline = num;
}

double Programmer::calcProAdditions() {
	return 0.03 * this->getProject()->getBudgetProject() * this->getNumHoursBeforeDeadline(); // получает 3% бюджета проекта за каждый досрочный час
}

int Programmer::calcHeads() {
	return 0;
}

void Programmer::calc() {
	double payy = this->calcBase(this->getSalary(), this->getWorkTime()) + this->calcBonus() + this->calcBudgetPart(this->getProject()->getBudgetPart(), this->getProject()->getBudgetProject()) + this->calcProAdditions();
	this->setPayment(payy);
}

void Programmer::printInfo() {
	std::cout << "ID: " << this->Employee::getId() << std::endl;
	std::cout << "Name: " << this->Employee::getName() << std::endl;
	std::cout << "Position: programmer" << std::endl;
	std::cout << "Worktime: " << this->Employee::getWorkTime() << std::endl;
	std::cout << "Salary: " << this->Programmer::getSalary() << " " << std::endl;
	std::cout << "Payment: " << this->Employee::getPayment() << std::endl;
	std::cout << "ID Project: " << this->Programmer::getProject()->getIdProject() << " " << std::endl;
}

Tester::Tester(int id, const std::string& name, int worktime, int salary, Position position, int numFixes) : Engineer(id, name, worktime, salary, position, project), numFixes(numFixes) {};


double Tester::calcProAdditions() {
	return this->getNumFixes() * 0.01 * this->getProject()->getBudgetProject(); //получает 1% бюджета проекта за каждую найденную ошибку
}


int Tester::calcHeads() {
	return 0;
}

void Tester::calc() {
	double payy = this->calcBase(this->getSalary(), this->getWorkTime()) + this->calcBonus() + this->calcBudgetPart(this->getProject()->getBudgetPart(), this->getProject()->getBudgetProject()) + this->calcProAdditions();
	this->setPayment(payy);
}

void Tester::printInfo() {
	std::cout << "ID: " << this->Employee::getId() << std::endl;
	std::cout << "Name: " << this->Employee::getName() << std::endl;
	std::cout << "Position: tester" << std::endl;
	std::cout << "Worktime: " << this->Employee::getWorkTime() << std::endl;
	std::cout << "Salary: " << this->Tester::getSalary() << " " << std::endl;
	std::cout << "Payment: " << this->Employee::getPayment() << std::endl;
	std::cout << "ID Project: " << this->Tester::getProject()->getIdProject() << " " << std::endl;
}

int Tester::calcBonus() {
	return 0;
}

int Tester::getNumFixes() const {
	return numFixes;
}

void Tester::setNumFixes(int num) {
	this->numFixes = num;
}


TeamLeader::TeamLeader(int id, const std::string& name, int worktime, int salary, Position position) : Programmer(id, name, worktime, salary, position, numHoursBeforeDeadline) {};

int TeamLeader::calcHeads() {
	return this->getProject()->getNumEngineers();
}

void TeamLeader::calc() {
	int payment = calcBase(this->getSalary(), this->getWorkTime()) + calcBudgetPart(this->getProject()->getBudgetPart(), this->getProject()->getBudgetProject()) + calcHeads() * 0.05 * this->getProject()->getBudgetProject(); //получает 5% бюджета проекта за руководство с каждого инженера
	this->setPayment(payment);
}

void TeamLeader::printInfo() {
	std::cout << "ID: " << this->Employee::getId() << std::endl;
	std::cout << "Name: " << this->Employee::getName() << std::endl;
	std::cout << "Position: team leader" << std::endl;
	std::cout << "Worktime: " << this->Employee::getWorkTime() << std::endl;
	std::cout << "Salary: " << this->TeamLeader::getSalary() << " " << std::endl;
	std::cout << "Payment: " << this->Employee::getPayment() << std::endl;
	std::cout << "ID Project: " << this->TeamLeader::getProject()->getIdProject() << " " << std::endl;
}

int TeamLeader::calcBonus() {
	return 0;
}