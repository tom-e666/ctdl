#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <fstream>

class Account
{
    std::string TaiKhoan;
    std::string MatKhau;

public:
    friend std::ifstream &operator>>(std::ifstream &, Account &);

    // Declare setTaiKhoan with a const parameter and void return type
    void setTaiKhoan(const std::string &);

    // Declare getTaiKhoan as const and specify its return type
    std::string getTaiKhoan() const;

    // Declare setMatKhau with a const parameter and void return type
    void setMatKhau(const std::string &);

    // Declare getMatKhau as const and specify its return type
    std::string getMatKhau() const;

    bool operator==(const Account &) const;
};

#endif
