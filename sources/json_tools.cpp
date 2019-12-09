#include "json_tools.hpp"


using std::string;
using std::size_t;


void JsonTools::expect_(char a, char b) {
	if(a!=b) throw std::exception();
}


bool JsonTools::is_digit(const char c){return c >= '0' && c <= '9';}

size_t JsonTools::size_of_item(const string& s, const size_t current, const char start, const char end){
	size_t st = 1, en = 0, i = current + 1;
	while (st != en && i <= s.size()){
		if (s[i] == start) ++st;
		if (s[i] == end) ++en;
		++i;
	}
	return i - current;
}

void JsonTools::filler(string& s){
	size_t i = 0;
	while (i < s.size()){
		if (s[i] == '\n' || s[i] == '\r' || s[i] == '\t' || s[i] == ' ') s.erase(s.begin() + i);
		else ++i;
	}
}

string JsonTools::parse_string_literally(const string& s, const size_t start){
	size_t i = start;
	for(; s[i] != '\"' && i<=s.size(); ++i);
	return s.substr(start, i-start);
}

string JsonTools::parse_number(const string& s, const size_t start){
	size_t i = start;
	for (; i < s.length() && is_digit(s[i]); ++i);
	return s.substr(start,i-start+1);
}
