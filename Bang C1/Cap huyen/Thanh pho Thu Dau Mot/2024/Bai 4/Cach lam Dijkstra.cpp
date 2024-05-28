#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define pp pop_back
#define fi first
#define se second
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--)
#define all(x) (x).begin(), (x).end()
#define len(x) (int)((x).size())
#define ins insert
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pii pair <int,int>
#define str string
#define INF INT_MAX
#define TIME 1.0*clock()/CLOCKS_PER_SEC
template <typename T1,typename T2> void mini(T1 &a,T2 b) {if (a>b) a=b;}
template <typename T1,typename T2> void maxi(T1 &a,T2 b) {if (a<b) a=b;}
const int N=1e6+5;

str s,x;
int n=0;

int d[1<<16+5];
bool check[1<<16+5];
struct node{
    int u,du;
};
struct comp{
    bool operator() (node a,node b) {
        return a.du>b.du;
    }
};
priority_queue <node,vector <node>, comp> q;

void dijsktra() {
    FOR(i,0,1<<16) d[i]=INF;
    d[n]=0;
    q.push({n,d[n]});
    while (!q.empty()) {
        int u=q.top().u;
        q.pop();
        if (check[u]) continue;
        check[u]=true;
        if (u==0) return;
        //Thao tác 1
        REP(i,16) {
            int v=u;
            v^=1<<i;
            if (i-4>=0) v^=1<<(i-4);
            if (i+4<16) v^=1<<(i+4);
            if ((i-1)%4!=3 and i-1>=0) v^=1<<(i-1);
            if ((i+1)%4!=0 and i+1<16) v^=1<<(i+1);
            if (!check[v]) if (d[v]>d[u]+1) {d[v]=d[u]+1; q.push({v,d[v]});}
        }
        //Thao tác 2;
        REP(i,16) {
            int v=u^(1<<i);
            if (!check[v]) if (d[v]>d[u]+2) {d[v]=d[u]+2; q.push({v,d[v]});}
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("");

    //Ý tưởng: với mỗi trạng thái ta sẽ sinh ra 32 trạng thái mới 
    //(16 trạng thái làm thao tác 1 ở bất cứ điểm nào và 16 trạng thái làm thao tác 2 ở bất cứ điểm nào từ trạng thái hiện tại. 
    //Với mỗi trạng thái, ta xem nó như 1 đỉnh 
    //(ta sẽ quy một trạng thái dạng bảng 0 và 1 thành một dãy nhị phân 0 và 1. Ta sẽ làm điều này bằng bitwise)
    //Nếu thực hiện tt1 thì sẽ tạo đường đi trọng số là 1, tt2 sẽ là 2. 
    //Bài toán được quy về thành tìm đường đi ngắn nhất từ đỉnh hiện tại về đỉnh 0

    REP(i,4) {cin >> x; s+=x;}
    reverse(all(s));
    REP(i,16) if (s[i]=='1') n^=1<<i;
    dijsktra();
    cout << d[0];
    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}
