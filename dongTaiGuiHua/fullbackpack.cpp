#include <iostream>
#include <vector>

using namespace std;



int main(){
    int kindCount = 4;
    int capacity = 10;

    vector<int> cost(kindCount + 1);
    vector<int> value(kindCount + 1);
    cost = {0,2,3,4,7};
    value = {0,1,3,5,9};

    vector<int> line(capacity + 1,0);
    vector<vector<int>> dp(kindCount + 1,line); 

    for(int i = 1;i <= kindCount;i++){
        for(int j = 0;j <= capacity;j++){
            if(j == 0){
                dp[i][j] = 0;
            }else if(j < cost[i]){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = max(dp[i - 1][j],dp[i][j - cost[i]] + value[i]);
            }
        }
    }

    cout << dp[kindCount][capacity] << endl;
    
}