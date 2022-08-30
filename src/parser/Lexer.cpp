//
// Created by arnisfet on 28.08.2022.
//

#include "Lexer.hpp"

Lexer::Lexer()
{}

Lexer::~Lexer()
{}

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

void Lexer::Remove_Space()
{
	std::string::iterator begin = _Config.begin();
	std::string::iterator end = _Config.end();
	std::string::iterator point = begin;

	while (begin != end)
	{
		if (*begin == ' ')
			if (point != begin)
			{
				*point = *begin;
				++point;
			}
		++begin;
	}

}

void Lexer::split()
{
	_Config.erase(std::remove(_Config.begin(), _Config.end(), '\n'), _Config.end());
	// Режу все символы переноса
	Remove_Space();

	std::cout << _Config;

}