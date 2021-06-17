#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>
#include <math.h>

using namespace std;


int main() {

	//opening and reading the file with the resampled values
	ifstream res;
	res.open("C:/Users/valea/source/repos/SISCorrections/SISCorrections/R4_Runs/R4_resampled_m0095.csv");
	vector < double > line_resampled;
	string st_line1;
	while (res >> st_line1) {
		size_t i1 = 0, start1 = 0, end1;
		string temp1;
		do {
			end1 = st_line1.find_first_of(',', start1);
			temp1 = st_line1.substr(start1, end1);
			line_resampled.push_back(atof(temp1.c_str()));
			i1++;
			start1 = end1 + 1;
		} while (start1);
	}
	vector < vector < double > > resampled(1000, vector < double >(31, 0.0));
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 31; j++) {
			resampled[i][j] = line_resampled[j + 31 * i];
		}
	}
	for (int i = 0; i < 1000; i++) {
		resampled[i].pop_back();
	}
	res.close();


	//opening and reading the file with the "observed" data
	ifstream real_value;
	real_value.open("C:/Users/valea/source/repos/SISCorrections/SISCorrections/R4_Runs/R4_vector_X_m0095.dat");
	vector < double > X;
	int i2 = 0;
	double st_line2;
	while (!real_value.eof()) {
		real_value >> st_line2;
		X.push_back(st_line2);
		i2++;
	}
	X.pop_back();


	//opening and reading the file with the observations
	ifstream real_obs;
	real_obs.open("C:/Users/valea/source/repos/SISCorrections/SISCorrections/R4_Runs/R4_vector_Z_m0095.dat");
	vector < int > Z;
	int i3 = 0;
	double st_line3;
	while (!real_obs.eof()) {
		real_obs >> st_line3;
		Z.push_back(st_line3);
		i3++;
	}
	Z.pop_back();







	return 0;
}