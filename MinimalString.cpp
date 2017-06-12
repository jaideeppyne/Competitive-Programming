//http://codeforces.com/contest/797/problem/C
//http://codeforces.com/contest/797/submission/27730569
//Minimal String

#include <bits/stdc++.h>
#define ll long long 
     
using namespace std;

int main() 
{
    std::ios::sync_with_stdio(0);cin.tie(0);
    
    string s;cin >> s;
	int n = s.length();
    s = ' ' + s;
    deque<char>t;
    vector<char>u;	//answer array
    vector<int>suffix(n + 1 , 500);
	suffix[n] = (int)s[n];
	
	/*The idea is to keep extracting each character from s until we
	have reached a lexicographically smallest character present.Then 
	insert that to u and check whether last character of t is smaller 
	than all other characters present in s.If yes , then keep extracting 
	from end of t and append to u until this condition mismatches.
	Then repeat from begining*/
	
    for(int i = n - 1;i >= 1;i--)
	   suffix[i] = min(suffix[i + 1] , (int)s[i]);
    //suffix array stores next minimal character
    
	int i = 1;
    t.push_back(s[i]);i++;//first character of s
    
    while(i <= n)
    {
        while(!t.empty() && t.back() <= suffix[i])
        {
            u.push_back(t.back());	// push each character to u
            t.pop_back();			//delete from end of t
        }
        if(t.empty())
        {
        	//if t is empty push one character 
        	//from s to t
            t.push_back(s[i]);i++;
        }
        while(i <= n && t.back() > suffix[i])
        {
        	//keep inserting in t as long as the remaining
        	//portion of string s contains lexicographically
        	//smallest charater
            t.push_back(s[i]);i++;
        }
    }
    while(!t.empty())
    {
        u.push_back(t.back());
        t.pop_back();
    }
    for(int ii = 0;ii < n;ii++)   cout << u[ii];//print answer
} 
//Overall Complexity : O(26 * n)
//tags : implementation , stack , strings
