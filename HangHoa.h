#ifndef HANGHOA_H
#define HANGHOA_H

#include <string>
#include <iostream>
#include <fstream>

class HangHoa
{
    std::string maHang = "";
    std::string tenHang = "";
    std::string noiSanXuat = "";
    std::string mauSac = "";
    int giaBan = 0;
    std::string ngayNhapKho = "";
    int soLuong = 0;

public:
    friend std::istream &operator>>(std::istream &in, HangHoa &);
    friend std::ostream &operator<<(std::ostream &out, const HangHoa &);
    friend std::ifstream &operator>>(std::ifstream &in, HangHoa &);
    friend std::ofstream &operator<<(std::ofstream &out, HangHoa &);

    std::string getMaHang() const;  // Marked as const
    int getSoLuong() const;         // Marked as const
    std::string getTenHang() const; // Marked as const
    void update(int so);
    void setMaHang(const std::string &);
    std::string getNoiSanXuat() const;  // Marked as const
    std::string getMauSac() const;      // Marked as const
    std::string getNgayNhapKho() const; // Marked as const
    int getGiaBan() const;              // Marked as const
    int getSoLuongHangHoa() const;      // Marked as const
};
#endif
