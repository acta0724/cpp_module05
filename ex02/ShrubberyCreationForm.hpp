#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
    std::string _target;

 public:
    ShrubberyCreationForm();
    explicit ShrubberyCreationForm(std::string const & target);
    ShrubberyCreationForm(ShrubberyCreationForm const & src);
    ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);
    ~ShrubberyCreationForm();

    std::string const & getTarget() const;
    void execute(Bureaucrat const & src) const;
};

#endif
