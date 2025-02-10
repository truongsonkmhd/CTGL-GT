package string_character_char;

public class main {
    public static void main(String[] args) {
        String s = "Hello World! 1 2 3 4";

        for(int i = 0 ; i < s.length() ; i++){
            char c = s.charAt(i);// in ra tung ki ty char trong string

            if(Character.isUpperCase(c)){ // ki tu in hoa
                System.out.println(c);
            }

            if(Character.isDigit(c)){ // in ra ki tu chu so
                System.out.println(c);
            }
            System.out.println(c);
        }

        char c = 'A';
        System.out.println("/n " + c+ "co ma ascii la : " + (int)c);

        String s1 = "Hello";
        String s2 = "Hello";
        String s3 = new String("Hello");

        System.out.println("\n s1==s2: " + (s1 == s2)); // true
        System.out.println("\n s2==s3: " + (s2 == s3)); // false
        System.out.println("\n s1==s3: " + (s1 == s3));// true

        System.out.println("\n s1==s2: " + (s1.equals(s2)));// true
        System.out.println("\n s2==s3: " + (s2.equals(s3)));// true
        System.out.println("\n s1==s3: " + (s1.equals(s3)));// true
    }
}
