#include <iostream>
#include <string>
#include <sstream>
#include <memory.h>

using namespace std;

int main(){
    int n;

    string str = "1 2 3 4 5 6";
    stringstream ss;
    ss << str;
    for (int i = 0;i < 6;i++){
        ss >>n;
        cout << n << endl;
    }
}