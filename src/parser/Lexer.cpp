//
// Created by arnisfet on 28.08.2022.
//

#include "Lexer.hpp"

Lexer::Lexer()
{}

Lexer::~Lexer()
{}

void Lexer::Remove_Space()
{
	for (std::string::iterator it = _Config.begin(); it != _Config.end(); it++)
	{
		std::string::iterator begin = it;
		while (it != _Config.end() && ::isspace(*it) )it++;
		if (it - begin > 1)
			it = _Config.erase(begin + 1, it) - 1;
	}
}

Lexer::Lexer(const std::string &path)
{
	std::string line; // Строка для чтения из потока

	_Path = path; // Запомнили путь
	std::ifstream read(_Path.c_str()); // Считали файл из заданного файла
	if (!read)
	{
			std::cerr << "File couldn't oppenning or reading!" << std::endl;
			exit (1);
	}
	while(getline(read, line))
		_Config = _Config + line + "\n"; // после этого цикла в _текст записан весь конфиг.
	read.close();
}

void Lexer::work_with_conf()
{
	std::string::iterator begin;
	std::string::iterator end;
	std::string::iterator cp_point;


	Remove_Space(); // Режу все символы переноса и пробелы
	end = _Config.end();
	for (begin = _Config.begin(); begin != end; begin++)
	{
		if (::isspace(*begin))
			begin++;
		if (*begin == '#')
			_Tokens.push_back(Hastag(begin, cp_point, end)) ;
	}

}
Token_type Lexer::Hastag(std::string::iterator begin, std::string::iterator cp_point,
						  std::string::iterator end)
{
	Token_type hashtagr;

	cp_point = begin;
	while (*cp_point != '\n' && cp_point != end)
	{
		cp_point++;
	}
	hashtagr.second = HASHTAG;
	hashtagr.first = _Config.substr(begin - _Config.begin(), cp_point - begin);
	std::cout << hashtagr.first;
	begin = cp_point;
	return (hashtagr);
}