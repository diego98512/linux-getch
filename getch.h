//
// Created by diego on 1/23/22.
//

#ifndef ENHANCEDITEMSHOP_GETCH_HPP
#define ENHANCEDITEMSHOP_GETCH_HPP

#endif //ENHANCEDITEMSHOP_GETCH_HPP

#include <termios.h>
#include <unistd.h>

int getch(void)
{
    struct termios oldt,
            newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}
