#include "DonHang.h" // Include the appropriate header file for DonHang
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include "Macro.h"
#include "ANSIColor.h"
int DonHang::STT = 0;
std::istream &operator>>(std::istream &in, DonHang &don)
{
    // Input for Ten khach hang
    {
        SPACE(NUB2);
        std::cout << ANSI_YELLOW << "Ten khach hang: " << ANSI_RESET;
        std::getline(in, don._strTenKhachHang);
    }

    // Input for Dia chi khach hang
    {
        SPACE(NUB2);
        std::cout << ANSI_YELLOW << "Dia chi khach hang: " << ANSI_RESET;
        std::getline(in, don._strDiaChi);
    }

    // Input for So dien thoai
    {
        SPACE(NUB2);
        std::cout << ANSI_YELLOW << "So dien thoai: " << ANSI_RESET;
        std::getline(in, don._strSoDienThoai);
    }

    // Input for Ngay dat hang
    {
        SPACE(NUB2);
        std::cout << ANSI_YELLOW << "Ngay dat hang: " << ANSI_RESET;

        std::getline(in, don._strNgayDat);
        if (don._strNgayDat == "" || don._strNgayDat == "now" || don._strNgayDat == "today")
        {
            std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
            std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
            // Convert the time to a string, "Tue Oct 24 21:24:36 2023"
            std::string timeStr = std::ctime(&currentTime);
        }
    }

    SPACE(NUB2);
    std::cout << ANSI_RED "Nhap so san pham can mua: " << ANSI_RESET;
    int _iNum;
    std::cin >> _iNum;
    NEWLINE(2);
    SPACE(NUB);
    std::cout << ANSI_GREEN "NHAP MA TUNG SAN PHAM \n\n"
              << ANSI_RESET;

    std::string strCode;
    {
        int i = 0;
        int iProduct;
        while (i < _iNum)
        {
            std::cin.ignore(256, '\n');

            SPACE(NUB + NUB);
            std::cout << ANSI_CYAN << "Ma san pham thu " << i + 1 << ": " << ANSI_RESET;
            in >> strCode;
            don.Code_Ma_HangHoa.push_back(strCode);
            SPACE(NUB * 2);
            std::cout << ANSI_CYAN << "So san pham dat mua: " << ANSI_RESET;
            in >> iProduct;
            don.so_Luong_Hang.push_back(iProduct);
            i++;
        }
    }
    don._iMa = DonHang::STT;
    std::cin.ignore(256, '\n');
    return in;
}
int DonHang::getMa() const
{
    return _iMa;
}
int DonHang::getGia() const
{
    return _iGia;
}
std::string DonHang::getTenKhachHang() const
{
    return _strTenKhachHang;
}
std::string DonHang::getDiaChi() const
{
    return _strDiaChi;
}
std::string DonHang::getSoDienThoai() const
{
    return _strSoDienThoai;
}
std::string DonHang::getNgayDat() const
{
    return _strNgayDat;
}
