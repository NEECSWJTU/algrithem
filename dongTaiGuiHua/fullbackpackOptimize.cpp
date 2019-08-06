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
    
    vector<int> dp(capacity + 1,0);

    for(int i = 1;i <= kindCount;i++){
        for(int j = 0;j <= capacity;j++){
            if(j < cost[i]){
                //如果装不下，则什么也不做
            }else{
                dp[j] = max(dp[j],dp[j - cost[i]] + value[i]);
            }
        }
    }

    cout << dp[capacity] << endl;
}