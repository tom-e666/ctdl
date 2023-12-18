#include "Account.h"
#include <iostream> // Include <iostream> for cin

// Tài khoản
std::ifstream &operator>>(std::ifstream &in, Account &acc)
{
    in >> acc.TaiKhoan >> acc.MatKhau;
    return in;
}

void Account::setMatKhau(const std::string &mk)
{
    MatKhau = mk;
}

std::string Account::getMatKhau() const
{
    return MatKhau;
}

void Account::setTaiKhoan(const std::string &tk)
{
    TaiKhoan = tk;
}

std::string Account::getTaiKhoan() const
{
    return TaiKhoan;
}

bool Account::operator==(const Account &acc) const
{
    return this->TaiKhoan == acc.TaiKhoan && this->MatKhau == acc.MatKhau;
}
