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

class Parser
{
private:
	std::vector<t_server> _Servers; // Вектор в котором будут хранится все структуры, равные
	// кол-ву серверов
	std::vector<Token_type> _Tokens;
	int _serv_nums;
	t_server *_serv_struct;
public:
	Parser(std::vector<Token_type> Tokens);
	~Parser();
	void ParseConfig();

};


#endif //WEB_SERV_PARSER_HPP
