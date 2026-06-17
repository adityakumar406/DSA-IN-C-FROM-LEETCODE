class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        long long num = 0;

        // Convert digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check overflow before adding digit
            if (num > (LLONG_MAX - digit) / 10)
                return sign == 1 ? INT_MAX : INT_MIN;

            num = num * 10 + digit;

            // Clamp to 32-bit signed integer range
            if (sign * num > INT_MAX)
                return INT_MAX;
            if (sign * num < INT_MIN)
                return INT_MIN;

            i++;
        }

        return (int)(sign * num);
    }
};