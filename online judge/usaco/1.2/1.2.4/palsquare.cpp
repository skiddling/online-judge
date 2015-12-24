/*
ID: skiddling
PROG: palsquare 
LANG: C++
*/

#include <cstring> 
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Al{
	public:
		int b;
		static const int ma = 301;
		ifstream fin;
		ofstream fout;
		
		Al();
		void solve();
		int check(string s);
		string change(int i);
};

Al :: Al(){
	fin.open("palsquare.in", ios :: in);
	fout.open("palsquare.out", ios :: out);
	fin >> b;
}

void Al :: solve(){
	string s1, s2;
	for(int i = 1; i < ma; i++){
		s1 = change(i);
		s2 = change(i * i);
		if(check(s2))
			fout << s1 << ' ' << s2 << endl;
	}
	fin.close();
	fout.close();
}

int Al :: check(string s){
	int tag = 1;
	for(int i = 0; i < s.length() / 2; i++){
		if(s[i] != s[s.length() - i - 1]){
			tag = 0;
			break;
		}
	}	
	return tag;
}

string Al :: change(int n){
	char cs[ma];
	int i = 0, t;
	for(; n; i++){
		t = n % b;
		if(t > 9)cs[i] = 'A' + (t - 10);
		else cs[i] = '0' + t;
		n /= b;
	}
	cs[i] = 0;	
	string s = cs;
	s.assign(s.rbegin(), s.rend());
	return s;
}

int main()
{
	Al al;
	al.solve();
	return 0;
}

