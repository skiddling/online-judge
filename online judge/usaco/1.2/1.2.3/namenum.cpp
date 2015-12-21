/*
ID: skiddling
PROG: namenum
LANG: C++11
*/

#include <iostream>
#include <cstring> 
#include <fstream>
#include <string>
#include <map>

using namespace std;

class Al{
	public:
		ifstream fin, tin;
		ofstream fout;
		long long n;
		map<char, int> c_map;
		map<string, long long> t_map;
		
		Al();
		void make_map();
		void solve();
};

Al :: Al(){
	fin.open("namenum.in", ios :: in);
	tin.open("dict.txt", ios :: in);
	fout.open("namenum.out", ios :: out);
}

void Al :: make_map(){
	char c_mod[10][3] = {
		{}, {}, {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, 
		{'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'},
		{'W', 'X', 'Y'}
	};	
	for(int i = 2; i < 10; i++){
		for(int j = 0; j < 3; j++){
			c_map[c_mod[i][j]] = i;
		}
	}
	string ts;
	while(tin >> ts){
		long long base = 1, sum = 0;;
		for(int i = ts.length() - 1; i >= 0; i--){
			sum += c_map[ts[i]] * base;
			base *= 10;
		}	
		t_map[ts] = sum;
	}
}

void Al :: solve(){
	make_map();
	fin >> n;
	int sign = 0;
	for(auto tm : t_map){
		if(tm.second == n){
			fout << tm.first << "\n";
			sign = 1;
		}
	}
	if(!sign)fout << "NONE\n";
	fout.close();
	fin.close();
	tin.close();
}

int main()
{
	Al al;
	al.solve();
	return 0;
}
