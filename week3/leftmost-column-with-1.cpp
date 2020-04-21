// This question was confusing (english wise)

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        rows = binaryMatrix.dimensions()[0];
        cols = binaryMatrix.dimensions()[1];

        // Cols we're interested in
        considering.first = 0;
        considering.second = cols;
        pivot = cols/2;
        
        // Why even troll
        if (cols == 0) {
            return 0;
        }
        
        //cout << considering.first << " " << considering.second << " " << pivot << "\n";
        
        int lastPivot = pivot;
        bool found, lastFound = false;
        
        while (true) {
            found = reduceProblemSpace(binaryMatrix);

            //cout << pivot << " | " << lastPivot << found << lastFound << "\n";
            // Special case
            if (pivot == 0 && found) {
                return 0;
            }

            // Losing condition
            if (lastPivot == pivot && !found) {
                return -1;
            }
            // Winning condition
            else if (
                (lastPivot - pivot == 1 || pivot - lastPivot == 1) &&
                found == false && lastFound == true) {
                    return lastPivot;
                
            }
            // Another one
            else if (potentiallyNewPivot == lastGoodPivot) {
                return lastGoodPivot;
            }
            
            
            lastPivot = pivot;
            lastFound = found;
        }
                
        // This should never happen
        return 0;        
    }
    
private:
    int rows;
    int cols;
    pair<int,int> considering;
    int pivot;
    int potentiallyNewPivot = -1;
    int lastGoodPivot = -1;

    /**
     * Reduces problem space
     *
     * Returns if it finds a 1
     */
    bool reduceProblemSpace(BinaryMatrix &binaryMatrix) {
        bool found = false;
        if (potentiallyNewPivot >= 0) {
            pivot = potentiallyNewPivot;            
        }
        
        for (int i = 0; i < rows; ++i) {
            if (binaryMatrix.get(i, pivot) == 1) {
                found = true;
                lastGoodPivot = pivot;
                break;
            }
        }
        
        // Split to the left
        if (found) {
            considering.second = pivot;
            potentiallyNewPivot = pivot - ((pivot - considering.first) / 2);
            
            // Edge case
            if (potentiallyNewPivot == pivot) {
                --potentiallyNewPivot;
            }
        }
        // Split to the right
        else {
            considering.first = pivot;
            potentiallyNewPivot = pivot + ((considering.second - considering.first) / 2);
            
            // Edge case
            if (potentiallyNewPivot == pivot) {
                ++potentiallyNewPivot;
            }
        }
               
        return found;
    }
}; 
