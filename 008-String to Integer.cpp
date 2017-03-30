class Solution {
public:
    int myAtoi(string str) {
        long long result = 0;
        int str_len = str.length();
        int count = 0;
        int flag1 = 0, flag2 = 0;
        //忽略前缀空格
        while (str[count] == ' '){
            count++;
        }
        //只能出现一个‘+’或者一个‘-’
        if (str[count] == '+'){
            flag1++;
            count++;
        }
        else{
            if (str[count] == '-'){
                flag2++;
                count++;
            }
        }
        //如果后续是数字继续处理，不是则返回0
        //要考虑越界的情况
        for (int i = count; i < str_len; i++){
            if (str[i] >= '0'&&str[i] <= '9'){
                result = result * 10 + str[i] - '0';
                if (flag2){
                    if (-result < INT_MIN) return INT_MIN;
                }
                else{
                    if (result > INT_MAX) return INT_MAX;
                }
            }
            else
                break;
        }
        if(flag2) result = -result;
        return (int)result;
    }
};







