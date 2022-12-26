#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 9;
struct package{
    ll start, end;
    string s;
};
int main() {
    cout << "Number of kahini : \n";
	ll n; cin >> n;
    ll s, e;
    struct package p[n+2];
    for(int i = 0; i < n; ++i) {
        cin >> s >> e;
        string str;
        getline(cin,str);
        p[i].start = s;
        p[i].end = e;
        p[i].s = str;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].end > p[j].end) {
                struct package temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
    int i = 0, totalActivities = 0;
	cout << "selected activites are : \n";
	for (ll j = 1; j < n; j++) {
		if (p[j].start >= p[i].end) {
			cout << p[j].s << ' ' << p[j].start << ' ' << p[j].end << '\n';
			i = j;
            totalActivities++;
		}
	}
    cout << "Total Number of activites is : " << totalActivities << '\n';
	return 0;
}
