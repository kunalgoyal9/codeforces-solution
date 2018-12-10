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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	*/
    // cout<<"Execution time : "<<tick()<<"\n";
    int n;
    int1(n);
    int cnt = 0;
    
    vector<pii> arr;
    vi g1,l1;
    map<int,int> mpp;
    
    
    fors(i,0,n){
		int temp;
		int1(temp);
		arr.pb({temp,i});
		mpp[i] = temp;
		if(temp>1) cnt++,g1.pb(i);
		else l1.pb(i);
	}
	
	sort(arr.rbegin(), arr.rend());
	
	int crnt = 2;
	
	fors(i,0,n){
		int a,b;
		tie(a,b) = arr[i];
		crnt += a-2;
		if(crnt<0){
			cout<<"NO";
			exit(0);
		}
		else if(crnt>=n-i-1){
			break;
		}
	}
	
	cout<<"YES ";
	
	if(cnt+2<=n){
		cout<<(cnt+1)<<endl<<(n-1)<<endl;
		
		fors(i,0,g1.size()-1){
			cout<<(g1[i]+1)<<" "<<(g1[i+1]+1)<<endl;
			mpp[g1[i]]--;
			mpp[g1[i+1]]--;
		}
		
		cout<<(g1[0]+1)<<' '<<(l1[0]+1)<<endl;
		mpp[g1[0]]--;
		cout<<(g1[g1.size()-1]+1)<<' '<<(l1[1]+1)<<endl;
		mpp[g1[g1.size()-1]]--;
		
		fors(i,2,l1.size()){
			fors(j,0,g1.size()){
				if(mpp[g1[j]]>0){
					cout<<(g1[j]+1)<<' '<<(l1[i]+1)<<endl;
					mpp[g1[j]]--;
					break;
				}
			}
		}
		
		
	}
	else if(cnt+1<=n){
		cout<<(cnt)<<endl<<(n-1)<<endl;
		fors(i,0,g1.size()-1){
			cout<<(g1[i]+1)<<" "<<(g1[i+1]+1)<<endl;
		}
		cout<<(g1[0]+1)<<' '<<(l1[0]+1)<<endl;
		
	}
	else{
		cout<<(cnt-1)<<endl<<(n-1)<<endl;
		fors(i,0,n-1){
			cout<<(i+1)<<" "<<(i+2)<<endl;
		}
	}
    return 0;
}
