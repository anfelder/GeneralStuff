#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>
#include <sstream>
using namespace std;


string to_string(int i){
	stringstream ss;
	ss << i;
	return ss.str();
}

int fibRecusive(int num_wanted){
	if(num_wanted <= 2) return 1;
	return fibRecusive(num_wanted - 1) + fibRecusive(num_wanted-2);
}

int fibWithMap(int num_wanted, map<string, int> &fib_values){
	//key is found in map
	map<string, int>::iterator it; 
	it = fib_values.find(to_string(num_wanted));
	if(it != fib_values.end()){
		return it->second;
	}else{
		int final_val = fibWithMap(num_wanted-1, fib_values) + fibWithMap(num_wanted-2, fib_values);
		fib_values[to_string(num_wanted)]=final_val;
		return final_val;
	}
}

int main(){

	map<string, int> fib_values; 
	fib_values["0"]=0;
	fib_values["1"]=1;
	fib_values["2"]=1;
	
	// time_t start_timer_NM;
	// time_t end_timer_NM;
	time_t start_timer_M;
	time_t end_timer_M;

	// time(&start_timer_NM);

	// cout << "Without Map value: " << (long unsigned) fibRecusive(47) << endl;

	// time(&end_timer_NM);

	// double seconds = difftime(end_timer_NM, start_timer_NM);
	// cout << "Seconds to complete (Without Map): " << seconds << endl;

	time(&start_timer_M);

	cout << (long unsigned)fibWithMap(50000, fib_values) << endl;

	time(&end_timer_M);

	double seconds = difftime(end_timer_M, start_timer_M);
	cout << "Seconds to complete (With Map): " << seconds << endl;

	return 0;
}