#include <iostream>

using namespace std;
double times[50];
void squared(){
	double n = 1;
	double rate = 0;
	double t = 0; //time
	int i = 0;
	for(n;n < 14000;n*=2){
		double val = 50*n*n;
		cout << "Enter time for n =" << n << ": ";
		cin >> t;
		rate = val/t;
		//cout << "n: "<< n << " val: " << val << endl;
		times[i] = rate;
		i++;
	}	
}

void incby1000(){
	long n = 1500;
	for(n;n<14000;n+=1000){
		long val = 50*n*n;
		cout << "n: "<< n << " val: " << val << endl;
	}
}

int power(int ex, int base){
	long total = 1;
	for(int i =0;i<ex;i++){
		total *= base;
	}
	return total;
}

int main(){
	for(int i = 0;i<50;i++){
		times[i] = 0;
	}
	squared();
	for(int i = 0; i++;i<15){
		cout << "n: " << power(i,2) << " rate: " << times[i] << endl;
	}
	//incby1000();
	return 0;
}