import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.regex.Pattern;
class Pallindrome
{
    public static void main(String[] args)throws Exception
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter string : ");
        String str = reader.readLine();
        if(str==null||!Pattern.matches("[a-zA-Z]+", str))
        {
            System.out.println("Invalid string(either null or contains special symbols)");
            System.exit(0);
        }
        str = str.toLowerCase();
        for(int i = 0; i < str.length()/2; i++)
        {
            if(str.charAt(i)!=str.charAt(str.length()-i-1))
            {
                System.out.println("String is not pallindrome");
                System.exit(0);
            }
        }
        System.out.println("String is pallindrome");
    }
}