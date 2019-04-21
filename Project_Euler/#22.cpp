#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll word_score(string s);

int main() {
    
    int N;
    cin>>N;
    vector<string>names(N);
    for(int i = 0;i<N;i++){
        cin>>names[i];
    }
    sort(names.begin(),names.end());
    map<string,pair<int,ll> >m;
    for(int i = 1;i<=N;i++){
        m[names[i-1]] = {i,word_score(names[i-1])};
    }
    int Q;
    cin>>Q;
    for(int i =0;i<Q;i++){
        string q;
        cin>>q;
        ll ans = 1ll*m[q].first*m[q].second;
        cout<<ans<<endl;
    }

    return 0;
}
ll word_score(string s){
    ll ans = 0;
    int i = 0 , n = s.length();
    while(i<n){
        ans = ans + s[i]-'A'+1;
        i++;
    }
    return ans;
}
