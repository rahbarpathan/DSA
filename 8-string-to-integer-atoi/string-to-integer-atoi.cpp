class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;

        // Step 1: skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Step 2: check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        // Step 3: build number
        long long res = 0;
        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');

            // Step 4: check overflow
            if (sign == 1 && res > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -res < INT_MIN)
                return INT_MIN;

            i++;
        }

        return (int)(sign * res);
    }
};
