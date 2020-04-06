// Runtime: 140 ms, faster than 9.29% of C++ online submissions for Group Anagrams.
// Memory Usage: 17.4 MB, less than 100.00% of C++ online submissions for Group Anagrams.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int> > groupByPosition;
        vector<vector<string>> result;
        string element;
        int i = 0;
        
        // Group the anagrams by index of original array
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it, ++i) {
            element = *it;
            sort(element.begin(), element.end());
            
            groupByPosition[element].push_back(i);
        }
        
        // Form result
        for (map<string, vector<int> >::iterator it = groupByPosition.begin(); it != groupByPosition.end(); ++it) {
            vector<string> singleSet;
            
            for (vector<int>::iterator iti = it->second.begin(); iti != it->second.end(); ++iti) {
                singleSet.push_back(strs[*iti]);
            }
            
            result.push_back(singleSet);
        }


        return result;
    }
};

// Bit simplified, but was unclear whether it would be more or less efficient
// Runtime changes by 30% every time it runs
// Runtime: 72 ms, faster than 30.23% of C++ online submissions for Group Anagrams.
// Memory Usage: 16.8 MB, less than 100.00% of C++ online submissions for Group Anagrams.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > groupByPosition;
        vector<vector<string>> result;
        string element;
        
        // Group the anagrams by index of original array
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
            element = *it;
            sort(element.begin(), element.end());
            
            groupByPosition[element].push_back(*it);
        }
        
        // Form result
        for (map<string, vector<string> >::iterator it = groupByPosition.begin(); it != groupByPosition.end(); ++it) {
            result.push_back(it->second);
        }

        return result;
    }
};
