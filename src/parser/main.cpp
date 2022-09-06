#include "Lexer.hpp"
#include "Parser.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Uncorrect number of arguments!\n";
		return (-1);
	}
	Parser parser(av[1]);
	parser.ParseConfig();
}
