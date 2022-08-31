//
// Created by arnisfet on 28.08.2022.
//
#pragma once

#ifndef WEB_SERV_LEXER_HPP
#define WEB_SERV_LEXER_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>


enum TOKENS {
	SEMICOLON,
	WORD,
	OPEN_BRACKET,
	CLOSE_BRACKET
};

typedef std::pair<std::string, TOKENS> Token_type;

class Lexer
{
private:
	std::string _Path;
	std::string _Config;
	std::vector<Token_type> _Tokens;
public:
	Lexer();
	Lexer(const std::string &path);
	std::string Remove_Space(std::string line);
	void Make_Simple_Tokens();
	void split();
	void Split_Tokens();
	~Lexer();
};


#endif //WEB_SERV_LEXER_HPP
