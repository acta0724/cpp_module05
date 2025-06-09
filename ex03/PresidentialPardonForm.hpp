#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
 private:
    std::string _target;

 public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const & target);
    PresidentialPardonForm(PresidentialPardonForm const & src);
    PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
    ~PresidentialPardonForm();

    std::string const & getTarget() const;
    void execute(Bureaucrat const & src) const;
};

#endif
