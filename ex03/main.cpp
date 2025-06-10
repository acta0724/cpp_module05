#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	Bureaucrat president("President", 1);

	std::cout << "=== Intern test ===" << std::endl;
	Intern someRandomIntern;
	AForm* rrf = NULL;
	AForm* scf = NULL;
	AForm* ppf = NULL;
	AForm* unknown = NULL;

	try {
		std::cout << "\n[correct form name: robotomy request]" << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		president.signForm(*rrf);
		president.executeForm(*rrf);
		delete rrf;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
		delete rrf;
	}

	try {
		std::cout << "\n[correct form name: shrubbery creation]" << std::endl;
		scf = someRandomIntern.makeForm("shrubbery creation", "home");
		president.signForm(*scf);
		president.executeForm(*scf);
		delete scf;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
		delete scf;
	}

	try {
		std::cout << "\n[correct form name: presidential pardon]" << std::endl;
		ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
		president.signForm(*ppf);
		president.executeForm(*ppf);
		delete ppf;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
		delete ppf;
	}

	try {
		std::cout << "\n[unknown form name]" << std::endl;
		unknown = someRandomIntern.makeForm("unknown form", "target");
		delete unknown;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
		delete unknown;
	}

	return 0;
}