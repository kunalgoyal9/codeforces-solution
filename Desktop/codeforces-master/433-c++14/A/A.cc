#include<cstdio>
#include<cstring>

int f[210], n;

int main(){
	scanf("%d", &n);
	f[0] = 1;
	int sum = 0;
	for(int i = 1; i <= n; i ++){
		int v;
		scanf("%d", &v);
		v /= 100;
		for(int j = (n << 1); j >= 0; j --)
			if(f[j])
				f[j + v] = 1;
		sum += v;
	}
	if(sum & 1)
		fputs("YES\n", stdout);
	else if(f[sum >> 1])
		fputs("YES\n", stdout);
	else
		fputs("NO\n", stdout);

	return 0;
}

