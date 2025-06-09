#include <string>
#include "AForm.hpp"

AForm::AForm() : _name(""), _signed(false), _gradeToSign(150), \
    _gradeToExecute(150) {}

AForm::AForm(std::string const & name, int gradeToSign, int gradeToExecute) : \
    _name(name), _signed(false), _gradeToSign(gradeToSign), \
    _gradeToExecute(gradeToExecute) {}

AForm::AForm(AForm const & src) : _name(src._name), _signed(src._signed), \
    _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm & AForm::operator=(AForm const & src) {
    if (this != &src) {
        _signed = src._signed;
    }
    return *this;
}

AForm::~AForm() {}

std::string const & AForm::getName() const {
    return _name;
}

bool AForm::getSigned() const {
    return _signed;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat const & src) {
    if (src.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _signed = true;
}

const char * AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char * AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char * AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

void AForm::beExecuted(Bureaucrat const & executor) const {
    if (!this->getSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
    }
}

std::ostream & operator<<(std::ostream & o, AForm const & src) {
    o << src.getName() << ", form grade " \
        << src.getGradeToSign() << ", execute grade " \
        << src.getGradeToExecute() << ", signed " << src.getSigned();
    return o;
}
