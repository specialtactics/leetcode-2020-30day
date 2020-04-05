class Solution {
public:
    bool isHappy(int n) {
        int result;
        set<int> previousResults;

        do {
            result = sumOfSquaredParts(n);
            if (result == 1) {
                return true;
            } else {
                if (previousResults.find(result) != previousResults.end()) {
                    break;
                }

                previousResults.insert(result);
                n = result;
            }
        } while (true);

        return false;
    }

    int sumOfSquaredParts(int n) {
        int sum = 0;

        do {
            sum += pow(n % 10, 2);
            n /= 10;
        } while (n > 0);

        return sum;
    }
};
