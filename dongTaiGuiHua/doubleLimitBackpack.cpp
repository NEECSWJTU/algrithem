#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int kindCount = 0;
    int capacity = 0;
    int weight = 0;

    cin >> kindCount >> capacity >> weight;

    vector<int> costCapacity;
    vector<int> costWeight;
    vector<int> value;
    costCapacity.push_back(0);
    costWeight.push_back(0);
    value.push_back(0);

    vector<int> weightLine(weight + 1,0);
    vector<vector<int>> dp(capacity + 1,weightLine);

    int costCapacityTmp = 0;
    int costWeightTmp = 0;
    int valueTmp = 0;
    for(int i = 0;i < kindCount;i++){
        cin >> costCapacityTmp >> costWeightTmp >> valueTmp;

        costCapacity.push_back(costCapacityTmp);
        costWeight.push_back(costWeightTmp);
        value.push_back(valueTmp);
    }

    for(int i = 1;i <= kindCount;i++){
        for(int j = capacity;j >= 0;j--){
            for(int k = weight;k >= 0;k--){
                if(costCapacity[i] <= j && costWeight[i] <= k){
                    dp[j][k] = dp[j][k] > dp[j - costCapacity[i]][k - costWeight[i]] + value[i] ? dp[j][k] : dp[j - costCapacity[i]][k - costWeight[i]] + value[i];
                }
            }
        }
    }

    cout << dp[capacity][weight] << endl;
}
