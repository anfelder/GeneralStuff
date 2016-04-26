#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
	
	float r = 0;
	float n = 2;
	float r2, n2;

	for(int i = 0;i<1000;i++){
		r2 = r*r;
		n2 = n*n;
		float val = (r2 - r)/(n2-n);
		cout << val << endl;
		if(val == .5) cout << "true" << endl;

		r++;
		n++;
	}

	return 0;
}