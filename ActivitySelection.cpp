#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 9;

int main() {
    cout << "Number of kahini : \n";
	ll n, i = 0; cin >> n;
    ll start[n+1], end[n+1];

    for(int i = 0; i < n; ++i) {
        cin >> start[i] >> end[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (end[i] > end[j]) {
                ll temp = end[j];
                end[j] = end[i];
                end[i] = temp;

                temp = start[j]; 
                start[j] = start[i];
                start[i] = temp;
            }
        }
    }

	cout << "selected activites are : \n";
	cout << i << " ";
	for (ll j = 1; j < n; j++) {
		if (start[j] >= end[i]) {
			cout << j << " ";
			i = j;
		}
	}
	return 0;
}
