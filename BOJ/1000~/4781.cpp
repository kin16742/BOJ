#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double n, m;

int main(){
    while(1){
        int res = 0;
        int dp[10005];
        vector<pair<int,int>> coin;
        double a, b;

        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i = 0; i < n; i++){
            cin >> a >> b;
            coin.push_back({(int)b * 100, (int)b});
        }
        sort(coin.begin(), coin.end());
        for(int i = 0; i < n; i++)
            dp[coin[i].first] = coin[i].second;
        
        for(int i = coin[0].first; i < m * 100; i++)
            for(int j = 0; j < n; j++)
                if(i - coin[j].first > 0) dp[i] = max(dp[i], dp[i - coin[j].first]);

        for(int i=0;i<=m*100;i++) res = max(res,dp[i]);
        cout << res << '\n';
    }
}