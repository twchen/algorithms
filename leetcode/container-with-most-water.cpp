/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines
are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area = 0;
        int left = 0, right = n - 1;
        int lh, rh;
        while(left < right){
            lh = height[left];
            rh = height[right];
            for( ; left < right && height[right] <= lh; --right){
                // height[right_curr] < height[right_prev] and right_curr < right_prev
                // not possible for area to be larger
                if(height[right] < rh) continue;
                rh = height[right];
                area = max(area, rh * (right - left));
            }
            if(left < right)
                area = max(area, lh * (right - left));
            // height[left_prev] > height[left_curr] and left_prev < left_curr
            // not possible for area to be larger
            while(left < right && height[left] <= lh) ++left;
        }
        return area;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area = 0;
        int left = 0, right = n - 1;
        while(left < right){
            int h = min(height[left], height[right]);
            area = max(area, h * (right - left));
            // both height[left] and height[right] should be larger than h
            // to make it possible that area is larger
            while(left < right && height[left] <= h) ++left;
            while(left < right && height[right] <= h) --right;
        }
        return area;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area = 0;
        int left = 0, right = n - 1;
        while(left < right){
            int h = min(height[left], height[right]);
            area = max(area, h * (right - left));
            if(height[left] < height[right]){
                ++left;
            }else{
                --right;
            }
        }
        return area;
    }
};
