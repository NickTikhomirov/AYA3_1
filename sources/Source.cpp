#include <iostream>
#include "json.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

using std::cout;
using std::any_cast;
using std::string;



int main() {
	Json a = Json::parseFile(string("/mnt/c/aya/somebody_once_told_me.txt"));
	if (!any_cast<bool>(a["islegal"]))
		cout << "\n\n FILE PARSING DONE NICELY \n\n";

	json c = json::array({
									   {"Si-9.15", "RTS-9.15", "GAZP-9.15"},
									   {100024, 100027, 100050},
									   {"Futures contract for USD/RUB", "Futures contract for index RTS", "Futures contract for Gazprom shares"}
	});
	json b = json::array();
	size_t i = 0;
	for (size_t j = 0; j < c.begin()->size(); ++j) {
		i = 0;
		json tmp = json::object();
		for (; i < c.size(); ++i) {
			switch (i) {
			case 0:
				tmp["ticker"] = c[i][j];
				break; 
			case 1:
				tmp["id"] = c[i][j];
				break; 
			case 2:
				tmp["description"] = c[i][j];
				break; 
			}
		}
		b.push_back(tmp);
	}
	c = b;
	for (string s : {"ticker", "id", "description"}){
		cout << s << ":\n";
		for (size_t j : {0, 1, 2}) 
			cout << c[j][s] << "\n";
	}
}
