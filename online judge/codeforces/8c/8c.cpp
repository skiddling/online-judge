#include <cstring> 
#include <fstream>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const static int ma = 1 << 24;

class Rec{
	public:
		int val;
		vector<int> rec;
		
		Rec(){
			val = -1;
		}
};

Rec tab[ma];

class Node{
	public:
		int x, y;
};

class Al{
	public:
		int n;
		Node coor[25];
		
		Al();
		void solve();
		//flag表示取得该状态的最优解
		Rec dfs(int flag);
		int cal_dis(int s, int e);
		int bit_make(int i, int flag);
		int bit_check(int i, int flag);
};

Al :: Al(){
	scanf("%d%d", &coor[0].x, &coor[0].y);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &coor[i].x, &coor[i].y);
	}
	tab[(1 << n) - 1].val = 0;
}

inline int Al :: cal_dis(int s, int e){
	int dx = coor[s].x - coor[e].x;
	int dy = coor[s].y - coor[e].y;
	return dx * dx + dy * dy;
}

inline int Al :: bit_check(int i, int flag){
	return (flag & (1 << (i - 1)));
}

inline int Al :: bit_make(int i, int flag){
	return (flag | (1 << (i - 1)));	
}

Rec Al :: dfs(int flag){
	if(tab[flag].val != -1)return tab[flag];
	int seed, tag, bitf;
	//选出一个没被用过的点
	for(int i = 1; i <= n; i++){
		if(!bit_check(i, flag)){
			seed = i;
			tag = bit_make(i, flag);
			break;
		}
	}
	int dis[3], sign = 0, sum;
   	dis[0] = cal_dis(0, seed);
	Rec ans = dfs(tag), temp;
	ans.val += dis[0] * 2;
	//再选出一个可能需要和seed一起的点
	for(int i = 1; i <= n; i++){
		if(i != seed && (!bit_check(i, tag))){
			bitf = bit_make(i, tag);
			temp = dfs(bitf);
			dis[1] = cal_dis(seed, i);
			dis[2] = cal_dis(i, 0);
			sum = dis[0] + dis[1] + dis[2];
			if(ans.val > + temp.val + sum){
				sign = i;
				ans = temp;
				ans.val += sum;
			}
		}	
	}
	ans.rec.push_back(seed);
	if(sign)ans.rec.push_back(sign);
	ans.rec.push_back(0);
	tab[flag] = ans;
	return ans;
}

void Al :: solve(){
	dfs(0);
	printf("%d\n0", tab[0].val);
	for(int i = 0; i < tab[0].rec.size(); i++){
		printf(" %d", tab[0].rec[i]);
	}
	puts("");
}

int main()
{
	Al al;
	al.solve();
	return 0;
}
