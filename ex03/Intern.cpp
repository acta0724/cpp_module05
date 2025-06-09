#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & src) {
    *this = src;
}

Intern & Intern::operator=(Intern const & src) {
    (void)src;
    return *this;
}

Intern::~Intern() {}

const char * Intern::FormNotFoundException::what() const throw() {
    return "Form not found";
}

static AForm* createShrubberyForm(std::string const & target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(std::string const & target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(std::string const & target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const & formName, std::string const & target) const {
    struct FormType {
        std::string name;
        AForm* (*create)(std::string const &);
    };
    
    FormType forms[] = {
        {"shrubbery creation", createShrubberyForm},
        {"robotomy request", createRobotomyForm},
        {"presidential pardon", createPresidentialForm}
    };
    for (int i = 0; i < 3; ++i) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }
    throw FormNotFoundException();
}