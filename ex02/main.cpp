#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    // std::srand(static_cast<unsigned int>(std::time(NULL)));

    Bureaucrat highRank("HighRank", 1);
    Bureaucrat midRank("MidRank", 40);
    Bureaucrat lowRank("LowRank", 150);

    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Zaphod");

    std::cout << "=== ShrubberyCreationForm テスト ===" << std::endl;
    std::cout << "try to execute without signature" << std::endl;
    highRank.executeForm(shrub);

    std::cout << "\ntry to sign" << std::endl;
    highRank.signForm(shrub);

    std::cout << "\ntry to execute with high rank" << std::endl;
    highRank.executeForm(shrub);

    std::cout << "\ntry to execute with low rank" << std::endl;
    lowRank.executeForm(shrub);

    std::cout << "\n=== RobotomyRequestForm テスト ===" << std::endl;
    std::cout << "try to execute without signature" << std::endl;
    highRank.executeForm(robot);

    std::cout << "\ntry to sign" << std::endl;
    highRank.signForm(robot);

    std::cout << "\ntry to execute with high rank" << std::endl;
    highRank.executeForm(robot);

    std::cout << "\ntry to execute with low rank" << std::endl;
    lowRank.executeForm(robot);

    std::cout << "\n=== PresidentialPardonForm テスト ===" << std::endl;
    std::cout << "try to execute without signature" << std::endl;
    highRank.executeForm(pardon);

    std::cout << "\ntry to sign" << std::endl;
    highRank.signForm(pardon);

    std::cout << "\ntry to execute with high rank" << std::endl;
    highRank.executeForm(pardon);

    std::cout << "\ntry to execute with mid rank" << std::endl;
    midRank.executeForm(pardon);

    return 0;
}