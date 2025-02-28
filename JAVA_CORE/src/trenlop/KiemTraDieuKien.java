package trenlop;

public class KiemTraDieuKien {
    public static boolean validateEmail(String email) {
        String regex = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,6}$";
        return email.matches(regex);
    }

    public static  boolean validatePhone(String phone) {
        String regex = "^0\\d{9}$"; // ko qua 10 so
        return phone.matches(regex);
    }

    public static boolean validateCMND(String cmnd) {
        String regex = "^\\d{9,12}$"; // 9 den 12 so
        return cmnd.matches(regex);
    }

    public static boolean validateMsv(String msv) {
        String regex = "^22103100\\d{3}$";
        return msv.matches(regex);
    }

    public static boolean validateName(String msv) {
        String regex = "^([A-ZÀ-Ỹ][a-zà-ỹ]*)\\s+([A-ZÀ-Ỹ][a-zà-ỹ]*(\\s+[A-ZÀ-Ỹ][a-zà-ỹ]*)*)$";
        return msv.matches(regex);
    }

}
