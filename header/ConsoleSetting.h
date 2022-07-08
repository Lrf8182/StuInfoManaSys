// ConsoleSetting.cpp

#pragma once

#include <string>

/**
 * @brief Change foregound and background color in cmd window for output.
 * @param foregroundColor <7> white(DEFAULT), <0> black, <1> blue,
                          <2> green, <3> red, <4> cyan, <5> pink, <6> yellow.
 * @param backgroundColor <0> black(DEFAULT), <1> blue, <2> green, <3> red,
                          <4> cyan, <5> pink, <6> yellow, <7> white.
 * @param foregroundIntensity <true>(DEFAULT), <false>.
 * @param backgroundIntensity <false>(DEFAULT), <true>.
*/
void setOutputColor(int foregroundColor = 7, int backgroundColor = 0,
                    bool foregroundIntensity = true, bool backgroundIntensity = false);

/**
 * @brief Output text in different colors.
 * @param str The output string.
 * @param foregroundColor <7> white(DEFAULT), <0> black, <1> blue,
                          <2> green, <3> red, <4> cyan, <5> pink, <6> yellow.
 * @param backgroundColor <0> black(DEFAULT), <1> blue, <2> green, <3> red,
                          <4> cyan, <5> pink, <6> yellow, <7> white.
 * @param foregroundIntensity <true>(DEFAULT), <false>.
 * @param backgroundIntensity <false>(DEFAULT), <true>.
*/
template<class T>
void colorfulOutput(const T& str,
                    int foregroundColor = 7, int backgroundColor = 0,
                    bool foregroundIntensity = true, bool backgroundIntensity = false)
{
    setOutputColor(foregroundColor, backgroundColor, foregroundIntensity, backgroundIntensity);
    std::cout << str;
    setOutputColor();
}