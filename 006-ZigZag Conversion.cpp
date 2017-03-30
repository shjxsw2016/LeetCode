class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        int s_num = s.length();
        int circle = 2 * numRows - 2;
        if (numRows <= 1){
            return s;
        }
        else
        {
            int Round = s.length() / circle + 1;
            for (int i = 0; i < numRows; i++){
                for (int j = 0; j < Round; j++){
                    int index = i + j * circle;
                    if (index < s_num){
                        result += s[index];
                    }
                    if (i != 0 && i != (numRows - 1)){
                        index = (j + 1)*circle - i;
                        if (index < s_num){
                            result += s[index];
                        }
                    }
                }
            }
        }
        return result;
    }
};







