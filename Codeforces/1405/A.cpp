#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    reverse(arr.begin(),arr.end());
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
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