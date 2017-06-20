//Problem link - http://codeforces.com/problemset/problem/805/D
//Accepted code - http://codeforces.com/contest/805/submission/27916074
//Minimum number of steps
//Codeforces Round #411(Div 2 , Problem D)
//Author - Jaideep Pyne
//http://codeforces.com/profile/jaideeppyne1997

#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main() 
{
    std::ios::sync_with_stdio(0);cin.tie(0);
    int T = 1;
    while(T--)
    {
        string s;cin >> s;int n = s.length();
        if(n == 1)
        {
            cout << "0";return 0;
        }
        ll mod = (int)1e9 + 7;
        
        ll power = 1 , ans = 0;
        int pos = n - 1;
        while(pos >= 0 && s[pos] != 'b')    pos--;
        ll a = 0 , b = 0;
        for(int i = pos;i >= 0;)
        {
            while(i >= 0 && s[i] == 'b')
            {
                b++;i--;
                b %= mod;
            }
            power = 1;
            while(i >= 0 && s[i] == 'a')
            {
                ans += (power * b) % mod;
                ans %= mod;
                power *= 2;
                power %= mod;
                i--;
            }
            b = (b * power) % mod;
        }
        cout << ans << "\n";
    }
}

//Overall Complexity : O(|s|)
//tags : implementation , greedy
