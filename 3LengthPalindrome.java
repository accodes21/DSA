class Solution {
    public int countPalindromicSubsequence(String s) {
        int [] minIndexExist = new int[26];
        int [] maxIndexExist = new int[26];

        for(int i = 0; i<26; i++){
            minIndexExist[i] = Integer.MAX_VALUE;
            maxIndexExist[i] = Integer.MIN_VALUE;
        }

        for(int i = 0; i<s.length(); i++){
            int charIndex = s.charAt(i) - 'a';
            minIndexExist[charIndex] = Math.min(minIndexExist[charIndex], i);
            maxIndexExist[charIndex] = Math.max(maxIndexExist[charIndex], i);
        }

        int uniqueCount = 0;
        for(int charIndex = 0; charIndex<26; charIndex++){
            if(minIndexExist[charIndex] == Integer.MAX_VALUE || maxIndexExist[charIndex] == Integer.MIN_VALUE){
                continue;
            }

            HashSet<Character> uniqueCharsBetween = new HashSet<>();

            for(int j = minIndexExist[charIndex]+1; j<maxIndexExist[charIndex]; j++){
                uniqueCharsBetween.add(s.charAt(j));
            }

            uniqueCount += uniqueCharsBetween.size();
        }
        return uniqueCount;
    }
}
