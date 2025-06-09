#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(Intern const & src);
    Intern & operator=(Intern const & src);
    ~Intern();

    AForm* makeForm(std::string const & formName, std::string const & target) const;

    class FormNotFoundException : public std::exception
    {
     public:
        const char * what() const throw();
    };
};

#endif