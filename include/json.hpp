// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_JSON_HPP_
#define INCLUDE_JSON_HPP_

#include <utility>
#include <string>
#include <any>
#include <vector>
#include <map>


using std::map;
using std::pair;
using std::vector;
using std::size_t;
using std::string;
using std::any;



class Json {
	map<string, any> init_object(const string& s, const size_t start);
	vector<any> init_array_contents(const string& s, const size_t start);
	pair<any, size_t> init_right_of_pair(const string& s, const size_t start);
public:
	// ����������� �� ������, ���������� Json-������.
	Json(const string& s);

	// ����� ���������� true, ���� ������ ��������� �������� � ���� JSON-������. ����� false.
	bool is_array() const;
	// ����� ���������� true, ���� ������ ��������� �������� � ���� JSON-������. ����� false.
	bool is_object() const;

	// ����� ���������� �������� �� ����� key, ���� ��������� �������� JSON-��������.
	// �������� ����� ����� ���� �� ��������� �����: Json, std::string, double, bool ��� ���� ������.
	// ���� ��������� �������� JSON-��������, ������������ ����������.
	any& operator[](const string& key);

	// ����� ���������� �������� �� ������� index, ���� ��������� �������� JSON-��������.
	// �������� ����� ����� ���� �� ��������� �����: Json, std::string, double, bool ��� ���� ������.
	// ���� ��������� �������� JSON-��������, ������������ ����������.
	any& operator[](size_t index);

	// ����� ���������� ������ ������ Json �� ������, ���������� Json-������.
	static Json parse(const string& s);
private:
	map<string, std::any> object;
	vector<any> array;
};

#endif // INCLUDE_JSON_HPP_
