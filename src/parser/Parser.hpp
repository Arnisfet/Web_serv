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

/**** Вот тут начинается треш, первый объект - структура под серверные переменные****/
typedef struct server{
	std::string root;
} t_server;
class Lexer;
class Parser
{
private:
//	std::vector<t_server> _Servers; // Вектор в котором будут хранится все структуры, равные
	// кол-ву серверов
	std::string _Path;
	std::vector<Token_type> _Tokens;
	int _serv_nums;
	int _now_serv;
	t_server *_serv_struct;

public:
	Parser(const std::string &path);
	~Parser();
	void ParseConfig();
	void Parse_Server(std::vector<Token_type >::iterator begin);

	class Error : public std::exception
			{
			public:
				Error(const char *err_msg) : err_msg(err_msg) {};
				virtual const char *what() const throw() {return (this->err_msg);}

			private:
				const char *err_msg;
			};

};


#endif //WEB_SERV_PARSER_HPP
