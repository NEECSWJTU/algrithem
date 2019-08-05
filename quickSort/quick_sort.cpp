#include <iostream>
#include <vector>

using namespace std;

void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(vector<int> &data,int l,int r){
    int l_tmp = l;
    int r_tmp = r;
    int key = data[l_tmp];

    while(l_tmp < r_tmp){
        while(l_tmp < r_tmp && data[r_tmp] >= key){
            r_tmp--;
        }
        if(l_tmp < r_tmp){
            swap(data[l_tmp],data[r_tmp]);
        }
        
        while(l_tmp < r_tmp && data[l_tmp] <= key){
            l_tmp++;
        }
        if(l_tmp < r_tmp){
            swap(data[l_tmp],data[r_tmp]);
        }
    }
    return l_tmp;
}

int quickSort(vector<int> &data,int l,int r){
    if(l >= r){
        return 0;
    }
    int keyPos = partition(data,l,r);
    quickSort(data,l,keyPos - 1);
    quickSort(data,keyPos + 1,r);
}

int main(){
    vector<int> data = { 12, 4, 34, 6, 8, 65, 3, 2, 988, 988, 45 };
    quickSort(data,0,data.size() - 1);
    for(auto &i:data){
        cout << i <<" ";
    }
    cout << endl;
}