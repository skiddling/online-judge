/*
ID: skiddling
PROG: dualpal
LANG: C++
*/

#include <cstring> 
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Al{
	public:
		int n, s;
		static const int ma = 301;
		ifstream fin;
		ofstream fout;
		
		Al();
		void solve();
		int check(int k);
		string change(int i, int b);
};

Al :: Al(){
	fin.open("dualpal.in", ios :: in);
	fout.open("dualpal.out", ios :: out);
	fin >> n >> s;
}

void Al :: solve(){
	while(n){
		s++;
		if(check(s)){
			n--;
			fout << s << endl;
		}
	}
	fin.close();
	fout.close();
}

int Al :: check(int k){
	string s;
	int tag = 0, flag;
	for(int i = 2; i < 11; i++){
		s = change(k, i);	
		flag = 1;
		for(int j = 0; j < s.length() / 2; j++){
			if(s[j] != s[s.length() - 1 - j]){
				flag = 0;
				break;
			}	
		}
		if(flag)tag++;
		if(tag == 2)break;
	}
	if(tag == 2)return 1;
	else return 0;
}

string Al :: change(int n, int b){
	char cs[ma];
	int i = 0, t;
	for(; n; i++){
		t = n % b;
		cs[i] = '0' + t;
		n /= b;
	}
	cs[i] = 0;	
	string s = cs;
	return s;
}

int main()
{
	Al al;
	al.solve();
	return 0;
}

