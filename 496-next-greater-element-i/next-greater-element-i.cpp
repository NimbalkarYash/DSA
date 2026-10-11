class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans(nums1.size(), -1);
        for(int i=0; i<nums2.size();i++)
        {
            mp[nums2[i]] = i; 
        }

        int j = 0;
        int i = 0;
        while(i < nums1.size())
        {
            j = mp[nums1[i]];

            for(int k = j; k<nums2.size(); k++)
            {
                if(nums2[k] > nums1[i])
                {
                    ans[i] = nums2[k];
                    break;
                }
            }
            i++;
        }
        return ans;

    }
};