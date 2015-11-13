#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

#define ma 1000010

class Node{
	public:
		int pos;
		char c;
		int dis;

		Node(){
			dis = 0;
		}
};

class Dp{
	public:
		stack<Node> stac;
		vector<Node> vec, queu;
		char ms[ma];	
		int ansn, ansl;	

		Dp(){
			ansn = 1;
			ansl = 0;
		}
		void init();
		void solve();
		void output();
};

void Dp :: init()
{
	fgets(ms, sizeof(ms), stdin);
	int slen = strlen(ms) - 1;
	vec = vector<Node> (slen);
	for(int i = 0; i < slen; i++){
		if(ms[i] == '('){
			vec[i].c = '(';	
		}
		else {
			vec[i].c = ')';	
		}
		vec[i].pos = i;
	}
}

void Dp :: solve(){
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].c == '('){
			stac.push(vec[i]);
		}
		else {
			if(!stac.empty()){
				vec[i].dis = vec[i].pos - stac.top().pos + 1;
				if(stac.top().pos != 0 && vec[stac.top().pos- 1].dis){
					vec[i].dis += vec[stac.top().pos - 1].dis;	
				}
				stac.pop();
			}
			queu.push_back(vec[i]);
		}
	}
	for(int i = 0; i < queu.size(); i++){
		if(ansl < queu[i].dis){
			ansl = queu[i].dis;
			ansn = 1;	
		}	
		else if(queu[i].dis != 0 && ansl == queu[i].dis){
			ansn++;
		}
	}
}
void Dp :: output(){
	printf("%d %d", ansl, ansn);
}

int main()
{
	Dp dp;
	dp.init();
	dp.solve();
	dp.output();
	return 0;
}
