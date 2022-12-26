#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 9;
float x[2000];

struct package{
    float weight, price;
    float ratio;
} ;
    
int main() {
    float capacity;
    int num, i, j;
    float temp;
    cout << "\nEnter the number of objects: ";
    cin >> num;
    struct package p[num + 2];
    cout << "\nEnter the weight - prices of each object:";
    for (i = 0; i < num; i++) {
        float w, pr, r;
        cin >> w >> pr;
        r = pr / w;
        p[i].price = pr;
        p[i].ratio = r;
        p[i].weight = w;
    }
    cout << "\nEnter the capacity of knapsack: ";
    cin >> capacity;

    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (p[i].ratio < p[j].ratio) {
                struct package temp = p[j];
                p[j] = p[i];
                p[i] =  temp;
            }
        }
    }
    float totalPrice = 0;
    int  u = capacity;
    for (i = 0; i < num; i++) {
        if (p[i].weight > u) break;
        else {
            x[i] = 1.0;
            totalPrice = totalPrice + p[i].price;
            u = u - p[i].weight;
        }
    }
    if (i < num) x[i] = u / p[i].weight;
    totalPrice = totalPrice + (x[i] * p[i].price);

    cout << "\nMaximum price is:" << totalPrice;
}