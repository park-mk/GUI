﻿#ifndef GUI_H
#define GUI_H

//gui
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

//size of cursor
#define CURSOR_WIDTH 12
#define CURSOR_HEIGHT 19

#define CURSORH_WIDTH 18
#define CURSORH_HEIGHT 24

//size of icon
#define ICON_WIDTH 60
#define ICON_HEIGHT 60


//position of icon
#define ICON_X1 40
#define ICON_X2 160

#define ICON_Y1 30
#define ICON_Y2 140
#define ICON_Y3 250
#define ICON_Y4 360
#define ICON_Y5 470

// //kind of icon
// #define ICON_COMPUTER 0
// #define ICON_DOCUMENT 1
// #define ICON_PAINT 2
// #define ICON_TEXT 3
// #define ICON_TRASH 4
// #define ICON_TRASH_FULL 5
// #define ICON_VIEWER 6

//kind of WINDOW
#define WINDOW_COMPUTER 0
#define WINDOW_DOCUMENT 1
#define WINDOW_PAINT 2
#define WINDOW_TEXT 3
#define WINDOW_TRASH 4
#define WINDOW_TRASH_FULL 5
#define WINDOW_VIEWER 6


//size of window
#define WINDOW_HEIGHT 450
#define WINDOW_WIDTH 600

//position of window
#define WINDOW_X 100
#define WINDOW_Y 75

//kbd
#define KBD_RIGHT -1
#define KBD_LEFT -2
#define KBD_UP -3
#define KBD_DOWN -4
#define KBD_ESC -5
#define KBD_END -6
<<<<<<< HEAD
#define KBD_INC -7
#define KBD_DEC -8

//paint command
#define PAINT_PEN 0
#define PAINT_ERASER 1
#define PAINT_RECT 2
#define PAINT_TEXT 3
#define PAINT_RESET 4

//word
#define WORD_HEIGHT 25
#define WORD_WIDTH 16
#define WORD_GAP 12

//size of canvas
#define CANVAS_HEIGHT 347
#define CANVAS_WIDTH 570

void drawWindow(int id, int posX, int posY);
int drawWord(int id, int posX, int posY, unsigned short color);
=======
>>>>>>> origin/master

#endif
