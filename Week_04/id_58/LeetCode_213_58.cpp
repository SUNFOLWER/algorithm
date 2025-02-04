class Solution {
public:
    int rob(vector<int>& nums) {
		/***************method1************************/
         if (nums.size() <= 1) 
             return nums.empty() ? 0 : nums[0];
         return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
     }
    
     int rob(vector<int> &nums, int left, int right) {
         if (right - left <= 1) 
             return nums[left];
        
         vector<int> dp(right, 0);
         dp[left] = nums[left];
         dp[left + 1] = max(nums[left], nums[left + 1]);
         for (int i = left + 2; i < right; ++i) {
             dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
         }
         return dp.back();
     }
        
        /***************method2************************/
        if (nums.size() <= 1) 
            return nums.empty() ? 0 : nums[0];
        return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
    }
    
    int rob(vector<int> &nums, int left, int right) {
        int even = 0, odd = 0;
        for (int i = left; i < right; ++i) {
            if (i & 1) {
                odd = max(odd + nums[i], even);
            } else {
                even = max(even + nums[i], odd);
            }
        }
        return max(odd, even);
    }
};