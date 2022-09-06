//
// Created by arnisfet on 03.09.2022.
//

#ifndef WEB_SERV_PARSER_HPP
#define WEB_SERV_PARSER_HPP

#include "Lexer.hpp"
/***
 * Создал словарь, должен помочь при парсинге
 */
enum DICTIONARY	{SERVER, LOCATION};
typedef struct s_location t_location;
/**** Вот тут начинается треш, первый объект - структура под серверные переменные
 * 		как говорится нет динамической памяти - нет проблем					****/

typedef struct server{
	std::string root;
	std::string index;
} t_server;

typedef struct s_location{
	std::string directory;
	std::vector<std::string> methods;
	std::string index;
}t_location;

class Lexer;
class Parser
{
private:
	std::vector<t_server> _Servers; // Вектор в котором будут хранится все структуры, равные
	// кол-ву серверов
	std::vector<std::pair<t_location, int> > _locations; // Гениально простое решение без
	// рекурсивных вкладок
	std::string _Path;
	std::vector<Token_type> _Tokens;
	int _serv_nums;

public:
	Parser(const std::string &path);
	~Parser();
	void ParseConfig();
	std::vector<Token_type >::iterator Parse_Server(std::vector<Token_type >::iterator begin);
	/*** Класс Exception по еблу ***/
	class Error : public std::exception
			{
			public:
				Error(const char *err_msg) : err_msg(err_msg) {};
				virtual const char *what() const throw() {return (this->err_msg);}

			private:
				const char *err_msg;
			};
	void	PrintServers();
	std::vector<Token_type>::iterator
	AddLocation(std::vector<Token_type>::iterator begin);
};


#endif //WEB_SERV_PARSER_HPP
