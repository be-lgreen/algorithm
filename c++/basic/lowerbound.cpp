/*
 * reference : https://www.geeksforgeeks.org/implementing-upper_bound-and-lower_bound-in-c/
 */
#include <iostream>
#include <vector>
using namespace std;

int lower_bound(vector<int> &v, int target){
    int left = 0;
    int right = v.size() - 1;
    int mid;

    while(right - left > 0){
        //mid = (right + left) / 2;
        mid = left + (right - left) / 2;

        if(target <= v[mid]){
            right = mid;
        }else{
            left = mid + 1;
        }
    }

    return left;
}

int upper_bound(vector<int> &v, int target){
    int left = 0;
    int right = v.size() - 1;
    int mid;

    while(right - left > 0){
        mid = left + (right - left) / 2;

        if(target < v[mid]){  // difference with lower_bound
            right = mid;
        }else{
            left = mid + 1;
        }
    }

    return left;
}

int main(){
    vector<int> v = {10, 10, 20, 20, 20, 20, 40};
    vector<int> v2 = {1, 2, 3};
    int num = 20;
    int num2 = 2;

    cout << lower_bound(v, num) << endl;
    cout << lower_bound(v2, num2) << endl;

    cout << upper_bound(v, num) << endl;
    cout << upper_bound(v2, num2) << endl;

}