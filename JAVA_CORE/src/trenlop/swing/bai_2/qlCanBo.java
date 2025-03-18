 /*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package trenlop.swing.bai_2;

import java.sql.*;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Admin
 */
public class qlCanBo extends javax.swing.JFrame {

    /**
     * Creates new form qlHoadon
     */
    public qlCanBo() {
        initComponents();
    }
    
    public void showData3(){
        try {
            ConnectDatabase cd = new ConnectDatabase();
            ResultSet rs = cd.getData("tt_canbo");
            
            DefaultTableModel model = (DefaultTableModel) table.getModel();
            model.setRowCount(0);
            
            while(rs.next()){
                model.addRow(new Object[]{
                    rs.getString("maCanBo"),
                    rs.getString("hoTen"),
                    rs.getString("diaChi"),
                     rs.getString("thamNien"),
                });
            }
            
        } catch (Exception e) {
           e.printStackTrace();
        }
    }

    public void showData() {
        try {
            ConnectDatabase cd = new ConnectDatabase();
            ResultSet rs = cd.getData("tt_canbo");

            DefaultTableModel model = (DefaultTableModel) table.getModel();
            model.setRowCount(0);

            while (rs.next()) {
                model.addRow(new Object[]{
                    rs.getString("maCanBo"),
                    rs.getString("hoTen"),
                    rs.getString("diaChi"),
                    rs.getInt("thamNien")});
            }
                getTableInfo();
            cd.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void getSelectedRow() {
        int selectedRow = table.getSelectedRow();
        if (selectedRow != -1) {
            edtCanBo.setText(table.getValueAt(selectedRow, 0).toString());
            edtHoTen.setText(table.getValueAt(selectedRow, 1).toString());
            edtDiaChi.setText(table.getValueAt(selectedRow, 2).toString());
            edtThamNien.setText(table.getValueAt(selectedRow, 3).toString());
            edtCanBo.setEditable(false);

        }
    }
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        edtHoTen = new javax.swing.JTextField();
        edtCanBo = new javax.swing.JTextField();
        edtDiaChi = new javax.swing.JTextField();
        edtThamNien = new javax.swing.JTextField();
        btnLamMoi = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        table = new javax.swing.JTable();
        btnDoubleNext = new javax.swing.JButton();
        btnNext = new javax.swing.JButton();
        btnDoublePrev = new javax.swing.JButton();
        btnPrev = new javax.swing.JButton();
        btnLayDuLieu = new javax.swing.JButton();
        btnXoa = new javax.swing.JButton();
        btnSua = new javax.swing.JButton();
        btnThoat = new javax.swing.JButton();
        btnThem = new javax.swing.JButton();
        jLabel6 = new javax.swing.JLabel();
        edtTimKiemMa = new javax.swing.JTextField();
        btnTimKiemTheoMa = new javax.swing.JButton();
        jLabel7 = new javax.swing.JLabel();
        edthamNienTu = new javax.swing.JTextField();
        jLabel8 = new javax.swing.JLabel();
        edtThamNienDen = new javax.swing.JTextField();
        btnTiemKiemTheoThamNien = new javax.swing.JButton();
        tvStartItem = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        tvMaxItem = new javax.swing.JLabel();
        btnCuoi = new javax.swing.JButton();
        btnDau1 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("HOÁ ĐƠN TIỀN ĐIỆN");

        jLabel1.setFont(new java.awt.Font("Segoe UI", 1, 24)); // NOI18N
        jLabel1.setText("Hoá đơn tiền điện");

        jLabel2.setText("Mã cán bộ:");

        jLabel3.setText("Họ tên:");

        jLabel4.setText("Địa chỉ:");

        jLabel5.setText("Thâm niên:");

        btnLamMoi.setText("Làm mới");
        btnLamMoi.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                btnLamMoiMouseClicked(evt);
            }
        });
        btnLamMoi.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnLamMoiActionPerformed(evt);
            }
        });

        table.setModel(new DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "Mã Cán Bộ", "Họ và tên", "Địa chỉ", "Thâm niên"
            }
        ));
        table.setShowGrid(true);
        table.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                tableMouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(table);

        btnDoubleNext.setText(">>");
        btnDoubleNext.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                btnDoubleNextMouseClicked(evt);
            }
        });
        btnDoubleNext.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnDoubleNextActionPerformed(evt);
            }
        });

        btnNext.setText(">");
        btnNext.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                btnNextMouseClicked(evt);
            }
        });
        btnNext.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnNextActionPerformed(evt);
            }
        });

        btnDoublePrev.setText("<<");
        btnDoublePrev.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                btnDoublePrevMouseClicked(evt);
            }
        });
        btnDoublePrev.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnDoublePrevActionPerformed(evt);
            }
        });

        btnPrev.setText("<");
        btnPrev.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                btnPrevMouseClicked(evt);
            }
        });
        btnPrev.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnPrevActionPerformed(evt);
            }
        });

        btnLayDuLieu.setText("Lấy dữ liệu");
        btnLayDuLieu.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                btnLayDuLieuMouseClicked(evt);
            }
        });
        btnLayDuLieu.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnLayDuLieuActionPerformed(evt);
            }
        });

        btnXoa.setText("Xoá");
        btnXoa.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                btnXoaMouseClicked(evt);
            }
        });
        btnXoa.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnXoaActionPerformed(evt);
            }
        });

        btnSua.setText("Sửa");
        btnSua.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                btnSuaMouseClicked(evt);
            }
        });
        btnSua.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnSuaActionPerformed(evt);
            }
        });

        btnThoat.setText("Thoát");
        btnThoat.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                btnThoatMouseClicked(evt);
            }
        });
        btnThoat.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnThoatActionPerformed(evt);
            }
        });

        btnThem.setText("Thêm");
        btnThem.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                btnThemMouseClicked(evt);
            }
        });
        btnThem.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnThemActionPerformed(evt);
            }
        });

        jLabel6.setText("Tìm kiếm mã:");

        edtTimKiemMa.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                edtTimKiemMaActionPerformed(evt);
            }
        });

        btnTimKiemTheoMa.setText("Tìm kiêm theo mã");
        btnTimKiemTheoMa.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                btnTimKiemTheoMaMouseClicked(evt);
            }
        });
        btnTimKiemTheoMa.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnTimKiemTheoMaActionPerformed(evt);
            }
        });

        jLabel7.setText("Thâm niên từ:");

        jLabel8.setText("Đến:");

        btnTiemKiemTheoThamNien.setText("Tìm kiếm theo thâm niên");
        btnTiemKiemTheoThamNien.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                btnTiemKiemTheoThamNienMouseClicked(evt);
            }
        });
        btnTiemKiemTheoThamNien.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnTiemKiemTheoThamNienActionPerformed(evt);
            }
        });

        tvStartItem.setText("1");

        jLabel10.setText("/");

        tvMaxItem.setText("9");

        btnCuoi.setText("Cuối");
        btnCuoi.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCuoiActionPerformed(evt);
            }
        });

        btnDau1.setText("Đầu");
        btnDau1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnDau1ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(268, 268, 268)
                        .addComponent(jLabel1))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(26, 26, 26)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel7, javax.swing.GroupLayout.PREFERRED_SIZE, 122, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 30, Short.MAX_VALUE)
                                .addComponent(edthamNienTu, javax.swing.GroupLayout.PREFERRED_SIZE, 48, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(21, 21, 21)
                                .addComponent(jLabel8, javax.swing.GroupLayout.PREFERRED_SIZE, 44, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(edtThamNienDen, javax.swing.GroupLayout.PREFERRED_SIZE, 48, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(132, 132, 132))
                            .addComponent(jLabel4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel5, javax.swing.GroupLayout.PREFERRED_SIZE, 108, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(0, 0, Short.MAX_VALUE))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                            .addComponent(jLabel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                            .addComponent(jLabel3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                        .addGap(18, 18, 18))
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(jLabel6, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addGap(29, 29, 29)))
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(edtTimKiemMa, javax.swing.GroupLayout.PREFERRED_SIZE, 312, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                        .addComponent(edtThamNien, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, 312, Short.MAX_VALUE)
                                        .addComponent(edtDiaChi, javax.swing.GroupLayout.Alignment.TRAILING)
                                        .addComponent(edtHoTen, javax.swing.GroupLayout.Alignment.TRAILING)
                                        .addComponent(edtCanBo, javax.swing.GroupLayout.Alignment.TRAILING)))))))
                .addGap(37, 37, 37)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(btnLayDuLieu, javax.swing.GroupLayout.PREFERRED_SIZE, 96, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(btnXoa, javax.swing.GroupLayout.PREFERRED_SIZE, 96, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(btnSua, javax.swing.GroupLayout.PREFERRED_SIZE, 96, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(btnThoat, javax.swing.GroupLayout.PREFERRED_SIZE, 96, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(btnThem, javax.swing.GroupLayout.PREFERRED_SIZE, 96, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addContainerGap(24, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(btnTimKiemTheoMa, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(btnLamMoi, javax.swing.GroupLayout.PREFERRED_SIZE, 96, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(0, 0, Short.MAX_VALUE))
                            .addComponent(btnTiemKiemTheoThamNien, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addGap(33, 33, 33))))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jScrollPane1)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(btnDoublePrev, javax.swing.GroupLayout.PREFERRED_SIZE, 47, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnPrev)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(tvStartItem)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLabel10)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(tvMaxItem)
                        .addGap(297, 297, 297)
                        .addComponent(btnCuoi)
                        .addGap(34, 34, 34)
                        .addComponent(btnNext)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnDoubleNext, javax.swing.GroupLayout.PREFERRED_SIZE, 49, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap())
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(104, 104, 104)
                    .addComponent(btnDau1)
                    .addContainerGap(572, Short.MAX_VALUE)))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(29, 29, 29)
                .addComponent(jLabel1)
                .addGap(19, 19, 19)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(edtCanBo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnLayDuLieu)
                    .addComponent(btnXoa)
                    .addComponent(jLabel2))
                .addGap(24, 24, 24)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(edtHoTen, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnSua)
                    .addComponent(btnThoat))
                .addGap(21, 21, 21)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(edtDiaChi, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnThem))
                .addGap(21, 21, 21)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(edtThamNien, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnLamMoi))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel6)
                    .addComponent(btnTimKiemTheoMa)
                    .addComponent(edtTimKiemMa, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(9, 9, 9)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(edthamNienTu, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel8)
                    .addComponent(edtThamNienDen, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnTiemKiemTheoThamNien))
                .addGap(18, 18, 18)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 147, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(40, 40, 40)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnDoubleNext)
                    .addComponent(btnNext)
                    .addComponent(btnDoublePrev)
                    .addComponent(btnPrev)
                    .addComponent(tvStartItem)
                    .addComponent(jLabel10)
                    .addComponent(tvMaxItem)
                    .addComponent(btnCuoi))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                    .addContainerGap(510, Short.MAX_VALUE)
                    .addComponent(btnDau1)
                    .addContainerGap()))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnLamMoiMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnLamMoiMouseClicked
       
       
    }//GEN-LAST:event_btnLamMoiMouseClicked

    private void tableMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tableMouseClicked
        getSelectedRow();
    }//GEN-LAST:event_tableMouseClicked

    private void btnNextMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnNextMouseClicked
    
    }//GEN-LAST:event_btnNextMouseClicked

    private void btnPrevMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnPrevMouseClicked
   
    }//GEN-LAST:event_btnPrevMouseClicked

    private void btnDoubleNextMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnDoubleNextMouseClicked
      
    }//GEN-LAST:event_btnDoubleNextMouseClicked

    private void btnDoublePrevMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnDoublePrevMouseClicked
    
    }//GEN-LAST:event_btnDoublePrevMouseClicked

    private void btnLayDuLieuMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnLayDuLieuMouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_btnLayDuLieuMouseClicked

    private void btnLayDuLieuActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnLayDuLieuActionPerformed
         showData();
    }//GEN-LAST:event_btnLayDuLieuActionPerformed

    private void btnXoaMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnXoaMouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_btnXoaMouseClicked

    private void btnXoaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnXoaActionPerformed
        try {
            ConnectDatabase cd = new ConnectDatabase();
            String maCb = edtCanBo.getText();
            if(maCb.equals("")){
                JOptionPane.showMessageDialog(rootPane, "vui lòng chọn hàng cần xoa");
            } else {
            cd.delete("tt_canbo", maCb);
            showData();
            }
        cd.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }//GEN-LAST:event_btnXoaActionPerformed

    private void btnSuaMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnSuaMouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_btnSuaMouseClicked

    private void btnSuaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnSuaActionPerformed
        try {
            ConnectDatabase cd = new ConnectDatabase();
            
            String maCb = edtCanBo.getText();
            if(maCb.equals("")){
                JOptionPane.showMessageDialog(rootPane, "vui lòng chọn hàng cần sửa");
            } else {
            String hoTen = edtHoTen.getText();
            String diaChi = edtDiaChi.getText();
            int thamNien = Integer.parseInt(edtThamNien.getText());
             
            cd.update("tt_canbo", maCb, hoTen, diaChi, thamNien);
            showData();
            
            }
            
            cd.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }//GEN-LAST:event_btnSuaActionPerformed

    private void btnThoatMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnThoatMouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_btnThoatMouseClicked

    private void btnThoatActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnThoatActionPerformed
       System.exit(0);
    }//GEN-LAST:event_btnThoatActionPerformed

    private void btnThemMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnThemMouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_btnThemMouseClicked

    private void btnThemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnThemActionPerformed
        try {
            ConnectDatabase cd = new ConnectDatabase();
       
             String maCB = edtCanBo.getText();
             String hoTen = edtHoTen.getText();
             String diaChi = edtDiaChi.getText();
             int thamNien = Integer.parseInt(edtThamNien.getText());
             
             cd.add("tt_canbo", maCB, hoTen, diaChi, thamNien);
             showData();
             cd.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        getTableInfo();
    }//GEN-LAST:event_btnThemActionPerformed

    private void btnLamMoiActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnLamMoiActionPerformed
        edtCanBo.setText("");
        edtHoTen.setText("");
        edtDiaChi.setText("");
        edtThamNien.setText("");
        edtThamNienDen.setText("");
       
    }//GEN-LAST:event_btnLamMoiActionPerformed

    private void btnTimKiemTheoMaMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnTimKiemTheoMaMouseClicked
  
    }//GEN-LAST:event_btnTimKiemTheoMaMouseClicked

    private void btnTimKiemTheoMaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnTimKiemTheoMaActionPerformed
      
        try {
          ConnectDatabase cd = new ConnectDatabase();
          String txSreach = edtTimKiemMa.getText();
          ResultSet rs = cd.getDataByMaCanBo("tt_canbo", txSreach);
          
        DefaultTableModel model = (DefaultTableModel) table.getModel();
        model.setRowCount(0);

        while (rs.next()) {
                model.addRow(new Object[]{
                    rs.getString("maCanBo"),
                    rs.getString("hoTen"),
                    rs.getString("diaChi"),
                    rs.getInt("thamNien")});
            }
            cd.close();
        } catch (Exception e) {
            e.printStackTrace();
        }       
    }//GEN-LAST:event_btnTimKiemTheoMaActionPerformed

    private void btnTiemKiemTheoThamNienMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnTiemKiemTheoThamNienMouseClicked
        try {
            ConnectDatabase cd = new ConnectDatabase();
            String txStartThamNienTu = edthamNienTu.getText();
            String txStartThamNienDen = edtThamNienDen.getText();
            ResultSet rs = cd.getDataByKhoangThamNien("tt_canbo", txStartThamNienTu, txStartThamNienDen);
            
        DefaultTableModel model = (DefaultTableModel) table.getModel();
        model.setRowCount(0);

        while (rs.next()) {
                model.addRow(new Object[]{
                    rs.getString("maCanBo"),
                    rs.getString("hoTen"),
                    rs.getString("diaChi"),
                    rs.getInt("thamNien")});
            }
            cd.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }//GEN-LAST:event_btnTiemKiemTheoThamNienMouseClicked

    private void btnTiemKiemTheoThamNienActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnTiemKiemTheoThamNienActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_btnTiemKiemTheoThamNienActionPerformed

    private void edtTimKiemMaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_edtTimKiemMaActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_edtTimKiemMaActionPerformed

    private void btnPrevActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnPrevActionPerformed
         int currentRow = table.getSelectedRow();
        int rowCount = table.getRowCount();

        if (currentRow == -1) {
            table.setRowSelectionInterval(0, 0);
        } else if (currentRow > 0) {
            table.setRowSelectionInterval(currentRow - 1, currentRow - 1);
        } else {
            table.setRowSelectionInterval(rowCount - 1, rowCount - 1);
        }
         getTableInfo();
    }//GEN-LAST:event_btnPrevActionPerformed

    private void btnDoublePrevActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnDoublePrevActionPerformed
         int currentRow = table.getSelectedRow();
        int rowCount = table.getRowCount();

        if (currentRow == -1) {
            table.setRowSelectionInterval(0, 0);
        } else if (currentRow > 0) {
            table.setRowSelectionInterval(currentRow - 2, currentRow - 2);
        } else {
            table.setRowSelectionInterval(rowCount - 1, rowCount - 1);
        }
         getTableInfo();
    }//GEN-LAST:event_btnDoublePrevActionPerformed

    private void btnNextActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnNextActionPerformed
         int currentRow = table.getSelectedRow();
        int rowCount = table.getRowCount();

        if (currentRow == -1) {
            table.setRowSelectionInterval(0, 0);
        } else if (currentRow < rowCount - 1) {
            table.setRowSelectionInterval(currentRow + 1, currentRow + 1);
        } else {
            table.setRowSelectionInterval(0, 0);
        }
         getTableInfo();
    }//GEN-LAST:event_btnNextActionPerformed

    private void btnDoubleNextActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnDoubleNextActionPerformed
           int currentRow = table.getSelectedRow();
        int rowCount = table.getRowCount();

        if (currentRow == -1) {
            table.setRowSelectionInterval(0, 0);
        } else if (currentRow < rowCount - 1) {
            table.setRowSelectionInterval(currentRow + 2, currentRow + 2);
        } else {
            table.setRowSelectionInterval(0, 0);
        }
        getTableInfo();
    }//GEN-LAST:event_btnDoubleNextActionPerformed

    private void btnCuoiActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCuoiActionPerformed
         int rowCount = table.getRowCount();

    if (rowCount > 0) {
        table.setRowSelectionInterval(rowCount - 1, rowCount - 1);
    } else {
        JOptionPane.showMessageDialog(this, "Table is empty!"); 
    }
    getTableInfo(); 
    }//GEN-LAST:event_btnCuoiActionPerformed

    private void btnDau1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnDau1ActionPerformed
     
     int rowCount = table.getRowCount();

    if (rowCount > 0) { // Kiểm tra nếu bảng có ít nhất 1 dòng
        table.setRowSelectionInterval(0, 0); // Chọn dòng đầu tiên
    } else {
        JOptionPane.showMessageDialog(this, "Table is empty!"); // Thông báo nếu bảng trống
    }
    getTableInfo(); // Gọi hàm xử lý thông tin dòng được chọn
    }//GEN-LAST:event_btnDau1ActionPerformed

    private void getTableInfo() {
    int rowCount = table.getRowCount(); // Lấy tổng số hàng
    int selectedRow = table.getSelectedRow(); // Lấy vị trí hiện tại (chỉ số hàng đang chọn)

    tvStartItem.setText(String.valueOf(selectedRow + 1));
    tvMaxItem.setText(String.valueOf(rowCount));
}

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(qlCanBo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(qlCanBo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(qlCanBo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(qlCanBo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new qlCanBo().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnCuoi;
    private javax.swing.JButton btnDau1;
    private javax.swing.JButton btnDoubleNext;
    private javax.swing.JButton btnDoublePrev;
    private javax.swing.JButton btnLamMoi;
    private javax.swing.JButton btnLayDuLieu;
    private javax.swing.JButton btnNext;
    private javax.swing.JButton btnPrev;
    private javax.swing.JButton btnSua;
    private javax.swing.JButton btnThem;
    private javax.swing.JButton btnThoat;
    private javax.swing.JButton btnTiemKiemTheoThamNien;
    private javax.swing.JButton btnTimKiemTheoMa;
    private javax.swing.JButton btnXoa;
    private javax.swing.JTextField edtCanBo;
    private javax.swing.JTextField edtDiaChi;
    private javax.swing.JTextField edtHoTen;
    private javax.swing.JTextField edtThamNien;
    private javax.swing.JTextField edtThamNienDen;
    private javax.swing.JTextField edtTimKiemMa;
    private javax.swing.JTextField edthamNienTu;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable table;
    private javax.swing.JLabel tvMaxItem;
    private javax.swing.JLabel tvStartItem;
    // End of variables declaration//GEN-END:variables
}
