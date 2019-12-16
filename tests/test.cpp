//Copyright 1991 nikitos
#include <gtest/gtest.h>
#include <string>
#include "json.hpp"


using std::any_cast;


TEST(Json, ReadString) {
	string potential_json = "\
	{\
		\"lastname\" : \"Ivanov\",\
		\"firstname\" : \"Ivan\",\
		\"age\" : 25,\
		\"islegal\" : false,\
		\"marks\" : [\
    		4,5,5,5,2,3\
		],\
		\"address\" : {\
    		\"city\" : \"Moscow\",\
			\"street\" : \"Vozdvijenka\"\
		}\
	}";
	Json that_thing = Json::parse(potential_json);
	EXPECT_EQ(any_cast<std::string>(that_thing["lastname"]), "Ivanov");
	EXPECT_EQ(any_cast<std::string>(that_thing["firstname"]), "Ivan");
	EXPECT_TRUE(!any_cast<bool>(that_thing["islegal"]));
	EXPECT_EQ(any_cast<double>(that_thing["age"]), 25);
	Json marks = any_cast<Json>(that_thing["marks"]);
	EXPECT_EQ(any_cast<double>(marks[0]), 4);
	EXPECT_EQ(any_cast<double>(marks[1]), 5);
	Json address = any_cast<Json>(that_thing["address"]);
	EXPECT_EQ(any_cast<std::string>(address["city"]), "Moscow");
	EXPECT_EQ(any_cast<std::string>(address["street"]), "Vozdvijenka");
}
