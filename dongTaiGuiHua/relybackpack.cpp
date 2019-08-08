#include <iostream>
#include <vector>

using namespace std;

int main(){
    int kindCount = 0;
    int capacity = 0;

    cin >> capacity >> kindCount;

    vector<int> cost;
    vector<int> value;
    vector<int> rely;
    cost.push_back(0);
    value.push_back(0);
    rely.push_back(0);

    vector<vector<int>> group(kindCount + 1);
    vector<int> dp(capacity + 1,0);

    int costTmp = 0;
    int valueTmp = 0;
    int relyTmp = 0;
    for(int i = 1;i <= kindCount;i++){
        cin >> costTmp >> valueTmp >> relyTmp;

        cost.push_back(costTmp);
        value.push_back(valueTmp);
        if(relyTmp != -1){
            group[relyTmp].push_back(i);
        }else{
            group[i].push_back(i);
        }
    }


    //对每一个组做01背包
    vector<int> groupTmp;
    for(int i = 1;i < kindCount + 1;i++){
        if(group[i].size() > 1){
            for(int j = 0;j < group[i].size();j++){
                if(group[i][j] != i){
                    groupTmp.push_back(group[i][j]);
                }  
            }

            group[i].clear();
            group[i].resize(capacity - cost[i] + 1);
            for(int j = 0;j < groupTmp.size();j++){
                for(int k = capacity - cost[i];k>=0;k--){
                    if(k > cost[groupTmp[j]]){
                        group[i][k] = group[i][k] > group[i][k - cost[groupTmp[j]]] + value[groupTmp[j]] ? 
                         group[i][k] : group[i][k - cost[groupTmp[j]]] + value[groupTmp[j]];
                    }
                }
            }

        }
    }

    //分组背包
    for(int i = 1;i <= kindCount;i++){
        if(group[i].size() == 0){
            continue;
        }
        if(group[i].size() == 1){
            for(int j = capacity;j >=0;j--){
                if(j >= cost[i]){
                    dp[j] = dp[j] > dp[j - cost[i]] + value[i] ? dp[j] : dp[j - cost[i]] + value[i];
                }
                
            }
        }
        if(group[i].size() > 0){
            for(int j = capacity;j >= 0;j--){
                for(int k = 0;k <= capacity - cost[i];k++){
                    if(j >= cost[i] + k){
                        dp[j] = dp[j] > dp[j - k - cost[i]] + value[i] + group[i][k] ? 
                        dp[j] : dp[j - k - cost[i]] + value[i] + group[i][k];
                    }
                }
            }
        }
    }

    for(int i = 0;i <= capacity;i ++){
        cout << dp[i] << " ";
    }
    cout << endl;
    cout << dp[capacity] << endl;
}