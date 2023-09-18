class Solution {
    private:
    int expandString(const string &s, int left, int right){
        while(left>=0 && right<s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 0;
        int start = 0;

        for(int i = 0; i<n; i++){
            int l1 = expandString(s,i,i);
            int l2 = expandString(s,i,i+1);
            int l = max(l1,l2);

            if(l > maxlen){
                maxlen = l;
                start = i - (l-1)/2;
            }
        }
        return s.substr(start, maxlen);
    }
};