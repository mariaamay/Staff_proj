#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include "Personal.h"
#include "Interfaces.h"

class Engineer : public ProjectBudget, public Heading, public Personal
{
protected:
	Project* project;
public:
	Engineer() = default;
	Engineer(int id, const std::string& name, int worktime, int salary, Position position, Project* project);
	virtual ~Engineer() = default;

	double calcBudgetPart(double part, int budget) override;

	Project* getProject() const;
	void setProject(Project* project);
};

class Programmer : public Engineer
{
protected:
	int numHoursBeforeDeadline;
public:
	Programmer() = default;
	Programmer(int id, const std::string& name, int worktime, int salary, Position position, int numHoursBeforeDeadline);
	double calcProAdditions() override;
	void printInfo() override;
	int calcBonus() override;
	void calc() override;
	int calcHeads() override;

	int getNumHoursBeforeDeadline() const;
	void setNumHoursBeforeDeadline(int num);
};

class Tester : public Engineer
{
protected:
	int numFixes;
public:
	Tester() = default;
	Tester(int id, const std::string& name, int worktime, int salary, Position position, int numFixes);
	double calcProAdditions() override;
	void printInfo() override;
	int calcBonus() override;
	void calc() override;
	int calcHeads() override;

	void setNumFixes(int num);
	int getNumFixes() const;
};

class TeamLeader : public Programmer
{
public:
	TeamLeader() = default;
	TeamLeader(int id, const std::string& name, int worktime, int salary, Position position);
	int calcHeads() override;
	void calc() override;
	int calcBonus() override;
	void printInfo() override;
};