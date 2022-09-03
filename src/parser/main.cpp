#include "Lexer.hpp"
#include "Parser.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Uncorrect number of arguments!\n";
		return (-1);
	}
	Lexer lex(av[1]);// Запоминаю путь, считываю конфиг
	lex.split(); // Бью конфиг на токены
	Parser(lex.getTokens()); // Кладу токены в реализацию функций сервера (выглядит
	// странно), но я хз как иначе
}
