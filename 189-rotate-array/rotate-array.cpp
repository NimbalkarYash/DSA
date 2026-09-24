class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int r = k%nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+r);
        reverse(nums.begin()+r, nums.end());
    }
};