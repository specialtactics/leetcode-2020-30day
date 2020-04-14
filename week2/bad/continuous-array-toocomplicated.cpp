#define BASE 10
#define DOUBLE 11

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int longestLength = 0;

        vector<int> reduced, original(nums);
        int reductions = 0;
        
        do {
            reductions = reduce(original, reduced);
            cout << "\nReduced: " << reductions << "\n";
            
            if (reductions > 0) {
                original.swap(reduced);
                reduced.clear();
            }
            
            // Print
            for (std::vector<int>::const_iterator i = original.begin(); i != original.end(); ++i)
                std::cout << *i << ' ';
        } while (reductions > 0);
       
        // Calculate result
        int result = *max_element(original.begin(), original.end());        
        result -= BASE;
        result *= 2;
        
        return result;
    }

private:
    /**
     * Reduce vector by doubles, and return the reductions count
     */
    int reduce(vector<int>& original, vector<int>& reduced) {
        vector<int>::iterator it, it2;
        int reductions = 0, hotStreak = 0;
        
        if (original.size() > 1) {
            // Reduce 2 at a time
            it = original.begin();
            it2 = it + 1;

            do {
                // Both are already reductions, add them
                if (*it > 1 && *it2 > 1) {
                    int toAdd = ((*it) - BASE) + ((*it2) - BASE);
                    if (hotStreak == 1) {
                        if (reduced.back() < BASE + 1) { cout << "Debug 3 NOT GUD\n"; }// Debug
                        reduced.back() += toAdd;
                    } else {
                        reduced.push_back(BASE + toAdd);
                    }
                    
                    it = it2 + 1;
                    it2 += 2;
                    hotStreak = 1;
                    ++reductions;
                }
                
                // First is a reduction already, move along
                else if (*it > 1 && *it2 <= 1) {
                    reduced.push_back(*it);
                    hotStreak = 1;
                    
                    ++it;
                    ++it2;
                }
                
                // Second element is a reduction, try and find one that isn't
                else if (*it <= 1 && *it2 > 1) {
                    int originalReductionValue = *it2;
                    ++it2;
                    
                    if (it2 == original.end()) {
                        // None left
                        reduced.push_back(*it);
                        reduced.push_back(originalReductionValue);
                        
                        it = it2; // to prevent double insertion
                        break;
                    }
                    
                    // If they are separated by 1 element
                    else if (*it2 <= 1) {
                        // Make reduction
                        if (*it != *it2) {
                            int toAdd = (1 + (originalReductionValue - BASE));
                            
                            if (hotStreak == 1) {
                                if (reduced.back() < BASE + 1) { cout << "Debug 2 NOT GUD\n"; }// Debug
                                reduced.back() += toAdd;
                            } else {
                                reduced.push_back(toAdd + BASE);
                                hotStreak = 1;
                            }

                            it = it2 + 1;
                            it2 += 2;
                            ++reductions;
                        }
                        // Just push them in and move on
                        else {
                            reduced.push_back(*it);
                            reduced.push_back(originalReductionValue);

                            hotStreak = 1; // Because our last added value is a reduction
                            it = it2;
                            ++it2;
                        }   
                        
                    }
                    // If we can't easily find one, move along and we'll reduce these 2 next pass
                    else {
                        reduced.push_back(*it);
                        hotStreak = 0;
                        ++it;
                    }
                }
                
                // Neither are reductions
                // This should only happen on the first pass
                else if (*it <= 1 && *it2 <= 1) {
                    // Make reduction
                    if (*it != *it2) {
                        if (hotStreak == 1) {
                            if (reduced.back() < BASE + 1) { cout << "Debug 1 NOT GUD\n"; }// Debug
                            reduced.back() += 1;
                        } else {
                            // If we can reduce them now or at the next element, we need to figure out which will produce a longer "hot-streak"
                            if (it2 + 1 != original.end() && *it2 != *(it2 + 1)) {
                                int streak1 = measureStreaks(it, original.end());
                                int streak2 = measureStreaks(it2, original.end());

                                if (streak2 > streak1) {
                                    reduced.push_back(*it);
                                    ++it;
                                    ++it2;
                                }
                            }
                            
                            reduced.push_back(BASE + 1);
                            hotStreak = 1;
                        }

                        it += 2;
                        it2 += 2;
                        ++reductions;
                    }
                    // Just add
                    else {
                        reduced.push_back(*it);
                        hotStreak = 0;

                        ++it;
                        ++it2;
                    }                    
                }
                
                // This really shouldn't happen
                else {
                    cout << "This shouldn't hapen ;_____;\n";
                }

            } while (it != original.end() && it2 != original.end());
            
            // Lone last element
            if (it != original.end()) {
                reduced.push_back(*it);
            }
            
        } else {
            reduced.push_back(original[0]);
        }
        
        return reductions;
    }
    
    /**
     * Measure the hottest possible streak from a given iterator
     */
    int measureStreaks(vector<int>::iterator it, vector<int>::iterator end) {
        vector<int>::iterator it2 = it + 1;
        int streak = 0;
        
        do {
            if (*it != *it2) {
                ++streak;
                
                it += 2;
                it2 += 2;
            } else {
                break;
            }
        } while (it != end && it2 != end);
        
        return streak;
    }

};

