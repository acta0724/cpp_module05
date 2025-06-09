#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	// 乱数の初期化
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	// ブローロクラットの作成（フォームの署名と実行に使用）
	Bureaucrat president("President", 1);

	std::cout << "=== Intern テスト ===" << std::endl;
	Intern someRandomIntern;
	AForm* rrf = NULL;
	AForm* scf = NULL;
	AForm* ppf = NULL;
	AForm* unknown = NULL;

	try {
		// robotomy requestフォームを作成
		std::cout << "\n[正しいフォーム名: robotomy request]" << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		
		// 作成したフォームを署名して実行
		president.signForm(*rrf);
		president.executeForm(*rrf);
		delete rrf; // メモリリークを防ぐ
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
		delete rrf; // 例外が発生した場合もメモリを解放
	}

	try {
		// shrubbery creationフォームを作成
		std::cout << "\n[正しいフォーム名: shrubbery creation]" << std::endl;
		scf = someRandomIntern.makeForm("shrubbery creation", "home");
		
		// 作成したフォームを署名して実行
		president.signForm(*scf);
		president.executeForm(*scf);
		delete scf; // メモリリークを防ぐ
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
		delete scf; // 例外が発生した場合もメモリを解放
	}

	try {
		// presidential pardonフォームを作成
		std::cout << "\n[正しいフォーム名: presidential pardon]" << std::endl;
		ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
		
		// 作成したフォームを署名して実行
		president.signForm(*ppf);
		president.executeForm(*ppf);
		delete ppf; // メモリリークを防ぐ
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
		delete ppf; // 例外が発生した場合もメモリを解放
	}

	try {
		// 存在しないフォーム名を指定
		std::cout << "\n[存在しないフォーム名: unknown form]" << std::endl;
		unknown = someRandomIntern.makeForm("unknown form", "target");
		delete unknown; // メモリリークを防ぐ
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}