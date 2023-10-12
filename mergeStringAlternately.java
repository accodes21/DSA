import java.util.Scanner;

/**
 * mergeStringAlternately
 */
public class mergeStringAlternately {

    public static String mergeAlternately(String s1, String s2){
        StringBuilder sb = new StringBuilder();
        int i = 0;
        while(i<s1.length() || i<s2.length()){
            if(i<s1.length()){
                sb.append(s1.charAt(i));
            }
            if(i<s2.length()){
                sb.append(s2.charAt(i));
            }
            i++;
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println("Enter string1:");
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();
        System.out.println("Enter string2:");
        String s2 = sc.nextLine();

        String result = mergeAlternately(s1,s2);
        System.out.println("Result "+result);
        sc.close();
    }
}