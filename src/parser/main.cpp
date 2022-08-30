#include "Lexer.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Uncorrect number of arguments!\n";
		return (-1);
	}
	Lexer lex(av[1]);
	lex.split();
}
