#include <fstream>
#include <string>
#include <iostream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : \
    AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : \
    AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : \
    AForm(src), _target(src._target) {}

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

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    this->beExecuted(executor);
    std::ofstream file(this->_target + ".shrubbery");
    if (!file.is_open()) {
        std::cout << "Failed to create file" << std::endl;
        return;
    }
    file << "         *         " << std::endl;
    file << "        /|\\        " << std::endl;
    file << "       / | \\       " << std::endl;
    file << "      /  |  \\      " << std::endl;
    file << "     /   |   \\     " << std::endl;
    file << "    *****|*****    " << std::endl;
    file << "        /|\\        " << std::endl;
    file << "       / | \\       " << std::endl;
    file << "      /  |  \\      " << std::endl;
    file << "     /   |   \\     " << std::endl;
    file << "    *****|*****    " << std::endl;
    file << "        |||        " << std::endl;
    file << "        |||        " << std::endl;
    file << "        |||        " << std::endl;
    file << "==================="<< std::endl;
    file << "* creates a shrubbery at " << this->_target << " *" << std::endl;
    file.close();
}
