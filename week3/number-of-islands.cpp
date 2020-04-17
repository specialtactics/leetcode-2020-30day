class Solution {
public:
    int numIslands(vector<vector<char>>& theGrid) {
        int islandCount = 0;
        grid = theGrid;
        
        vector<char>::iterator inner;
        vector<vector<char>>::iterator outer;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1' && seen.find(pair<int, int>(i, j)) == seen.end()) {
                    ++islandCount;
                    
                    // Iterate through island
                    iterateSquare(i, j);
                }
            }
        }

        return islandCount;
    }

        
private:
    set<pair<int, int>> seen;
    vector<vector<char>> grid;
    
    /**
     * Iterate island horizonally
     */
    bool iterateSquare(int vertical, int startingHorizontal) {
        // Check bounds
        int upperBound = grid.size();
        
        // Optimisation
        if (seen.find(pair<int, int>(vertical, startingHorizontal)) != seen.end()) {
            return false;
        }

        seen.insert(pair<int, int>(vertical, startingHorizontal));
        
        // Horizonally right
        for (int b = startingHorizontal; b < grid[vertical].size(); ++b) {
            if (grid[vertical][b] != '1') {
                break;
            } else {
                seen.insert(pair<int, int>(vertical, b));
                
                if (vertical - 1 >= 0) {
                    if (grid[vertical-1][b] == '1') {
                        iterateSquare(vertical - 1, b);                    
                    }                         
                }
                if (vertical + 1 < upperBound) {
                    if (grid[vertical+1][b] == '1') {
                        iterateSquare(vertical + 1, b);                    
                    }             
                }
            }
        }

        // Horizonally left
        for (int b = (startingHorizontal - 1); b >= 0; --b) {
            if (grid[vertical][b] != '1') {
                break;
            } else {
                seen.insert(pair<int, int>(vertical, b));
                
                if (vertical - 1 >= 0) {
                    if (grid[vertical-1][b] == '1') {
                        iterateSquare(vertical - 1, b);                    
                    }                    
                }
                if (vertical + 1 < upperBound) {
                    if (grid[vertical+1][b] == '1') {
                        iterateSquare(vertical + 1, b);                    
                    }                    
                }
            }
        }
        
        return true;
    }
};
