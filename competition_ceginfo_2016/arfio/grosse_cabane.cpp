#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int main() {

	/*******************************TEST*******************************/
	streambuf *backup;
	istringstream oss("3 4\noxox\nxoxo\noxox\n");
	backup = cin.rdbuf();
	cin.rdbuf(oss.rdbuf());
	/*******************************************************************/

	int l = 0;
	cin >> l;
	int c = 0;
	cin >> c;
	
	bool* plan = new bool[l*c];
	char place = 0;
	for (int i = 0; i < l*c; i++){
		cin.get(place);
		if (place == 'x')
			plan[i] = false;
		else if (place == 'o')
			plan[i] = true;
		else
			i--;
	}
	std::stack<int> caseAVerifier;
	int nSalles = 0;
	int i = 0;
	
	while (i < c*l){
		if (plan[i] == true){
			caseAVerifier.push(i);
			plan[i] = false;
			nSalles++;
		}
		else{
			i++;
			continue;
		}
		while (!caseAVerifier.empty()){
			int pos = caseAVerifier.top();
			caseAVerifier.pop();
			if (pos + 1 > 0 && pos + 1 < c*l && pos % c != c - 1 && plan[pos + 1] == true){
				caseAVerifier.push(pos + 1);
				plan[pos + 1] = false;
			}
			if (pos - 1 > 0 && pos - 1 < c*l && pos % c != 0 && plan[pos - 1] == true){
				caseAVerifier.push(pos - 1);
				plan[pos - 1] = false;
			}
			if (pos + c > 0 && pos + c < c*l && plan[pos + c] == true){
				caseAVerifier.push(pos + c);
				plan[pos + c] = false;
			}
			if (pos - c > 0 && pos - c < c*l && plan[pos - c] == true){
				caseAVerifier.push(pos - c);
				plan[pos - c] = false;
			}
		}
	}
	cout << nSalles << endl;
	return 0;
}
