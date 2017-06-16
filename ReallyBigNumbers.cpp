//Problem link - http://codeforces.com/contest/817/problem/C
//Accepted code - http://codeforces.com/contest/817/submission/27814924
//Really Big Numbers
//Educational Round 23(Problem C)
//Author - Jaideep Pyne
//http://codeforces.com/profile/jaideeppyne1997

#include <bits/stdc++.h>
#define ll long long 

using namespace std;

bool check(ll x , ll s)
{
    ll sod = 0 , X = x;
    while(x > 0)
    {
        sod += (x % 10);//sum of digits
        x /= 10;
    }
    return (X - sod >= s);
    //number - sum of its digits >= given s
}
int main() 
{
    std::ios::sync_with_stdio(0);cin.tie(0);
	ll n , s;
	cin >> n >> s;
	ll low = 1 , high = n;
	ll ans = numeric_limits<ll>::max();
	while(low <= high)
	{
	    ll mid = (low + high) >> 1;
	    if(check(mid , s))
	    {
	        ans = min(ans , mid);
	        high = mid - 1;
	    }
	    else    low = mid + 1;
	}
	if(ans == numeric_limits<ll>::max())    cout << "0\n";
	else                                    cout << n - ans + 1 << "\n";
}

//Overall Complexity : O(log n)
//tags : binary search
