/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> t(n+1, 0); // t[i]: number of unique BSTs of a sequence of length i
        t[0] = 1;
        // recursive formula: t[n] = SUM( t[i-1] * t[n - i] ), i from 1 to n
        // pick the ith smallest number m in the sequence as root
        // the i-1 numbers that are smaller than m would be on the left side of root
        // the n-i numbers that are larger than m would be on the right side of root
        // so the number of unique BSTs using the ith smallest number as root is t[i-1] * t[n-i]
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= i; ++j){
                t[i+1] += t[j] * t[i - j];
            }
        }
        return t[n];
    }
};
