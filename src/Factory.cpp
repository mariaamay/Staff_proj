#include "Factory.h"
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"

void StaffFactory::makeProjects(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error opening file!\n";
		return;
	}
	else {
		std::string line;
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			int idProject, projectBd, projPart;
			std::string prName;
			if (!(iss >> idProject >> prName >> projectBd >> projPart)) {
				break;
			}
			Project* proj = new Project(idProject, prName, projectBd, projPart, 0);
			projects.push_back(proj);
		}
	}
	file.close();
}

void StaffFactory::makeStaff(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error opening file!\n";
		return;
	}
	else {
		std::string line;
		while (std::getline(file, line)) {
			std::stringstream iss(line);
			int id, worktime, salary, numExtra, engineers, idProj;
			std::string fullName, surn, name, patr, position;
			iss >> id >> surn >> name >> patr >> position;
			fullName = surn + " " + name + " " + patr;
			 if (position == "cleaner") {
				iss >> worktime >> salary;
				Cleaner* cl = new Cleaner(id, fullName, worktime, salary, cleaner);
				staff.push_back(cl);
			}
			else if (position == "driver") {
				iss >> worktime >> salary >> numExtra;
				Driver* dr = new Driver(id, fullName, worktime, salary, numExtra, driver);
				staff.push_back(dr);
			}
			else if (position == "programmer") {
				iss >> worktime >> salary >> numExtra >> idProj;
				Programmer* pr = new Programmer(id, fullName, worktime, salary, programmer, numExtra);
				for (Project* proj : this->getProjects()) {
					if (proj->getIdProject() == idProj) {
						pr->setProject(proj);
						int num = proj->getNumEngineers();
						num++;
						proj->setNumEngineers(num);
					}
				}
				staff.push_back(pr);
			}
			else if (position == "tester") {
				iss >> worktime >> salary >> numExtra >> idProj;
				Tester* tst = new Tester(id, fullName, worktime, salary, tester, numExtra);
				for (Project* proj : this->getProjects()) {
					if (proj->getIdProject() == idProj) {
						tst->setProject(proj);
						int num = proj->getNumEngineers();
						num++;
						proj->setNumEngineers(num);
					}
				}
				staff.push_back(tst);
			}
			else if (position == "team_leader") {
				iss >> worktime >> salary >> idProj;
				TeamLeader* tmld = new TeamLeader(id, fullName, worktime, salary, team_leader);
				for (Project* proj : this->getProjects()) {
					if (proj->getIdProject() == idProj) {
						tmld->setProject(proj);
					}
				}
				staff.push_back(tmld);
			}
			else if (position == "project_manager") {
				iss >> worktime >> idProj;
				ProjectManager* pm = new ProjectManager(id, fullName, worktime, project_manager, projects);
				for (Project* proj : this->getProjects()) {
					if (proj->getIdProject() == idProj) {
						pm->setProject(proj);
					}
				}
				staff.push_back(pm);

			}
			else if (position == "senior_manager") {
				iss >> worktime;
				SeniorManager* sm = new SeniorManager(id, fullName, worktime, senior_manager, projects);
				sm->setProjects(projects);
				staff.push_back(sm);
			}
		}
	}
	file.close();
}

 const std::vector<Project*>& StaffFactory::getProjects() const {
	return projects;
}

 void StaffFactory::setProjects(const std::vector<Project*>& newProjects) {
	 projects = newProjects;
}

 const std::vector<Employee*>& StaffFactory::getStaff() const {
	 return staff;
}
 void StaffFactory::setStaff(const std::vector<Employee*>& newStaff) {
	 staff = newStaff;
}