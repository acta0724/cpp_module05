#include "Bureaucrat.hpp"

int main() {
    Bureaucrat b("b", 1);
    std::cout << b << std::endl;
	try {
		b.incrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << b << std::endl;
	try {
		b.decrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
    std::cout << b << std::endl;
	try {
		b.decrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
    std::cout << b << std::endl;
    return 0;
}
