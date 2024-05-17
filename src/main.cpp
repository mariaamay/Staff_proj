#include <iostream>
#include "Factory.h"
#include "Engineer.h"

int main() {
	StaffFactory factory;
	factory.makeProjects("C:\\Users\\PC\\source\\repos\\Staff\\projects_info.txt");
	factory.makeStaff("C:\\Users\\PC\\source\\repos\\Staff\\staff_info.txt");

	std::cout << "Projects:" << std::endl << std::endl;
	for (Project* proj : factory.getProjects()) {
		std::cout << "Project ID: " << proj->getIdProject() << std::endl;
		std::cout << "Project name: " << proj->getNameProject() << std::endl;
		std::cout << "Project budget: " << proj->getBudgetProject() << std::endl;
		std::cout << std::endl;
	}

	std::cout << "Staff:" << std::endl << std::endl;
	for (Employee* emp : factory.getStaff()) {
		emp->calc();
		emp->printInfo();
		std::cout << std::endl;
	}

	return 0;
}