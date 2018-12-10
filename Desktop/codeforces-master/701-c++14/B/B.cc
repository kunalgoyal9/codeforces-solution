#include <stdio.h>
#include <assert.h>
#include <inttypes.h>
#include <vector>
#include <iostream>
 
typedef unsigned int uint_t;
typedef std::vector<uint_t> uint_v;
const uint_t T = 5, M = 1000000, M1 = 1000;
const uint64_t N = 1000000000000000000ULL;
 
 
struct Factor {
    std::vector<uint_t> ps, ks;
    uint_t size() const { return ps.size(); }
    
    Factor(uint_t x) {
        assert (0 < x);
        if (x % 2 == 0) {
            uint_t k = 0;
            do {
                x /= 2;
                k++;
            } while (x % 2 == 0);
            ps.push_back(2);
            ks.push_back(k);
        }
        for (uint_t p = 3; ; p += 2) {
            uint_t q = x / p, r = x % p;
            if (q < p)
                break;
            if (r)
                continue;
            uint_t k = 0;
            do {
                x /= p;
                k++;
            } while (x % p == 0);
            ps.push_back(p);
            ks.push_back(k);
 
        }
        if (x > 1) {
            ps.push_back(x);
            ks.push_back(1);
        }
    }
};
 
static uint_t revmod(uint_t a, uint_t b)
{
    assert (0 < b);
    uint_t x = a % b, y = b, u = 1, v = 0;
    while (x > 0) {
        uint_t q = y / x, r = y % x;
        uint_t w = q * (uint64_t) u % b;
        w = v >= w ? v - w : v + (b - w);
        y = x; v = u;
        x = r; u = w;
    }
    assert (y == 1);
    return v;
}
 
 
static uint_t binmod1(uint_t a, uint64_t b, uint_t m, const Factor &mf)
{
    assert (a <= M1);
    const uint_t l = mf.size(); 
    std::vector<uint_t> ks(l, 0);
    std::vector<uint64_t> ts(a, 0);
 
    for (uint_t i = 0; i < a; i++)
        ts[i] = i + 1;
    for (uint_t i = 0; i < l; i++) {
        uint_t p = mf.ps[i], k = 0;
        for (uint_t q = p - 1; q < a; q += p) {
            uint_t x = ts[q];
            while (x % p == 0) {
                x /= p;
                k++;
            }
            ts[q] = x;
        }
        ks[i] = k;
    }
    uint_t ra = 1;
    for (uint_t i = 0; i < a; i++)
        ra = ra * ts[i] % m;
 
    for (uint_t i = 0; i < a; i++)
        ts[i] = b + i + 1;
    for (uint_t i = 0; i < l; i++) {
        uint_t p = mf.ps[i], k = ks[i];
        for (uint_t q = p - 1 - b % p; 0 < k && q < a; q += p) {
            uint64_t x = ts[q];
            while (k > 0 && x % p == 0) {
                x /= p;
                k--;
            }
            ts[q] = x;
        }
        assert (k == 0);
    }
    uint_t rb = 1;
    for (uint_t i = 0; i < a; i++)
        rb = rb * (ts[i] % m) % m;
 
    return revmod(ra, m) * (uint64_t) rb % m;
}
 
static uint_t upow(uint_t x, uint_t n)
{
    uint_t a = 1, b = x;
    for (uint_t k = n; k; k >>= 1) {
        if (k & 1)
            a *= b;
        b *= b;
    } 
    return a;
}
 
static uint64_t factpow(uint64_t n, uint_t p)
{
    uint64_t res = 0;
    while (n >= p) {
        n /= p;
        res += n;
    }
    return res;
}
 
static uint_t binmodpk1(uint64_t a, uint_t p, uint_t pk, const uint_v &ms)
{
    uint_t res = 1;
    for (uint64_t v = a; v; v /= p) {
        uint64_t q = v / pk;
        uint_t r = v % pk;
        res = res * (uint64_t) ms[r] % pk;
        if (q % 2 != 0 && ms[pk - 1] != 1)
            res = pk - res;
    }
    return res;
}
 
static uint_t binmodpk(uint64_t a, uint64_t b, uint_t p, uint_t k)
{
    uint64_t c = a + b;
//    fprintf(stderr, "p=%u, k=%u \n", p, k);
    uint64_t ak = factpow(a, p);
    uint64_t bk = factpow(b, p);
    uint64_t ck = factpow(c, p);
//    fprintf(stderr, "ak=%llu, bk=%llu, ck=%llu \n", ak, bk, ck);
    assert (ck >= ak && ck - ak >= bk);
    uint_t fk = ck - ak - bk, rk = k - fk;
//    fprintf(stderr, "fk=%u, rk=%u \n", fk, rk);
    if (fk >= k)
        return 0;
    uint_t rp = upow(p, rk);
//    fprintf(stderr, "rp=%u \n", rp);
    std::vector<uint_t> ms(rp);
    for (uint_t i = 0; i < rp; i++)
        ms[i] = i;
    for (uint_t i = 0; i < rp; i += p)
        ms[i] = 1;
    for (uint_t i = 1; i < rp; i++)
        ms[i] = ms[i - 1] * (uint64_t) ms[i] % rp;
 
    uint_t ra = binmodpk1(a, p, rp, ms);
    uint_t rb = binmodpk1(b, p, rp, ms);
    uint_t rc = binmodpk1(c, p, rp, ms);
 
    uint_t rd = revmod(ra * (uint64_t) rb % rp, rp);
    uint_t res = rc * (uint64_t) rd % rp;
    return res * upow(p, fk);
}
 
static uint_t binmod(uint64_t a, uint64_t b, uint_t m)
{
    if (b < a)
        std::swap(a, b);
//    fprintf(stderr, "a=%llu, b=%llu \n", a, b);
    Factor mf(m);
    
    if (a <= M1) {
        uint64_t c = a + b;
        switch (a) {
        case 0:
            return 1;
        case 1:
            return c % m;
#if 0
        case 2:
            if (c & 1) {
                return (c % m) * (uint64_t) (c / 2 % m) % m;
            } else {
                return (c / 2 % m) * (uint64_t) ((c - 1) % m) % m; 
            }
#endif
        default:
            return binmod1(a, b, m, mf);
        }
    }
    
    uint_t rv = 0, rm = 1;
    for (uint_t i = 0; i < mf.size(); i++) {
        uint_t pi = mf.ps[i], ki = mf.ks[i];
        uint_t im = upow(pi, ki), iv = binmodpk(a, b, pi, ki);
        uint_t ia = rm * revmod(rm, im), ra = rm * im - ia + 1;
        rm *= im;
        rv = (rv * (uint64_t) ra + iv * (uint64_t) ia) % rm;
    }
    
    return rv;
}
 
 
 
int main()
{
        uint_t res = binmod(5, 2, 23);
        std::cout << res << std::endl;
    
	return 0;
}
 
