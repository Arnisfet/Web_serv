//
// Created by arnisfet on 03.09.2022.
//

#include "Parser.hpp"

Parser::Parser(const std::string &path) : _serv_nums(0), _Path(path), _now_serv(0)
 {
	Lexer lex(_Path);// Запоминаю путь, считываю конфиг
	lex.split(); // Бью конфиг на токены
	_Tokens =  lex.getTokens(); // Кладу токены в реализацию функций сервера (выглядит странно),
	// но я хз как иначе

	std::vector<Token_type >::iterator begin = _Tokens.begin();
	std::vector<Token_type >::iterator end = _Tokens.end();
	for (; begin != end; begin++)
		if (begin->first == "server")
			_serv_nums++;
	_serv_struct = new t_server [_serv_nums]; // Вот это конечно мда, надеюсь сработает
 }

 Parser::~Parser()
 {
		delete[] _serv_struct;
 }

 void Parser::ParseConfig()
 {
	std::vector<Token_type >::iterator begin = _Tokens.begin();
	std::vector<Token_type >::iterator end = _Tokens.end();
	for (; begin != end && _serv_nums; begin++)
	{
		if (begin->first == "server")
		{
			if ((begin+1)->second == OPEN_BRACKET)
			{
				Parse_Server(begin);
				_serv_nums--;
			}
			else
				throw Error("Expected token {");
		}
	}
 }

 void Parser::Parse_Server(std::vector<Token_type >::iterator begin)
 {
	begin +=2;
	for (; begin != _Tokens.end(); begin++)
	{
		if (begin->first == "root")
		{
			_serv_struct[_now_serv].root = begin->first;
		}
	}

 }
