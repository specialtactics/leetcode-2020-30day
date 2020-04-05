bool comparison (int i, int j) {
    return (i < j);
}

class Solution {
public:
    
    int singleNumber(vector<int>& nums) {
        std::sort (nums.begin(), nums.end(), comparison);
        
        int result = 0;
        
        // Set up iterators
        std::vector<int>::iterator lastit = nums.begin(), it = nums.begin();
        ++it;
        
        // Loop until we find the non matching numbers, in a sorted vector
        do {
            // First, or in the middle
            if (it == nums.end() || *lastit != *it) {
                result = *lastit;
                break;
            } else {
                lastit++;
                lastit++;
                it++;
                it++;
            }
            
            // Last number in the list
            if (it == nums.end()) {
                result = *lastit;
                break;
            }
            
        } while (true);
        
       
        return result;
    }
};


