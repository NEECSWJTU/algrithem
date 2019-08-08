#include <iostream>
#include <vector>

using namespace std;

int main(){
    int kindCount = 0;
    int capacity = 0;

    cin >> capacity >> kindCount;

    vector<int> cost;
    vector<int> value;
    vector<int> count;
    cost.push_back(0);
    value.push_back(0);
    count.push_back(0);

    vector<int> dp(capacity + 1,0);

    int costTmp = 0;
    int valueTmp = 0;
    int countTmp = 0;
    for(int i = 0;i < kindCount;i++){
        cin >> costTmp >> valueTmp >> countTmp;

        if(countTmp == 0){
            cost.push_back(costTmp);
            value.push_back(valueTmp);
            count.push_back(countTmp);
        }else{
            int k = 1;
            while(countTmp - (1 << (k - 1)) > 0){
                cost.push_back((1 << (k-1)) * costTmp);
                value.push_back((1 << (k-1)) * valueTmp);
                countTmp = countTmp - (1 << (k - 1));
                count.push_back(1);
                k++;
            }
            cost.push_back(countTmp * costTmp);
            value.push_back(countTmp * valueTmp);
            count.push_back(0);
        }
    }

    for(int i = 1;i < cost.size();i++){
        if(i == 0){
            //完全背包，数量不限
            for(int j = 0;j <= capacity;j++){
                if(cost[i] <= j){
                    dp[j] = dp[j] > dp[j - cost[i]] + value[i] ? dp[j] : dp[j - cost[i]] + value[i];
                }
            }
        }else{
            for(int j = capacity;j >= 0;j--){
                if(cost[i] <= j){
                    dp[j] = dp[j] > dp[j - cost[i]] + value[i] ? dp[j] : dp[j - cost[i]] + value[i];
                }
            }
        }
    }

    cout << dp[capacity] <<endl;

}