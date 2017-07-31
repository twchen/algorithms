/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

// simple solution 1
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string sum(max(i, j) + 1, '0');
        bool carry = false;
        while(i >= 0 || j >= 0){
            int curr = (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0) + carry;
            sum[max(i, j) + 1] = curr % 2 + '0';
            carry = curr > 1; // carry = curr / 2;
        }
        if(carry){ // overflow
            sum.insert(sum.begin(), '1');
        }
        return sum;
    }
};

// simple solution 2
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string sum = "";
        int carry = 0;
        while(i >= 0 || j >= 0 || carry != 0){ // i < 0 && j < 0 && carry == 1: overflow
            if(i >= 0){
                carry += a[i] - '0';
                --i;
            }
            if(j >= 0){
                carry += b[j] - '0';
                --j;
            }
            // the above two if clauses can be replaced by the following one-line code;
            //carry = (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0) + carry;
            sum = (carry % 2 ? "1" : "0") + sum;
            carry /= 2;
        }
        return sum;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        string *l, *s;
        if(a.size() > b.size()){
            l = &a; s = &b;
        }else{
            l = &b; s = &a;
        }
        string sum(l->size(), '0');
        int i = l->size() - 1;
        int j = s->size() - 1;
        char carry = '0';
        for(; j >= 0; --i, --j){
            int temp = l->at(i) + s->at(j) + carry;
            if(temp == '0' * 3 || temp == '0' + '1' * 2){
                sum[i] = '0';
            }else{
                sum[i] = '1';
            }
            if(temp < '1' * 2 + '0'){
                carry = '0';
            }else{
                carry = '1';
            }
        }
        for(; i >= 0; --i){
            if(carry + l->at(i) == '0' + '1'){
                sum[i] = '1';
            }else{
                sum[i] = '0';
            }
            if(carry + l->at(i) == '1' + '1'){
                carry = '1';
            }else{
                carry = '0';
            }
        }
        if(carry == '1'){
            sum.insert(sum.begin(), '1');
        }
        return sum;
    }
};
