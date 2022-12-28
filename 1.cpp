#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 9;
struct package{
    ll start, end;
    string description;
};
int main() {
	ll n; cin >> n;
    ll s, e;
    struct package p[n+2];
    for(int i = 0; i < n; ++i) {
        cin >> s >> e;
        string str;
        getline(cin,str);
        p[i].start = s;
        p[i].end = e;
        p[i].description = str;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].end >= p[j].end) {
                swap(p[i], p[j]);
            }
        }
    }
    int i = 0, totalActivities = 1;
    for (ll j = 1; j <= n; j++) {
		if (p[j].start >= p[i].end) {
			i = j;
            totalActivities++;
		}
	}
    cout << "Total Number of activites is:" << totalActivities << '\n';
    i = 0;
    cout << p[0].description << ' ' << p[0].start << ' ' << p[0].end << '\n';
	for (ll j = 1; j <= n; j++) {
		if (p[j].start >= p[i].end) {
			cout << p[j].description << ' ' << p[j].start << ' ' << p[j].end << '\n';
			i = j;
		}
    }
	return 0;
}
