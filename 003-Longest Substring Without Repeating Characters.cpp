class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> isin(128,false);  //因为ASCII码一共128个
        int result = 0;
        for (int front=0,rear=0;front<s.length();front++){
            if(isin[s[front]]){
                //当这个字母出现第二次的时候，进入这个if，把rear指到这个字母第一次出现的位置的后面（例如第一个c的后面，作为新的字符串的开始），前面的全部改成false
                for(;rear<front && isin[s[front]];rear++){
                    isin[s[rear]] = false;
                }
            }
            isin[s[front]] = true; //当这个字母出现了，就把它改成true
            result = max(result, front-rear+1);
        }
        return result;
    }
};


