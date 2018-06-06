/*
Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.
Note:
The length sum of the given matchsticks is in the range of 0 to 10^9.
The length of the given matchstick array will not exceed 15.
 */

// This problem is NP-complete

class Solution {
public:
    typedef map<int, int, greater<int>> Map;
    bool makesquare(vector<int>& nums) {
        Map m;
        int sum = 0;
        for(int n : nums){
            ++m[n];
            sum += n;
        }
        int n_sides = 4;
        if(sum == 0 || sum % n_sides != 0) return false;
        int side_len = sum / n_sides;
        for(int i = 0; i < n_sides; ++i){
            int max = m.begin()->first;
            if(max > side_len) return false;
            bool success = delete_from(m, side_len);
            if(!success) return false;
        }
        return m.empty();
    }
    
private:
    bool delete_from(Map &m, int n){
        auto it = m.begin();
        for(; it != m.end(); ++it){
            if(it->first <= n){
                int num = it->first;
                --m[num];
                if(m[num] == 0) m.erase(num);
                if(num == n) return true;
                bool success = delete_from(m, n - num);
                if(success) return true;
                else ++m[num];
            }
        }
        return false;
    }
};

// use dfs
// credit: https://discuss.leetcode.com/topic/72107/java-dfs-solution-with-explanation
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum = 0;
        for(int n : nums){
            sum += n;
        }
        if(sum < n_sides || sum % n_sides != 0) return false;
        int side_len = sum / n_sides;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> sides(n_sides, 0);
        return dfs(nums, 0, sides, side_len);
    }

private:
    bool dfs(vector<int> &nums, int idx, vector<int> &sides, int side_len){
        if(idx == nums.size()){
            for(int i = 0; i < n_sides - 1; ++i){
                if(sides[i] != side_len) return false;
            }
            return true;
        }
        for(int i = 0; i < n_sides; ++i){
            if(sides[i] + nums[idx] > side_len) continue;
            sides[i] += nums[idx];
            bool success = dfs(nums, idx + 1, sides, side_len);
            if(success) return true;
            sides[i] -= nums[idx];
        }
        return false;
    }

    const int n_sides = 4;
};
