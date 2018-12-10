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
#define ll long long
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

lli _sieve_size; // ll is defined as: typedef long long ll;
bitset<10000010> bs; // 10^7 should be enough for most cases
vi primes;

vi primeFactors(ll N) { // remember: vi is vector<int>, ll is long long
	vi factors;
	ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
	while (PF * PF <= N) { // stop at sqrt(N); N can get smaller
		while (N % PF == 0) { 
			N /= PF; 
			factors.push_back(PF); 
		} // remove PF
		PF = primes[++PF_idx]; // only consider primes!
	}
	if (N != 1) factors.push_back(N); // special case if N is a prime
	return factors; // if N does not fit in 32-bit integer and is a prime
}

void isprime(ll upperbound) { // create list of primes in [0..upperbound]
    _sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (ll i = 2; i <= _sieve_size; i++) 
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i) 
                bs[j] = 0;
            primes.push_back((int)i); // add this prime to the list of primes
        }
}

long long pow(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}

/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}

long long C(int n, int r, int MOD)
{
    vector<long long> f(n + 1,1);
    for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}

int n;
vector<pii> vpii;
int dp[71][1<<19];
vector<int> odn;
vector<bitset<20> > primefactors;

lli recrs(int idx,bitset<20> bit){
    int val = bit.to_ulong();
    if(dp[idx][val]!=-1) return dp[idx][val];
    if(idx>=n) {
		if(bit.to_ulong()==0) return 1;
		else return 0;
	}    
    bitset<20> tmp = primefactors[idx]^bit;
    if(tmp.to_ulong()==0){
		int temp = ((recrs(idx+1,bit)+recrs(idx+1,tmp))*pow(2,vpii[idx].second-1,mod)%mod);
		//cout<<idx<<' '<<bit<<' '<<temp;nl;
        return dp[idx][val]=temp;
    }
    else{
		int temp = ((recrs(idx+1,bit)+recrs(idx+1,tmp))*pow(2,vpii[idx].second-1,mod)%mod);
		//cout<<idx<<' '<<bit<<' '<<temp;nl;
        return dp[idx][val]=temp;
        }
}

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
    int1(n);
    vi arr;
    Set(dp,-1);
    map<int,int> mpp;
    int cnt1 = 0;
    bool chk = true;
    fors(i,n){
		int t;int1(t);
		if(t==1){
			cnt1++;
			continue;
		}
		arr.pb(t);
		mpp[t]++;
	}
    for(map<int,int>::iterator it=mpp.begin(); it!=mpp.ed; it++){
		vpii.pb(mp(it->first,it->second));
	}
	mpp.clear();
	n=vpii.size();
	isprime(70);
	map<int,int> primemap;
	int cnt = 0;
	fors(i,primes.size()) primemap[primes[i]]=cnt++;
	
	fors(i,vpii.size()){
		 vi prmv = primeFactors(vpii[i].first);
		map<int,int> mpcnt;
		 fors(i,prmv.size()){
			 mpcnt[prmv[i]]++;
		 }
		 bitset<20> tmpbit(0);
		 for(map<int,int>::iterator it = mpcnt.begin(); it!=mpcnt.end(); it++){
			 if(it->second%2==1){
				 tmpbit[primemap[it->first]]=true;
			 }
		 }
		 primefactors.pb(tmpbit);
	}
	bitset<20> btt(0);
	lli ansod = recrs(0,btt);
	//pint(ansod);
	lli pw = pow(2,cnt1,mod);
	lli ans = (ansod*pw)%mod;
	ans--;
	plint(ans);
    return 0;
}

