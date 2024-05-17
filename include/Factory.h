#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Employee.h"
#include "Manager.h"

class Project;

class StaffFactory {
private:
	std::vector<Project*> projects;
	std::vector<Employee*> staff;
public:
	StaffFactory() = default;
	void makeProjects(const std::string& filename);
	void makeStaff(const std::string& filename);

	const std::vector<Project*>& getProjects() const;
	void setProjects(const std::vector<Project*>& projects);
	const std::vector<Employee*>& getStaff() const;
	void setStaff(const std::vector<Employee*>& staff);
};



