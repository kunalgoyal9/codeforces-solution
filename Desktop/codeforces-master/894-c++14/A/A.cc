#include<bits/stdc++.h>

using namespace std;
#define int1(a) scanf("%d",&a)
#define int2(a,b) scanf("%d %d",&a,&b)
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define int4(a,b,c,d) scanf("%d %d %d %d",&a,&b,&c,&d)
#define lint1(a) scanf("%lld",&a)
#define lint2(a,b) scanf("%lld %lld",&a,&b)
#define lint3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define lint4(a,b,c,d) scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define lli long long int
#define pint(x) printf("%d",x)
#define all(x) x.begin(),x.end()
#define ps printf(" "); 
#define plint(x) printf("%lld",x)
//#define sort(a,n) qsort(a,n,sizeof(int),cmpfunc)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define bg begin()
#define ed end()
#define Set(a, s) memset(a, s, sizeof (a))
#define mod 1000000007
#define tmod(k) if ((k) >= mod) k %= mod;
#define endl '\n'
#define nl printf("\n");
#define fors(i,n) for(int i=0; i<n; i++)
#define fore(i,n) for(int i=n-1; i>=0; i--)
#define forv(i,a,n) for(int i=a; i<n; i++)
#define fora(i,ele) for(auto i: ele)
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef pair<int,int> pii;
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
void ASCII_Chart(){int i,j,k;printf("ASCII Chart:(30-129)\n");forv(i,30,50){fors(j,5){k=i+j*20;printf("%3d---> '%c'   ",k,k);}printf("\n");}}
const int INF = 0x3f3f3f3f;
#define pi 3.14159265
float roundoff(float val, float p){ return floor(val*pow(10.0,p)+0.5)/pow(10.0,p);}

//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};
//int dx[]={1,-1,0,0}; int dy[]={0,0,1,-1};
class node{
public:
	int id;
	int prio;
	int prd;
};

class compare{
public:
	bool operator()(node &n1, node &n2){
		if(n1.prio>n2.prio)//ascending
			return true;
		else if(n1.prio==n2.prio){
			return n1.id>n2.id;
		}
		return false;
	}
};
//priority_queue<node, vector<node>, compare> pq;

int main(void) {
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    cout.tie(NULL);
    /*#ifdef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #else
    // online submission
    #endif*/
    st str;
    cin>>str;
    int cnt = 0;
    fors(i,str.length()){
		forv(j,i+1,str.length()){
			forv(k,j+1,str.length()){
				if(str[i]=='Q'&&str[j]=='A'&&str[k]=='Q'){
					cnt++;
				}
			}
		}
	}
    pint(cnt);
    return 0;
}

