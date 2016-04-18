#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(void){

    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);

    for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	cout << *i << ",";
    cout << endl;

    map<string, string> d;
    d["key1"] = "value1";
    d["key2"] = "value2";
    d["key3"] = "value3";
    d["key2"] = "value4";

    cout << "key1=" << d["key1"] << endl;
    cout << "key2=" << d["key2"] << endl;
    cout << "key3=" << d["key3"] << endl;

    d.erase("key1");

    cout << "key1=" << d["key1"] << endl;

    return 0;

}
