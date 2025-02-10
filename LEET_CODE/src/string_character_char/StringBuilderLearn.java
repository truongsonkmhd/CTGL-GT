package string_character_char;

public class StringBuilderLearn {
    public static boolean arrayStringsAreEqual(String[] arr1, String[] arr2){
     StringBuilder r1 = new StringBuilder();
        StringBuilder r2 = new StringBuilder();

        for (String s : arr1){
            r1.append(s);
        }

        for (String s : arr2){
            r2.append(s);
        }
        return r1.toString().equals(r2.toString());
    }

    public static void main(String[] args) {
        String[] str1 = {"fwefsd0", " fawefsde"};
        String[] str2 = {"fwe", " fwefs"};
        System.out.println(arrayStringsAreEqual(str1, str2));
    }
}
