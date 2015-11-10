#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
	fstream f;
	char filename[] = "test.txt";
	f.open(filename);
	string input = "test";
	getline(f, input);
	cout << input << endl;
	f << "new stuff";
	getline(f, input);
	cout << input << endl;
	return 0;
}