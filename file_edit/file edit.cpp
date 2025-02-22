#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	char IN[100];
	
	ofstream pp;
	pp.open("bbt.txt");
	
	cin.getline(IN, 100);
	pp << IN << endl;
	pp.close();
}
	
