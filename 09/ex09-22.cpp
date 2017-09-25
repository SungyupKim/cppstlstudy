#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void main() 
{
	string a = "? ? ?";
	string::size_type start = 0;
	int paramindex = 0;
	while ((start = a.find("?", start)) != string::npos){
		string index_string = ":" + to_string(paramindex++);
	}
}