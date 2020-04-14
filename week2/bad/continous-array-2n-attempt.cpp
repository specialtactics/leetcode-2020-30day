// Does not work, but idea was efficient (original attempt)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result1 = checkStart(0, nums);
        int result2 = checkStart(1, nums);
        
        return max(result1, result2);
    }

private:
    // Check nums against a given start condition
    int checkStart(int startCondition, vector<int>& nums) {
        int longestLength = 0;
        
        int slackLeft = 0;
        int groupLength = -1;
        
        vector<int>::iterator it = nums.begin(), groupStartIt;
        
        // Iterate
        while (it != nums.end())  {
            // Measure the length of one group
            if (*it == startCondition) {
                groupStartIt = it;
                
                groupLength = measureGroup(startCondition, &it, nums.end(), slackLeft);
                    
                if (groupLength > longestLength) {
                    longestLength = groupLength;
                }
                
                slackLeft = determineSlack(groupStartIt, it, startCondition);
            } else {
                ++slackLeft;
            }
            
            ++it;
        }
        
        return longestLength;
    }
    
    // Measure the length of one group
    int measureGroup(int startCondition, vector<int>::iterator* originalIt, vector<int>::iterator end, int slackLeft) {
        vector<int>::iterator potentialEndOfGroup, it = *originalIt;
        potentialEndOfGroup = it;
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
                    
                    cout << " Forward " << targetCount << "\n";
                }
            }
            // Backwards case
            shortFall = targetCount * 2 - groupDistance;
            if (shortFall > 0 && slackLeft >= shortFall) {
                if (targetCount > groupLength) {
                    groupLength = targetCount;
                    potentialEndOfGroup = it;
                    
                    cout << " Backward " << targetCount << "\n";
                }
            }
            
            ++it;
        }
        
        // Restore iterator to the end of this group, so that next group can be considered correctly
        *originalIt = potentialEndOfGroup;
        
        // Double as we stored the target count
        return (groupLength * 2);        
    }
    
    // Determine accurate amount of "slack" for the next group
    int determineSlack(vector<int>::iterator groupStart, vector<int>::iterator current, int startCondition) {
        int slack = 0;
        
        while (*current != startCondition) {
            --current;
            ++slack;
            
            if (current == groupStart) {
                break;
            }
        }
        
        cout << "Slack: " << slack << "\n";
        
        return slack;
    }
};
 
