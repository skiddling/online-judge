#include <cstring> 
#include <fstream>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Al{
	public:
		long long n;
		static const int ma = 65;
		vector<vector<long long> >tab;
		//0 storage one bit, 1 stroage the rem
		vector<long long> bit;
		
		void solve();
		inline void get_bit();
		int dfs(int pos);
};

inline void Al :: get_bit(){
	long long t = n;
	while(t){
		bit.push_back(t % 10);	
		t /= 10;
	}
	for(int i = 0; i < bit.size() / 2; i++){
		swap(bit[i], bit[bit.size() - 1 - i]);
	}
}

void Al :: solve(){
	get_bit();
	tab = vector<vector<long long> > (ma, vector<long long> (3));
	// 0 means the sum of numvers include 49
	// 1 means the number of end of 4
	// 2 means the number end with except 4
	if(bit[0] > 4){
		tab[0][1] = 1;
		tab[0][2] = bit[0] - 1;
	}
	else tab[0][2] = bit[0];
	int len = bit.size() - 1, tag;
	tag = dfs(len);
	printf("%I64d\n", tag + tab[len][0]);
}

int Al :: dfs(int pos){
	if(!pos)return 0;
	int tag = dfs(pos - 1);
	tab[pos][0] = tab[pos - 1][0] * 10 + tab[pos - 1][1];
	tab[pos][1] = tab[pos - 1][2] + tab[pos - 1][1];
	tab[pos][2] = tab[pos - 1][2] * 9 + tab[pos - 1][1] * 8;
	if(tag)tab[pos][0] += bit[pos];
	else if(bit[pos] > 4){
		tab[pos][1] ++;	
		tab[pos][2] += bit[pos] - 1;
	}
	else tab[pos][2] += bit[pos];
	if(tag)return 1;
	else if((bit[pos - 1] == 4) && (bit[pos] == 9))return 1;
	else return 0;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		Al al;
		cin >> al.n;
		al.solve();
	}
	return 0;
}
