    //http://www.spoj.com/problems/AFS/
	
	#include<bits/stdc++.h>
    #define ll long long 
    #define max1 1000000
    using namespace std;
     
    int sp[max1 + 1];
    int f[max1 + 1];
    void smallestprime()
    {
    	memset(sp , 0 , sizeof(sp));
     
    	for(ll int i = 2;i <= max1;i++)
    	{
    		if(!sp[i])
    		{
    			sp[i] = i;
    			for(ll int j = i * i;j <= max1;j += i)
    			{
    				if(!sp[j])
    					sp[j] = i;
    			}
    		}
    	}
    }
    void find_f()
    {
    	memset(f , 0 , sizeof(f));
     
    	for(ll int i = 2;i <= max1;i++)
    	{
    		ll int sof = 1;
    		if(sp[i] == i){f[i] = 1;continue;}
    		
    		ll int no = i;map<ll int ,ll int>m , power;m.clear();
    		while(no > 1)
    		{
    			m[sp[no]]++;
    			if(power.find(sp[no])!=power.end())
    			    power[sp[no]] += pow(sp[no] , m[sp[no]]);
    			else
    			    power[sp[no]] = pow(sp[no] , m[sp[no]]);
    			no = no / sp[no];
    		}
    		for(map<ll int ,ll int >::iterator it = power.begin(); it != power.end();it++)
    		{//if(i == 6) cout << it->second<<endl;
    			sof *= (it->second + 1);
    		}
    		f[i] = sof - i;
    	}
    }
    int main()
    {
    	std::ios::sync_with_stdio(0);cin.tie(0);
    	smallestprime();
    	find_f();//cout << f[6]<<endl;
    	int T;
    	cin >> T;
    	while(T--)
    	{
    		int n; cin >> n;
    		ll int a[n + 1];a[0] = a[1] = 0;
    		for(int i = 2;i <= n;i++)
    		{a[i] = a[i - 1] + f[i];}//cout << a[i - 1] <<" "<<f[i]<< "\n";}
    		cout << a[n] << "\n";
    	}
    } 
    //tags : number theory
