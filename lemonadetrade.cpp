#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string out, in;
    double rate;
    map<string, double> stock;
    stock["pink"] = 0.0;
    for (int i = 0; i < n; ++i) {
        cin >> out >> in >> rate;
        if (stock.find(in) == stock.end()) continue;
        if (stock.find(out) != stock.end()) {
//            cout<<out<<" to "<<max(stock[out], stock[in] * rate)<<endl;
            stock[out] = max(stock[out], stock[in] + log(rate));
        } else {
//            cout<<out<<" to "<<stock[in] * rate<<endl;
            stock[out] = stock[in] + log(rate);
        }
    }
    if (stock.find("blue") == stock.end())
        cout << "0.0" << endl;
    else
        printf("%.9f", min(exp(stock["blue"]), 10.0));
//    cout << min(stock["blue"], 10.0) << endl;
    return 0;
}
