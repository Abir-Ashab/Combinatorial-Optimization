#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 9;

void merge(ll arr[], ll p, ll q, ll r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], M[n2];
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
  int i, j, k;
  i = 0;
  j = 0;
  k = p;
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i]; i++;
    } else {
      arr[k] = M[j];j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++; k++;
  }
  while (j < n2) {
    arr[k] = M[j];
    j++; k++;
  }
}
void mergeSort(ll arr[], ll l, ll r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}
int minValue(int x, int y) {
    if(x > y) return y;
    else return x;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, w; 
    cout << "Enter the Number of elements you want:"; cin >> n; 
    ll a[n+2], b[N];
    for(int i = 0; i < n; ++i) {
        ll weight, pricePerKg;
        cout << "\nEnter element Num " << i+1 << ":";
        cin >> weight >> pricePerKg;
        a[i] = weight;
        b[weight] = pricePerKg;
    }
    mergeSort(a, 0, n - 1);
    cout << "\nEnter total weight/capacity you can carry:";
    cin >> w; ll ans = 0;
    for(int i = 0; i < n; ++i) {
        ll z = minValue(w, a[i]);
        w -= z;
        ans += z * b[a[i]];
    }
    cout << "\nAns is: " << ans << '\n';            
    return 0;
}