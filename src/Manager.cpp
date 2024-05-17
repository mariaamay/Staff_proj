#include <numeric>
#include "Manager.h"


ProjectManager::ProjectManager(int id, const std::string& name, int worktime, Position position, std::vector<Project*>& projects) : Employee(id, name, worktime, position), project(project), managerProjects(projects) {};

int ProjectManager::calcHeads() {
	return this->getProject()->getNumEngineers() + 1; //инженеры + тимлид
}

double ProjectManager::calcBudgetPart(double part, int budget) {
	return part * budget * 100;
}

double ProjectManager::calcProAdditions() {
	return 0;
}

void ProjectManager::calc() {
	int payment = this->getWorkTime() * calcBudgetPart(this->getProject()->getBudgetPart(), this->getProject()->getBudgetProject()) + calcHeads() * 0.07 * this->project->getBudgetProject(); //получает 7% бюджета проекта за руководство с каждого инженера и тимлида
	this->setPayment(payment);
}

Project* ProjectManager::getProject() const {
	return project;
}

void ProjectManager::setProject(Project* project) {
	this->project = project;
}

const std::vector<Project*>& ProjectManager::getProjects() const {
	return managerProjects;
}

void ProjectManager::setProjects(std::vector<Project*>& projects) {
	managerProjects = projects;
};

void ProjectManager::printInfo() {
	std::cout << "ID: " << this->Employee::getId() << std::endl;
	std::cout << "Name: " << this->Employee::getName() << std::endl;
	std::cout << "Position: project manager" << std::endl;
	std::cout << "Worktime: " << this->Employee::getWorkTime() << std::endl;
	std::cout << "Payment: " << this->Employee::getPayment() << std::endl;
	std::cout << "ID Project: " << this->ProjectManager::getProject()->getIdProject() << std::endl;
}

SeniorManager::SeniorManager(int id, const std::string& name, int worktime, Position position, std::vector<Project*>& sProjects) : ProjectManager(id, name, worktime, position, sProjects) {} ;

const std::vector<Project*>& SeniorManager::getProjects() const {
	return seniorManagerProjects;
}

void SeniorManager::setProjects(std::vector<Project*>& projects) {
	seniorManagerProjects = projects;
};

double SeniorManager::calcBudgetPart(double part, int budget) {
	return part * budget * 500;
}

double SeniorManager::calcProAdditions() {
	return 0;
}

int SeniorManager::calcHeads() {
	int allEngineers = 0;
	for (Project* proj : seniorManagerProjects) {
		allEngineers += proj->getNumEngineers() + 2; // + тимлид и проджект менеджер каждого проекта
	}
	return allEngineers;
}

void SeniorManager::calc() {
	double total = 0;
	for (Project* proj : this->getProjects()) {
		double part = proj->getBudgetPart();
		int budget = proj->getBudgetProject();
	// + тимлид и проджект менеджер каждого проекта
		total += part * budget;
	}
	double sum = total * this->getWorkTime() + calcHeads()*15000; // фиксированная сумма за каждого подчиненного 
	this->setPayment(sum);
}

void SeniorManager::printInfo() {
	std::cout << "ID: " << this->Employee::getId() << std::endl;
	std::cout << "Name: " << this->Employee::getName() << std::endl;
	std::cout << "Position: senior manager" << std::endl;
	std::cout << "Worktime: " << this->Employee::getWorkTime() << std::endl;
	std::cout << "Payment: " << this->getPayment() << std::endl;
	std::cout << "The number of projects: " << this->ProjectManager::getProjects().size() << std::endl;
}