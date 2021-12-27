/*
 * @lc app=leetcode.cn id=2069 lang=cpp
 *
 * [2069] 模拟行走机器人 II
 */

// @lc code=start
class Robot {
public:
    int sum;
    int width, height;
    int cur = 0;
    Robot(int width, int height) {
        sum = width + height + width + height - 4;
        this->width = width;
        this->height = height;
    }
    
    void step(int num) {
        cur += num;
    }
    
    vector<int> getPos() {
        int cur = this->cur;
        if(cur > sum) cur %= sum;
        if(cur <= width - 1){
            return vector<int>{cur, 0};
        }
        cur -= width - 1;
        if(cur <= height - 1){
            return vector<int>{width - 1, cur};
        }
        cur -= height - 1;
        if(cur <= width - 1){
            return vector<int>{width - 1 - cur, height - 1};
        }
        cur -= width - 1;
        return vector<int>{0, height - 1 - cur};
    }
    
    string getDir() {
        if (cur == 0) return "East";
        int cur = this->cur;
        if(cur > sum) cur %= sum;
        if (cur == 0) return "South";
        if(cur <= width - 1){
            return "East";
        }
        cur -= width - 1;
        if(cur <= height - 1){
            return "North";
        }
        cur -= height - 1;
        if(cur <= width - 1){
            return "West";
        }
        cur -= width - 1;
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
// @lc code=end

