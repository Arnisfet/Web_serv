//
// Created by arnisfet on 28.08.2022.
//

/** Тот кто по неизвестным мне причинам решил прочесть этот файл: сейчас ты увидишь генильнейшее
 * решение разбивки на лексемы, все уложилось в 4-5 функций, и ничего лишнего
 */

#include "Lexer.hpp"

Lexer::Lexer()
{}

Lexer::~Lexer()
{}

/** Конструктор **/

Lexer::Lexer(const std::string &path)
{
	std::string line; // Строка для чтения из потока

	_Path = path; // Запомнили путь
	std::ifstream read(_Path.c_str()); // Считали файл
	if (!read)
	{
			std::cerr << "File couldn't oppenning or reading!" << std::endl;
			exit (1);
	}
	while(getline(read, line))
		_Config = _Config + line + "\n"; // после этого цикла в _текст записан весь конфиг.
	read.close();
}

/** Основная функция **/

void Lexer::split()
{
	// Режу все символы переноса
	_Config = Remove_Space(_Config);
	Make_Simple_Tokens();
	// Дальше не сложное - дробление в вектор....
	Split_Tokens();
//	print_vector();
//	std::cout << _Config;
}

/** Основная суть функции в том, чтобы оставить только пробел, пробел нужен для дробления слов на
 * лексемы **/

std::string Lexer::Remove_Space(std::string line)
{
	std::string::size_type begin;
	std::string::size_type end;
	int i = 0;

	while (1)
	{// Вырезаю хештеги к чертовой матери, их наличие усложняет алгоритм
		begin = line.find_first_of('#', 0);
		if (begin == std::string::npos)
			break ;
		end = line.find_first_of('\n', begin);
		line.erase(begin, end - begin);
	}
	/********* Заменяю все символы переноса на пробелы *********/
	while (line[i])
	{
		if (isspace(line[i]) && line[i] != ' ')
			line[i] = ' ';
		i++;
	}
	i = 0;
	/********* Убираю все лишние пробелы *********/
	while(line[i])
	{
		if (isspace(line[0]))
		{// Если в самом начале есть такой символ то вырезаем его нахуй
			line.erase(0, 1);
			continue;
		}
		if (isspace(line[i]) && isspace(line[i+1]))
		{// Основное условие для обработки пробела
			begin = i;
			end = line.find_first_not_of(line[i], begin);
			line.erase(begin, end - begin - 1);
			i = 0; continue;
		}
		i++;
	}
	return (line);
}

void Lexer::Make_Simple_Tokens()
{
	int i = 0;
	/** Подготавливаю ; к дроблению вставляя пробелы между точкой запятой и другими лексемами**/
	while (_Config[i])
	{
		if (_Config[i] == ';')
		{
			if (_Config[i - 1] != ' ')
			{
				_Config.insert(i, 1, ' ');
				i++;
			}
			if (_Config[i + 1] != ' ')
			{
				_Config.insert(i + 1, 1, ' ');
				i++;
			}
		}
		/*** для кавычек, боже как же я все обыграл ***/
		if (_Config[i] == '}' || _Config[i] == '{')
		{
			if (_Config[i - 1] != ' ')
			{
				_Config.insert(i, 1, ' ');
				i++;
			}
			if (_Config[i + 1] != ' ')
			{
				_Config.insert(i + 1, 1, ' ');
				i++;
			}
		}
		i++;
	}
}

/** Ну тут все легко, написано максимально просто, обычный сплиит лексем **/

void Lexer::Split_Tokens()
{
	std::string::size_type begin = 0;
	std::string::size_type end;
	std::string substr;
	int i = 0;

	begin = i;
	while (_Config[i])
	{
		if (_Config[i] == ' ')
		{
			substr = _Config.substr(begin, i - begin);
			if (substr == ";")
				_Tokens.push_back(std::pair<std::string, TOKENS>(substr, SEMICOLON));
			else if (substr == "{")
				_Tokens.push_back(std::pair<std::string, TOKENS>(substr, OPEN_BRACKET));
			else if (substr == "}")
				_Tokens.push_back(std::pair<std::string, TOKENS>(substr, CLOSE_BRACKET));
			else
				_Tokens.push_back(std::pair<std::string, TOKENS>(substr, WORD));
			begin = i + 1;
		}
		i++;
	}
}

void Lexer::print_vector()
{
	std::vector<Token_type >::iterator begin = _Tokens.begin();
	std::vector<Token_type >::iterator end = _Tokens.end();

	for (; begin != end; begin++)
		std::cout << " Стринга: " << begin->first << " Токен к стринге: " << begin->second <<
		std::endl;
}

std::vector<Token_type> &Lexer::getTokens()
{
	return (_Tokens);
}