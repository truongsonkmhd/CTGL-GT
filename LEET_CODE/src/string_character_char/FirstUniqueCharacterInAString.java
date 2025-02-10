package string_character_char;
//Given a string s, return the first non-repeating character in it and return its index.
//if it does not exist, return -1
//InPut: s = "leetcode"
//output: 0

public class FirstUniqueCharacterInAString {
    public static int firstUniqueCharacter(String s) {
        int[] count = new int[52]; // 26 cho chữ thường + 26 cho chữ hoa

        // Đếm số lần xuất hiện
        for (char c : s.toCharArray()) {
            if (Character.isLowerCase(c)) {
                count[c - 'a']++;
            } else {
                count[c - 'A' + 26]++;
            }
        }

        // Tìm vị trí xuất hiện đầu tiên có count = 1
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if ((Character.isLowerCase(c) && count[c - 'a'] == 1) ||
                    (Character.isUpperCase(c) && count[c - 'A' + 26] == 1)) {
                return i;
            }
        }

        return -1; // Không có ký tự duy nhất
    }

    // Hàm main để test
    public static void main(String[] args) {
        String[] testCases = {
                "LeetCode",     // Output: 0 (L là ký tự duy nhất đầu tiên)
                "aAbbcc",       // Output: 1 (b là ký tự duy nhất đầu tiên)
                "aA",           // Output: 0 (a là ký tự duy nhất đầu tiên)
                "xXyYzZ",       // Output: -1 (Không có ký tự duy nhất)
                "helloWorld",   // Output: 0 (h là ký tự duy nhất đầu tiên)
                "swiss"         // Output: 0 (w là ký tự duy nhất đầu tiên)
        };

        for (String test : testCases) {
            int index = firstUniqueCharacter(test);
            System.out.println("Chuỗi: \"" + test + "\" → Vị trí ký tự duy nhất đầu tiên: " + index);
        }

    }
}
