#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src), _target(src._target) {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {
    if (this != &src) {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string const & RobotomyRequestForm::getTarget() const {
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    this->beExecuted(executor);
    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2 == 0) {
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << this->_target << " has been robotomized unsuccessfully" << std::endl;
    }
}