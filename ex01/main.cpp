#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    Bureaucrat b("b", 1);
    Form f("f", 1, 1);
	try {
		b.signForm(f);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	Bureaucrat b2("b2", 150);
	try {
		b2.signForm(f);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
    return 0;
}