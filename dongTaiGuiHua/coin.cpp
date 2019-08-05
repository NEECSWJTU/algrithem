#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> price = {2,4,5};
    vector<int> happy = {3,6,10};
    vector<int> count = {3,2,1};
    int money = 30;

    vector<int> happyArray(money + 1,0);
    vector<int> lastPosition(money + 1,0);

    happyArray[0] = 0;
    for(int i = 1;i<= money;i++){
        int happyMax = 0;
        int happyMaxIndex = -1;
        for(int j = 0;j < price.size();j++){
            int happyMaxTmp = happyArray[i - 1];
            if(count[j] > 0){
            
                if(i - price[j] >= 0){
                    happyMaxTmp = happyArray[i-price[j]] + happy[j];
                    if(happyMaxTmp > happyMax){
                        happyMax = happyMaxTmp;
                        happyMaxIndex = j;
                    }
                }
            }
        }
        cout << "happyMaxIndex : " << happyMaxIndex << endl;
        if(lastPosition[happyMaxIndex] < i - price[happyMaxIndex]){
            count[happyMaxIndex] --;
        }
        
        cout << "i : " << i << " * ";
        for(int k = 0;k < count.size();k++){
            cout << count[k] << " ";
        }

        if(happyMax == 0 || happyMax < happyArray[i - 1]){
            happyMax = happyArray[i - 1];
        }
        happyArray[i] = happyMax;
        
    }
    for(int i = 0;i <= money;i++){
        cout << happyArray[i] << " ";
    }
    cout << endl;

    cout << happyArray[money] << endl;

}