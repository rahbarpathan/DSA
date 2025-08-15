class Solution {
public:
    bool powerOf4(int x) {
        if (x == 1)
            return true;
        if (x <= 0 || x % 4 != 0)
            return false; // reject negatives, zero, and non-multiples of 4
        return powerOf4(x / 4);
    }

    bool isPowerOfFour(int n) { return powerOf4(n); }
};
