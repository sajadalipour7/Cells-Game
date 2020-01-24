//in the name of god

//Cells Game

//By : Sajad Alipour

#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <winbgim.h>
#include <windows.h>
#include "GUI.h"
#include "Map.h"
int main()
{
    int **MapGame;
    int sizemap;
    MapGame=MapReader(MapGame,"map2.bin",&sizemap);
    //ShowMainMenu();
    //Initializing Window of the Game

    initwindow(800,600);
    HWND hWnd, hWndChild;
    hWnd = FindWindow(NULL, "Windows BGI");
    hWndChild = GetWindow(hWnd, GW_CHILD);
    SendMessage((HWND) hWnd, WM_SETTEXT,0, (LPARAM)"Cells Game");

    //--------------------------------------------------------------------
    ShowMyMap(MapGame,sizemap);
    MapPrinterConsole(MapGame,sizemap);
    getch();
    return 0;
}
