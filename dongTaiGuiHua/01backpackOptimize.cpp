#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void zeroOneBackpack(vector<int> &dp,
                     int kindCount,int capacity,
                     vector<int> cost,vector<int> value)
{
    dp[0] = 0;
    for(int i = 1; i <= kindCount;i++){
        for(int j = capacity;j > 0;j--){
            if(cost[i] > j){
                //do nothing
            }else{
                dp[j] = dp[j] > dp[j - cost[i]] + value[i] ?
                    dp[j] : dp[j - cost[i]] + value[i];
            }
        }
    }

    for(int i = 0;i <= capacity;i++){
        cout << dp[i] << " ";
    }
    cout << endl;
}
int main(){
    int kindCount = 0;
    int capacity = 0;
    vector<int> cost;
    vector<int> value;
    
    cost.push_back(0);
    value.push_back(0);
    
    cin >> capacity >> kindCount;
    
    for(int i = 0;i < kindCount;i++){
        int cost_tmp = 0;
        int value_tmp = 0;
        cin >> cost_tmp >> value_tmp;
        cost.push_back(cost_tmp);
        value.push_back(value_tmp);
    }
    vector<int> dp(capacity + 1,INT_MIN);
    zeroOneBackpack(dp,kindCount,capacity,
                     cost,value);
    cout << dp[capacity] << endl;
}