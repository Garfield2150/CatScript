#include "var.h"

using namespace std;

void print_name()
{
	cout << "Nice to meet you, " << Input << endl;
}

unordered_map<string, void(*)()> Linker(unordered_map<string, void(*)()>FunctionMap)
{
	FunctionMap["print_name"] = &print_name;

	return FunctionMap;
}
