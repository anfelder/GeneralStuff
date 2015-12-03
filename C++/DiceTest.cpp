#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int d6(){
	return (1 + rand() % 6);
}
int d20(){
	return (1 + rand() % 20);
}
void FindMin(int &d1, int &d2, int &d3, int &d4){
	int m1 = min(d1, d2);
	int m2 = min(d3, d4);
	int m3 = min(m1, m2);
	if(m3 == d1) d1 = 0;
	else if(m3 == d2) d2 = 0;
	else if(m3 == d3) d3 = 0;
	else if(m3 == d4) d4 = 0;
}
void CheckTotals(int &num18, int &num17, int &num16, int &num15, int d1, int d2, int d3, int d4){
	int total = d1 + d2 + d3 + d4;
	if(total == 18) num18++;
	else if(total == 17) num17++;
	else if(total == 16) num16++;
	else if(total == 15) num15++;
}
float StatRollAvg(){
	float c_total = 0;
	int d1 = 0;
	int d2 = 0;
	int d3 = 0;
	int d4 = 0;
	int num18 = 0;
	int num17 = 0;
	int num16 = 0;
	int num15 = 0;
	for(int i = 0; i < 1000;i++){
		d1 = d6();
		d2 = d6();
		d3 = d6();
		d4 = d6();
		FindMin(d1, d2, d3, d4);
		CheckTotals(num18, num17, num16, num15, d1, d2, d3, d4);
		c_total += d1 + d2 + d3 + d4;
	}
	cout << "18: " << num18 << endl
		 << "17: " << num17 << endl
		 << "16: " << num16 << endl
		 << "15: " << num15 << endl;
		  
	return (c_total/1000.0);
}
float AdvAvg(){
	float c_total;
	for(int i = 0; i < 1000; i++){
		c_total += max(d20(),d20());
	}
	return c_total/1000;
}
float DisadvAvg(){
	float c_total;
	for(int i = 0; i < 1000; i++){
		c_total += min(d20(),d20());
	}
	return c_total/1000;
}
float Normald20Avg(){
	float c_total = 0;
	for(int i = 0; i < 1000; i++){
		c_total += d20();
	}
	return (c_total/1000);
}
int main(){
	srand(time(NULL));
	int choice = 0;
	system("clear");
	do{
		cout << "Options (All are tested with 1000 sets of rolls):" << endl;
		cout << "1: Average total of 4d6 drop low die" << endl
			 << "2: Average roll of a d20" << endl
			 << "3: Average roll of a d20 with Advantage" << endl
			 << "4: Average roll of a d20 with Disadvantage" << endl;
		cout << "Enter your choice (1-4): ";
		cin >> choice;
	}while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
	switch(choice){
		case 1:
			cout << "Average total of 4d6 drop low die: " << StatRollAvg() << endl;
			break;
		case 2:
			cout << "Average roll of a d20: " << Normald20Avg() << endl;
			break;
		case 3:
			cout << "Average roll of a d20 with Advantage: " << AdvAvg() << endl;
			break;
		case 4:
			cout << "Average roll of a d20 with Disadvantage: " << DisadvAvg() << endl;
			break;
		default:
			cout << "Error in switch statement" << endl;
	}
	return 0;
}