#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const & name, int grade) \
    : _name(name), _grade(grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const & src) \
    : _name(src._name), _grade(src._grade) {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src) {
    if (this != &src) {
        _grade = src._grade;
    }
    return *this;
}

std::string const & Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade == 1) {
        throw GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade == 150) {
        throw GradeTooLowException();
    }
    _grade++;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

void Bureaucrat::signForm(Form & src) {
    try {
        src.beSigned(*this);
    }
    catch (std::exception & e) {
        std::cout << _name << " cannot sign " << \
            src.getName() << " because " << e.what() << std::endl;
        return;
    }
    std::cout << _name << " signs " << src.getName() << std::endl;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src) {
    o << src.getName() << ", bureaucrat grade " << src.getGrade();
    return o;
}
