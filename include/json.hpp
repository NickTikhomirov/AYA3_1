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
	map<string, any> init_object(string& s, size_t start);
	vector<any> init_array_contents(string& s, size_t start);
	any init_right_of_pair(string& s, size_t& start);
public:
	// Конструктор из строки, содержащей Json-данные.
	Json(const string& s);

	// Метод возвращает true, если данный экземпляр содержит в себе JSON-массив. Иначе false.
	bool is_array() const;
	// Метод возвращает true, если данный экземпляр содержит в себе JSON-объект. Иначе false.
	bool is_object() const;

	// Метод возвращает значение по ключу key, если экземпляр является JSON-объектом.
	// Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
	// Если экземпляр является JSON-массивом, генерируется исключение.
	any& operator[](const string& key);

	// Метод возвращает значение по индексу index, если экземпляр является JSON-массивом.
	// Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
	// Если экземпляр является JSON-объектом, генерируется исключение.
	any& operator[](size_t index);

	// Метод возвращает объект класса Json из строки, содержащей Json-данные.
	static Json parse(const string& s);

	// Метод возвращает объекта класса Json из файла, содержащего Json-данные в текстовом формате.
	static Json parseFile(const std::string& path_to_file);
private:
	map<string, std::any> object;
	vector<any> array;
};



#endif // INCLUDE_JSON_HPP_
