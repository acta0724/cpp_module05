#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm {
 private:
    std::string const   _name;
    bool                _signed;
    int const           _gradeToSign;
    int const           _gradeToExecute;

 public:
    AForm();
    AForm(std::string const & name, int gradeToSign, int gradeToExecute);
    AForm(AForm const & src);
    AForm & operator=(AForm const & src);
    virtual ~AForm();

    std::string const & getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat const & src);
    void beExecuted(Bureaucrat const & executor) const;
    virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception {
     public:
        const char * what() const throw();
    };

    class GradeTooLowException : public std::exception {
     public:
        const char * what() const throw();
    };

    class FormNotSignedException : public std::exception {
     public:
        const char * what() const throw();
    };
};

std::ostream & operator<<(std::ostream & o, AForm const & src);

#endif
