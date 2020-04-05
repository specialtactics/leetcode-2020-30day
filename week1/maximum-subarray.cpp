class Solution {
public:
  
    int maxSubArray(vector<int>& nums) {
        vector<int>::iterator it = nums.begin();
        int current, highest, addingSet;
        highest = addingSet = *it;
            
        ++it;
        
        while (it != nums.end()) {
            current = *it;
            
            // No point adding to the subarray, if the next number is already bigger than the current subarray going
            if (current > current + addingSet) {
                addingSet = current;
            } else {
                addingSet += current;
            }
            
            if (addingSet > highest) {
                highest = addingSet;
            }
            
            ++it;
        }

        return highest;
    }
};
