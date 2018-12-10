
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
    int t;
    int1(t);
    while(t--){
		string str;
		cin>>str;
		bool l,c,d;
		l=c=d=false;
		
		int cl=0,cc=0,cd=0;
		
		fors(i,0,str.length()){
			if(str[i]>='a' and str[i]<='z'){
				cl++;
				l=true;
			}
			else if(str[i]>='A' and str[i]<='Z'){
				c=true;
				cc++;
			}
			else{
				cd++;
				d = true;
			}
		}
		int temp = l+c+d;
		if(temp==3){
			cout<<str<<endl;
		}
		else if(temp==1){
			if(l){
				str[0]='A';
				str[1]='1';
				cout<<str<<endl;
			}
			else if(c){
				str[0] = 'a';
				str[1] = '1';
				cout<<str<<endl;
			}
			else{
				str[0] = 'A';
				str[1] = 'a';
				cout<<str<<endl;
			}
		}
		else{
			if(!l){
				if(cc>1){
					fors(i,0,str.length()){
						if(str[i]>='A' and str[i]<='Z'){
							str[i] = 'a';
							break;
						}
					}
					cout<<str<<endl;
				}
				else if(cd>1){
					fors(i,0,str.length()){
						if(str[i]>='0' and str[i]<='9'){
							str[i] = 'a';
							break;
						}
					}
					cout<<str<<endl;
				}
			}
			else if(!c){
				if(cd>1){
					fors(i,0,str.length()){
						if(str[i]>='0' and str[i]<='9'){
							str[i] = 'A';
							break;
						}
					}
					cout<<str<<endl;
				}
				else if(cl>1){
					fors(i,0,str.length()){
						if(str[i]>='a' and str[i]<='z'){
							str[i] = 'A';
							break;
						}
					}
					cout<<str<<endl;
				}
			}
			else{
				if(cl>1){
					fors(i,0,str.length()){
						if(str[i]>='a' and str[i]<='z'){
							str[i] = '1';
							break;
						}
					}
					cout<<str<<endl;
				}
				else if(cc>1){
					fors(i,0,str.length()){
						if(str[i]>='A' and str[i]<='Z'){
							str[i] = '1';
							break;
						}
					}
					cout<<str<<endl;
				}
			}
		}
	}
	
    return 0;
}
