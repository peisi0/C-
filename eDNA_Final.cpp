#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const string dna_given_filepath = "Invasive example.txt";
vector<string> dna_sample = {"CARP1/Bighead Carp.txt", "CARP1/Black Carp.txt", "CARP1/Grass Carp.txt", "CARP1/Silver Carp.txt"};

string bigheadCarp;
string blackCarp;
string grassCarp;
string silverCarp;

vector<string> UnknownSample;

int readSample(vector<string> & dna) {
    ifstream file(dna_given_filepath);
    string data;
    
    if (!file.is_open()) {
        cerr << "Error occur in opening the file!" << endl;
        return 1;
    }
    
    int i = 0;
    while(getline(file, data)) {
        if (i % 2 == 0) {
            dna.push_back(data);
        }
        i ++;
    }
    return 0;
}

int readDNA(string fileName, string &variable) {
    ifstream file(fileName);
    
    if (!file.is_open()) {
        cerr << "Error occur in opening the file!";                               
        return 1;
    }
    
    getline(file, variable);
    file.close();
    return 0;
}

bool compare(string str, string substring) {
    size_t pos = str.find(substring);
    if (pos == string::npos) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    readDNA(dna_sample[0], bigheadCarp);
    readDNA(dna_sample[1], blackCarp);
    readDNA(dna_sample[2], grassCarp);
    readDNA(dna_sample[3], silverCarp);
    
    readSample(UnknownSample);
    
    for (int i = 0;i < 10;i++){
    	if (compare(UnknownSample[i], bigheadCarp) == 0){
    		cout << "The Unknown Sample " << i + 1 << "matches that of the Bighead Carp";
		}
		if (compare(UnknownSample[i], silverCarp) == 0){
    		cout << "The Unknown Sample " << i + 1 << "matches that of the Bighead Carp";
		}
		if (compare(UnknownSample[i], grassCarp) == 0){
    		cout << "The Unknown Sample " << i + 1 << "matches that of the Bighead Carp";
		}
		if (compare(UnknownSample[i], blackCarp) == 0){
    		cout << "The Unknown Sample " << i + 1 << "matches that of the Bighead Carp";
		}
	}
    
    
    
//    cout << compare(UnknownSample[1], blackCarp) << endl;

    return 0;
}
