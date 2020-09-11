#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll Q[2],Na,Nb,ans=0;
    pair<ll,ll> Item[2];
    cin>>Q[0]>>Q[1];
    cin>>Item[0].second>>Item[1].second;
    cin>>Item[0].first>>Item[1].first;
    
    if(Item[0].first>Item[1].first)
        swap(Item[0], Item[1]);
    
    if(Q[0]>Q[1])
        swap(Q[0],Q[1]);

    ll firstInsert;

    ans += min(Q[1]/Item[0].first, Item[0].second);
    firstInsert = ans;
    // cout<<"Inserted "<<Item[0].first<<"kg (Quan:"<<ans<<") into "<<Q[1]<<"\n";   
    Item[0].second -= ans;
    Q[1] -= ans*Item[0].first;

    ll ans2 = min(Q[1]/Item[1].first, Item[1].second);
    Item[1].second -= ans2;
    Q[1] -= ans2*Item[1].first;

    ans += ans2;
    
    ll delta = Item[1].first - Item[0].first;
    
    if(delta!=0)
    {
        ll exchange = Q[1]/delta;
        exchange = min({exchange, firstInsert, Item[1].second});
        Item[0].second += exchange;
        Item[1].second -= exchange;
        Q[1] -= exchange*delta;

        // cout<<"Exchanged "<<exchange<<" Items into "<<Q[1]<<"\n";
    }
    
    
    ll tempans;
    tempans = min(Q[0]/Item[0].first, Item[0].second); 

    Item[0].second -= tempans;
    Q[0] -= tempans*Item[0].first;

    // cout<<"Inserted "<<Item[0].first<<"kg (Quan:"<<tempans<<") into "<<Q[0]<<"\n";
    ans += tempans;


    tempans = min(Q[0]/Item[1].first, Item[1].second); 
    Item[1].second -= tempans;
    Q[0] -= tempans*Item[1].first;

    // cout<<"Inserted "<<Item[1].first<<"kg (Quan:"<<tempans<<") into "<<Q[0]<<"\n";
    ans += tempans;
    
    cout<<ans<<"\n";

}

int main()
{
    ll t;
    cin>>t;
    while(t--)
        Solve();

    return 0;
}