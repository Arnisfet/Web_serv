//
// Created by arnisfet on 28.08.2022.
//
#pragma once

#ifndef WEB_SERV_LEXER_HPP
#define WEB_SERV_LEXER_HPP

#include <vector>
#include <iostream>

enum TOKENS {
	HASHTAG,
	SEMICOLON,
	WORD,
	OPEN_BRACKET,
	CLOSE_BRACKET
};

typedef std::pair<std::string, TOKENS> Token_type;

class Lexer
{
private:
	std::string const Path;
	std::vector<Token_type> const Tokens;
public:
	Lexer();
	~Lexer();
};


#endif //WEB_SERV_LEXER_HPP
