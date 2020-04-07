 class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, int> counter;
        int totals = 0;
        
        for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
            ++(counter[(*it)]);
        }
        
        // Get rid of dups
        sort(arr.begin(), arr.end());
        vector<int>::iterator newEnd = unique(arr.begin(), arr.end());
        
        for (vector<int>::iterator it = arr.begin(); it != newEnd; ++it) {
            totals += counter[(*it)-1];
        }
        
        return totals;
    }
};
