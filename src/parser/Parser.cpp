//
// Created by arnisfet on 03.09.2022.
//

#include "Parser.hpp"

Parser::Parser(const std::string &path) : _Path(path), _serv_nums(0)
 {
	Lexer lex(_Path);// Запоминаю путь, считываю конфиг
	lex.split(); // Бью конфиг на токены
	_Tokens =  lex.getTokens(); // Кладу токены в реализацию функций сервера (выглядит странно),
	// но я хз как иначе
 }

 Parser::~Parser()
 {
 }

 void Parser::ParseConfig()
 {
	std::vector<Token_type >::iterator begin = _Tokens.begin();
	std::vector<Token_type >::iterator end = _Tokens.end();
	for (; begin != end; begin++)
	{
		if (begin->first == "server")
		{
			if ((begin+1)->second == OPEN_BRACKET)
				begin = Parse_Server(begin);
			else
				throw Error("Expected token {");

		}
	}
	PrintServers();
 }

 std::vector<Token_type >::iterator Parser::Parse_Server(std::vector<Token_type >::iterator begin)
 {
	t_server _serv_struct;
	_serv_nums++;

	begin +=2;
	for (; begin != _Tokens.end() && begin->first != "}"; begin++)
	{
		if (begin->first == "root")
		{
			_serv_struct.root = (begin+1)->first;
			continue ;
		}
		if (begin->first == "location")
		{
			begin = AddLocation(begin);
		}
		if ((begin)->first == "server")
			break ;
	}
	_Servers.push_back(_serv_struct);
	return (begin-1);
 }

 void	Parser::PrintServers()
 {
	std::vector<t_server >::iterator begin = _Servers.begin();
	std::vector<t_server >::iterator end = _Servers.end();
	for (; begin != end; begin++)
	{
		std::cout << begin->root<< std::endl;
	}
	std::vector<std::pair<t_location, int> >::iterator l_begin = _locations.begin();
	std::vector<std::pair<t_location, int> >::iterator l_end = _locations.end();
	for (; l_begin != l_end; l_begin++)
	{
		std::cout << "дирректория локейшн " << l_begin->first.directory<< " для сервера " <<
		l_begin->second <<	std::endl ;

		std::cout << "индекс локейшн " << l_begin->first.index << " для сервера " <<
		l_begin->second <<	std::endl ;
	}
 }

 std::vector<Token_type >::iterator Parser::AddLocation(std::vector<Token_type >::iterator begin)
 {
	t_location location;
	begin++;
	location.directory = begin->first;
	if ((begin + 1)->first == "{")
	{
		begin += 2;
		for (; begin != _Tokens.end() && begin->first != "}"; begin++)
		{
			if (begin->first == "index")
			{
				location.index = (begin+1)->first;
				continue ;
			}
			if (begin->first == "methods")
			{
				for (; begin->first != ";" && begin != _Tokens.end(); begin++)
					location.methods.push_back(begin->first);
				continue ;
			}
		}
		_locations.push_back(std::pair<t_location, int>(location, _serv_nums));
	}
	return (begin);
 }
