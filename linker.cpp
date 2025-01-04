#include "lib/test_library.cpp"

unordered_map<string, void(*)()> Link(unordered_map<string, void(*)()>FunctionMap)
{
	FunctionMap = test_library(FunctionMap);

	return FunctionMap;
}
