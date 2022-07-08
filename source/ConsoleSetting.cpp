// ConsoleSetting.cpp

#include <Windows.h>
#include <iostream>
#include <string>
#include "../header/ConsoleSetting.h"

/**
 * @brief Change foregound and background color in cmd window for output.
 * @param foregroundColor <7> white(DEFAULT), <0> black, <1> blue,
                          <2> green, <3> red, <4> cyan, <5> pink, <6> yellow.
 * @param backgroundColor <0> black(DEFAULT), <1> blue, <2> green, <3> red,
                          <4> cyan, <5> pink, <6> yellow, <7> white.
 * @param foregroundIntensity <true>(DEFAULT), <false>.
 * @param backgroundIntensity <false>(DEFAULT), <true>.
*/
void setOutputColor(int foregroundColor, int backgroundColor,
                    bool foregroundIntensity, bool backgroundIntensity)
{
    unsigned int fgOption = 0x0000, bgOption = 0x0000;
    // Change foreground intensity.
    if (foregroundIntensity) { fgOption |= FOREGROUND_INTENSITY; }
    // Change backgound intensity.
    if (backgroundIntensity) { bgOption |= BACKGROUND_INTENSITY; }
    // Change foregound color.
    switch (foregroundColor) {
    case 0: // black
    { break; }
    case 1: // blue
    { fgOption |= FOREGROUND_BLUE; break; }
    case 2: // green
    { fgOption |= FOREGROUND_GREEN; break; }
    case 3: // red
    { fgOption |= FOREGROUND_RED; break; }
    case 4: // cyan
    { fgOption |= (FOREGROUND_BLUE | FOREGROUND_GREEN); break; }
    case 5: // pink
    { fgOption |= (FOREGROUND_BLUE | FOREGROUND_RED); break; }
    case 6: // yellow
    { fgOption |= (FOREGROUND_GREEN | FOREGROUND_RED); break; }
    case 7: // white
    { fgOption |= (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); break; }
    default: // error, change to white
    {
        fgOption |= (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
        printf("[Error Parameter Value] Foregound color change to white.\n");
        break;
    }
    }
    // Change backgound color.
    switch (backgroundColor) {
    case 0: // black
    { break; }
    case 1: // blue
    { bgOption |= BACKGROUND_BLUE; break; }
    case 2: // green
    { bgOption |= BACKGROUND_GREEN; break; }
    case 3: // red
    { bgOption |= BACKGROUND_RED; break; }
    case 4: // cyan
    { bgOption |= (BACKGROUND_BLUE | BACKGROUND_GREEN); break; }
    case 5: // pink
    { bgOption |= (BACKGROUND_BLUE | BACKGROUND_RED); break; }
    case 6: // yellow
    { bgOption |= (BACKGROUND_GREEN | BACKGROUND_RED); break; }
    case 7: // white
    { bgOption |= (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); break; }
    default: // error, change to black
    {
        // Make sure foregound color is not black.
        if (!(fgOption & 0x0111)) { fgOption |= (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); }
        printf("[Error Parameter Value] Backgound color change to black.\n");
        break;
    }
    }
    // Actual step to change color.
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fgOption | bgOption);
}