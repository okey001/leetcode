/*
 * @lc app=leetcode.cn id=1226 lang=cpp
 *
 * [1226] 哲学家进餐
 */

// @lc code=start
class DiningPhilosophers {
public:
    mutex mut[5], g;
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int l = (philosopher) % 5;
        int r = (philosopher + 1) % 5;

        g.lock();

        mut[l].lock();
        mut[r].lock();
        pickLeftFork();
        pickRightFork();
        eat();

        g.unlock();

        putLeftFork();
        putRightFork();

        mut[l].unlock();
        mut[r].unlock();
    }
};
// @lc code=end

