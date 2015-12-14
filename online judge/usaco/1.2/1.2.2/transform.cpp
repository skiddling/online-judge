/*
ID: skiddling
PROG: transform
LANG: C++
*/

#include <cstring> 
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

ifstream fin("transform.in", ios :: in);
ofstream fout("transform.out", ios :: out);

class Maze{
	public:
		vector<vector<char> > maze;	
		
		Maze(){};
		Maze(int n);
		Maze rotation(int n, int multi);
		Maze reflection(int n);
		bool compare(int n, Maze t);
};

Maze :: Maze(int n){
	maze = vector<vector<char> > (n, vector<char> (n));
}

Maze Maze :: reflection(int n){
	Maze res(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			res.maze[i][n - 1 - j] = maze[i][j];
		}
	}
	return res;
}

Maze Maze :: rotation(int n, int multi){
	Maze res(n), temp(n); 
	temp.maze = maze;
	for(int t = 0; t < multi; t++){
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j ++){
				res.maze[j][n - 1 - i] = temp.maze[i][j];
			}
		}
		temp = res;
	}
	return res;
}

bool Maze :: compare(int n, Maze t){
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j++){
			if(maze[i][j] != t.maze[i][j])return 0;
		}
	}
	return 1;
}

class Al{
	public:
		int n;
		Maze s, e;

		Al();
		void solve();
};

Al :: Al(){
	fin >> n;
	s = Maze(n);
	e = Maze(n);
	string ts;
	for(int i = 0; i < n; i++){
		fin >> ts;
		for(int j = 0; j < n; j++)
			s.maze[i][j] = ts[j];
	}
	for(int i = 0; i < n; i++){
		fin >> ts;
		for(int j = 0; j < n; j++)
			e.maze[i][j] = ts[j];
	}
}

void Al :: solve(){
	int tag = 0;
	for(int i = 1; i < 4; i++){
		if(s.rotation(n, i).compare(n, e)){
			fout << i;
			tag = 1;
			break;
		}
	}
	if(tag == 0){
		if(s.reflection(n).compare(n, e)){
			fout << 4;
			tag = 1;
		}
	}
	if(tag == 0){
		for(int i = 1; i < 4; i++){
			if(s.rotation(n, i).reflection(n).compare(n, e)){
				fout << 5;
				tag = 1;
				break;
			}
		}
	}
	if(tag == 0){
		if(s.compare(n, e)){
			tag = 1;
			fout << 6;
		}
	}
	if(tag == 0)fout << 7;
	fout << endl;
}

int main()
{
	Al al;
	al.solve();
	fin.close();
	fout.close();
	return 0;
}
