#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll n,minn=1000000007;
    cin>>n;
    vector<ll> arr(n);
    vector<pair<ll,int> > sarr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr.at(i);
        sarr.at(i) = {arr.at(i),i};
        if(arr.at(i)<minn)
            minn = arr.at(i);
    }

    sort(sarr.begin(),sarr.end());

    bool poss = true;
    for(int i=0;i<n;i++)
    {
        if(arr.at(i)!=sarr.at(i).first)
        {
            if(arr.at(i)%minn!=0)
            {
                poss = false;
                break;
            }
        }
    }

    (poss)?cout<<"YES\n":cout<<"NO\n";
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
        Solve();

    return 0;
}