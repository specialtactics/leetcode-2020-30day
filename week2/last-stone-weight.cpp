 class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Initial sort
        sort(stones.begin(), stones.end());
        
        // Reduce to <= 1
        while (stones.size() > 1) {
            doOnePass(stones);
        }
        
        if (stones.size() == 1) {
            return stones[0];
        } else {
            return 0;
        }
    }
    
private:
    /**
     * One pass of the stones
     */ 
    void doOnePass(vector<int>& stones) {
        int highest[2];
        
        highest[0] = stones.back();
        stones.pop_back();
        highest[1] = stones.back();
        stones.pop_back();
        
        // Calculate new stone int
        if (highest[0] != highest[1]) {
            int newStone;
            
            if (highest[0] > highest[1]) {
                newStone = highest[0] - highest[1];
            } else {
                newStone = highest[1] - highest[0];
            }
            
            // Insert it
            if (stones.size() == 0) {
                stones.push_back(newStone);
            } else {
                vector<int>::iterator it = stones.begin();
                
                while (it != stones.end() && (*it) < newStone) {
                    ++it;
                }
                
                stones.insert(it, newStone);
            }
        }        
    }
};
