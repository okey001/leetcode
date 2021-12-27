// merge and reverse two linked lists
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Integer{
private:
    static const int SYSTEM = 10;
    vector<int> data;
public: 
    Integer(){
        data.push_back(0);
    }
    Integer(int n){
        do{
            data.push_back(n % SYSTEM);
            n = n / SYSTEM;
        } while(n);
    }
    void add(Integer other){
        int size = data.size();
        if (other.data.size() > size) size = other.data.size();
        data.resize(size);
        for(int i = 0; i < size; i++){
            if(i < other.data.size()){
                data[i] += other.data[i];
            }
            if(i > 0){
                data[i] += data[i - 1] / SYSTEM;
                data[i - 1] %= SYSTEM;
            }
        }
        while(data.back() >= SYSTEM){
            int num = data.back() / SYSTEM;
            data.back() %= SYSTEM;
            data.push_back(num);
        }
    }
    void mul(int n){
        for(int i = 0; i < data.size(); i++){
            data[i] *= n;
            if(i > 0){
                data[i] += data[i - 1] / SYSTEM;
                data[i - 1] %= SYSTEM;
            }
        }
        while(data.back() >= SYSTEM){
            int num = data.back() / SYSTEM;
            data.back() %= SYSTEM;
            data.push_back(num);
        }
    }
    void reset(){
        data.clear();
        data.push_back(0);
    }
    string toString(){
        string s;
        for(int i = data.size() - 1; i >= 0; i--){
            s += '0' + data[i];
        }
        return s;
    }

};

Integer count(int n){
    if (n == 0) return Integer(0);
    if (n == 1) return Integer(0);
    if (n == 2) return Integer(1);
    Integer dp[3];
    dp[1] = Integer(0);
    dp[2] = Integer(1);
    for(int i = 3; i <= n; i++){
        dp[i % 3].reset();
        dp[i % 3].add(dp[(i - 1) % 3]);
        dp[i % 3].add(dp[(i - 2) % 3]);
        dp[i % 3].mul(i - 1);
    }
    return dp[n % 3];
}

int main(){
    int n;
    cin >> n;
    cout << count(n).toString() << endl;
    return 0;
}