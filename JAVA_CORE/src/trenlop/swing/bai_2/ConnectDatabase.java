/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package trenlop.swing.bai_2;

import java.sql.*;

public class ConnectDatabase {
    private Connection conn;
    
    public ConnectDatabase() throws ClassNotFoundException, SQLException {
        Class.forName("com.mysql.cj.jdbc.Driver");
        this.conn = DriverManager.getConnection("jdbc:mysql://localhost:3307/qlcanbo", "root", "");
    }
    
    
    public ResultSet getData(String tableName) throws SQLException {
        ResultSet rs = null;
        Statement statement = this.conn.createStatement();
        String sql = "SELECT * FROM " + tableName + " ";
        rs = statement.executeQuery(sql);
        return rs;
    }
    
    public ResultSet getDataByMaCanBo(String tableName, String search) throws SQLException {
        ResultSet rs = null;
        Statement statement = this.conn.createStatement();
        String sql = "SELECT * FROM " + tableName + " WHERE maCanBo LIKE '%" + search + "%' ";
        rs = statement.executeQuery(sql);
        return rs;
    }
    
  
       
 public ResultSet getDataByKhoangThamNien(String tableName, String thamNienTu, String thamNienDen) throws SQLException {
    Statement statement = this.conn.createStatement();

    int thamNienTuInt = Integer.parseInt(thamNienTu);
    int thamNienDenInt = Integer.parseInt(thamNienDen);

    String sql = "SELECT * FROM " + tableName 
               + " WHERE thamNien >= " + thamNienTuInt 
               + " AND thamNien <= " + thamNienDenInt;

    // Thực thi câu lệnh SQL
    ResultSet rs = statement.executeQuery(sql);
    return rs;
}

    
    public void add(String tableName, String maCanBo, String hoTen, String diaChi, int thamNien) throws SQLException {
        Statement statement = this.conn.createStatement();
        String sql = "INSERT INTO " + tableName + " (maCanBo, hoTen, diaChi, thamNien) VALUES ('" 
                + maCanBo + "', '" 
                + hoTen + "', '" 
                + diaChi + "', '" 
                + thamNien + "')";
        statement.executeUpdate(sql);
    }
    
    
    
    
    public void update(String tableName, String maCanBo, String hoTen, String diaChi, int thamNien) throws SQLException {
        Statement statement = this.conn.createStatement();
        String sql = "UPDATE " + tableName 
                + " SET hoTen = '" + hoTen + "',"
                + " diaChi = '" + diaChi + "'," 
                + " thamNien = " + thamNien 
                + " WHERE maCanBo = '" + maCanBo + "'";
        statement.executeUpdate(sql);
    }
    
 
    public void delete(String tableName, String maCanBo) throws SQLException{
        Statement statement = this.conn.createStatement();
        String sql = "DELETE FROM " + tableName + " WHERE maCanBo = '" + maCanBo + "'";
        statement.executeUpdate(sql);
    }
    
   
    public void close() throws SQLException {
        if(this.conn != null) this.conn.close();
    }
    
  
}
