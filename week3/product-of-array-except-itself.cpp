 class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        map<int, int> results;
        map<int, int>::iterator mapIt;
        int resultSoFar = 1;
        bool seenIt;
        vector<int> resultsV;

        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            seenIt = true;
            
            // Initiate if we haven't seen this value before
            if (results.find(*it) == results.end()) {
                results[*it] = resultSoFar;
                seenIt = false;
            }
            
            // Multiply through
            for (mapIt = results.begin(); mapIt != results.end(); ++mapIt) {
                if (mapIt->first != *it || seenIt) {
                    mapIt->second *= *it;
                }
            }
            
            resultSoFar *= *it;
        }
        
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            resultsV.push_back(results[*it]);
        }

        return resultsV;        
    }
};
