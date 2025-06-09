#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
    std::string _target;

 public:
    RobotomyRequestForm();
    explicit RobotomyRequestForm(std::string const & target);
    RobotomyRequestForm(RobotomyRequestForm const & src);
    RobotomyRequestForm & operator=(RobotomyRequestForm const & src);
    ~RobotomyRequestForm();

    std::string const & getTarget() const;
    void execute(Bureaucrat const & src) const;
};

#endif
