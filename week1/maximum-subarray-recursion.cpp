This works I believe, but it got time limit exceeded, so we need to make it smarter

 class Solution {
public:
    vector<int>::iterator end;
    
    int maxSubArray(vector<int>& nums) {
        vector<int>::iterator it = nums.begin();
        this->end = nums.end();

        return recurse(*it, *it, ++it);
    }
    
    int recurse(int highestSum, int currentSum, vector<int>::iterator it) {
        // End recursion
        if (it == this->end) {
            return highestSum;
        }
        
        // Get current value and next iterator
        int currentValue = *it;
        int newSum = currentSum + currentValue;
        ++it;
        
        // Try both options
        int startOver = recurse(highestSum, currentValue, it);
        int keepAdding = recurse(highestSum, newSum, it);

        // Figure out which option is best, and handle all the special cases
        int newResult = max(max(max(max(currentSum, keepAdding), startOver), newSum), currentValue);

        // If we have a better result, pass it up
        if (newResult > highestSum) {
            highestSum = newResult;
        }
        
        return highestSum;
    }
};


With a cool-off


static const int COLD_LIMIT = 5;

class Solution {
public:
    vector<int>::iterator end;
    
    int maxSubArray(vector<int>& nums) {
        vector<int>::iterator it = nums.begin();
        this->end = nums.end();

        return recurse(*it, *it, ++it, 0);
    }
    
    int recurse(int highestSum, int currentSum, vector<int>::iterator it, int coldness) {
        // End recursion
        if (it == this->end || coldness == COLD_LIMIT) {
            return highestSum;
        }
        
        // Get current value and next iterator
        int currentValue = *it;
        int newSum = currentSum + currentValue;
        ++it;
        
        // Have a concept of whether we are getting warmer or colder to a new best result
        if (newSum < currentSum) {
            ++coldness;
        }
        
        // Try both options
        int startOver = recurse(highestSum, currentValue, it, 0);
        int keepAdding = recurse(highestSum, newSum, it, coldness);

        // Figure out which option is best, and handle all the special cases
        int newResult = max(max(max(max(currentSum, keepAdding), startOver), newSum), currentValue);

        // If we have a better result, pass it up
        if (newResult > highestSum) {
            highestSum = newResult;
        }
        
        return highestSum;
    }
};
