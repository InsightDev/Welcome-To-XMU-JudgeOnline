import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cas = in.nextInt();

        String regex = "^(\\+|-)?\\d+(\\.\\d+)?((e|E)(\\+|-)?\\d+)?$";
        Pattern pattern = Pattern.compile(regex);
        for(int i=0; i<cas; i++){
            Matcher matcher = pattern.matcher(in.next());
            if(matcher.find())
                System.out.println("yes");
            else
                System.out.println("no");
        }
    }
}
