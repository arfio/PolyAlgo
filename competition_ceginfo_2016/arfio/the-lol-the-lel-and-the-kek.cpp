#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <list>
using namespace std;

int main() {

	/*******************************TEST*******************************/
	streambuf *backup;
	istringstream oss("lol\ncar\nlol lil lel kel kek par pap pak kap kak kar rak lap pal pal lol car");
	backup = cin.rdbuf();
	cin.rdbuf(oss.rdbuf());
	/*********************************************************************/

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	string motDepart;
	getline(cin, motDepart);

	string motFin;
	getline(cin, motFin);

	list<string> mots;
	mots.sort();

	string temp;
	while (!cin.eof()){
		cin >> temp;
		mots.push_back(temp);
	}

	list<string> reponsesPossibles;

	queue<string> reponses;
	reponses.push(motDepart);

	// Tant qu'il reste un chemin possible
	while (!reponses.empty()){
		string reponse = reponses.front();
		reponses.pop();
		// Pour tous les mots du dictionnaire
		for (auto mots_it = mots.begin(); mots_it != mots.end();){
			// la derniere reponse
			string lastRep = reponse.substr(reponse.length() - motDepart.length(), reponse.length());
			int difCount = 0;
			// Pour toutes les lettres du mot
			for (int i = 0; (unsigned) i < mots_it->length(); i++){
				if (lastRep[i] != (*mots_it)[i]){
					difCount++;
				}
			}
			if (difCount == 1){
				string newRep = reponse + " " + *mots_it;
				if (*mots_it == motFin){
					reponsesPossibles.push_back(newRep);
					break;
				}
				reponses.push(newRep);
				mots_it = mots.erase(mots_it);
			}
			else
				mots_it++;
		}
	}
	if (!reponsesPossibles.empty()){
		reponsesPossibles.sort();
		cout << *reponsesPossibles.begin();
	}
	else
		cout << ":(";

	return 0;
}
