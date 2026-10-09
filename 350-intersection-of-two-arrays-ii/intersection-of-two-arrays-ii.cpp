class Solution {
public:
    vector<int> helper(vector<int>& bigger, vector<int>& smaller)
    {
        sort(bigger.begin(), bigger.end());
        sort(smaller.begin(), smaller.end());
        int i = 0;
        int j = 0;
        vector<int> ans;
        while(i < bigger.size() && j<smaller.size())
        {
            if(bigger[i] == smaller[j])
            {
                ans.push_back(smaller[j]);
                i++;
                j++;
            }
            else if(bigger[i] < smaller[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
        {
            return helper(nums1,nums2);
        }
        else
        {
            return helper(nums2, nums1);
        }
    }
};