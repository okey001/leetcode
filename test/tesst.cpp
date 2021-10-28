#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v;
    v.reserve(1000);
    v.resize(100);
    v.emplace_back(1);
    auto v1 = vector<int>(v);
    cout<< v.capacity() << " " << v.size() <<endl;
    cout<< v1.capacity() << " " << v.size() <<endl;
    v1.swap(v);
    cout<< v.capacity() << " " << v.size() <<endl;
    cout<< v1.capacity() << " " << v.size() <<endl;
    sort(v.begin(), v.end(), greater<int>());
    return 0;
}