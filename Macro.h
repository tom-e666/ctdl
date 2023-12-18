#ifndef MACRO_H
#define MACRO_H

#define NUB 6 // change if console wonfit, or change the console size
#define NUB2 NUB * 2
#define SPACE(i) for (int j = 0; j < i; j++, (std::cout << ' '))
#define NEWLINE(i) for (int j = 0; j < i; j++, (std::cout << '\n'))
#define WIDTH 1
#define TOP 5
#define BOTTOM 3
#define VER(i) for (int j = 0; j < i; j++, (std::cout << '|'))
#define HOR(i) for (int j = 0; j < i; j++, (std::cout << '_'))
#define SP1 11
#define SP2 18
#define SP3 25
#define ESC 27
#define ENTER 13
#define BACKSPACE 8

#endif