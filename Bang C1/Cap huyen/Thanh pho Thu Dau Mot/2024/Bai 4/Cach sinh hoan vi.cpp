#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 1e6+7;
const int inf = 1e15;
int a[5][5], res = inf, b[20];
int dx[5] = {1, 0, -1, 0, 0};
int dy[5] = {0, 1, 0, -1, 0};
void print()
{
    int tmp[5][5], p = 0;
    for(int i = 1; i <= 4; i++)
    for(int j = 1; j <= 4; j++)
        tmp[i][j] = a[i][j];
    int id = 0;
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            if(b[++id] == 1)
            {
                for(int k = 0; k < 5; k++)
                {
                    int i1 = i+dx[k];
                    int j1 = j+dy[k];
                    tmp[i1][j1] ^= 1;
                }
                p++;
            }
        }
    }
 
    for(int i = 1; i <= 4; i++)
    for(int j = 1; j <= 4; j++)
        p += 2*tmp[i][j];
    res = min(res, p);
}
void st(int i)
{
    for(int j = 0; j < 2; j++)
    {
        b[i] = j;
        if(i == 16) print();
        else st(i+1);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //Ý tưởng: sinh ra 2^16 trường hợp làm thao tác 1 ở các nút, vậy thì các chỗ còn lại mà còn số 1 sau khi thực hiện
    //thao tác 1 xong sẽ làm thao tác 2. Lấy min số bước thực hiện trong 2^16 cách làm đó.

    for(int i = 1; i <= 4; i++)
    for(int j = 1; j <= 4; j++)
    {
        char x;
        cin >> x;
        a[i][j] = (x-'0');
    }
 
    st(1);
    cout << res;
}
