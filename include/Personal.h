#pragma once

#include <iostream>
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime
{
protected:
	int salary;
public:
	Personal() = default;
	Personal(int id, const std::string& name, int worktime, int salary, Position position);
	~Personal() override = default;

	int calcBase(int salary, int worktime) override;
	void printInfo() override;
	
	int getSalary() const;
	void setSalary(int salary);
};

class Cleaner : public Personal
{
public:
	Cleaner() = default;
	Cleaner(int id, const std::string& name, int worktime, int salary, Position position);
	~Cleaner() = default;
	void calc() override;
	int calcBonus() override;
	void printInfo() override;
};

class Driver : public Personal
{
private:
	int nightWorkTime;
public:
	Driver() = default;
	Driver(int id, const std::string& name, int worktime, int salary, int nightWorkTime, Position position);
	~Driver() = default;
	void calc() override;
	int calcBonus() override;
	void printInfo() override;

	int getNightWorkTime() const;
	void setNightWorkTime(int time);
};