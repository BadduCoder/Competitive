#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll n, sum=0;
    cin>>n;

    vector<ll> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr.at(i);

    sort(arr.begin(),arr.end());

    ll largest = arr.at(arr.size()-1);
    double poww = 1;
    poww /= (n-1);
    long long approx = pow(largest, poww);
    // cout<<approx<<"\n";

    ll changeReq = 1000000000000007;
    
    ll start = max((ll)1, approx-100);
    
    for(ll i=start;i<approx+100;i++)
    {
        ll change = 0;
        for(int j=0;j<n;j++)
            change += abs(arr.at(j) - pow(i,j));
        changeReq = min(changeReq, change);
        // cout<<change<<" for "<<i<<"\n";
    }

    cout<<changeReq<<"\n";
}

int main()
{
    ll t=1;
    // cin>>t;
    while(t--)
        Solve();

    return 0;
}