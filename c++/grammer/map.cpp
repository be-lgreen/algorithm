#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

void my_print(map<string, int> &m){
    map<string, int>::iterator itr;
    for(itr = m.begin(); itr != m.end(); itr++){
        cout << itr -> first << " " << itr -> second << endl;
    }
}

void find_value(map<string, int> &m){
    cout << "----- find_value -----" << endl;

    if (m.find("one") != m.end())
    {
        cout << "find" << endl;
        cout << m.find("one") -> first << " " << m.find("one") -> second << endl;
    }
    else {
        cout << "not find" << endl;
    }

    if(m.count("one") != 0)
    {
        cout << "find" << endl;
    }
    else {
        cout << "not find" << endl;
    }

    cout << endl;
}

void map_iterator(map<string, int> m){

    cout << "----- map_iterator -----" << endl;
         //map<string ,int>::iterator iter;
    for(auto iter=m.begin(); iter != m.end(); iter++){
        cout << (*iter).first << " " << (*iter).second << endl;
        cout << iter -> first << " " << iter -> second << endl;
    }
    cout << endl;
}

int main() {
    //0. map 선언 (key, value)
    map<string, int> map;

    map.insert(make_pair("one", 100 ));
    map.insert(make_pair("two", 200 ));
    map["three"] = 300;
    map["four"] = 400;

    //1. key값으로 value접근
    find_value(map);

    //2. map 반복문
    map_iterator(map);

    //3. map에 insert시 vector에 키를 삽입하면 키값 리스트를 만들 수 있다.

    return 0;


}