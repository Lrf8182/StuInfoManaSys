#pragma once
#include "ConsoleSetting.h"
/**
 * @brief Print colorfully and randomly.
 * @tparam T {std::string,char,int,double,char[]}
 * @param str The content to be printed.
*/
template <class T>
void colorprint(const T& str)
{
    srand((int) time(0));
    int font = rand() % 8;
    srand((int) time(0));
    int back = rand() % 8;
    while (font == back) {
        font = rand() % 8;
        srand((int) time(0));
    }
    colorfulOutput(str, font, back);

}