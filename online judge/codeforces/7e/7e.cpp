#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Dp{
	public:
		const static int ma = 110;
		
		char mod[ma], val[ma], exp[ma];
		int n;
		map<string, int> tab;

		void init();
		int getval(string s);
		int cal(int l, int r);
};

void Dp :: init(){
	scanf("%d\n", &n);	
	string t;
	for(int i = 0; i < n; i++){
		scanf(" #%*s");
		cin >> mod;
		gets(val);
		t = val;
		tab[mod] = getval(t);
	}
	gets(val);
	t = val;
	if(getval(t))puts("OK");
	else puts("Suspicious");
}

int Dp :: getval(string s){
	const char *p = s.c_str();
	int len = 0;
	for(int i = 0; p[i]; i++){
		if(p[i] != ' ')exp[len++] = p[i];	
	}
	exp[len] = 0;
	return cal(0, len - 1); 
}

int Dp :: cal(int l, int r){
	int L, R;
	for(int i = r, t = 0; i >= l; i--){
		if(exp[i] == ')')t++;
		if(exp[i] == '(')t--;
		if(t == 0 && (exp[i] == '+' || exp[i] == '-')){
			if(tab.count(string(exp + l, exp + i)) == 0){
				L = cal(l, i - 1);
			}
			else L = tab[string(exp + l, exp + i)];
			if(tab.count(string(exp + i + 1, exp + r + 1)) == 0){
				R = cal(i + 1, r);
			}
			else R = tab[string(exp + i + 1, exp + r + 1)];
			if(L && R && (exp[i] != '-' || R > 1))return 1;
			else return 0;
		}
	}
	for(int i = r, t = 0; i >= l; i--){
		if(exp[i] == ')')t++;
		if(exp[i] == '(')t--;
		if(t == 0 && (exp[i] == '*' || exp[i] == '/')){
			if(tab.count(string(exp + l, exp + i)) == 0){
				L = cal(l, i - 1);
			}
			else L = tab[string(exp + l, exp + i)];
			if(tab.count(string(exp + i + 1, exp + r + 1)) == 0){
				R = cal(i + 1, r);
			}
			else R = tab[string(exp + i + 1, exp + r + 1)];
			if((L > 1) && (R > 1) && (exp[i] != '/' || R > 2))return 2;
			else return 0;
		}
	}
	if(exp[l] == '('){
		L = cal(l + 1, r - 1);
		if(L == 0)return 0;
		else return 3;
	}
	if(tab.count(string(exp + l, exp + r + 1))){
		return tab[string(exp + l, exp + r + 1)];
	}
	else return 3;
}

int main()
{
	Dp dp;
	dp.init();	
	return 0;
}
