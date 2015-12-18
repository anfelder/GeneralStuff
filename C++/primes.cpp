#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int u = 0;
	bool prime;
	while(true){
		prime = true;
		cin >> u;
		for(int i = 2; i <= sqrt(u);i++){
			if(u % i == 0){
				prime = false;
			}
		}
		if(prime){
			cout << u << " is prime" << endl;
		}
		else cout << u << " is not prime" << endl;
	}
	return 0;
}