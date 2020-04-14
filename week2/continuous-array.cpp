class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int longestLength = 0, currentLength = 0, travelled = 0;
        int deviator = 0;
        
        map<int, int> deviationSizes;
        map<int, int>::iterator mit;
        deviationSizes[0] = 0;

        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            ++travelled;
            
            // Deviate
            if (*it == 0) {
                --deviator;
            } else {
                ++deviator;
            }
            
            // Try and find the deviation before and measure length, otherwise store it
            if ((mit = deviationSizes.find(deviator)) != deviationSizes.end()) {
                currentLength = travelled - mit->second;
                if (currentLength > longestLength) {
                    longestLength = currentLength;
                }
            } else {
                deviationSizes[deviator] = travelled;
            }
        }
        
        return longestLength;
    }
};

