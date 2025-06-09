#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	// 乱数の初期化
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	// ブューロクラットの作成
	Bureaucrat highRank("HighRank", 1);
	Bureaucrat midRank("MidRank", 40);
	Bureaucrat lowRank("LowRank", 150);

	// 各フォームの作成
	ShrubberyCreationForm shrub("garden");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Zaphod");

	std::cout << "=== ShrubberyCreationForm テスト ===" << std::endl;
	try {
		// 署名なしで実行を試みる
		std::cout << "[署名なしで実行を試みる]" << std::endl;
		highRank.executeForm(shrub);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// 署名する
	std::cout << "[署名する]" << std::endl;
	highRank.signForm(shrub);

	try {
		// 権限が十分なブューロクラットが実行
		std::cout << "[権限が十分なブューロクラットが実行]" << std::endl;
		highRank.executeForm(shrub);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		// 権限が不足しているブューロクラットが実行を試みる
		std::cout << "[権限が不足しているブューロクラットが実行を試みる]" << std::endl;
		lowRank.executeForm(shrub);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== RobotomyRequestForm テスト ===" << std::endl;
	// 署名する
	std::cout << "[署名する]" << std::endl;
	highRank.signForm(robot);

	try {
		// 権限が十分なブューロクラットが実行
		std::cout << "[権限が十分なブューロクラットが実行]" << std::endl;
		highRank.executeForm(robot);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		// 権限が十分なブューロクラットが再度実行（結果が異なる可能性あり）
		std::cout << "[再度実行（結果が異なる可能性あり）]" << std::endl;
		highRank.executeForm(robot);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== PresidentialPardonForm テスト ===" << std::endl;
	// 署名する
	std::cout << "[署名する]" << std::endl;
	highRank.signForm(pardon);

	try {
		// 権限が十分なブューロクラットが実行
		std::cout << "[権限が十分なブューロクラットが実行]" << std::endl;
		highRank.executeForm(pardon);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		// 権限が不足しているブューロクラットが実行を試みる
		std::cout << "[権限が不足しているブューロクラットが実行を試みる]" << std::endl;
		midRank.executeForm(pardon);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}