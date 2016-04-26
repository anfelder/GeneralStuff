#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
	ofstream dout;
	dout.open("RandomNumsOut.txt", ios::app);
	if(argc != 1){
		if(atoi(argv[1]) >= 1000) dout << "True" << endl;
		else					  dout << "False" << endl;
	}
	dout.close();
	return 0;
}