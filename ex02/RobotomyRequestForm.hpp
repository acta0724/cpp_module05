#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
 private:
    std::string _target;

 public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const & target);
    RobotomyRequestForm(RobotomyRequestForm const & src);
    RobotomyRequestForm & operator=(RobotomyRequestForm const & src);
    ~RobotomyRequestForm();

    std::string const & getTarget() const;
    void execute(Bureaucrat const & src) const;
};

#endif
