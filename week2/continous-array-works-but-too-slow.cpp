class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int longestLength = 0;
        
        int slackLeft = 0;
        int groupLength = -1;
        int incrementIterator = 0;
        
        vector<int>::iterator it = nums.begin();
        
        // Iterate
        while (it != nums.end())  {
            // Measure the length of one group
            if (*it == startCondition) {
                groupLength = measureGroup(it, nums.end(), slackLeft);
                    
                if (groupLength > longestLength) {
                    longestLength = groupLength;
                }

                /*
                incrementIterator = groupLength / 10;
                if (incrementIterator > 0) {
                    it += incrementIterator;           
                }
                */
                
                slackLeft = 0;
            } else {
                ++slackLeft;
            }
            
            ++it;
        }
        
        return longestLength;        
    }

private:
    // Start condition for group
    int startCondition = 0;
    
    // Measure the length of one group
    int measureGroup(vector<int>::iterator it, vector<int>::iterator end, int slackLeft) {
        vector<int>::iterator potentialEndOfGroup = it;
        int targetCount = 0;
        
        // Current length of group
        int groupDistance = 0;
        
        // Highest length so far
        int groupLength = 0;
        
        int shortFall = 0;
        
         while (it != end) {
            if (*it == startCondition) {
                ++targetCount;
            }
            
            ++groupDistance;
            
            // Forward case
            if (groupDistance / 2 == targetCount && groupDistance % 2 == 0) {
                if (targetCount > groupLength) {
                    groupLength = targetCount;
                    potentialEndOfGroup = it;
                    
                    //cout << " Forward " << targetCount << "\n";
                }
            }
            // Backwards case
            shortFall = targetCount * 2 - groupDistance;
            if (shortFall > 0 && slackLeft >= shortFall) {
                if (targetCount > groupLength) {
                    groupLength = targetCount;
                    potentialEndOfGroup = it;
                    
                    //cout << " Backward " << targetCount << "\n";
                }
            }
            
            // Break early if possible
            if (groupDistance > targetCount * 4) {
                break;
            }             
             
            ++it;
        }
        
        // Double as we stored the target count
        return (groupLength * 2);        
    }
};
 
