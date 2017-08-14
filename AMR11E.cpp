    //http://www.spoj.com/problems/AMR11E/

    #include<bits/stdc++.h>
    #define ll long long
    using namespace std;
     
    const int N = (int)1e6 + 1;
    bool prime[N];
    vector<ll int>primes , lucky;
     
    void sieve()
    {
        memset(prime , true , sizeof(prime));
        
        for(int i = 2;i < N;i++)
        {
            if(prime[i])    for(ll int j = i + i;j < N;j += i)  prime[j] = false;
        }
        for(int i = 2;i < N && primes.size() < 1001;i++)    if(prime[i])    primes.push_back(i);
    }
    void check(int n)
    {
        int c = 0;
        for(int i = 0;i < primes.size();i++)
        {
            if(n % primes[i] == 0)  c++;
            if(c == 3){  lucky.push_back(n);break;}
        }
    }
    int main()
    {
        std::ios::sync_with_stdio(0);cin.tie(0);
        sieve();
        int x = 30;
        while(lucky.size() <= 1000)
        {
            check(x++);
        }
        int T;cin >> T;
        while(T--)
        {
            int n;cin >> n;
            cout << lucky[n - 1] << endl;
        }
    } 
    //tags - math , number theory
