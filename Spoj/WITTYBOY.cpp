#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

ll findUpSteps(ll current,ll target,ll n, vector<ll> blocked)
{
    ll upKey = target - current;
        
    if(upKey>0)
        upKey -= blocked[target]-blocked[current];
    else
    {
        upKey += n;
        upKey %= n;
        upKey -= blocked[n]-blocked[current];
        upKey -= blocked[target]-blocked[0];
    }

    return upKey;
}

ll findDownSteps(ll current,ll target,ll n, vector<ll> blocked)
{
    ll downKey = current - target;
    if(downKey>0)
        downKey -= blocked[current]-blocked[target];
    else
    {
        downKey += n;
        downKey %= n;
        downKey -= blocked[n]-blocked[target];
        downKey -= blocked[current]-blocked[0];
    }

    return downKey;
}

void Solve(int CaseN)
{
    ll n,k;
    cin>>n>>k;
    
    ll temp;
    vector<ll> blocked(n+1);
    unordered_map<ll,ll> isBlocked;
    for(int i=0;i<k;i++)
    {
        cin>>temp;
        blocked[temp] = 1;
    }
    for(int i=1;i<=n;i++)
        blocked[i] += blocked[i-1];
        

    ll channels;
    cin>>channels;
    vector<ll> watch(channels);
    for(int i=0;i<channels;i++)
        cin>>watch.at(i);
    
    ll last=watch.at(0),prev=watch.at(0),ans = 0;
    ll lastLast=LONG_LONG_MAX;
    ans += (ll)log10(watch.at(0))+1;
    cout<<"Takes "<<(ll)log10(watch.at(0))+1<<"P to goto channel "<<watch.at(0)<<"\n";
    for(int i=1;i<channels;i++)
    {
        ll currChannel = watch.at(i);
        ll upKey = findUpSteps(prev, currChannel, n, blocked);
        ll downKey = findDownSteps(prev, currChannel, n, blocked);

        ll lastKey = LONG_LONG_MAX;
        if(lastLast!=LONG_LONG_MAX)
        {
            ll upKeyy = findUpSteps(lastLast, currChannel, n, blocked) + 1;
            ll downKeyy = findDownSteps(lastLast, currChannel, n, blocked) + 1;
            cout<<"From last channel "<<lastLast<<" it takes "<<upKeyy<<"(U)"<<"\n";
            cout<<"From last channel "<<lastLast<<" it takes "<<downKeyy<<"(D)"<<"\n";
        
            lastKey = min(upKeyy, downKeyy);
            cout<<"From last channel "<<lastLast<<" it takes "<<lastKey<<"\n";
        }

        ll dig = log10(currChannel)+1;
        if(dig <= min({upKey, downKey, lastKey}))
        {
            if(last == LONG_LONG_MAX)
                last = currChannel;
            else
            {
                lastLast = last;
                last = currChannel;
            }
        }
        else
        {
            lastLast = LONG_LONG_MAX;
            last = LONG_LONG_MAX;
        }
        prev = currChannel;
        ans += min({upKey, downKey, lastKey, dig});

        cout<<"Takes "<<min({upKey, downKey, lastKey, dig})<<"P to goto channel "<<currChannel<<"\n";
    }

    cout<<"Case #"<<CaseN<<": "<<ans<<"\n";
}

int main()
{
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++)
        Solve(i);

    return 0;
}