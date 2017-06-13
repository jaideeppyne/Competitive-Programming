//Problem link - http://codeforces.com/problemset/problem/702/C
//Accepted code - http://codeforces.com/contest/702/submission/27759919
//Cellular Network
//Educational Round 15(Problem C)
//Author - Jaideep Pyne
//http://codeforces.com/profile/jaideeppyne1997


#include <bits/stdc++.h>
#define ll long long 
     
using namespace std;

int main() 
{
    std::ios::sync_with_stdio(0);cin.tie(0);
    int n , m;cin >> n >> m;
    set<pair<ll , char> >a;
    for(int i = 1;i <= n;i++)
    {   
        ll d;
        cin >> d;a.insert({d , 'c'});
    }
    ll left , right;
    bool no_city = true;
    for(int i = 1;i <= m;i++)
    {   
        ll d;
        cin >> d;
        if(a.find({d , 'c'}) != a.end())
        {
            a.insert({d , 't'});
        if(i == 1)  left = d;
        if(i == m)  right = d;
            continue;
        }
        no_city = false;
        a.insert({d , 't'});
        if(i == 1)  left = d;
        if(i == m)  right = d;
    }
    if(no_city && n <= m)
    {
        cout << "0";return 0;
    }
    map<ll , ll>f , b;
    ll point = -numeric_limits<ll>::max();
    
    for(auto it = a.begin();it != a.end();it++)
    {
        pair<ll , char>p = *it;
        if(p.second == 't')
        {
            point = p.first;
            if(p.second == 'c')
            {
                b[p.first] = point - p.first;
            }
        }
        else         
        {
            f[p.first] = p.first - point;
        }
    }
    point = numeric_limits<ll>::max();
    for(auto it = a.rbegin();it != a.rend();it++)
    {
        pair<ll , char>p = *it;
        if(p.second == 't')
        {
            point = p.first;
        }
        else         
        {
            b[p.first] = point - p.first;
        }
    }
    ll r = -numeric_limits<ll>::max();
    for(auto it = f.begin() , it1 = b.begin();it != f.end();it++ , it1++)
    {
        if(it->first >= right)
        {
            r = max(r,it->second);continue;
        }
        if(it1->first <= left)
        {
            r = max(r,it1->second);continue;
        }
        ll temp = min(it->second , it1->second);
        r = max(r , temp);
    }
    if(r == -numeric_limits<ll>::max())     r = 0;
    cout << r <<"\n";
} 

//Overall Complexity : O((n + m) * log(n + m))
//tags : implementation , greedy

