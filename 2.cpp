#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {

    int n, edges; cin >> n;
    int nodes[n][n], vis[n];
    memset(nodes, -1, sizeof nodes);
    memset(vis, 0, sizeof vis);
    cin >> edges;
    string MapingIndex;
    char ch = 'A';
    for(int i = 0; i <= edges; ++i) {
        MapingIndex[i] = ch;
        ch++;
    }
    for(int i = 0; i < edges; i++) {
        int a, b,cost;
        char c, d;
        cin >> c >> d >> cost;
        for(int i = 0; i < edges; ++i) {
        if(MapingIndex[i] == c) a = i;
        if(MapingIndex[i] == d) b = i; 
        }
        nodes[a][b] = nodes[b][a] = cost;
    }
    char sr, ds; cin >> sr >> ds;
    int source, destination;
    for(int i = 0; i < edges; ++i) {
        if(MapingIndex[i] == sr) source = i;
        if(MapingIndex[i] == ds) destination = i; 
    }
    int i = source, store = INF; vis[i] = 1;
    cout << "Paths : " << MapingIndex[source]  << " -> ";
    while(1) {
        int low = INF, cnt = 0;
        for(int j = 0; j < n; j++) {
            if(nodes[i][j] != -1 and nodes[i][j] <= low and !vis[j]) {
                    low = nodes[i][j];
                    store = j;
            }
            else cnt++;
        }
        if(cnt == n) {
            cout << "Not Possible\n";
            break;
        }
        cout << MapingIndex[store] << " -> ";
        vis[store] = 1;
        i = store;
        if(store == destination){
            cout << "finish" << '\n';
            break;
        }
    }
    cout << endl;
}