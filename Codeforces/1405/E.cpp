#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll n,q;
    cin>>n>>q;

    vector<ll> arr(n);

    for(int i=0;i<n;i++)
        cin>>arr.at(i);

    for(int i=0;i<n;i++)
    {
        if(arr.at(i)>(i+1))
            arr.at(i) = LONG_LONG_MIN;
        else
            arr.at(i) = (i+1)-arr.at(i);
    }
 
    vector<int> lis(n,0); 
    unordered_map<ll,bool> occur(false);

    for (ll i = 0; i < n; i++)  
    { 
        if(arr.at(i) == 0 || occur[arr.at(i)-1])
        {
            lis[i]++;
            occur[arr.at(i)] = true;
        }
    }
    
    for(int i=1;i<n;i++)
        lis[i] += lis[i-1];
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<lis[i]<<" ";
    cout<<"\n";
    
    while(q--)
    {
        ll x,y;
        cin>>x>>y;

        y = n-y;
        ll ans=0;
        
        if(x>0)
        {
            cout<<lis[y-1]<<"\t"<<lis[x-1]<<"\n";
            ans = lis[y-1]-lis[x-1];
        }
        else
            ans = lis[y-1];

        cout<<ans<<"\n";
    }

}

int main()
{
    ll t=1;
    // cin>>t=1;
    while(t--)
        Solve();

    return 0;
}