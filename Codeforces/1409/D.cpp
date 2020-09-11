#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll n,s,currSum=0,oldNum;
    cin>>n>>s;
    oldNum = n;

    vector<int> digits;
    while(n)
    {
        digits.push_back(n%10);
        currSum += n%10;
        n/=10;
    }
    digits.push_back(0);

    int carry = 0, index=0;
    for(int i=0;i<digits.size();i++)
    {
        // cout<<"on digit "<<digits.at(i)<<":\n";
        digits.at(i) += carry;
        carry = 0;

        if(currSum <= s)
        {
            index = i;
            break;
        }

        // if(digits.at(i)-1 < currSum-s)
        // {
        // digits.at(i) = 0;
        currSum -= digits.at(i)-1;
        // cout<<"added "<<10-digits.at(i)<<"\n";
        digits.at(i) = 0;
        carry = 1;
        // }
        // else
        // {
        //     digits.at(i) += s;
        //     currSum -= currSum-s;
        //     cout<<"added "<<s<<"\n";
        // }
    }
    // if(index+1 < digits.size())
    //     digits.at(index+1) += carry;
    
    reverse(digits.begin(),digits.end());
    ll newNum = 0;
    
    // cout<<"\n\nNew Num: ";
    for(int i=0;i<digits.size();i++)
    {
        // cout<<digits.at(i)<<" ";
        newNum *= 10;
        newNum += digits.at(i);
    }
    // cout<<"\n";
    cout<<newNum-oldNum<<"\n";
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
        Solve();

    return 0;
}