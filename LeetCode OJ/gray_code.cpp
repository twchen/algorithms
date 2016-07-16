/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        res.reserve(1 << n);
        for(int i = 0; i < n; ++i){
            int m = 1 << i;
            for(int j = res.size() - 1; j >= 0; --j){
                res.push_back(res[j] | m);
            }
        }
        return res;
    }

    // black magic ...
    // the ith code = i ^ (i / 2)
    // credit: https://discuss.leetcode.com/topic/8557/an-accepted-three-line-solution-in-java/2
    vector<int> grayCode(int n) {
        vector<int> res;
        res.reserve(1 << n);
        for(int i = 0; i < 1 << n; ++i){
            res.push_back(i ^ (i >> 1));
        }
        return res;
    }
};
