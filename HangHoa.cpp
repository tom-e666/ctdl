#include "HangHoa.h"
#include <iostream> // For input and output stream operations
#include <fstream>  // For file stream operations
#include <string>   // For string manipulation
#include <iomanip>
#include "Macro.h"
#include "ANSIColor.h"

// poluted define

std::istream &operator>>(std::istream &in, HangHoa &hang) // fixing
{
    SPACE(NUB2);

    std::cout << std::setw(25) << "Ten mat hang: ";
    std::getline(in, hang.tenHang);
    SPACE(NUB2);
    std::cout << std::setw(25) << "Noi san xuat: ";
    std::getline(in, hang.noiSanXuat);
    SPACE(NUB2);
    std::cout << std::setw(25) << "Mau sac: ";
    std::getline(in, hang.mauSac);
    SPACE(NUB2);
    std::cout << std::setw(25) << "Gia ca: ";
    in >> hang.giaBan;

    in.ignore();
    SPACE(NUB2);
    std::cout << std::setw(25) << "Ngay nhap kho: ";
    std::getline(std::cin, hang.ngayNhapKho);
    SPACE(NUB2);
    std::cout << std::setw(25) << "So luong: ";
    in >> hang.soLuong;

    return in;
}

std::ostream &operator<<(std::ostream &out, const HangHoa &hang)
{

    out << std::left;
    SPACE(NUB - WIDTH);
    out << '|' << std::setw(SP1) << hang.maHang;
    out << '|' << std::setw(SP3) << hang.tenHang;
    out << '|' << std::setw(SP2) << hang.noiSanXuat;
    out << '|' << std::setw(SP1) << hang.mauSac;
    out << '|' << std::setw(SP1) << hang.giaBan;
    out << '|' << std::setw(SP2) << hang.ngayNhapKho;
    out << '|' << std::setw(SP1) << hang.soLuong;
    VER(1);

    out << "\n";
    SPACE(NUB - WIDTH); // flag
    // co the xay dung fn(strargs[]), lam sau
    out << std::left;
    out << '|' << std::setw(SP1) << std::string(SP1, '_');
    out << '|' << std::setw(SP3) << std::string(SP3, '_');
    out << '|' << std::setw(SP2) << std::string(SP2, '_');
    out << '|' << std::setw(SP1) << std::string(SP1, '_');
    out << '|' << std::setw(SP1) << std::string(SP1, '_');
    out << '|' << std::setw(SP2) << std::string(SP2, '_');
    out << '|' << std::setw(SP1) << std::string(SP1, '_');
    VER(1);
    out << "\n";
    return out;
}

std::ifstream &operator>>(std::ifstream &in, HangHoa &hang)
{
    std::string strtemp = "";
    std::getline(in, strtemp);

    size_t i = 0;
    for (; strtemp[i] != '~'; i++)
        hang.maHang += strtemp[i];
    i++;

    for (; strtemp[i] != '~'; ++i)
        hang.tenHang += strtemp[i];
    ++i;

    for (; strtemp[i] != '~'; i++)
        hang.noiSanXuat += strtemp[i];
    ++i;

    for (; strtemp[i] != '~'; i++)
        hang.mauSac += strtemp[i];
    ++i;

    std::string Price = "";
    for (; strtemp[i] != '~'; i++)
        Price += strtemp[i];
    ++i;

    hang.giaBan = std::stoi(Price);

    for (; strtemp[i] != '~'; i++)
        hang.ngayNhapKho += strtemp[i];
    ++i;

    std::string number = "";
    for (; i < strtemp.size(); i++)
        number += strtemp[i];
    hang.soLuong = std::stoi(number);

    return in;
}

std::ofstream &operator<<(std::ofstream &out, HangHoa &hang)
{
    out << hang.getMaHang() << '~' << hang.getTenHang() << '~' << hang.getNoiSanXuat() << '~' << hang.getMauSac() << '~' << hang.getGiaBan() << '~' << hang.getNgayNhapKho() << '~' << hang.getSoLuongHangHoa();

    return out;
}

std::string HangHoa::getMaHang() const
{
    return maHang;
}

std::string HangHoa::getTenHang() const
{
    return tenHang;
}

std::string HangHoa::getNoiSanXuat() const
{
    return noiSanXuat;
}

std::string HangHoa::getMauSac() const
{
    return mauSac;
}

int HangHoa::getGiaBan() const
{
    return giaBan;
}

std::string HangHoa::getNgayNhapKho() const
{
    return ngayNhapKho;
}

int HangHoa::getSoLuong() const
{
    return soLuong;
}

void HangHoa::setMaHang(const std::string &ma)
{
    maHang = ma;
}

void HangHoa::update(int so)
{
    soLuong += so;
}

int HangHoa::getSoLuongHangHoa() const
{
    return soLuong;
}
