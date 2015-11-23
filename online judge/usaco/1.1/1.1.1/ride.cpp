/*
ID: skiddling
PROG: ride
LANG: C++
*/

#include <cstring> 
#include <fstream>

using namespace std;

class Al{
	public:
		static const int ma = 10;
		char comet[ma], group[ma];

		void solve();
};

void Al :: solve(){
	ifstream fin("ride.in");
	ofstream fout("ride.out");

	fin >> comet >> group;
	int c = 1, g = 1;
	for(int i = 0; comet[i]; i++){
		c *= (comet[i] - 'A' + 1);
	}

	for(int i = 0; group[i]; i++){
		g *= (group[i] - 'A' + 1);
	}
	if(c % 47 == g % 47)fout << "GO\n";
	else fout << "STAY\n";
	
}

int main()
{
	Al al;
	al.solve();
	return 0;
}

