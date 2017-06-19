//http://www.spoj.com/problems/ACODE/

#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main() 
{
    std::ios::sync_with_stdio(0);cin.tie(0);
    while(true)
    {
        string s;cin >> s;
        if(s[0] == '0')     return 0;
        int n = s.length();
        s = ' ' + s;
        vector<ll>dp(n + 1);
        fill(dp.begin() , dp.end() , 0);//populate with zeroes
        dp[0] = dp[1] = 1;
        //dp[1] is needed for 1 length strings
        //dp[0] is needed for 2 length strings
        for(int i = 2;i <= n;i++)
        {
            if(s[i] != '0')     dp[i] = dp[i - 1];
            //current valid character append
            int last_2_char = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if(last_2_char <= 26 && last_2_char >= 10)   
                dp[i] += dp[i - 2]; // last 2 valid characters append
        }
        cout << dp[n] << "\n";
    }
}
//tags - dynamic programming(basic)
//Overall Complexity - O(|s|)
