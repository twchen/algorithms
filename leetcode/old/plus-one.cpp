/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /*
        int carry = 1;
        int i = digits.size();
        while(i-- && carry){
            carry = (digits[i] + 1) / 10;
            digits[i] = (digits[i] + 1) % 10;
        }
        // overflow
        if(carry){
            int size = digits.size();
            digits.resize(size + 1);
            for(int i=size; i>0; --i){
                digits[i] = digits[i-1];
            }
            digits[0] = 1;
        }
        return digits;
        */
        // simpler solution
        int i = digits.size();
        while(i-- && digits[i] == 9)
            digits[i] = 0;
        if(i == -1) // overflow
            digits.insert(digits.begin(), 1);
        else
            digits[i]++;
        return digits;
    }
};
