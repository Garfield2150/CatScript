#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include "linker.cpp"
#include "var.h"

using namespace std;

string Input;

bool EndsWith (std::string const &fullString, std::string const &ending)
{
	if(fullString.length() >= ending.length())
	{
		return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
	}
	else
	{
		return false;
	}
}

std::string trim(const std::string& str) {
	    auto start = str.begin();
	        while (start != str.end() && std::isspace(*start)) ++start;
		    auto end = str.end();
		        do { --end; } while (end != start && std::isspace(*end));
			    return std::string(start, end + 1);
}

bool replace(std::string& str, const std::string& from, const std::string& to) {
	    size_t start_pos = str.find(from);
	        if(start_pos == std::string::npos)
			        return false;
		    str.replace(start_pos, from.length(), to);
		        return true;
}

int main(int argc, char *argv[])
{
	if(!argv[1])
	{
		puts("Eiwor: pwss spesify da path to file :3");

		return 1;
	}

	string Path = argv[1];
	ifstream file(Path);
	string Line;
	string Temp;

	unordered_map<string, void(*)()>FunctionMap;
	FunctionMap = Linker(FunctionMap);

	if(!file.is_open())
	{
		puts("Eiwor: nu file found :<");

		return 1;
	}

	while(getline(file, Line))
	{
		Line = trim(Line);

		replace(Line, "\\&e", "");

		if(Line.empty()){}
		else if(Line.rfind("#", 0) == 0){}
		else if(Line.rfind("meow", 0) == 0)
		{
			Line.erase(0, 4);
			if(Line.rfind(" ", 0) == 0)
			{
				cout << Line.erase(0, 1) << endl;
			}
			else
			{
				puts("Eiwor: nu spess aftuhr keywurd :<");

				return 1;
			}
		}
		else if(Line.rfind("lissen", 0) == 0)
		{
			Line.erase(0, 6);
			if(Line.rfind(" ", 0) == 0)
			{
				cout << Line.erase(0, 1);
				getline(cin, Input);
			}
			else
			{
				getline(cin, Input);
			}
		}
		else if(Line.rfind("if", 0) == 0)
		{
			Line.erase(0, 2);
			if(!(Line.rfind(" ", 0) == 0))
			{
				puts("Eiwor: nu spess aftuhr keywurd :<");

				return 1;
			}
			Line.erase(0, 1);
			reverse(Line.begin(), Line.end());
			if(!(Line.rfind("ned", 0) == 0))
			{
				puts("Eiwor: nu den keywurd :<");

				return 1;
			}
			Line.erase(0, 3);
			if(!(Line.rfind(" ", 0) == 0))
			{
				puts("Eiwor: nu spess b4 den :<");

				return 1;
			}
			Line.erase(0, 1);
			reverse(Line.begin(), Line.end());
			if(Input.compare(Line) == 0){}
			else
			{
				while(!(Line.rfind("bai", 0) == 0))
				{
					getline(file, Line);
					Line = trim(Line);
					if(Line.rfind("if", 0) == 0)
					{
						Line = "bai";
					}
				}
			}
		}
		else if(Line.rfind("bai", 0) == 0){}
		else if(EndsWith(Line, ":")){}
		else if(Line.rfind("set", 0) == 0)
		{
			Line.erase(0, 3);
			if(!(Line.rfind(" ", 0) == 0))
			{
				puts("Eiwor: nu spess aftuhr keywurd :<");

				return 1;
			}
			Line.erase(0, 1);
			Input = Line;
		}
		else if(Line.rfind("goto", 0) == 0)
		{
			Line.erase(0, 4);
			if(!(Line.rfind(" ", 0) == 0))
			{
				puts("Eiwor: nu spess aftuhr keywurd :<");

				return 1;
			}
			Line.erase(0, 1);
			Temp = Line + ":";
			file.clear();
			file.seekg(0);
			while(!(Line.rfind(Temp, 0) == 0))
			{
				getline(file, Line);
				Line = trim(Line);
			}
		}
		else if(Line.rfind("kawl", 0) == 0)
		{
			Line.erase(0, 4);
			if(!(Line.rfind(" ", 0) == 0))
			{
				puts("Eiwor: nu spess aftuhr keywurd :<");

				return 1;
			}
			Line.erase(0, 1);
			if(FunctionMap.find(Line) != FunctionMap.end())
			{
				FunctionMap[Line]();
			}
			else
			{
				puts("Eiwor: nu function :<");

				return 1;
			}
		}
		else
		{
			puts("Eiwor: unno keywurd :<");

			return 1;
		}
	}


	file.close();
	return 0;
}
