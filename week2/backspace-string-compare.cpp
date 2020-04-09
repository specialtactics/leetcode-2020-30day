class Solution {
public:
    bool backspaceCompare(string S, string T) {
        bool same = true;
        
        // Do backspace
        string first = backSpaceString(S), second = backSpaceString(T);
        string::iterator it = first.begin(), it2 = second.begin();
        
        do {
            // Check for end scenarios
            if (it == first.end() && it2 == second.end()) {
                break;
            } else if (it == first.end() || it2 == second.end()) {
                same = false;
                break;
            }
            
            // Compare
            if (*it != *it2) {
                same = false;
                break;
            }
            
            ++it;
            ++it2;
        } while (true);
        
        return same;
    }
    
private:
    /**
     * backspace the string
     */
    string backSpaceString(string input) {
        string output;
        int backspaces = 0;
        
        for (string::reverse_iterator it = input.rbegin(); it != input.rend(); ++it) {
            if (*it == '#') {
                ++backspaces;
            } else {
                if (backspaces > 0) {
                    --backspaces;
                } else {
                    output.push_back(*it);
                }
            }
        }
        
        return output;
    }
}; 
