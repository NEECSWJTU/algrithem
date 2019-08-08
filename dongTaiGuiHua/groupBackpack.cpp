#include <iostream>
#include <vector>

using namespace std;

int main(){
    int kindCount = 0;
    int capacity = 0;
    int group = 0;

    cin >> capacity >> kindCount >> group;

    vector<int> cost(kindCount);
    vector<int> value(kindCount);
    vector<int> groupId(kindCount);
    cost.push_back(0);
    value.push_back(0);
    groupId.push_back(0);

    vector<int> dp(capacity + 1,0);

    int costTmp = 0;
    int valueTmp = 0;
    int groupIdTmp = 0;
    for(int i = 0;i < kindCount;i++){
        cin >> costTmp >> valueTmp >> groupIdTmp;

        cout << costTmp << " : " << valueTmp << " : " << groupIdTmp << endl;
        cost.push_back(costTmp);
        value.push_back(valueTmp);
        groupId.push_back(groupIdTmp);
    }

    for(int i = 0;i <= kindCount;i++){
        cout << cost[i] << " : " << value[i] << " : " << groupId[i] << endl;
    }


    for(int i = 1;i <= group;i++){
        for(int j = capacity;j >= 0;j--){
            for(int k = 1;k <= kindCount;k++){
                cout << k << groupId[k] <<" : " << i << endl;
                if(groupId[k] == i){
                    if(j >= cost[k]){
                        dp[j] = dp[j] > dp[j - cost[k]] + value[k] ? dp[j] : dp[j - cost[k]] + value[k];
                    }
                }
            }
        }
    }
    for(int i = 0;i <= capacity;i++){
        cout << dp[i] << " ";
    }
    cout << endl;
    cout << dp[capacity] << endl;
}