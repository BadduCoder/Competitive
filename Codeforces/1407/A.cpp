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

    ll odd=0, even=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==1)
            odd+=arr.at(i);
        else
            even+=arr.at(i);
    }
    
    ll total=0, delta = even-odd;
    bool evenn = (delta>0)?true:false;
    bool isEven = true;
    delta = abs(delta);
    vector<ll> ans;

    for(int i=0;i<n;i++)
    {
        if(delta && even!=odd && arr.at(i)==1)
        {
            if(odd>even && i%2==1)
                odd--;
            else if(even>odd && i%2==0)
                even--;
        }
        else
        {
            ans.push_back(arr.at(i));
            total++;
        }
    }
    cout<<total<<"\n";
    for(int i=0;i<total;i++)
        cout<<ans.at(i)<<" ";
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