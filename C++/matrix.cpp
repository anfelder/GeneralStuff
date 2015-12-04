#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int generateRand(){
	int t = rand() % 100;
	if (t > 34){
		t = 34;
	}
	return t;
}
int main(){
	char characters[35] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','!','@','#','$','%','^','&','*',' '};
	srand(time(NULL));
	while(true){
		cout << characters[generateRand()];
	}
	return 0;
}