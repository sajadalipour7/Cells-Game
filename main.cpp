//in the name of god

//Cells Game

//By : Sajad Alipour

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
#include <math.h>
#include <winbgim.h>
#include <windows.h>
#include "LinkedList.h"
#include "GUI.h"
#include "Map.h"

int main()
{
    //Start of the game
    srand(time(NULL));
    int **MapGame;
    ShowMainMenu();
    char tmp[20];
    int temp,sizemap;
    gets(tmp);
    temp=atoi(tmp);
    struct MyCells* Player1=CreateNewCellsList();
    struct MyCells* Player2=CreateNewCellsList();
    switch(temp){
    case 1:
        printf("Enter Your SaveSlot Name(.bin format) :\n");
        gets(tmp);
        MapGame=MapReader(MapGame,tmp,&sizemap);
        printf("[1]Single Player\n[2]Multiplayer\n");
        gets(tmp);
        temp=atoi(tmp);
        if(temp==1){
            printf("How Many Cells Do You Want?\n");
            gets(tmp);
            temp=atoi(tmp);
            int i=0;
            while(i<temp){
                int x=rand()%sizemap;
                int y=rand()%sizemap;
                if(MapGame[y][x]!=3){
                    CelluleAppender(Player1,CreateNewCellule(RandString(7),0,x,y));
                    i++;
                }
            }
            ShowMyCells(Player1);
        }else if(temp==2){

        }
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        return 0;
        break;
    }
    //---------------------------------------------------------------------------------------
    //Initializing Graphics for the Game
    initwindow(800,600);
    HWND hWnd, hWndChild;
    hWnd = FindWindow(NULL, "Windows BGI");
    hWndChild = GetWindow(hWnd, GW_CHILD);
    SendMessage((HWND) hWnd, WM_SETTEXT,0, (LPARAM)"Cells Game");
    /*
    settextstyle(3,0,5);
    outtextxy(150,100,"Cells Game");
    settextstyle(1,0,3);
    outtextxy(150,350,"Loading...");
    int i;
    rectangle(100,400,600,450);
    for(i=0;i<6;i++){
        bar(100,400,100*(i+1),450);
        Sleep(500);
    }
    setfillstyle(1,BLACK);
    bar(0,0,800,600);
    */
    //--------------------------------------------------------------------
    ShowMyMap(MapGame,sizemap);
    ShowMyCellsOnMap(MapGame,sizemap,Player1);
    //--------------------------------------------------------------------

    MapPrinterConsole(MapGame,sizemap);
    getch();
    return 0;
}
