// Probably bigger than it needs to be, but I'm feeling lazy !
// Performance is also perfect so :shrug:

class Solution {
public:
    bool checkValidString(string s) {
        return checkForward(s) && checkBack(s);        
    }
    
    bool checkForward(string s) {
        int opened = 0;
        int wildcards = 0;
        
        for (string::iterator it = s.begin(); it != s.end(); ++it) {
            if (*it == '(') {
                ++opened;
            }
            else if (*it == ')') {
                --opened;
                
                while (opened < 0 && wildcards > 0) {
                    ++opened;
                    --wildcards;
                }
                
                if (opened < 0) {
                    return false;
                }
            } else if (*it == '*') {
                ++wildcards;
            }
        }
        
        if (opened == 0 || abs(opened) <= wildcards) {
            return true;
        }
        
        return false;
    }
    
    bool checkBack(string s) {
        int closed = 0;
        int wildcards = 0;
        
        for (string::reverse_iterator it = s.rbegin(); it != s.rend(); ++it) {
            if (*it == ')') {
                ++closed;
            }
            else if (*it == '(') {
                --closed;
                
                while (closed < 0 && wildcards > 0) {
                    ++closed;
                    --wildcards;
                }
                
                if (closed < 0) {
                    return false;
                }
            } else if (*it == '*') {
                ++wildcards;
            }
        }
        
        if (closed == 0 || abs(closed) <= wildcards) {
            return true;
        }
        
        return false;
    }
}; 
