#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src._target) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
    if (this != &src) {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string const & ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & src) const {
    if (src.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
    }
    std::ofstream file(this->_target + ".shrubbery");
    if (!file.is_open()) {
        throw std::runtime_error("Failed to create file");
    }
    file << "* creates a shrubbery at " << this->_target << " *" << std::endl;
    file.close();
}