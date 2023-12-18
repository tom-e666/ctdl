#ifndef DONHANG_H
#define DONHANG_H

#include <string>
#include "Vector.h"

class DonHang
{
    static int STT;
    int _iMa = 1;
    int _iGia = 0;
    std::string _strTenKhachHang;
    std::string _strDiaChi;
    std::string _strSoDienThoai;
    std::string _strNgayDat;

public:
    Vector<std::string> Code_Ma_HangHoa;
    Vector<int> so_Luong_Hang;
    friend std::istream &operator>>(std::istream &in, DonHang &);

    int getMa() const;                   // Marked as const
    int getGia() const;                  // Marked as const
    std::string getTenKhachHang() const; // Marked as const
    std::string getDiaChi() const;       // Marked as const
    std::string getSoDienThoai() const;  // Marked as const
    std::string getNgayDat() const;      // Marked as const
};
#endif
