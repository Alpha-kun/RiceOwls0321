#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> s;
    vector<ll> l;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            s.push_back(i);
            l.push_back(n/i);
        }
    }
    for (int i = 0; i < s.size(); ++i) {
        cout<<s[i]-1<<" ";
    }

    for (int i = s.size()-(s[s.size()-1]==l[s.size()-1]? 2:1); i >= 0; --i) {
        cout<<l[i]-1<<" ";
    }

    return 0;
}
