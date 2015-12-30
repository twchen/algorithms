/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.
*/

// solution 1
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN){
            return 0;
        }
        if(x < 0){
            return -1 * reverse(-x);
        }
        int rev = 0;
        int temp = 0;
        while(x > 0){
            temp = rev * 10 + x % 10;
            if(temp / 10 != rev){
                return 0;
            }else{
                rev = temp;
                x /= 10;
            }
        }
        return rev;
    }
};

// solution 2
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN){
            return 0;
        }
        if(x < 0){
            return -1 * reverse(-x);
        }
        int rev = 0;
        int temp = 0;
        while(x > 0){
            if((INT_MAX - x % 10) / 10 < rev){
                return 0;
            }else{ // overflow
                rev = rev * 10 + x % 10;
                x /= 10;
            }
        }
        return rev;
    }
};

// solution 3
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN)
            return 0;
        if(x < 0)
            return -1 * reverse(-x);
        int max_diff = INT_MAX / 10;
        int rev = 0;
        while(x > 0){
            if(rev > max_diff)
                return 0;
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
};
