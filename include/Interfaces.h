#pragma once

#include <iostream>

class WorkBaseTime 
{
public:
	WorkBaseTime() = default;
	virtual ~WorkBaseTime() = default;

	virtual int calcBase(int salary, int worktime) = 0;
	virtual int calcBonus() = 0;
};

class ProjectBudget 
{
public: 
	ProjectBudget() = default;
	virtual ~ProjectBudget() = default;

	virtual double calcBudgetPart(double part, int budget) = 0;
	virtual double calcProAdditions() = 0;
};

class Heading 
{
public:
	Heading() = default;
	virtual ~Heading() = default;

	virtual int calcHeads() = 0;
};
