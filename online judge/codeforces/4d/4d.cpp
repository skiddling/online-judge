#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Node{
	public:
		int id, pos;
		int w, h;
		int pre, next;

		Node(){
			pre = next = -1;
		}

		bool operator < (const Node &a)const{
			if(w != a.w)return w < a.w;
			else return h < a.h;
		}
};

class Dp{
	public:
		vector<Node> que;	
		int n, cw, ch;	
		int len, fp;

		Dp(){
			fp = len = 0;
		}
		void init();
		void solve();
		void output(int p);
};

void Dp :: init(){
	scanf("%d %d %d", &n, &cw, &ch);	
	int tw, th;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &tw, &th);
		if(tw <= cw || th <= ch)continue;
		else {
			Node t;
			t.id = i + 1;
			t.w = tw;
			t.h = th;
			que.push_back(t);
		}
	}
	if(que.size()){
		sort(que.begin(), que.end());
		que[0].pre = -1;
		que[0].pos = 1;
	}
}

void Dp :: solve(){
	int tp, ti;
	for(int i = 1; i < que.size(); i++){
		//ti is stand for the number in the sorted queue, tp is stand for the position in the answer que
		tp = 0;
		ti = -1;
		for(int j = 0; j < i; j++){
			if(que[i].w > que[j].w && que[i].h > que[j].h && tp < que[j].pos){
				tp = que[j].pos;
			   	ti = j;	
			}	
		}	
		que[i].pos = tp + 1;
		que[i].pre = ti;
	}	

	for(int i = 0; i < que.size(); i++){
		if(que[i].pos > len){
			fp = i;	
			len = que[i].pos;
		}
	}
	printf("%d\n", len);
}

void Dp :: output(int p){
	if(que[p].pre == -1){
		printf("%d", que[p].id);
		return;
	}
	else {
		output(que[p].pre);
		printf(" %d", que[p].id);
	}
}

int main()
{
	Dp dp;
	dp.init();
	if(dp.que.size() == 0){
		putchar('0');
		return 0;
	}
	dp.solve();
	dp.output(dp.fp);
	return 0;
}
