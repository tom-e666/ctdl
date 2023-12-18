
#ifndef PROGRAM_H
#define PROGRAM_H

#include "Vector.h"
#include "Queue.h"
#include "Account.h" // Include the header for Account class
#include "HangHoa.h" // Include the header for HangHoa class
#include "DonHang.h" // Include the header for DonHang class

class Program
{

    // lựa chọn của người dùng
    char _cKey = 0;
    int STT = 0;

    // mảng các account, đơn hàng, hàng hóa
    Vector<Account> Admin;
    Vector<HangHoa> Items;
    Queue<DonHang> Orders;

public:
    // lấy admin và hàng từ txt
    void getAdmin();
    void getItems();

    //---------------------------

    void run();
    void menu();

    // menu
    void display();
    void timKiem();
    void datHang();
    void quanLy();

    // Quản lý
    void menuQuanLy();
    void getOrders();
    void quanLyItems();

    // Quản lý hàng hóa
    void addItem();
    void deleteItem();
    void updateItem();

    // UpdateItem
    void updateItem(const std::string &, int);
    bool foundItem(const std::string &);

    void ghiFile(DonHang &, const std::string &, bool);
    void uploadFie(const std::string &);

    // Hàm support
    bool orderSuccess(DonHang &);
    int log();

    // Kiểm tra số sản phẩm truyền vô có lớn hơn số sản phẩm tối đa của sản phẩm có mã là ...
    bool checkQuantity(const std::string &, int);
};
#endif
