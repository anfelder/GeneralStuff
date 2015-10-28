#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

int add(int x, int y, int z){
	return ( x + y + z);
}
int addArray(int array[]){
	int a = 0;
	for(int i = 0; i < array.size() ;i++){
		a += array[i];
	}
	return a;
}

void printStuff(){
	cout << "Hello world" << endl;
}

int main(){
	int a = add(3, 4, 5);
	int ar[5] = {1, 2, 3, 4, 9};
	cout << a << endl;
	cout << add(3, 4, 5) << endl;

	cout << addArray(ar) << endl;

	printStuff();
	return 0;
}