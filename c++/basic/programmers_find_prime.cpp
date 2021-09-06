#include <string>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
int check(string str1, string str2){
    int arr[10] = {0};
    int index;
    int temp;
    for(int i=0; i<str1.size(); i++){
        arr[str1[i] - '0'] += 1;
    }

    for(int i=0; i<str2.size(); i++){
        index = str1.find(str2[i]);

        temp = arr[str1[index] - '0'];
        arr[str1[index] - '0'] = temp -1;
        if(temp -1 < 0)
            return 0;
    }
    return 1;
}
int check2(string str1, string str2){
    cout << "" << str1 << endl;
    cout << "" << str2 << endl << endl;
    sort(str1.begin(), str1.end(), greater<int>());
    sort(str2.begin(), str2.end(), greater<int>());


    int a = str1.length();
    int i=0;
    int j=0;
    while(i<a){
        if(j >= str2.length()){

            return 1;
        }
        if(str1[i] == str2[j]){
            i+=1;
            j+=1;
        }else{
            i++;
        }
    }
    if(i==str1.length() && j == str2.length())
        return 1;
    return 0;
}
int solution(string numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end(), greater<int>());
    if(numbers[0] == 0)
        return 0;

    int prime[1000010] = {0};
    int max_num = 0;
    for(int i=1; i<=numbers.size(); i++){
        max_num += ((numbers[i-1]-'0') * pow(10, numbers.size()-i));
    }

    prime[1] = -1; //false
    int div = 1;
    while(div < max_num){
        div++;
        if(prime[div] == -1) {
            continue;
        }else{
            prime[div] = 1;
            if(check2(numbers, to_string(div))){
                answer += 1;
            }
        }

        for(int i=div+1; i<=max_num; i++){
            if(i%div == 0)
                prime[i] = -1;
        }
    }
    return answer;
}


int main(){
    //printf("%d",check2("110","101"));
    printf("%d",solution("011"));


}