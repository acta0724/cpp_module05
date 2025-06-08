#include "Form.hpp"

Form::Form() : _name(""), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string const & name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

Form::Form(Form const & src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

Form & Form::operator=(Form const & src) {
    if (this != &src) {
        _signed = src._signed;
    }
    return *this;
}

Form::~Form() {}

std::string const & Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(Bureaucrat const & src) {
    if (src.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _signed = true;
}

const char * Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char * Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream & operator<<(std::ostream & o, Form const & src) {
    o << src.getName() << ", form grade " << src.getGradeToSign() << ", execute grade " << src.getGradeToExecute() << ", signed " << src.getSigned();
    return o;
}
    