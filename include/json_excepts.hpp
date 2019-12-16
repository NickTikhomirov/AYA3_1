// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_EXCEPTS_HPP_
#define INCLUDE_EXCEPTS_HPP_

#include <exception>
#include <string>

using std::exception;
using std::string;

namespace json_exception {
	class JsonException : public exception{
		const char* msg;
	public:
		JsonException(char* r) : msg(r){}
		const char* what() const noexcept {
			return msg;
		}
	};

	class JsonArgumentException : public JsonException{
	public:
		JsonArgumentException(char* r) : JsonException(r) {}
	};
}
#endif
