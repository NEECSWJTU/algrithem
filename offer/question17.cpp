#include <iostream>
#include <memory.h>

using namespace std;


int print1ToMaxOfN(char *num,int length,int index){
    if(index == length - 1){
        for(int i = 0;i < length;i ++){
            cout << num[i];
        }
        cout << endl;
        return 0;
    }

    for(int i = 0;i < 10;i++){
        num[index + 1] = i - 0 +'0';
        print1ToMaxOfN(num,length,index + 1);
    }
    return 0;
}

int main(){
    int n;

    cin >> n;

    cout << "n = " << n << endl;

    char * num = new char[n];
    memset(num,'0',n);

    for(int i = 0;i < 10;i++){
        num[0] = i - 0 + '0';
        print1ToMaxOfN(num,n,0);
    }
}