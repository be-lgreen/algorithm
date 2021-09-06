#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(const string& data, const char& delimitor = ' '){
    vector<string> result;
    string token;
    stringstream ss(data);

    while(getline(ss, token, delimitor)){
        result.push_back(token);
    }

    return result;
}



int main(){
    vector<string> li = split("hi my name is yeonsu");
    for(int i=0; i<li.size(); i++){
        cout << li[i] << endl;
    }


    string str = "my name is yeonsu";
    cout << str.substr(0,4) << endl;
    cout << str.find("name") << endl;
}