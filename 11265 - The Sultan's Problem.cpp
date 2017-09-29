//kunal_goyal
#include<bits/stdc++.h>

using namespace std;
#define int1(a) scanf("%d",&a)
#define int2(a,b) scanf("%d %d",&a,&b)
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define int4(a,b,c,d) scanf("%d %d %d %d",&a,&b,&c,&d)
#define int5(a,b,c,d,e) scanf("%d %d %d %d %d",&a,&b,&c,&d,&e)
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
#define itn int
#define Set(a, s) memset(a, s, sizeof (a))
#define mod 1000000007
#define tmod(k) if ((k) >= mod) k %= mod;
#define EPS 1e-9
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
#define PI 2*acos(0.0)
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

struct point_i { int x, y; 
point_i() { x = y = 0; } 
point_i(int _x, int _y) : x(_x), y(_y) {} };

struct point { double x, y;
point() { x = y = 0.0; }
point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const { 
	if (fabs(x - other.x) > EPS) 
		return x < other.x; 
		return y < other.y; }
    bool operator == (point other) const {
	return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } 
};

struct line { double a, b, c; 
	line(){a=1,b=1,c=1;}
	line(double _a, double _b, double _c) : a(_a),b(_b),c(_c) {}
};

struct vec { double x, y; // name: ‘vec’ is different from STL vector
vec(double _x, double _y) : x(_x), y(_y) {} };

// pythagoras hypot
double hypot(double dx,double dy){ return sqrt(dx * dx + dy * dy);} 

//return distance b/w p1 and p2
double dist(point p1, point p2) { 
return hypot(p1.x - p2.x, p1.y - p2.y); }

double DEG_to_RAD(double theta){return (theta*pi)/180.0;}

// rotate p by theta degrees CCW w.r.t origin (0, 0) 
/**** if point is not the origin i.e. (0,0) let (a,b) then 
 * we shift the point by subtracting the (a,b) from the point so that the cordinate system changes to (a,b)
 * now doing the rotation below i.e. rotate() to get the new rotated points let (c,d) 
 * then we add (a,b) back to get new rotated points about a point other than origin (a,b) ****/
 
point rotate(point p, double theta) {
double rad = DEG_to_RAD(theta);
return point(p.x * cos(rad) - p.y * sin(rad),
p.x * sin(rad) + p.y * cos(rad)); }

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
l.a = 1.0; l.b = 0.0; l.c = -p1.x; // default values
} 
else {
l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
l.c = -(double)(l.a * p1.x) - p1.y;
} }

bool areParallel(line l1, line l2) { // check coefficients a & b
return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

bool areSame(line l1, line l2) { // also check coefficient c
return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); }


// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
if (areParallel(l1, l2)) return false; // no intersection
// solve system of 2 linear algebraic equations with 2 unknowns
p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
// special case: test for vertical line to avoid division by zero
if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
else p.y = -(l2.a * p.x + l2.c);
return true; }

vec toVec(point a, point b) { // convert 2 points to vector a->b
return vec(b.x - a.x, b.y - a.y); }

vec scale(vec v, double s) { // nonnegative s = [<1 .. 1 .. >1]
return vec(v.x * s, v.y * s); } // shorter.same.longer

point translate(point p, vec v) { // translate p according to v
return point(p.x + v.x , p.y + v.y); }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }


// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
// formula: c = a + u * ab
/*a______b_ _ c_ _ _
              |_|
              |
              |
              *p    */
vec ap = toVec(a, p), ab = toVec(a, b);
double u = dot(ap, ab) / norm_sq(ab);
c = translate(a, scale(ab, u)); // translate a to c
return dist(p, c); }


// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
/*   a.______.b c
	      \ 
               \ 
                \
                 *p      */	
	
vec ap = toVec(a, p), ab = toVec(a, b);
double u = dot(ap, ab) / norm_sq(ab);
if (u < 0.0) { c = point(a.x, a.y); // closer to a
return dist(p, a); } // Euclidean distance between p and a
if (u > 1.0) { c = point(b.x, b.y); // closer to b
return dist(p, b); } // Euclidean distance between p and b
return distToLine(p, a, b, c); }

double angle(point a, point o, point b) { // returns angle aob in rad
vec oa = toVec(o, a), ob = toVec(o, b);
return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }
 
// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
return cross(toVec(p, q), toVec(p, r)) > 0; }

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

// convert point and gradient/slope to line
void pointSlopeToLine(point p, double m, line &l) {
l.a = -m; // always -m
l.b = 1; // always 1
l.c = -((l.a * p.x) + (l.b * p.y)); }

//similar to distToLine when line and point p is given
void closestPoint(line l, point p, point &ans) {
line perpendicular; // perpendicular to l and pass through p
if (fabs(l.b) < EPS) { // special case 1: vertical line
ans.x = -(l.c); ans.y = p.y; return; }
if (fabs(l.a) < EPS) { // special case 2: horizontal line
ans.x = p.x; ans.y = -(l.c); return; }
pointSlopeToLine(p, 1 / l.a, perpendicular); // normal line
// intersect line l with this perpendicular line
// the intersection point is the closest point
areIntersect(l, perpendicular, ans); }

// returns the reflection of point on a line
void reflectionPoint(line l, point p, point &ans) {
point b;
closestPoint(l, p, b); // similar to distToLine
vec v = toVec(p, b); // create a vector
ans = translate(translate(p, v), v); } // translate p twice

/********************************************** TRIANGLE ********************************************************/
double areaherons(double s1,double s2, double s3){
	double s = (s1+s2+s3)/2;
	return sqrt(s*(s-s1)*(s-s2)*(s-s3));
}
double perimeter(double s1, double s2, double s3){
	return s1+s2+s3;
}
/**A triangle with area A and semi-perimeter s has an inscribed circle (incircle) with radius r = A/s **/
double rInCircle(double ab, double bc, double ca) {
return areaherons(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca)); }
double rInCircle(point a, point b, point c) {
return rInCircle(dist(a, b), dist(b, c), dist(c, a)); } 

// returns 1 if there is an inCircle center, returns 0 otherwise
// if this function returns 1, ctr will be the inCircle center
// and r is the same as rInCircle
int inCircle(point p1, point p2, point p3, point &ctr, double &r) {
r = rInCircle(p1, p2, p3);
if (fabs(r) < EPS) return 0; // no inCircle center
line l1, l2; // compute these two angle bisectors
double ratio = dist(p1, p2) / dist(p1, p3);
point p = translate(p2, scale(toVec(p2, p3), ratio / (1 + ratio)));
pointsToLine(p1, p, l1);
ratio = dist(p2, p1) / dist(p2, p3);
p = translate(p1, scale(toVec(p1, p3), ratio / (1 + ratio)));
pointsToLine(p2, p, l2);
areIntersect(l1, l2, ctr); // get their intersection point
return 1; }

double rCircumCircle(double ab, double bc, double ca) {
return ab * bc * ca / (4.0 * areaherons(ab, bc, ca)); }
double rCircumCircle(point a, point b, point c) {
return rCircumCircle(dist(a, b), dist(b, c), dist(c, a)); }

bool istrianle(double a, double b, double c){
	return (a+b>c) && (a+c>b) && (b+c>a);
}

/******************************************* POLYGON ***************************************************/

// returns the area, which is half the determinant
double area(const vector<point> &P) {
double result = 0.0, x1, y1, x2, y2;
for (int i = 0; i < (int)P.size()-1; i++) {
x1 = P[i].x; x2 = P[i+1].x;
y1 = P[i].y; y2 = P[i+1].y;
result += (x1 * y2 - x2 * y1);
}
return fabs(result) / 2.0; }

bool isConvex(const vector<point> &P) { // returns true if all three
int sz = (int)P.size(); // consecutive vertices of P form the same turns
if (sz <= 3) return false; // a point/sz=2 or a line/sz=3 is not convex
bool isLeft = ccw(P[0], P[1], P[2]); // remember one result
for (int i = 1; i < sz-1; i++) // then compare with the others
if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
return false; // different sign -> this polygon is concave
return true; }

//check if p is inside or outside of a polygon
// returns true if point p is in either convex/concave polygon P
bool inPolygon(point pt, const vector<point> &P) {
if ((int)P.size() == 0) return false;
double sum = 0; // assume the first vertex is equal to the last vertex
for (int i = 0; i < (int)P.size()-1; i++) {
if (ccw(pt, P[i], P[i+1]))
sum += angle(P[i], pt, P[i+1]); // left turn/ccw
else sum -= angle(P[i], pt, P[i+1]); } // right turn/cw
return fabs(fabs(sum) - 2*PI) < EPS; }

//*********************** convex hull ***********************

point pivot(0, 0);
bool angleCmp(point a, point b) { // angle-sorting function
if (collinear(pivot, a, b)) // special case
return dist(pivot, a) < dist(pivot, b); // check which one is closer
double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; } // compare two angles
vector<point> CH(vector<point> P) { // the content of P may be reshuffled
int i, j, n = (int)P.size();
if (n <= 3) {
if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
return P; } // special case, the CH is P itself
// first, find P0 = point with lowest Y and if tie: rightmost X
int P0 = 0;
for (i = 1; i < n; i++)
if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
P0 = i;
point temp = P[0]; P[0] = P[P0]; P[P0] = temp; // swap P[P0] with P[0]
// second, sort points by angle w.r.t. pivot P0
pivot = P[0]; // use this global variable as reference
sort(++P.begin(), P.end(), angleCmp); // we do not sort P[0]
vector<point> S;
S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]); // initial S
i = 2; // then, we check the rest
while (i < n) { // note: N must be >= 3 for this method to work
j = (int)S.size()-1;
if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]); // left turn, accept
else S.pop_back(); } // or pop the top of S until we have a left turn
return S; }
 
//******************** cut polygon ********************************

/** This cutPolygon function only returns the left side of the polygon Q after cutting it with line ab. 
 * To return right, Swap point a and b when calling cutPolygon(a, b, Q).**/ 
 
 // line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B) {
double a = B.y - A.y;
double b = A.x - B.x;
double c = B.x * A.y - A.x * B.y;
double u = fabs(a * p.x + b * p.y + c);
double v = fabs(a * q.x + b * q.y + c);
return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); }

// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
vector<point> P;
for (int i = 0; i < (int)Q.size(); i++) {
double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
if (i != (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
if (left1 > -EPS) P.push_back(Q[i]); // Q[i] is on the left of ab
if (left1 * left2 < -EPS) // edge (Q[i], Q[i+1]) crosses line ab
P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
}
if (!P.empty() && !(P.back() == P.front()))
P.push_back(P.front()); // make P’s first point = P’s last point
return P; }


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
    int n,l,b,x,y;
    int cnt = 1;
    /*int4(n,l,b,x);
    int1(y);*/
    // int t;
    // int1(t);
    while(int5(n,l,b,x,y)==5){
           point fon = point(x,y);
           vector<point> P;
           P.pb(point(0,0));
           P.pb(point(l,0));
           P.pb(point(l,b));
           P.pb(point(0,b));
           P.pb(point(0,0));
           vector<point> mainn=P;
           fors(i,n){
               int x1,y1,x2,y2;
               int4(x1,y1,x2,y2);
               point p1 = point(x1,y1);
               point p2 = point(x2,y2);
               vector<point> right,left;
               right = cutPolygon(p1,p2,mainn);
               if(inPolygon(fon,right)){mainn = right; continue;}
               left = cutPolygon(p2,p1,mainn);
               if(inPolygon(fon,left)){
                   mainn = left;
               }
           }
           cout<<"Case #"<<cnt<<": ";
           cnt++;
           cout<<setprecision(3)<<fixed<<area(mainn);nl;
    }
    
    return 0;
}

