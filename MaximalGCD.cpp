//http://codeforces.com/problemset/problem/803/C
//codeforces Educational Round 20
#include<bits/stdc++.h>
#define ll unsigned long long

using namespace std;

int main()
{
	ll n , k , ans = 0;cin >> n >> k;
	for(ll i = 1;i * i <= n;i++) // Notice that GCD of the resulting sequence is always a divisor of n. Now let's iterate over all divisors up to sqrt(n). 
	{
		ll d = n % i;				
		if(d == 0)	//checking d is a divisor or not
		{
			ll s = i * k * (k - 1) / 2;
			if(n > s && (k - 1) * i < n - s)//Current divisor is i. One of the ways to retrieve resulting sequence is to take i,2i,3i,...,(k-1)·i, their sum is s.
			{	
				if((n - s ) % i == 0)	//the last number in the sequence should have i as a divisor because i is the gcd of all numbers in the sequence.
				ans = max(ans , i);		//choosing maximum possible divisor
			}
			s = (n / i) * k * (k - 1) / 2;// if i is a divisor , n/i is also a divisor , because we iterate upto sqrt(n) only.
			if(n > s && (k - 1) * (n / i) < n - s)
			{
				if((n - s ) % (n / i)== 0)	
				ans = max(ans , (n / i));
			}
		}
	}
	if(!ans || k * (k + 1) / 2 > n)	// no divisors found in these 2 cases 
	{
		cout << "-1\n";return 0;
	}
	ll s = 0;
	for(int i = 1;i < k;i++)
	{
		cout << ans * i << " ";
		s += ans * i;
	}
	cout << n - s;
}
//Overall Time Complexity : O(sqrt(n))
