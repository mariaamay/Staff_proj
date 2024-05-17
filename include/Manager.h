#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"
#include "Interfaces.h"

class ProjectManager : public Employee, public ProjectBudget, public Heading
{
protected:
	Project* project;
	std::vector<Project*> managerProjects;
public:
	ProjectManager() = default;
	ProjectManager(int id, const std::string& name, int worktime, Position position, std::vector<Project*>& projects);
	virtual ~ProjectManager() = default;
	int calcHeads() override;
	void calc() override;
	void printInfo() override;
	double calcBudgetPart(double part, int budget) override;
	double calcProAdditions() override;

	Project* getProject() const;
	void setProject(Project* project);
	const std::vector<Project*>& getProjects() const;
	void setProjects(std::vector<Project*>& projects);
};


class SeniorManager : public ProjectManager
{
protected:
	std::vector<Project*> seniorManagerProjects;
public:
	SeniorManager() = default;
	SeniorManager(int id, const std::string& name, int worktime, Position position, std::vector<Project*>& projects);
	~SeniorManager() = default;
	void calc() override;
	void printInfo() override;
	int calcHeads() override;
	double calcBudgetPart(double part, int budget) override;
	double calcProAdditions() override;

	const std::vector<Project*>& getProjects() const;
	void setProjects(std::vector<Project*>& projects);
};

