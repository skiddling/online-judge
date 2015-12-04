/*
ID: skiddling
PROG: friday
LANG: C++
*/

#include <cstring> 
#include <fstream>
#include <vector>

using namespace std;

class Al{
	public:
		ifstream fin;
		ofstream fout;
		const static int ma = 410;
		int n, start;
		vector<vector<int> > tab;
		vector<vector<int> > ans;
		
		Al(){
			fin.open("friday.in");
			fout.open("friday.out");
			start = 1900;
			int temp[2][13] = {
				{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
				{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
			};
			tab  = vector<vector<int> > (2, vector<int> (13));
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 13; j++){
					tab[i][j] = temp[i][j];
				}
			}

			ans = vector<vector<int> > (ma, vector<int> (8));
		}
		void init();
		void solve();
};

void Al :: solve(){
	init();
	fin >> n;
	fout << ans[n][6] << ' ' << ans[n][0];
	for(int i = 1; i < 6; i++){
		fout << ' ' << ans[n][i];
	}
	fout << endl;
}

void Al :: init(){
	int year, tag, sum = 0, t;
	for(int i = 0; i < ma - 1; i++){
		year = start + i;
		if((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)))tag = 1;	
		else tag = 0;
		t = sum;
		for(int j = 1; j < 13; j++){
			t += tab[tag][j - 1];	
			ans[i + 1][(t + 13) % 7]++;
		}
		if(tag)sum += 366;
		else sum += 365;
	}	
	for(int i = 0; i < 8; i++){
		for(int j = 1; j < ma; j++){
			ans[j][i] += ans[j - 1][i];
		}
	}
}

int main()
{
	Al al;
	al.solve();
	return 0;
}

