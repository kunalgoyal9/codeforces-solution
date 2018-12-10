//kunal_goyal
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
#define plint(x) printf("%lld",x)
#define endl '\n'
#define nl printf("\n");
#define ps printf(" "); 
 
#define all(x) x.begin(),x.end()
#define pb push_back
#define Set(a, s) memset(a, s, sizeof (a))
#define mod1 (lli)(1e9 + 7)
#define mod2 (lli)(1e9 + 9)
#define EPS 1e-9

#define fore(i,n) for(int i=n; i>=0; i--)
#define fors(i,a,n) for(int i=a; i<n; i++)
#define fora(i,ele) for(auto i: ele)
 
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<lli> vli;
 
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
 
double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
float roundoff(float val, float p){ return floor(val*pow(10.0,p)+0.5)/pow(10.0,p);}
lli power(lli a, lli b, lli mod){lli x=1,y=a; while(b > 0){if(b&1){x=(x*y)%mod;}y = (y*y)%mod; b /= 2;}return x;}
 
const int INF = 0x3f3f3f3f;
const float pi = 3.14159265;
 
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};
//int dx[]={1,-1,0,0}; int dy[]={0,0,1,-1};
 
int main(void) {
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    cout.tie(NULL);
	//srand (time(NULL));
	/*
    
    freopen("output.txt","w",stdout);
	*/
    // cout<<"Execution time : "<<tick()<<"\n";
    
	int n,m;
	int2(n,m);
	
	queue<pair<int,int>> q;
	q.push({0,n-1});
	
	vector<vi> vec(m);
	map<int,int> mpp[m];
	
	fors(i,0,m){
		fors(j,0,n){
			int t;
			int1(t);
			vec[i].pb(t-1);
		}
	}
	
	fors(i,0,n){
		mpp[0][vec[0][i]] = i;
	}
	
	vector<vi> nvec(m);
	
	fors(i,0,n){
		nvec[0].pb(i);
	}
	
	fors(i,1,m){
		fors(j,0,n){
			nvec[i].pb(mpp[0][vec[i][j]]);
		}
	}
	
	fors(i,1,m){
		fors(j,0,n){
			mpp[i][nvec[i][j]] = j;
		}
	}
	//trace3(nvec[0][0],nvec[0][1],nvec[0][2]);
	//trace3(nvec[1][0],nvec[1][1],nvec[1][2]);
	fors(i,1,m){
		int cnt = 0;
		while(cnt!=n){
			int l = q.front().first, r = q.front().second;
			trace2(l,r);
			q.pop();
			
			bool chk = true;
			
			int curnt = mpp[i][l];
			cnt++;
			fors(j,l+1,r+1){
				cnt++;
				if(curnt+1 != mpp[i][j]){
					q.push({l,j-1});
					l = j;
					curnt = mpp[i][j];  
				}
				else
				curnt++;
			}
			q.push({l,r});
		}
	}
	
	lli sum = 0;
	
	while(!q.empty()){
		lli f = q.front().first, s = q.front().second;
		q.pop();
		lli d = s-f+1;
		sum += ((d)*(d+1))/2;
	}
	cout<<sum;
    return 0;
}
