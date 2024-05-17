#include "Employee.h"

Employee::Employee(int id, const std::string& name, int worktime, Position position) : id(id), name(name), position(position), worktime(worktime) {} ;


int Employee::getId() const {
	return id;
};

const std::string& Employee::getName() const {
	return name;
}

Position Employee::getPosition() const {
	return position;
}

int Employee::getWorkTime() const {
	return worktime;
}

double Employee::getPayment() const {
	return payment;
}

void Employee::setId(int id) {
	this->id = id;
}

void Employee::setName(const std::string& name) {
	this->name = name;
}

void Employee::setPosition(Position position) {
	this->position = position;
}

void Employee::setWorkTime(int time) {
	worktime = time;
}
void Employee::setPayment(double payment) {
	this->payment = payment;
}

Project::Project(int id, const std::string& ProjectName, int budget, float part, int numEngineers) : id(id), ProjectName(ProjectName), budget(budget), part(part), numEngineers(numEngineers) {};

int Project::getIdProject() const {
	return id;
}

const std::string& Project::getNameProject() const {
	return ProjectName;
}

int Project::getBudgetProject() const {
	return budget;
}

float Project::getBudgetPart() const {
	return part;
}

int Project::getNumEngineers() const {
	return numEngineers;
}

void Project::setIdProject(int id) {
	this->id = id;
}

void Project::setProjectName(const std::string& name) {
	ProjectName = name;
}

void Project::setBudget(int budget) {
	this->budget = budget;
}

void Project::setPart(float part) {
	this->part = part;
}

void Project::setNumEngineers(int num) {
	numEngineers = num;
}