#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Dp{
public:
    static const int inf = 0x3f3f3f3f;
    static const int ma = 31;
    int n, a, b;
    vector<int> hp;
    //i, l, m表示到该状态接下去需要扔多少才能到最优状态,rec的值需要按照定义以及相应要求好好维护
    vector<vector<vector<int> > > rec;
    vector<vector<vector<int> > > next;
    vector<int> vec;

    void init();
    //int 用来得到最少的总个数
    int dfs(int pos, int l, int m);
};

void Dp :: init(){
    scanf("%d%d%d", &n, &a, &b);
    hp = vector<int> (n + 1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &hp[i]);
    }

    rec = vector<vector<vector<int> > > (n + 1,
            vector<vector<int> > (ma,
                vector<int> (ma, inf)));
    next = vector<vector<vector<int> > > (n + 1,
            vector<vector<int> > (ma,
                vector<int> (ma, 0)));

}

//表示到达该状态需要扔几次
int Dp :: dfs(int pos , int l, int m){
    int t[2];
    if(pos == n - 1){
        if(hp[n - 1] >= (b * l + a * m))return inf;
        else if(hp[n] >= b * m)return inf;
        else return m;
    }

    if(rec[pos][l][m] < inf)return rec[pos][l][m];
    t[1] = inf;
    int s = (hp[pos] - b * l - a * m + b) / b;
    if(s < 0) s = 0;
    for(int i = s; i < ma; i++){
        t[0] = dfs(pos + 1, m, i);
        if(t[0] < t[1]){
            t[1] = t[0];
            //next记录下一个位置扔多少个，rec记录到那个状态最少要扔多少个,dfs用
            next[pos][l][m] = i;
            rec[pos][l][m] = t[0] + m;
        }
    }
    return rec[pos][l][m];
}

int main()
{
    Dp dp;
    dp.init();
    int put, ans = dp.inf, t;
    for(int i = (dp.hp[1] + dp.b) / dp.b; i < dp.ma; i++){
        t = dp.dfs(2, 0, i);
        if(t < ans){
            ans = t;
            put = i;
        }
    }
    printf("%d\n", ans);
    int left = 0, mid = put, rig;
    t = put;
    while(t--)dp.vec.push_back(2);
    for(int i = 2; i < dp.n - 1; i++){
        rig = dp.next[i][left][mid];
        t = rig;
        if(t){
            while(t--)dp.vec.push_back(i + 1);
        }
        left = mid;
        mid = rig;
    }
    for(int i = 0; i < dp.vec.size(); i++){
        if(i != 0)putchar(' ');
        printf("%d", dp.vec[i]);
    }
    return 0;
}

//关于debug，本身程序而言就是输入，输出，确定模型，检查当中每一个变量是否符合定义的要求，以及各种对变量的操作是否符合对各个变量的要求
