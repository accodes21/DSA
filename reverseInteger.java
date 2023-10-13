class Solution {
    public int reverse(int x) {
        boolean isNeg = x<0;
        if(isNeg) x = x*-1;
        int rev = 0;
        while(x>0){
            if((rev*10) % 10 != 0) return 0;
            int rem = x%10;
            rev = rev*10+rem;
            x/=10;
        }
        if(isNeg) rev = rev*-1;
        return rev;
    }
}
