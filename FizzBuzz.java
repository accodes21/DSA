class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> ans = new ArrayList<>(n);

        for(int i = 1; i <= n; i++){
            boolean divisibleBy3 = i%3 == 0;
            boolean divisibleBy5 = i%5 == 0;

            if(divisibleBy3 && divisibleBy5){
                ans.add("FizzBuzz");
            }
            else if(divisibleBy3){
                ans.add("Fizz");
            }
            else if(divisibleBy5){
                ans.add("Buzz");
            }
            else{
                ans.add(String.valueOf(i));
            }
        }
        return ans;
    }
}
