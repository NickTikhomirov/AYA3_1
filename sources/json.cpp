// Copyright 2018 Your Name <your_email>

#include "json.hpp"
#include "json_tools.hpp"

using std::map;
using std::pair;
using std::vector;
using std::size_t;
using std::string;
using std::any;


Json::Json(const string& s){
	string str = s;
	JsonTools::filler(str);
	switch (str[0]) {
		case '{':
			object = init_object(str, 1);
			break;
		case '[':
			array = init_array_contents(str, 1);
			break;
		default:
			throw std::exception();
	}
}

Json Json::parse(const string& s) {
	return Json(s);
}

bool Json::is_array() const{
	return !array.empty();
}

bool Json::is_object() const{
	return !object.empty();
}

any& Json::operator[](const string & key){
	if (is_object())
		return object[key];
	throw std::exception();
}

any& Json::operator[](size_t index){
	if (is_array())
		return array[index];
	throw std::exception();
}



map<string, any> Json::init_object(const string & s, const size_t start){
	map<string, any> result;
	pair<any, size_t> value;
	for (size_t i = start; i <= s.size(); ++i){
		JsonTools::expect_(s[i], '\"');
		string key = JsonTools::parse_string_literally(s, ++i);
		i += key.size() + 1;
		JsonTools::expect_(s[i], ':');
		value = init_right_of_pair(s, ++i);
		result.emplace(key, value.first);
		if (s[i] == '\"') ++i;
		i += value.second;
		if (s[i] == '}') break;
		else JsonTools::expect_(s[i], ',');
	}
	return result;
}

vector<any> Json::init_array_contents(const string& s, const size_t start){
	vector<any> result;
	pair<any, size_t> value;
	for (size_t i = start; i < s.size(); ++i) {
		value = init_right_of_pair(s, i);
		result.push_back(value.first);
		i += value.second;
		if (s[i] == ']') break;
		else JsonTools::expect_(s[i], ',');
	}
	return result;
}

pair<any, size_t> Json::init_right_of_pair(const string & s, const size_t start){
	size_t i = start;
	any value;
	string str;
	if (s[i] == '\"'){
		str = JsonTools::parse_string_literally(s, start + 1);
		i += str.size() + 1;
		value = str;
	} else if (s[i] == '[') {
		size_t end = JsonTools::size_of_item(s, i, '[', ']');
		str = s.substr(i, end);
		value = Json(str);
		i += end;
	} else if (s[i] == '{') {
		size_t end = JsonTools::size_of_item(s, i, '{', '}');
		str = s.substr(i, end);
		value = Json(str);
		i += end;
	} else if (JsonTools::is_digit(s[i])) {
		str = JsonTools::parse_number(s, start);
		i += str.size()-1;
		value = atof(str.c_str());
	} else {
		bool gotit = false;
		JsonTools j;
		for (auto p : j.allowedLexems) {
			if (s.substr(i, p.first.length()) == p.first) {
				i += p.first.length();
				value = p.second;
				gotit = true;
				break;
			}
		}
		if(!gotit) throw std::exception();
	}
	return pair<any, size_t>(value, i - start);
}

