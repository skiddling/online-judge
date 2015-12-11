/*
ID: skiddling
PROG: milk2
LANG: C++
*/

#include <cstring> 
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Node{
	public:
		int s, e;
		
		bool operator < (const Node &a)const;
};

bool Node :: operator < (const Node &a)const{
	if(s != a.s)return s < a.s;
	else return e < a.e;
}

class Al{
	public:
		int n;
		vector<Node> vec;
		ifstream fin;
		ofstream fout;
		int milked, unmilked;
		
		Al();
		void solve();
};

Al :: Al(){
	fin.open("milk2.in", ios :: in);
	fout.open("milk2.out", ios :: out);
	fin >> n;
	vec = vector<Node> (n);
	for(int i = 0; i < n; i++){
		fin >> vec[i].s >> vec[i].e;
	}
	sort(vec.begin(), vec.end());
	/*
	 *for(int i = 0; i < n; i++){
	 *    fout << vec[i].s << ' ' << vec[i].e << endl;
	 *}
	 */
}

void Al :: solve(){
	int ts = vec[0].s, te = vec[0].e;
	milked = te - ts;
	unmilked = 0;
	for(int i = 1; i < n; i++){
		if(vec[i].s <= te){
			if(vec[i].e > te)te = vec[i].e;	
		}
		else {
			if(te - ts > milked)milked = te - ts;
			if(vec[i].s - te > unmilked)unmilked = vec[i].s - te;
			ts = vec[i].s;
			te = vec[i].e;
		}
	}
	fout << milked << ' ' << unmilked << endl;
}

int main()
{
	Al al;
	al.solve();
	return 0;
}

