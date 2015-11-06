#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Node{
	public:
		long long multi[2];
		long long fn[2];
		char c[2];
		Node(int a){
			//0 stands for 2, 1 stands for 5
			fn[0] = fn[1] = 1;
			multi[0] = multi[1] = 0;
			c[0] = c[1] = 0;
		}

		Node(){
			fn[0] = fn[1] = 0;
			multi[0] = multi[1] = 1;
			c[0] = c[1] = 0;
		}

		Node operator +(const Node &a){
			Node t;
			for(int i = 0; i < 2; i++){
				t.fn[i] = fn[i] + a.fn[i];
				t.multi[i] = multi[i];
			}
			return t;
		}
};

class Dp{
	public:
		int n, az, aj;
		vector<vector<Node> > matrix;

		void init();
		void solve();
		void cal_num(Node &x);
		void output(int i, int j, int k);
};


void Dp :: init(){
	//freopen("in", "r", stdin);
	scanf("%d", &n);	
	matrix = vector<vector<Node> > (n, vector<Node> (n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%I64d", &matrix[i][j].multi[0]);
			matrix[i][j].multi[1] = matrix[i][j].multi[0];
			cal_num(matrix[i][j]);
		}
	}
}

void Dp :: solve(){
	int tz, tp;
	long long t;
	//0 stands for up to down, 1 stands for right to left
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i + j == 0)continue;
			//tm will be used for matrix[i][j]
			for(int k = 0; k < 2; k++){
				Node tm[2] = {1, 1};
				if(matrix[i][j].multi[k] != 0){
					if(i != 0 && matrix[i - 1][j].multi[k] != 0){
						tm[0] = matrix[i][j] + matrix[i - 1][j];
					}
					if(j != 0 && matrix[i][j - 1].multi[k] != 0){
						tm[1] = matrix[i][j] + matrix[i][j - 1];
					}
				}

				if(j == 0){
					matrix[i][j].multi[k] = tm[0].multi[k];
					matrix[i][j].fn[k] = tm[0].fn[k];
					matrix[i][j].c[k] = 'D';
				}
				else if(i == 0){
					matrix[i][j].multi[k] = tm[1].multi[k];
					matrix[i][j].fn[k] = tm[1].fn[k];
					matrix[i][j].c[k] = 'R';
				}
				else {
					if(tm[0].fn[k] <= tm[1].fn[k]){
						matrix[i][j].multi[k] = tm[0].multi[k];
						matrix[i][j].fn[k] = tm[0].fn[k];
						matrix[i][j].c[k] = 'D';
					}
					else {
						matrix[i][j].multi[k] = tm[1].multi[k];
						matrix[i][j].fn[k] = tm[1].fn[k];
						matrix[i][j].c[k] = 'R';
					}
				}
			}
		}
	}
	if(matrix[n - 1][n - 1].fn[0] <= matrix[n - 1][n - 1].fn[1]){
		printf("%d\n", matrix[n - 1][n - 1].fn[0]);
		output(n - 1, n - 1, 0);
	}
	else {
		printf("%d\n", matrix[n - 1][n - 1].fn[1]);
		output(n - 1, n - 1, 1);
	}
}

void Dp :: cal_num(Node &tm){
	int ary[2] = {2, 5};
	if(tm.multi[0] == 0){
		tm.fn[0] = tm.fn[1] = 1;
		return ;
	}
	else tm.fn[0] = tm.fn[1] = 0;
	long long t = tm.multi[0];
	for(int i = 0; i < 2; i++){
		while(t % ary[i] == 0){
			tm.fn[i]++;
			t /= ary[i];
		}
	}
}

void Dp :: output(int i, int j, int k){
	if(i + j == 0)return;
	if(matrix[i][j].c[k] == 'R'){
		output(i, j - 1, k);
		putchar('R');
	}
	else {
		output(i - 1, j, k);
		putchar('D');
	}
}

int main()
{
	Dp dp;	
	dp.init();	
	dp.solve();
	return 0;
}
