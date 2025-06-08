#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
 private:
    std::string const   _name;
    bool                _signed;
    int const           _gradeToSign;
    int const           _gradeToExecute;

 public:
    Form();
    Form(std::string const & name, int gradeToSign, int gradeToExecute);
    Form(Form const & src);
    Form & operator=(Form const & src);
    ~Form();

    std::string const & getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat const & src);

    class GradeTooHighException : public std::exception
    {
     public:
        const char * what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
     public:
        const char * what() const throw();
    };
};

std::ostream & operator<<(std::ostream & o, Form const & src);

#endif
