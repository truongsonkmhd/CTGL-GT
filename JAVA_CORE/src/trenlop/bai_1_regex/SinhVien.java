package trenlop.bai_1_regex;

class SinhVien {
    String masv, hoTen, email, soDT, cmnd;

    public SinhVien(String masv, String hoTen, String email, String soDT, String cmnd) {
        this.masv = masv;
        this.hoTen = hoTen;
        this.email = email;
        this.soDT = soDT;
        this.cmnd = cmnd;
    }

    @Override
    public String toString() {
        return "MSSV: " + masv + ", Họ tên: " + hoTen + ", Email: " + email + ", SĐT: " + soDT + ", CMND: " + cmnd;
    }


}