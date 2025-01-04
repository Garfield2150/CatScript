#include "../var.hpp"

using namespace std;

void print_name()
{
	cout << "Nice to meet you, " << Input << endl;
}

unordered_map<string, void(*)()> test_library(unordered_map<string, void(*)()>FunctionMap)
{
	FunctionMap["print_name"] = &print_name;

	return FunctionMap;
}
