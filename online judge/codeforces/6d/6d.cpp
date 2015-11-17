#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int ma = (~0)^(1 << 31);

class Dfs{
	public:
		int n, a, b, res;
		vector<int> hpv;
		vector<int> ans;

		void init();
		void dfs(int pos, vector<int> thpv, vector<int> tans, int tres);	
		void output();
};

void Dfs :: init(){
	res = ma;
	scanf("%d %d %d", &n, &a, &b);
	hpv = vector<int> (n);
	ans = vector<int> (n);
	for(int i = 0; i < n; i ++){
		scanf("%d", &hpv[i]);
	}
}

void Dfs :: dfs(int pos, vector<int> thpv, vector<int> tans, int tres){
	if(tres > res)return;
	if(pos >= n - 1){
		if(thpv[n - 1] >= 0){
			tres += (thpv[n - 1] + b) / b;
			thpv[n - 1] = -1;
			tans[n - 2] += tres; 
		}
		if(tres < res){
			res = tres;
			ans = tans;
		}
		return ;
	}
	//brute force: 2 steps 1.kill i-1, 2.kill i
	int tib = (thpv[pos - 1] + b) / b, tia = (thpv[pos] + a) / a;
	vector<int> tp = thpv, ta = tans;
	if(tib >= tia){
		tp[pos - 1] = tp[pos] = -1;
		tp[pos + 1] -= b * tib;
		ta[pos] += tib;
		dfs(pos + 1, tp, ta, tres + tib);
	}
	else {
		for(int i = tib; i <= tia; i++){
			tp = thpv;
			tp[pos - 1] = -1;
			tp[pos] -= a * i;
			tp[pos + 1] -= b * i;
			if(tp[pos] < 0)tp[pos] = -1;
			ta = tans;
			ta[pos] += i;
			dfs(pos + 1, tp, ta, tres + i);
		}
	}
}

void Dfs :: output(){
	printf("%d\n", res);
	for(int i = 0, t = 1; i < res; i++){
		if(i != 0)putchar(' ');
		while(ans[t] == 0)t++;
		printf("%d", t + 1);
		ans[t]--;
	}
}

int main()
{
	Dfs dfs;
	dfs.init();	
	dfs.dfs(1, dfs.hpv, dfs.ans, 0);
	dfs.output();
	return 0;
}
