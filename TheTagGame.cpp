//Problem link - http://codeforces.com/problemset/problem/813/C
//Accepted code - http://codeforces.com/contest/813/submission/27737416
//The Tag Game
//Educational Round 22(Problem C)
//Author - Jaideep Pyne
//http://codeforces.com/profile/jaideeppyne1997

#include <bits/stdc++.h>
#define ll long long 

using namespace std;

std::vector<int>adj[2 * (int)1e6 + 1] , alice(2 * (int)1e6 + 1) , bob(2 * (int)1e6 + 1);
bool visited[2 * (int)1e6 + 1];

void dfs(vector<int>& person , int s)//simple DFS
{
    visited[s] = true;
    
    for(int i = 0;i < adj[s].size();i++)
    {
        if(!visited[adj[s][i]])
        {
            person[adj[s][i]] = person[s] + 1;
            //store distance of adjacent node of s from s
            dfs(person , adj[s][i]);//recursive call
        }
    }
}
int main() 
{
    std::ios::sync_with_stdio(0);cin.tie(0);
    int n , x;
    cin >> n >> x;
    for(int i = 1;i < n;i++)
    {
        int u , v;
        cin >> u >> v;
        //adjacency list creation
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited , false , sizeof visited);
    dfs(alice , 1);
    //getting distance of all nodes from starting point 
    //of Alice
    memset(visited , false , sizeof visited);
    dfs(bob , x);
    //getting distance of all nodes from starting point 
    //of Bob
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        if(alice[i] > bob[i])   ans = max(ans , 2 * alice[i]);
    }
    cout << ans << "\n";
}
//Overall Complexity : O(n)
//tags : dfs
