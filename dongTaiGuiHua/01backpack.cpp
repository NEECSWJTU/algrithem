#include<iostream>
#include <vector>

using namespace std;

int main(){
    int kindCount = 8;
    int capacity = 200;

    vector<int> cost(kindCount + 1);
    vector<int> value(kindCount + 1);

    cost = {0,79,58,86,11,28,62,15,68};
    value = {0,83,14,54,79,72,52,48,62};

    vector<int> capacityInit(capacity + 1,0);
    vector<vector<int>> rec(kindCount + 1,capacityInit);

    //第一行置为0
    for(int i = 0;i <= capacity;i++){
        rec[0][i] = 0;
    }

    for(int i = 1;i <= kindCount;i++){
        for(int j = 0;j <= capacity;j++){
            if(j == 0){
                //capacity 为0时
                rec[i][j] = 0;
            }else if(cost[i] > j){
                rec[i][j] = rec[i - 1][j];
            }else{
                rec[i][j] = max(rec[i - 1][j],rec[i - 1][j - cost[i]] + value[i]);
            }

        }
    }

    cout << rec[kindCount][capacity] << endl;

}