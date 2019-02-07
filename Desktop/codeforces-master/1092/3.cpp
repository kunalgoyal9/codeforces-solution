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
	if(n==2){
		cout<<"SP";
		exit(0);
	}
	
	vector<pair<int,pair<int, string>>> arr1,arr;
	
	fors(i,0,2*n-2){
		string str;
		cin>>str;
		arr.pb({str.length(),{i, str}});
	}
	
	
	sort(arr.rbegin(), arr.rend());
	
	string s1 = arr[0].second.second, s2 = arr[1].second.second;
	trace2(s1,s2);
	//1
	
	vector<char> ans(2*n-2);
	
	string s11 = s1.substr(1), s21 = "";
	
	fors(i,0,s2.length()-1){
		s21 += s2[i];
	}
	
	trace2(s11,s21);
	string fnl;
	
	if(s11 == s21){
		string ts1 = s1 + s2[s2.length()-1];
		fnl = ts1;
		
		bool chk = true;
		trace1(fnl);
		fors(i,0,2*n-2){
			string str1 = arr[i].second.second, str2 = arr[i+1].second.second;
			int idx1 = arr[i].second.first, idx2 = arr[i+1].second.first;
			i++;
			
			string stemp = fnl.substr(0,str1.length());
			string stems = "";
			
			trace2(str1,str2);
			
			
			fors(i,fnl.length()-str1.length(),fnl.length()){
				stems += fnl[i];
			}
			trace2(stemp,stems);
			if(str1 == stemp and str2 == stems){
				trace1('d');
				ans[idx1] = 'P';
				ans[idx2] = 'S';
			}
			else if(stemp == str2 and stems == str1){
				trace1('m');
				ans[idx1] = 'S';
				ans[idx2] = 'P';
			}
			else{
				trace1('exit');
				chk = false;
				break;
			}
		}
		if(chk){
			fors(i,0,2*n-2){
			cout<<ans[i];
			exit(0);
			}
		}
		else{
			trace1('k');
			ans.clear();
		}
		
	}
	
		fnl = "";
		s2 += s1[s1.length()-1];
		fnl = s2;
	
	//trace1(fnl);
	fors(i,0,2*n-2){
		string str1 = arr[i].second.second, str2 = arr[i+1].second.second;
		int idx1 = arr[i].second.first, idx2 = arr[i+1].second.first;
		i++;
		
		string stemp = fnl.substr(0,str1.length());
		if(str1 == stemp){
			ans[idx1] = 'P';
			ans[idx2] = 'S';
		}
		else{
			ans[idx1] = 'S';
			ans[idx2] = 'P';
		}
	}
	fors(i,0,2*n-2){
		cout<<ans[i];
	}
	
    return 0;
}
