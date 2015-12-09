/*
ID: skiddling
PROG: beads
LANG: C++
*/

#include <cstring> 
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Tool{
	public:
		int lp, rp;
		char lc, rc;
		int llen, rlen;
		int tag;

		Tool(int ip, string s){
			rp = ip;
			lp = (ip - 1 + s.length()) % s.length();
			lc = s[lp];
			rc = s[rp];
			llen = rlen = tag = 0;
		}
};

class Al{
	public:
		int n, ans;
		string s;
		ifstream fin;
		ofstream fout;
		
		Al(){
			fin.open("beads.in", ios :: in);	
			fout.open("beads.out", ios :: out);
			fin >> n >> s;
			ans = 0;
		}
		void init();
		void solve();
		int ri2le(char c, int p, int op);
		int nextpos(int i, int op);
};

void Al :: solve(){
	for(int i = 0; i < s.length(); i++){
		Tool kit(i, s);
		if(s[i] != 'w'){
			kit.rlen = ri2le(s[i], i, 0);
		}	
		else {
			kit.rlen = max(ri2le('r', i, 0), ri2le('b', i, 0));
		}
		if(kit.rlen != s.length()){
			if(s[i] != 'w'){
				kit.llen = ri2le(s[kit.lp], kit.lp, 1);
			}
			else {
				kit.llen = max(ri2le('r', kit.lp, 1), ri2le('b', kit.lp, 1));
			}
		}
		else kit.llen = 0;
		if(ans < kit.llen + kit.rlen && kit.llen + kit.rlen <= s.length())ans = kit.llen + kit.rlen;
	}	
	fout << ans << endl;
}

int Al :: ri2le(char c, int p, int op){
	int sum  = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[p] == c || s[p] == 'w')sum++;
		else break;
		p = nextpos(p, op);
	}
	return sum;
}

inline int Al :: nextpos(int i, int op){
	if(op == 0) return (i + 1 + s.length()) % s.length();
	else return (i - 1 + s.length()) % s.length();
}

int main()
{
	Al al;
	al.solve();
	return 0;
}

