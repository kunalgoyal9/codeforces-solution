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

bitset<50010> primes;
vi primen;

void generateprime(){
    fors(i,50000){
        primes.set(i);
    }
    primes[1]=false;
    primes[0]=false;
    int init = 2;
    while(init <= 50000){
        if(primes[init]){
            for(int i = 2; init*i<=50000; i++){
                primes[init*i]=false;  
            }
          primen.pb(init);  
        }
        init++;
    }
}

bool isprime(int i){
    if(i<=50000){
        return primes[i];
    }
    else{
        for(auto k : primen){
            if(i%k==0) return false;
            if(k*k>i) return true;
        }
        return true;
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
    
    unsigned int l,r;
    generateprime();
    int var = 2;
    while((scanf("%d %d",&l,&r))==2){
        // int2(l,r);
        //  trace2(l,r);
        // trace1("k");
        int minm = INF;
        int maxm = -INF;
        bool checka=false ,checkb=false;
        bool first = false;
        int in1,in2;
        int mna=-1,mnb=-1,mxa=-1,mxb=-1;
        //pint(2147483647);
        forv(i,l,r+1){
            //  trace1(i);
            if(isprime(i) && !checka){
                in1 = i;
                checka = true;
                // trace2(in1,checka);
            }
            else if(isprime(i) && !checkb && checka){
                in2 = i;
                // trace2(in1,in2);
                first = true;
                if(in2-in1<minm){
                    mna = in1;
                    mnb = in2;
                    minm = in2-in1;
                }
                if(in2-in1>maxm){
                    mxa = in1;
                    mxb = in2;
                    maxm = max(maxm,in2-in1);
                }
                in1 = in2;
            }
        }
        if(first){
            cout<<mna<<','<<mnb<<" are closest, "<<mxa<<','<<mxb<<" are most distant."<<endl;
        }
        else{
            cout<<"There are no adjacent primes."<<endl;
        }
    }
    
    
    return 0;
}

