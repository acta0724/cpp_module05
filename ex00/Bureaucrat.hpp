#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
 private:
    std::string const   _name;
    int                 _grade;

 public:
    Bureaucrat();
    Bureaucrat(std::string const & name, int grade);
    ~Bureaucrat();
    Bureaucrat(Bureaucrat const & src);
    Bureaucrat & operator=(Bureaucrat const & src);
    std::string const & getName() const;
    int getGrade() const;
    void    incrementGrade();
    void    decrementGrade();

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

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src);

#endif
