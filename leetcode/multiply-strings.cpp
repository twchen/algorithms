/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

// thought too much ...
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0') return "0";
        return mult(num1, num2);
    }

private:
    typedef unsigned long long myint_t;
    string mult(string &num1, string &num2){
        vector<myint_t> nvec1, nvec2;
        tovector(num1, nvec1);
        tovector(num2, nvec2);
        vector<pair<myint_t, int>> products;
        for(int i = 0; i < nvec1.size(); ++i){
            for(int j = 0; j < nvec2.size(); ++j){
                myint_t prod = nvec1[i] * nvec2[j];
                products.emplace_back(prod, (i + j) * d);
            }
        }
        sort(products.begin(), products.end(), [](pair<myint_t, int> &a, pair<myint_t, int> &b){
            return a.second < b.second;
        });
        int max_pow = (nvec1.size() + nvec2.size()) * d;
        string ans(max_pow, '0');
        myint_t carry = 0;
        int i = 0;
        int power = d;
        myint_t quotient = pow(10, d);
        while(i < products.size()){
            myint_t sum = carry;
            while(i < products.size() && products[i].second < power){
                sum += products[i].first;
                ++i;
            }
            myint_t remainder = sum % quotient;
            carry = sum / quotient;
            copyto(ans, to_string(remainder), max_pow - power + d - 1);
            power += d;
        }
        if(carry != 0){
            copyto(ans, to_string(carry), max_pow - power + d - 1);
        }
        i = 0;
        while(ans[i] == '0') ++i;
        return ans.substr(i);
    }
    
    void tovector(string &num, vector<myint_t> &nvec){
        int n = num.size();
        for(int i = n; i > 0; i -= d){
            int pos = max(i - d, 0);
            string s = num.substr(pos, i - pos);
            nvec.push_back(stoull(s));
        }
    }
    
    void copyto(string &num, const string &remainder, int right){
        int n = remainder.size();
        for(int i = 0; i < n; ++i){
            num[right - i] = remainder[n - 1 - i];
        }
    }
    const int d = static_cast<int>(log10(numeric_limits<myint_t>::max()) - 1) / 2;
};

// 12ms
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0') return "0";
        int n1 = num1.size();
        int n2 = num2.size();
        int n = n1 + n2;
        string ans(n, '0');
        int carry = 0;
        for(int d = 0; d < n; ++d){
            int sum = carry;
            for(int i = 0; i < n1; ++i){
                int j = d - i;
                if(0 <= j && j < n2){
                    sum += (num1[n1 - 1 - i] - '0') * (num2[n2 - 1 - j] - '0');
                }
            }
            carry = sum / 10;
            ans[n - 1 - d] = '0' + sum % 10;
        }
        int i = 0;
        while(ans[i] == '0') ++i;
        return ans.substr(i);
    }
};

// 11ms
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0') return "0";
        int n1 = num1.size();
        int n2 = num2.size();
        int n = n1 + n2;
        vector<int> v(n1 + n2, 0); // sums of products
        // v[d] = sum of products with degree d
        for(int i = 0; i < n1; ++i){
            for(int j = 0; j < n2; ++j){
                v[n - 2 - i - j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        int carry = 0;
        for(int i = 0; i < n; ++i){
            carry += v[i];
            v[i] = carry % 10;
            carry /= 10;
        }
        int n_digits = (v[n-1] == 0 ? n - 1 : n);
        string ans(n_digits, '0');
        for(int i = 0; i < n_digits; ++i){
            ans[n_digits - 1 - i] += v[i];
        }
        return ans;
    }
};