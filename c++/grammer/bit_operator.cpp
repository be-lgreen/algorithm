#include <iostream>
using namespace std;

//1.  2^n 구하는법.
void function1(int n){
    cout << (1<<n) << endl;
}

//2. 부분집합 구하는법
void function2(int n){
    //예) 4자리수 부분집합
    //0001 ~ 1111 : 1 ~ 15
    for(int i=1; i<(1 << n); i++){
        for(int j=0; j<n; j++){
            if(i & (1 << j)){
                cout << "1";
            }else{
                cout << "0";
            }
        }
        cout << endl;
    }
}

int main(void){
    function1(6);
    function2(4);
}