#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
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
    ~AForm();

    std::string const & getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat const & src);
	virtual void execute(Bureaucrat const & src) const = 0;
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

std::ostream & operator<<(std::ostream & o, AForm const & src);

#endif
