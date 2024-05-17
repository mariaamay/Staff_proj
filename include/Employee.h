#pragma once

#include <iostream>
#include <string>
#include <map>

enum Position
{
	cleaner,
	driver,
	programmer,
	tester,
	team_leader,
	project_manager,
	senior_manager,
};

class Employee
{
protected:
	int id;
	std::string name;
	Position position;
	int worktime;
	double payment;
public:
	Employee() = default;
	Employee(int id, const std::string& name, int worktime, Position position);
	virtual ~Employee() = default;
	virtual void calc() = 0;
	virtual void printInfo() = 0;

	int getId() const;
	const std::string& getName() const;
	Position getPosition() const;
	int getWorkTime() const;
	double getPayment() const;

	void setId(int id);
	void setName(const std::string& name);
	void setPosition(Position position);
	void setWorkTime(int time);
	void setPayment(double payment);
};

class Project
{
private:
	int id;
	std::string ProjectName;
	int budget;
	int part;
	int numEngineers;
public:
	Project() = default;
	Project(int id, const std::string& projectName,  int budget, float part, int numEngineers);
	~Project() = default;

	int getIdProject() const;
	const std::string& getNameProject() const;
	int getBudgetProject() const;
	float getBudgetPart() const;
	int getNumEngineers() const;

	void setIdProject(int id);
	void setProjectName(const std::string& name);
	void setBudget(int budget);
	void setPart(float part);
	void setNumEngineers(int num);
};