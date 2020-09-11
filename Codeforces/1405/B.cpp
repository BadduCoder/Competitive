#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr.at(i);

    ll minn = arr.at(0);
    for(int i=1;i<n;i++)
    {
        arr.at(i) += arr.at(i-1);
        minn = min(minn, arr.at(i));
    }

    cout<<abs(minn)<<"\n";
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
        Solve();

    return 0;
}