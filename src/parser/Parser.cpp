//
// Created by arnisfet on 03.09.2022.
//

#include "Parser.hpp"

Parser::Parser(std::vector<Token_type> Tokens) : _Tokens(Tokens), _serv_nums(0)
 {
	std::vector<Token_type >::iterator begin = _Tokens.begin();
	std::vector<Token_type >::iterator end = _Tokens.end();
	for (; begin != end; begin++)
		if (begin->first == "server") _serv_nums++;
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
	TOKENS i;
	for (; begin != end; begin++)
	{
		i = begin->second;
//		switch (i)
//		{
//			case
//		}

	}
 }

