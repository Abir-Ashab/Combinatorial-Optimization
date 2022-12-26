#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 9;
float x[2000];
struct Package{
    float weight, price;
    float ratio;
};
void knapsack(int n, float weight[], float price[], float capacity) {
    float tp = 0;
    int i, u = capacity;
    for (i = 0; i < n; i++) {
        if (weight[i] > u) break;
        else {
            x[i] = 1.0;
            tp = tp + price[i];
            u = u - weight[i];
        }
    }
    if (i < n) x[i] = u / weight[i];
    tp = tp + (x[i] * price[i]);
    cout << "\nMaximum price is:" << tp;
}
int main() {
    float weight[200], price[200], capacity;
    int num, i, j;
    float ratio[200], temp;

    cout << "\nEnter the number of objects: ";
    cin >> num;

    cout << "\nEnter the weight and prices of each object:\n";
    for (i = 0; i < num; i++) {
        cin >> weight[i] >> price[i];
        ratio[i] = price[i] / weight[i];
    }
    cout << "\nEnter the capacity of knapsack: ";
    cin >> capacity;

    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j]; 
                weight[j] = weight[i];
                weight[i] = temp;

                temp = price[j];
                price[j] = price[i];
                price[i] = temp;
            }
        }
    }
    knapsack(num, weight, price, capacity);
}