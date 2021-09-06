#include <iostream>
#include <string>
#include <vector>
using namespace std;


void string_to_vector(){
    string str = "13579";
    vector<int> v(str.begin(), str.end());

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout<< endl;
}

int main(){
    string_to_vector();
}