//Problem link - http://codeforces.com/problemset/problem/665/C
//Accepted code - http://codeforces.com/contest/665/submission/27815194
//Simple Strings
//Educational Round 12(Problem C)
//Author - Jaideep Pyne
//http://codeforces.com/profile/jaideeppyne1997

#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main() 
{
    std::ios::sync_with_stdio(0);cin.tie(0);
	string s;cin >> s;
	int n = s.length();
	if(n > 1)   s = s + s[n - 2];
	for(int i = 1;i < n;i++)
	{
	    if(s[i] == s[i - 1])    
	    {
	        if(s[i] == s[i + 1])
	        {
	            s[i] = (char)(((((int)s[i - 1] + 1) - 97) % 26) + 97);
	        }
	        else
	        {
	            if((s[i - 1] == 'z' && s[i + 1] == 'a')||(s[i - 1] == 'a' && s[i + 1] == 'z'))  s[i] = 'b';
	            else
	            s[i] = (char)((((max((int)s[i - 1] , (int)s[i + 1]) + 1) - 97) % 26) + 97);
	        }
	        i++;
	    }
	}
	for(int i = 0;i < n;i++)    cout << s[i];
}
//Overall Complexity : O(|s|)
//tags : implementation , greedy
