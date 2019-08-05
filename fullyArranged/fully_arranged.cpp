#include <iostream>
#include <vector>

using namespace std;

int print1ToN(vector<int> &data,vector<int> &flag,int n,int length,int index)
{
    //3cout << index << " : " <<length << endl;
    if(index == length - 1){
        //cout << "test" <<endl;
        for(int i = 0;i < length;i++){
            cout << data[i] <<" ";
        }
        cout << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        if(flag[i] == 1){
            //i++;
            continue;
        }
        //if(flag[i] != 1){
            data[index + 1] = i;
            flag[i] = 1;
            print1ToN(data,flag,n,n,index + 1);
            flag[i] = 0;
        //}
        
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> data = {0};
    vector<int> flag = {0};
    for(int i = 1;i <= n;i++){
        data[0] = i;
        flag[i] = 1;
        print1ToN(data,flag,n,n,0);
        flag[i] = 0;
    }
}