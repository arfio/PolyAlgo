#include <iostream>
#include <string>
#include <chrono>
#include <sstream>

using namespace std;
using namespace std::chrono;

int main() {
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	/*******************************TEST*******************************/
	streambuf *backup;
	istringstream oss("1213211211\n");
	backup = cin.rdbuf();
	cin.rdbuf(oss.rdbuf());
	/******************************************************************/
	string conway = "";
	string conway1 = "";
	string conway2 = "";
	
	getline(cin, conway);
	bool estPremierConway = false;
	while (!estPremierConway && conway1.size() % 2 == 0){
		char c = 0;
		char c2 = 0;
		char c2_1 = 0;
		int i = 0;
		while ((unsigned)(i + 1) < conway.size()){
			c = conway[i++];
			c2 = conway[i++];

			c -= 48;
			while (c > 0){
				conway2 += c2;
				c--;
			}
			if (c2_1 == c2){
				estPremierConway = true;
				break;
			}
			c2_1 = c2;
		}
		i = 0;
		conway1 = conway;
		conway = conway2;
		conway2 = "";
		if (conway1 == conway){
			cout << ":(";
			return 0;
		}
	}
	cout << conway1;
	/********************************************************************************/

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(t2 - t1).count();
	cout << endl << "duration:" << duration << endl;
	return 0;
}
