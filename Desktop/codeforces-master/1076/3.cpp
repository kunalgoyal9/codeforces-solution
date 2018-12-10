#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define mod 1000000007
#define mx 100003
#define ss second
#define ff first
#define ld long double
#define pii pair<long long, long long>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int cnt[1000005], p[1000003];
int main()
{
    IOS;
    int n, temp, ans = 1;
    cin >> n;
    rep(i,2,n){
        if(!p[i]){
            for(int j = i*2; j <= n; j += i) p[j] = 1;
        }
    }
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0 and p[i] == 0){
           temp = n;
           while(temp % i == 0) cnt[i]++, temp /= i;
           ans *= i;
        }
        if(n % i == 0 and i != (n/i) and p[(n/i)] == 0){
            temp = n;
           while(temp % (n/i) == 0) cnt[(n/i)]++, temp /= (n/i);
           ans *= (n/i);
        }
    }
    if(ans == 1){
        cout << n << ' ' << 0 << endl;
        return 0;
    }
    temp = 0;
    rep(i,2,n){
        if(cnt[i]){
            temp = max(temp, cnt[i]);
        }
    }
    
    int id = 1,flag=0;
    while(1){
        if(id >= temp) break;
        id *= 2;
    }
    rep(i,2,n)
        if(cnt[i] != id and cnt[i] != 0) flag = 1;
    temp = 0;
    if(flag == 1) temp++;
    cout<<"temp"<<" "<<temp<<endl;
    while(1){
        if(id <= 1) break;
        id /= 2;
        temp++;
    }
    cout << ans << " " << temp << endl;
}
