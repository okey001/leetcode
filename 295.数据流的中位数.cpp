/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */
#include<queue>
#include<iostream>
using namespace std;
// @lc code=start
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> qMin;
    priority_queue<int, vector<int>, greater<int>> qMax;
    MedianFinder() {

    }
    
    void addNum(int num) {
        qMin.push(num);
        if(qMin.size() - 1 > qMax.size()){
            qMax.push(qMin.top());
            qMin.pop();
        }
        if(qMin.size() && qMax.size() && qMin.top() > qMax.top()){
            int maxTop = qMax.top();
            qMax.pop();
            qMax.push(qMin.top());
            qMin.pop();
            qMin.push(maxTop);
        }
    }
    
    double findMedian() {
        if (qMin.size() > qMax.size())return qMin.top();
        else return (qMin.top() + qMax.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

int main(){
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    obj->addNum(3);
    obj->addNum(4);
    obj->addNum(5);
    return 0;
}