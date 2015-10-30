#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

int add(int x, int y, int z){
	return ( x + y + z);
}


void printStuff(){
	cout << "Hello world" << endl;
}

void addOne(int &num){
	num++;
}

int addOneNR(int num){
	return num++;
}
int main(){
	int a = add(3, 4, 5);
	cout << a << endl;
	cout << add(3, 4, 5) << endl;

	int n = 5;
	n = addOneNR(n);
	cout << n << endl;

	addOne(n);
	cout << n << endl;
	//printStuff();
	return 0;
}