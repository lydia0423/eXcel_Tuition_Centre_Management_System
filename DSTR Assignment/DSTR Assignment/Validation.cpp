#include <iostream>
#include <string>

using namespace std;

void tokenize(string s, string del = " "){
	int start = 0;
	int end = s.find(del);
	while (end != -1) {
		cout << s.substr(start, end - start) << endl;
		start = end + del.size();
		end = s.find(del, start);
	}
	cout << s.substr(start, end - start);
}