class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices that are out of this window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove indices whose corresponding values are less than nums[i]
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Starting from index k - 1, record the maximum
        if (i >= k - 1) {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;

    }
    
};