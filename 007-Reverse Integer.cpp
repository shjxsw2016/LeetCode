class Solution {
public:
    int reverse(int x) {
        long result = 0;

        while (x != 0){
            result = result * 10 + x % 10;
            x = x / 10;
        }
        if (result > (numeric_limits<int>::max)() || result < (numeric_limits<int>::min)()){
            result = 0;
        }
        return result;
    }
};





