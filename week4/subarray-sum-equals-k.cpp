class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> sums;
        map<int, int>::iterator sumsIt;
        
        int sum = 0;
        sums.insert(pair<int, int>(0, 1));
        int result = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            if ((sumsIt = sums.find(sum - k)) != sums.end()) {
                result += sumsIt->second;
            }
            
            ++(sums[sum]);
        }
        
        return result;
    }
}; 
