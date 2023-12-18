#include "Program.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <thread>
#include <chrono>
#include "Program.h"
#include "Macro.h"
#include "ANSIColor.h"

void enableCursor(bool State = true)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    if (!State)
    {
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    }
    else
    {
        cursorInfo.bVisible = true;
        SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    }
    return;
}
enum class ccolor

{
    BLACK,
    BLUE,
    GREEN,
    AQUA,
    RED,
    PURPLE,
    YELLOW,
    WHITE,
    GRAY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_AQUA,
    LIGHT_RED,
    LIGHT_PURPLE,
    LIGHT_YELLOW,
    BRIGHT_WHITE,
};
void setColor(ccolor highlight, ccolor text)
{
    auto hig_color = (int)highlight;
    auto text_color = (int)text;
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
    auto code = hig_color * 16 + text_color;
    SetConsoleTextAttribute(hand, code);
}

void loadingbar()
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n  ";
    const int width = 100;
    for (int i = 0; i <= 100; i += 2)
    {
        std::cout << "\r[";

        int pos = width * i / 100;
        for (int j = 0; j < width; ++j)
        {

            if (i < 25)
                setColor(ccolor::BLACK, ccolor::RED);
            else if (i < 50)
                setColor(ccolor::BLACK, ccolor::YELLOW);
            else if (i < 75)
                setColor(ccolor::BLACK, ccolor::GREEN);
            else
                setColor(ccolor::BLACK, ccolor::PURPLE);
            //..............................................
            if (j < pos)
                std::cout << "=";
            else if (j == pos)
                std::cout << ">";
            else
                std::cout << " ";
        }
        std::cout << "] " << i << "%";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        if (i == 90 || i == 50 || i == 96 || i == 83)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    std::cout << std::endl;
}
void pwellcome()
{
    setColor(ccolor::BLACK, ccolor::LIGHT_GREEN);
    char welcome[] = "STORE";
    char welcome1[] = "MANAGEMENT";
    char welcome2[] = "APPLICATION";
    std::cout << "\n\n\n\n\n\t\t\t";
    for (int wlc = 0; wlc < strlen(welcome); wlc++)
    {
        std::cout << welcome[wlc] << " ";
        Sleep(100);
    }
    std::cout << "\n\n\n\n\n\t\t\t\t ";
    for (int wlc1 = 0; wlc1 < strlen(welcome1); wlc1++)
    {
        std::cout << welcome1[wlc1] << " ";
        Sleep(100);
    }
    std::cout << "\n\n\n\n\n\t\t\t\t\t ";
    for (int wlc2 = 0; wlc2 < strlen(welcome2); wlc2++)
    {
        std::cout << welcome2[wlc2] << " ";
        Sleep(100);
    }
}
void GoTo(SHORT x, SHORT y)
{
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hand, pos);
}

void Program::getAdmin()
{
    Account acc;
    std::ifstream inf;
    inf.open("Admin.txt", std::ios::in);
    while (!inf.eof())
    {
        inf >> acc;
        Admin.push_back(acc);
    }
    inf.close();
}
void Program::getItems()
{
    std::ifstream inf;
    inf.open("HangHoa.txt", std::ios::in);
    while (!inf.eof())
    {
        HangHoa hang;
        inf >> hang;
        Items.push_back(hang);
    }
    inf.close();
}

bool Program::orderSuccess(DonHang &don)
{
    for (size_t i = 0; i < don.Code_Ma_HangHoa.size(); i++)
    {
        if (!foundItem(don.Code_Ma_HangHoa[i]))
            return false;
        else if (don.so_Luong_Hang[i] <= 0 && checkQuantity(don.Code_Ma_HangHoa[i], don.so_Luong_Hang[i]))
            return false;
    }
    return true;
}

bool Program::foundItem(const std::string &ma)
{
    for (size_t i = 0; i < Items.size(); i++)
    {
        if (ma == Items[i].getMaHang())
            return true;
    }
    return false;
}

bool Program::checkQuantity(const std::string &ma, int n)
{
    for (size_t i = 0; i < Items.size(); i++)
        if (ma == Items[i].getMaHang())
            return Items[i].getSoLuong() <= n;
    return false;
}

void Program::updateItem(const std::string &ma, int product)
{
    for (size_t i = 0; i < Items.size(); i++)
    {
        if (ma == Items[i].getMaHang())
            Items[i].update(product);
        return;
    }
}

void Program::run()
{

    loadingbar();
    system("cls");
    pwellcome();
    Sleep(300);
    menu();
}
void Program::menu()

{
    system("cls");
    setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
    NEWLINE(TOP);
    SPACE(NUB2);
    std::cout << "*************************************************\n";
    SPACE(NUB2);
    std::cout << "***";
    setColor(ccolor::BLACK, ccolor::LIGHT_RED);
    std::cout << "                   Menu                    ";
    setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
    std::cout << "***\n";
    SPACE(NUB2);
    std::cout << "*************************************************\n";
    setColor(ccolor::BLACK, ccolor::LIGHT_PURPLE);
    SPACE(NUB2);
    std::cout << "1. Hien thi thong tin hang hoa.\n";
    SPACE(NUB2);
    std::cout << "2. Tim kiem thong tin hang hoa.\n";
    SPACE(NUB2);
    std::cout << "3. Dat hang.\n";
    SPACE(NUB2);
    std::cout << "4. Quan ly.\n\n";

    NEWLINE(BOTTOM);
    setColor(ccolor::BLACK, ccolor::LIGHT_AQUA);
    SPACE(NUB2);
    std::cout << "An \"ESC\" de thoat.\n";

    setColor(ccolor::BLACK, ccolor::WHITE);

    while (_cKey = _getch())
    {

        switch (_cKey)
        {
        case '1':
            display();
            exit(0);
        case '2':
            timKiem();
            exit(0);
        case '3':
            datHang();
            exit(0);
        case '4':
            quanLy();
            exit(0);
        case ESC:
            exit(0);
        default:

            setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
            SPACE(NUB2);
            std::cout << "Khong hop le! \n";
            Sleep(2000);
            menu();
            exit(0);
        }
    }
}
// Chức năng 1: Hiển thị thông tin hàng hóa
void Program::display()
{
    auto CloseLine = []()
    {
        VER(WIDTH);
        NEWLINE(1);
        SPACE(NUB - WIDTH);
        VER(WIDTH);
        HOR(SP1);
        VER(WIDTH);
        HOR(SP3);
        VER(WIDTH);
        HOR(SP2);
        VER(WIDTH);
        HOR(SP1);
        VER(WIDTH);
        HOR(SP1);
        VER(WIDTH);
        HOR(SP2);
        VER(WIDTH);
        HOR(SP1);
        VER(WIDTH);
        NEWLINE(1);
    };
    system("cls");
    std::cout << std::left;
    SPACE(NUB - WIDTH);
    setColor(ccolor::BLACK, ccolor::RED);
    HOR(WIDTH + SP1 + WIDTH + SP3 + WIDTH + SP2 + WIDTH + SP1 + WIDTH + SP1 + WIDTH + SP2 + WIDTH + SP1 + WIDTH);
    NEWLINE(1);
    SPACE(NUB - WIDTH);
    VER(WIDTH);
    std::cout << std::left;
    // std::cout << std::setw(SP1) << ANSI_RED << "Ma hang" << ANSI_RESET;
    // ansi clear out left-alignment
    std::cout << std::setw(SP1) << "Ma hang";
    VER(WIDTH);
    std::cout << std::setw(SP3) << "Ten hang";
    VER(WIDTH);
    std::cout << std::setw(SP2) << "Noi san xuat";
    VER(WIDTH);
    std::cout << std::setw(SP1) << "Mau sac";
    VER(WIDTH);
    std::cout << std::setw(SP1) << "Gia ban";
    VER(WIDTH);
    std::cout << std::setw(SP2) << "Ngay nhap kho";
    VER(WIDTH);
    std::cout << std::setw(SP1) << "So luong";
    VER(WIDTH);
    NEWLINE(1);
    SPACE(NUB - WIDTH);
    VER(WIDTH);
    HOR(SP1);
    VER(WIDTH);
    HOR(SP3);
    VER(WIDTH);
    HOR(SP2);
    VER(WIDTH);
    HOR(SP1);
    VER(WIDTH);
    HOR(SP1);
    VER(WIDTH);
    HOR(SP2);
    VER(WIDTH);
    HOR(SP1);
    VER(WIDTH);
    NEWLINE(1);
    // CloseLine();
    std::cout << std::left;
    setColor(ccolor::BLACK, ccolor::LIGHT_GREEN);
    for (size_t i = 0; i < Items.size(); i++)
    {
        std::cout << Items[i];
    }
    // CloseLine();
    NEWLINE(3);
    setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
    SPACE(NUB2);
    std::cout << "Nhan \"ESC\" de thoat hoac \"r\" de quay lai.\n";
    while (_cKey = _getch())
    {
        if (_cKey == ESC)
        {
            exit(0);
        }
        else if (_cKey == 'r')
        {
            menu();
        }
    }
}
// Chức năng 2: Tìm kiếm thông tin hàng hóa
void Program::timKiem()
{
    system("cls");

    NEWLINE(TOP);
    std::string strNameProduct = "";
    setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
    SPACE(NUB);
    std::cout << "Nhap ten san pham can tim: ";
    setColor(ccolor::BLACK, ccolor::BRIGHT_WHITE);
    std::getline(std::cin, strNameProduct);
    NEWLINE(BOTTOM);
    std::cout << std::left;
    SPACE(NUB - WIDTH);
    int check = 0;
    for (size_t i = 0; i < Items.size(); i++)
    {
        // not so good
        if (strNameProduct == Items[i].getTenHang())
        {
            check++;
        }
    }
    if (check != 0)
    {
        setColor(ccolor::BLACK, ccolor::LIGHT_RED);
        HOR(WIDTH + SP1 + WIDTH + SP3 + WIDTH + SP2 + WIDTH + SP1 + WIDTH + SP1 + WIDTH + SP2 + WIDTH + SP1 + WIDTH);
        NEWLINE(1);
        SPACE(NUB - WIDTH);
        VER(WIDTH);
        std::cout << std::setw(SP1) << "Ma hang";
        VER(WIDTH);
        std::cout << std::setw(SP3) << "Ten hang";
        VER(WIDTH);
        std::cout << std::setw(SP2) << "Noi san xuat";
        VER(WIDTH);
        std::cout << std::setw(SP1) << "Mau sac";
        VER(WIDTH);
        std::cout << std::setw(SP1) << "Gia ban";
        VER(WIDTH);
        std::cout << std::setw(SP2) << "Ngay nhap kho";
        VER(WIDTH);
        std::cout << std::setw(SP1) << "So luong";
        VER(WIDTH);
        NEWLINE(1);
        SPACE(NUB - WIDTH);
        VER(WIDTH);
        HOR(SP1);
        VER(WIDTH);
        HOR(SP3);
        VER(WIDTH);
        HOR(SP2);
        VER(WIDTH);
        HOR(SP1);
        VER(WIDTH);
        HOR(SP1);
        VER(WIDTH);
        HOR(SP2);
        VER(WIDTH);
        HOR(SP1);
        VER(WIDTH);
        NEWLINE(1);
        setColor(ccolor::BLACK, ccolor::LIGHT_BLUE);
        for (size_t i = 0; i < Items.size(); i++)
            if (Items[i].getTenHang() == strNameProduct)
                std::cout << Items[i];
        NEWLINE(2);
    }
    else
    {
        setColor(ccolor::BLACK, ccolor::AQUA);
        SPACE(NUB);
        std::cout << " Khong tim thay\n";
        NEWLINE(1);
    }
    setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
    SPACE(NUB);
    std::cout << "Nhan \"ESC\" de thoat hoac \"ENTER\" de tiep tuc tim kiem hoac \"r\" de quay lai.\n";

    while (_cKey = _getch())
    {
        if (_cKey == ESC)
            exit(0);
        else if (_cKey == 'r')
            menu();
        else if (_cKey == ENTER)
            timKiem();
        exit(0);
    }
}
// Chức năng 3: Đặt hàng
void Program::datHang()
{
    system("cls");
    NEWLINE(TOP);

    DonHang don;
    std::cin >> don;

    NEWLINE(3);

    if (orderSuccess(don))
    {
        Orders.push(don);
        NEWLINE(5);
        setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
        SPACE(NUB2);
        std::cout << "Don hang dang duoc xu ly";
        Sleep(1000);
        std::cout << ".";
        Sleep(1000);
        std::cout << ".";
        Sleep(2000);
        std::cout << ".";
        std::cout << "Store da chap nhan don hang";
    }
    else
    {
        setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
        SPACE(NUB2);
        std::cout << "dat hang that bai!!!";
    }

    NEWLINE(3);
    setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
    SPACE(NUB2);
    std::cout << "Nhan \"ESC\" de thoat hoac \"ENTER\" de tiep tuc dat hang hoac \"r\" de quay lai .\n";

    while (_cKey = _getch())
    {
        if (_cKey == ESC)
            exit(0);
        else if (_cKey == 'r')
            menu();
        else if (_cKey == ENTER)
            datHang();
    }
}

void Program::getOrders() // flag
{
    system("cls");
    setColor(ccolor::BLACK, ccolor::AQUA);
    NEWLINE(TOP);
    SPACE(NUB2);
    std::cout << "He thong ghi nhan " << Orders.size() << " don hang\n";
    SPACE(NUB2);
    std::cout << "Ban co muon xu li khong?\n";
    setColor(ccolor::BLACK, ccolor::LIGHT_PURPLE);
    SPACE(NUB2);
    std::cout << "1. Co\n";
    SPACE(NUB2);
    std::cout << "2.Khong\n";
    int DonThanhCong = 0;
    int DonThatBai = 0;
    Queue<DonHang> failedOrders;
    auto fn = [&]()
    {
        Queue<DonHang> failedOrders;
        for (size_t i = 0; i < Orders.size(); i++)
        {
            DonHang temp_DonHang(Orders.front());
            STT++;
            if (orderSuccess(temp_DonHang)) // flag
            // vi sao lai ghi file o day?
            {
                DonThanhCong++;
                ghiFile(temp_DonHang, "DonHang.txt", true);

                for (size_t j = 1; j < temp_DonHang.Code_Ma_HangHoa.size(); j++)
                    updateItem(temp_DonHang.Code_Ma_HangHoa[j], -temp_DonHang.so_Luong_Hang[j]);
            }
            else
            {
                DonThatBai++;
                ghiFile(temp_DonHang, "DonHang.txt", false);
                failedOrders.push(temp_DonHang);
            }
            Orders.pop();
        }
    };
    NEWLINE(TOP);
    while (_cKey = _getch())
    {
        if (_cKey == '1')
        {
            fn();
            break;
        }
        else if (_cKey == 'r')
            menuQuanLy();
        else if (_cKey == '2')
            break;
    }

    setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
    SPACE(NUB2);
    std::cout << "Xu li thanh cong " << DonThanhCong << " don hang\n";
    SPACE(NUB2);
    std::cout << "Xu li that bai " << DonThatBai << " don hang\n";
    if (DonThatBai)
    {
        SPACE(NUB2);
        std::cout << "Ban co muon luu cac don khong thanh cong cho dot xu li tiep theo khong?\n";
        SPACE(NUB2);
        std::cout << "1. Co";
        SPACE(NUB2);
        std::cout << "2. Khong";
        while (_cKey = _getch())
        {
            if (_cKey == '1')
            {
                for (int i = 1; i <= failedOrders.size(); ++i)
                {
                    Orders.push(failedOrders.front());
                    failedOrders.pop();
                }
                SPACE(NUB2);
                std::cout << "sao luu thanh cong\n";
                break;
            }
            else if (_cKey == 'r')
                menuQuanLy();
            else if (_cKey == '2')
                break;
        }
    }

    NEWLINE(BOTTOM);
    SPACE(NUB2);
    std::cout << "An \"ESC\" de thoat hoac \"r\" quay lai man hoac \"ENTER\" de tiep tuc.\n";
    while (_cKey = _getch())
    {
        if (_cKey == ESC)
            exit(0);
        else if (_cKey == 'r')
            menuQuanLy();
        else if (_cKey == ENTER)
            getOrders();
    }
}
void Program::ghiFile(DonHang &don, const std::string &path, bool state)
{
    std::ofstream of;
    of.open("DonHang.txt", std::ios::app);
    setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
    of << "======DON HANG " << (state ? "THANH CONG" : "THAT BAI") << " ======\n";
    of << "Ma don: " << STT << std::endl;
    of << "Ten khach hang: " << don.getTenKhachHang() << std::endl;
    of << "Dia chi: " << don.getDiaChi() << std::endl;
    of << "Dien thoai: " << don.getSoDienThoai() << std::endl;
    of << "Ngay dat: " << don.getNgayDat() << std::endl;
    of << "***Cac san pham dat mua la***" << std::endl;
    for (size_t i = 0; i < don.Code_Ma_HangHoa.size(); i++)
        of << "   Ma hang hoa " << don.Code_Ma_HangHoa[i] << " voi " << don.so_Luong_Hang[i] << " so luong.\n";
    of << "\n=====================================================" << std::endl;
    of.close();
}
void Program::uploadFie(const std::string &path)
{
    std::ofstream of;
    of.open(path, std::ios::out);
    if (of)
    {
        for (size_t i = 0; i < Items.size(); i++)
        {
            of << Items[i];
            if (i != Items.size() - 1)
                of << "\n";
        }
    }
    of.close();
}
// Chức năng 4: Quản lý
int Program::log() // flag-unflag
{
    Account acc;
    GoTo(NUB2 + 12, TOP + BOTTOM + 3);
    std::string UserName;
    std::cin >> UserName;
    acc.setTaiKhoan(UserName);
    GoTo(NUB2 + 12, TOP + BOTTOM + 3 + 1);
    acc.setMatKhau("");

    while (true)
    {
        _cKey = _getch();

        if (_cKey == BACKSPACE) // erase 1st char
        {
            std::string new_Pass = acc.getMatKhau();
            if (new_Pass != "")
            {
                new_Pass.pop_back();
                std::cout << "\b \b"; // pop the cursor twice, because (8) counted 2;
            }
            acc.setMatKhau(new_Pass);
        }
        else if (isspace(_cKey)) // stop
        {
            break;
        }
        else // approrpiate char
        {
            acc.setMatKhau(acc.getMatKhau() + _cKey);
            std::cout << '*';
        }
    }

    setColor(ccolor::BLACK, ccolor::YELLOW);
    NEWLINE(3);

    static int so_lan_nhap = 3;
    bool success = false;
    for (size_t i = 0; i < Admin.size(); i++)
    {
        if (Admin[i] == acc)
        {
            success = true;
            break;
        }
    }
    if (success && so_lan_nhap)
    {
        setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
        SPACE(NUB2);
        std::cout << "Dang nhap thanh cong.";
        Sleep(1000);
        menuQuanLy();
        NEWLINE(6);
        return 2;
    }
    else if (success && so_lan_nhap == 0)
    {
        setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
        SPACE(NUB2);
        std::cout << "Dang nhap thanh cong.";
        Sleep(1000);
        menuQuanLy();
        NEWLINE(6);
        return 2;
    }
    else if (!success)
    {
        (so_lan_nhap > 0) ? so_lan_nhap-- : so_lan_nhap;
        setColor(ccolor::BLACK, ccolor::RED);
        SPACE(NUB2);
        std::cout << "Dang nhap khong thang cong.\n";
        setColor(ccolor::BLACK, ccolor::BRIGHT_WHITE);
        SPACE(NUB2);
        std::cout << "So lan nhap lai: " << so_lan_nhap;
        NEWLINE(6);
        setColor(ccolor::BLACK, ccolor::WHITE);
        if (!success && so_lan_nhap == 0)
        {
            setColor(ccolor::BLACK, ccolor::RED);
            SPACE(NUB2);
            std::cout << "Da het luot dang nhap.\n";
            setColor(ccolor::BLACK, ccolor::BRIGHT_WHITE);
            SPACE(NUB2);
            std::cout << "Vui long thoat chuong trinh ";
            Sleep(2000);
            exit(0);
        }
        return 1;
    }
    return 0;
}

void Program::quanLy() // flag
{
    system("cls");
    NEWLINE(TOP);
    setColor(ccolor::BLACK, ccolor::LIGHT_AQUA);
    SPACE(NUB2);
    std::cout << "*************************************************\n";
    SPACE(NUB2);
    std::cout << "***";
    setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
    std::cout << "             DANG NHAP HE THONG            ";
    setColor(ccolor::BLACK, ccolor::LIGHT_AQUA);
    std::cout << "***\n";
    SPACE(NUB2);
    std::cout << "*************************************************\n";
    NEWLINE(BOTTOM);
    setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
    SPACE(NUB2);
    std::cout << "User      : \n";
    SPACE(NUB2);
    std::cout << "Password  : \n";
    setColor(ccolor::BLACK, ccolor::WHITE);
    int login = log();
    SPACE(NUB2);
    std::cout << "Nhan \"ESC\" de thoat hoac an \"p\" de quay lai man hinh hoac an \"ENTER\" de tiep tuc.\n";
    while (_cKey = _getch())
    {
        if (_cKey == ESC)
            exit(0);
        else if (_cKey == 'p')
            menu();
        else if (_cKey == ENTER)
            if (login == 2)
                menuQuanLy();
            else if (login == 1)
                quanLy();
            else
                exit(0);
    }
}

// quan ly
void Program::menuQuanLy()
{
    system("cls");
    NEWLINE(TOP);
    setColor(ccolor::BLACK, ccolor::LIGHT_AQUA);
    SPACE(NUB2);
    std::cout << "*************************************************\n";
    SPACE(NUB2);
    std::cout << "***";
    setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
    std::cout << "                Menu Quan Ly               ";
    setColor(ccolor::BLACK, ccolor::LIGHT_AQUA);
    std::cout << "***\n";
    SPACE(NUB2);
    std::cout << "*************************************************\n";
    setColor(ccolor::BLACK, ccolor::LIGHT_BLUE);
    NEWLINE(BOTTOM);
    SPACE(NUB2);
    std::cout << "1. Xu ly don hang.\n";
    SPACE(NUB2);
    std::cout << "2. Quan ly hang hoa.\n";
    NEWLINE(BOTTOM);
    setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
    SPACE(NUB2);
    std::cout << "Nhan \"ESC\" de thoat hoac \"p\" de quay lai man hinh chinh.\n";

    while (_cKey = _getch())
    {
        switch (_cKey)
        {
        case '1':
            getOrders();
            exit(0);
        case '2':
            quanLyItems();
            exit(0);
        case 'p':
            menu();
            exit(0);
        case ESC:
            exit(0);
        default:
            setColor(ccolor::BLACK, ccolor::LIGHT_RED);
            SPACE(NUB2);
            std::cout << "Du lieu khong hop le!";
            Sleep(2000);
            menuQuanLy();
            exit(0);
        }
    }
}
void Program::quanLyItems()
{
    system("cls");
    NEWLINE(TOP);
    setColor(ccolor::BLACK, ccolor::LIGHT_AQUA);
    SPACE(NUB2);
    std::cout << "*************************************************\n";
    SPACE(NUB2);
    std::cout << "***";
    setColor(ccolor::BLACK, ccolor::LIGHT_GREEN);
    std::cout << "              Quan Ly Hang Hoa            ";
    setColor(ccolor::BLACK, ccolor::LIGHT_AQUA);
    std::cout << "***\n";
    SPACE(NUB2);
    std::cout << "*************************************************\n";
    setColor(ccolor::BLACK, ccolor::LIGHT_AQUA);
    NEWLINE(BOTTOM);
    SPACE(NUB2);
    std::cout << "1. Them hang moi.\n";
    SPACE(NUB2);
    std::cout << "2. Xoa hang.\n";
    SPACE(NUB2);
    std::cout << "3. Cap nhat so luong hang.\n";
    NEWLINE(BOTTOM);
    SPACE(NUB2);
    std::cout << "An \"ESC\" de thoat hoac \"p\" de quay lai.\n";
    while (_cKey = _getch())
    {
        switch (_cKey)
        {
        case '1':
            addItem();
            exit(0);
        case '2':
            deleteItem();
            exit(0);
        case '3':
            updateItem();
            exit(0);
        case 'p':
            menuQuanLy();
            exit(0);
        case ESC:
            exit(0);
        default:
            setColor(ccolor::BLACK, ccolor::LIGHT_RED);
            SPACE(NUB2);
            std::cout << "Du lieu khong hop le!!!";
            Sleep(2000);
            quanLyItems();
            exit(0);
        }
    }
}
// cac chuc nang cua quan ly hang hoa
// chuc nang 1: them hang
void Program::addItem()
{
    system("cls");
    NEWLINE(TOP);

    HangHoa hang;
    std::string strCode;

    SPACE(NUB2);
    std::cout << std::setw(25) << "Ma hang: ";
    std::cin >> strCode;
    std::cin.ignore(225, '\n');
    if (foundItem(strCode))
    {
        NEWLINE(BOTTOM);
        SPACE(NUB2);
        std::cout << "Ma hang da ton tai.\n";
    }
    else
    {
        std::cin >> hang;
        hang.setMaHang(strCode);
        Items.push_back(hang);
        NEWLINE(3);
        setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
        SPACE(NUB2);
        std::cout << "Them thanh cong";
    }

    uploadFie("HangHoa.txt");
    NEWLINE(BOTTOM);
    SPACE(NUB);
    std::cout << "Nhan \"ESC\" de thoat hoac \"p\" de quay lai hoac \"ENTER\" de tiep tuc.";
    while (_cKey = _getch())
    {
        if (_cKey == ESC)
            exit(0);
        else if (_cKey == 'p')
            quanLyItems();
        else if (_cKey == ENTER)
            addItem();
    }
}
// chuc nang 2: xoa hang
void Program::deleteItem()
{
    system("cls");
    NEWLINE(TOP);
    SPACE(NUB2);
    std::cout << "Ma hang: ";
    std::string strCode;
    std::cin >> strCode;
    bool success = false;
    for (size_t i = 0; i < Items.size(); i++)
    {
        if (Items[i].getMaHang() == strCode)
        {
            Items.removeAt(i);
            success = true;
        }
    }
    NEWLINE(BOTTOM);
    if (success)
    {
        setColor(ccolor::BLACK, ccolor::LIGHT_YELLOW);
        SPACE(NUB2);
        std::cout << ANSI_RED << "!!!Da xoa!!!" << ANSI_RESET << '\n';
        uploadFie("HangHoa.txt");
        NEWLINE(BOTTOM);
    }
    else
    {
        std::cout << "Khong ton tai.";
    }

    SPACE(NUB2);
    std::cout << ANSI_YELLOW << "An \"ESC\" de thoat hoac \"p\" de quay lai hoac \"ENTER\" de tiep tuc.\n"
              << ANSI_RESET;
    while (_cKey = _getch())
    {
        if (_cKey == ESC)
            exit(0);
        else if (_cKey == 'p')
            quanLyItems();
        else if (_cKey == ENTER)
            deleteItem();
    }
}
// Chuc nang 3: cap nhat
void Program::updateItem()
{
    system("cls");
    NEWLINE(TOP);
    SPACE(NUB2);
    std::cout << ANSI_GREEN << "Mat hang muon cap nhat: " << ANSI_RESET;
    std::string strCode;
    std::cin >> strCode;
    int i_Product = 0;
    SPACE(NUB2);
    std::cout << "1. Tang\n";
    SPACE(NUB2);
    std::cout << "2. Giam\n";
    bool flag = false;
    while (_cKey = _getch())
    {
        if (_cKey == '1' || _cKey == '2')
        {
            SPACE(NUB2);
            flag = _cKey == '1';
            std::cout << ((flag) ? "Tang them: " : "Giam xuong: ");
            break;
            // confusing
        }
    }
    std::cin >> i_Product;
    bool success = false;
    for (size_t i = 0; i < Items.size(); i++)
    {
        if (Items[i].getMaHang() == strCode)
        {
            success = true;
            flag ? Items[i].update(i_Product) : Items[i].update(-i_Product);
        }
    }
    uploadFie("HangHoa.txt");
    NEWLINE(BOTTOM);
    if (success)
    {
        SPACE(NUB2);
        std::cout << "!!!!THANH CONG!!!!";
    }
    NEWLINE(BOTTOM);
    SPACE(NUB);
    std::cout << "Nhan \"ESC\" de thoat hoac \"p\" de quay lai.";
    while (_cKey = _getch())
    {
        if (_cKey == ESC)
            exit(0);
        if (_cKey == 'p')
            quanLyItems();
    }
}
