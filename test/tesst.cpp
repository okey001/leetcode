#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
using namespace std;

class Singleton {
public:
    static Singleton &Instance()
    {
        static Singleton instance;
        return instance;
    }

public:
    Singleton(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton &operator=(const Singleton &) = delete;
    Singleton &operator=(Singleton &&) = delete;

private:
    Singleton() = default;
    ~Singleton() = default;
};

struct cmp1{
    bool operator()(int a, int b){
        return a < b;
    }
};
bool cmp(int a, int b){
    return a < b;
}

class A {
public:
    int a;
    A(int v = 10): a(v){
        cout << "constructor" <<endl;
    }
    A(const A& other): a(other.a){
        cout << "copy constructor" <<endl;
    }
    A(A&& other): a(other.a){
        cout << "copy constructor" <<endl;
    }
    A& operator=(const A& other) {
        a = other.a;
        cout << "= constructor" <<endl;
        return *this;
    }
    A& operator=(A&& other) {
        a = other.a;
        cout << "= constructor" <<endl;
        return *this;
    }
};


void op(string a){
    cout<<1<<endl;
    cout<<a.size()<<endl;
    //cout<< a.length();
    return ;
}

A func(A a){
    return A();
}

class Solution {
public:
    void dfs(map<int, int>& m, vector<int>& cur, vector<vector<int>>& ans){
        if(m.size() == 0){
            ans.push_back(cur);
            return ;
        }
        for(auto it = m.begin(); it != m.end();){
            int k = it->first;
            int v = it->second;
            if(it->second == 1){
                it++;
                m.erase(k);
            }else{
                m[k]--;
                it++;
            }
            cur.push_back(k);
            dfs(m, cur, ans);
            cur.pop_back();
            m[k]++;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        map<int, int> m;
        for(auto v: nums) m[v]++;
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(m, cur, ans);
        return ans;
    }
};



int main()
{
    Solution s;
    vector<int> nums = {1,2,3};
    auto ans = s.permute(nums);
    for(auto v: ans) {
        for(auto i: v) {
            cout << i << ' ' ;
        }
        cout<< endl;
    }
    cout << endl;
    return 0;
}