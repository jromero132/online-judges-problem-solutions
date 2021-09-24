// Problem name: Is This a Zebra?
// Problem link: https://codeforces.com/contest/953/problem/C
// Submission link: https://codeforces.com/contest/953/submission/37915465

#include <stdio.h>

typedef long long ll;

int a[100005];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	int x = a[0], c = 0;
	for (int i = 0; i < n && a[i] == x; ++i, ++c);

	for (int i = 0; i < n; )
	{
		for (int j = 0; j < c; ++j)
			if (i+j >= n || a[i+j] != x)
			{
				printf("NO");
				return 0;
			}
		i += c;
		x ^= 1;
	}

	printf("YES");

	return 0;
}