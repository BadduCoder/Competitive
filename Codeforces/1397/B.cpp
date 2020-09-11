#include<bits/stdc++.h>

typedef unsigned long long ll;
using namespace std;

void Solve()
{
    bool notOne = true;
    ll n, sum=0,r=1,tempsum=0;
    cin>>n;

    vector<ll> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr.at(i);
        sum += arr.at(i);
        if(arr.at(i)!=1)
            notOne = true;
    }

    if(!notOne)
    {
        cout<<"0\n";
        return;
    }

    sort(arr.begin(),arr.end());

    cout<<sum<<"\n";
    for(ll i=2;i<=10000000;i++)
    {
        tempsum = pow(i,n);
        tempsum -= 1;
        tempsum /= (i-1);

        if(tempsum>sum)
        {
            cout<<tempsum<<" for "<<i<<"\n";
            r = i-1; 
            break;
        }
    }

    ll changeReq = 100000000007;
    for(ll i=r-100;i<r+100;i++)
    {
        ll change = 0;
        for(int j=0;j<n;j++)
            change += abs(arr.at(j) - pow(i,j));
        changeReq = min(changeReq, change);
        cout<<change<<" for "<<i<<"\n";
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

// 2999999979
// 1999982505