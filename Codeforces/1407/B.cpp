#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll n,maxx,maxi=-1;
    cin>>n;
    vector<ll> arr(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>arr.at(i);
        if(i==0)
        {
            maxx = arr.at(i);
            maxi = 0;
        }
        if(maxx<arr.at(i))
        {
            maxx = arr.at(i);
            maxi = i;
        }
    }  

    vector<pair<ll,ll>> ans;
    for(int i=0;i<n;i++)
    {
        if(i!=maxi)
        {
            ans.push_back({__gcd(arr.at(i),maxx),arr.at(i)});
            // cout<<__gcd(arr.at(i),maxx)<<":"<<arr.at(i)<<"\n";
        }
    }
    cout<<maxx<<" ";
    sort(ans.begin(),ans.end());
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans.at(i).second<<" ";
    cout<<"\n";
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
        Solve();

    return 0;
}