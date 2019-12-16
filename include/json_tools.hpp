//Copyright 2019 nikitos
#ifndef INCLUDE_TOOLS_HPP_
#define INCLUDE_TOOLS_HPP_


#include <unordered_map>
#include <string>
#include <utility>
#include <any>

using std::unordered_map;
using std::string;
using std::size_t;
using std::any;

struct JsonTools{
	unordered_map<string, any> allowedLexems{ {"false", false}, {"true", true}, {"null", nullptr} };

	static void expect_(char,char);
	static void filler(string&);
	static size_t size_of_item(const string&, const size_t, const char, const char);
	static string parse_string_literally(const string&, const size_t);
	static string parse_number(const string&, const size_t);
	static bool is_digit(const char c);
};


#endif
