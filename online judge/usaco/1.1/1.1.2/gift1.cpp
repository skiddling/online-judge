/*
ID: skiddling
PROG: gift1
LANG: C++
*/

#include <cstring> 
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Node{
	public:
		int id;
		string name;
		int mini, mfin, mget;

		Node(){
			mget = 0;
		}
};

class Al{
	public:
		int n;
		map<string, int> ntab;	
		vector<Node> que;	
		
		void init();
		void output();
};

void Al :: init(){
	ifstream fin("gift1.in");
	fin >> n;
	que = vector<Node> (n);
	string s;
	for(int i = 0; i < n; i++){
		fin >> s;
		ntab[s] = i;
		que[i].name = s;
	}
	int aom, nop, ave;
	for(int i = 0; i < n; i++){
		fin >> s >> aom >> nop;
		que[ntab[s]].mini = aom;
		if(nop == 0)continue;
		ave = aom / nop;
		que[ntab[s]].mget += (que[ntab[s]].mini - ave * nop);
		for(int j = 0; j < nop; j++){
			fin >> s;
			que[ntab[s]].mget += ave;	
		}
	}

}

void Al :: output(){
	ofstream fout("gift1.out");
	
	for(int i = 0; i < n; i++){
		que[i].mfin = que[i].mget - que[i].mini;
	}
	
	for(int i = 0; i < n; i++)
		fout << que[i].name << ' ' << que[i].mfin << "\n";
	
}

int main()
{
	Al al;
	al.init();
	al.output();
	return 0;
}

