//in the name of god

//Cells Game

//By : Sajad Alipour

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <graphics.h>
#include <time.h>
#include <math.h>
#include <winbgim.h>
#include <windows.h>
#include "LinkedList.h"
#include "GUI.h"
#include "Map.h"
#include "MapEditorGUI.h"

int main()
{
    //Start of the game
    int IsMultiPlayer=0;
    srand(time(NULL));
    int **MapGame;
    ShowMainMenu();
    char tmp[20];
    int temp,sizemap;
    gets(tmp);
    temp=atoi(tmp);
    int flag=1;
    struct MyCells* Player1=CreateNewCellsList();
    struct MyCells* Player2=CreateNewCellsList();
    do
    {
        switch(temp)
        {
        case 1:
            printf("Enter Your SaveSlot Name(.bin format) :\n");
            gets(tmp);
            MapGame=MapReader(MapGame,tmp,&sizemap);
            printf("[1]Single Player\n[2]Multiplayer\n");
            gets(tmp);
            temp=atoi(tmp);
            if(temp==1)
            {
                printf("How Many Cells Do You Want?\n");
                gets(tmp);
                temp=atoi(tmp);
                int i=0;
                while(i<temp)
                {
                    int x=rand()%sizemap;
                    int y=rand()%sizemap;
                    if(MapGame[y][x]!=3  && CheckCellByLocation(Player1,x,y))
                    {
                        CelluleAppender(Player1,CreateNewCellule(RandString(7),0,x,y));
                        i++;
                    }
                }
                //ShowMyCells(Player1);
            }
            else if(temp==2)
            {
                IsMultiPlayer=1;
                printf("Player 1 \nHow Many Cells Do You Want?\n");
                gets(tmp);
                temp=atoi(tmp);
                int i=0;
                while(i<temp)
                {
                    int x=rand()%sizemap;
                    int y=rand()%sizemap;
                    if(MapGame[y][x]!=3 && CheckCellByLocation(Player1,x,y) && CheckCellByLocation(Player2,x,y))
                    {
                        CelluleAppender(Player1,CreateNewCellule(RandString(7),0,x,y));
                        i++;
                    }
                }
                printf("Player 2 \nHow Many Cells Do You Want?\n");
                gets(tmp);
                temp=atoi(tmp);
                i=0;
                while(i<temp)
                {
                    int x=rand()%sizemap;
                    int y=rand()%sizemap;
                    if(MapGame[y][x]!=3 && CheckCellByLocation(Player1,x,y) && CheckCellByLocation(Player2,x,y))
                    {
                        CelluleAppender(Player2,CreateNewCellule(RandString(7),0,x,y));
                        i++;
                    }
                }
            }
            flag=0;
            break;
        case 2:
            printf("[1]Custom Map\n[2]Random Map\n");
            gets(tmp);
            temp=atoi(tmp);
            if(temp==1)
            {
                printf("Please enter your ideal size of map :\n");
                gets(tmp);
                temp=atoi(tmp);
                char name[20];
                MapRawCreator(temp,name);
                printf("Please restart the game and load your map \n");
                gets(tmp);
                return 0;
            }
            else if(temp==2)
            {
                printf("Please enter your ideal save name :\n");
                gets(tmp);
                char dummy[7];
                printf("Please enter your ideal size of map :\n");
                gets(dummy);
                int dum=atoi(dummy);
                CreateRandomMap(tmp,dum);
                MapGame=MapReader(MapGame,tmp,&sizemap);
                printf("How Many Cells Do You Want?\n");
                gets(tmp);
                temp=atoi(tmp);
                int i=0;
                while(i<temp)
                {
                    int x=rand()%sizemap;
                    int y=rand()%sizemap;
                    if(MapGame[y][x]!=3  && CheckCellByLocation(Player1,x,y))
                    {
                        CelluleAppender(Player1,CreateNewCellule(RandString(7),0,x,y));
                        i++;
                    }
                }
                flag=0;
            }
            else
            {
                printf("Unknown Command!\n");
                flag=1;
            }
            break;
        case 3:
            break;
        case 4:
            printf("Are you sure you want to close the game?\n[1]Yes\n[2]No\n");
            gets(tmp);
            temp=atoi(tmp);
            if(temp==1)
                return 0;
            flag=1;
            ShowMainMenu();
            gets(tmp);
            temp=atoi(tmp);
            break;
        default:
            printf("Unknown Command!\n");
            ShowMainMenu();
            gets(tmp);
            temp=atoi(tmp);
            flag=1;
            break;
        }
    }
    while((temp!=1 && temp!=2 && temp!=3 && temp!=4) || flag);
    //---------------------------------------------------------------------------------------
    //Initializing Graphics for the Game
    initwindow(800,800);
    HWND hWnd, hWndChild;
    hWnd = FindWindow(NULL, "Windows BGI");
    hWndChild = GetWindow(hWnd, GW_CHILD);
    SendMessage((HWND) hWnd, WM_SETTEXT,0, (LPARAM)"Cells Game");
    //Loading GUI

    settextstyle(3,0,5);
    outtextxy(150,100,"Cells Game");
    settextstyle(1,0,3);
    outtextxy(150,350,"Loading...");
    int i;
    rectangle(100,400,600,450);
    for(i=0; i<6; i++)
    {
        bar(100,400,100*(i+1),450);
        Sleep(500);
    }
    setfillstyle(1,BLACK);
    bar(0,0,800,600);

    //--------------------------------------------------------------------
    ShowMyMap(MapGame,sizemap);
    ShowMyCellsOnMap(MapGame,sizemap,Player1);
    if(IsMultiPlayer)
        ShowMyCellsOnMapPlayer2(MapGame,sizemap,Player2);
    //--------------------------------------------------------------------

    //MapPrinterConsole(MapGame,sizemap);
    //This is For Single Player Mode
    if(!IsMultiPlayer)
    {
        while(1)
        {
            ShowPlayerCells(Player1,sizemap);
            char tmp[7];
            int temp;
            gets(tmp);
            temp=atoi(tmp);
            int i;
            struct cells* current=Player1->head;
            for(i=1; i<temp; i++)
                current=current->next;
            char *name=current->cellule->name;
            int x=current->cellule->x;
            int y=current->cellule->y;
            int energy=current->cellule->energy;
            ShowOptionsMenu(current,MapGame);
            gets(tmp);
            temp=atoi(tmp);
            switch (temp)
            {
            case 1:
                ShowMovementOptions(current,MapGame,sizemap,Player1,Player2);
                break;
            case 2:
                if(MapGame[y][x]==2)
                {
                    if(energy>80)
                    {
                        int xrand=0,yrand=0;
                        if(x%2)
                        {
                            if(y+1<sizemap && CheckCellByLocation(Player1,x,y+1))
                            {
                                if(MapGame[y+1][x]!=3)
                                {
                                    xrand=0;
                                    yrand=1;
                                }
                            }
                            else if(y-1>=0 && CheckCellByLocation(Player1,x,y-1))
                            {
                                if(MapGame[y-1][x]!=3 )
                                {
                                    xrand=0;
                                    yrand=-1;
                                }
                            }
                            else if(x+1<sizemap && CheckCellByLocation(Player1,x+1,y))
                            {
                                if(MapGame[y][x+1]!=3  )
                                {
                                    xrand=1;
                                    yrand=0;
                                }
                            }
                            else if(y+1<sizemap && x+1<sizemap && CheckCellByLocation(Player1,x+1,y+1))
                            {
                                if(MapGame[y+1][x+1]!=3 )
                                {
                                    xrand=1;
                                    yrand=1;
                                }
                            }
                            else if(x-1>=0 && CheckCellByLocation(Player1,x-1,y))
                            {
                                if(MapGame[y][x-1]!=3  )
                                {
                                    xrand=-1;
                                    yrand=0;
                                }
                            }
                            else if(y+1<sizemap && x-1>=0  && CheckCellByLocation(Player1,x-1,y+1))
                            {
                                if(MapGame[y+1][x-1]!=3 )
                                {
                                    xrand=-1;
                                    yrand=1;
                                }
                            }
                        }
                        else
                        {
                            if(y+1<sizemap && CheckCellByLocation(Player1,x,y+1))
                            {
                                if(MapGame[y+1][x]!=3)
                                {
                                    xrand=0;
                                    yrand=1;
                                }
                            }
                            else if(y-1>=0 && CheckCellByLocation(Player1,x,y-1))
                            {
                                if(MapGame[y-1][x]!=3)
                                {
                                    xrand=0;
                                    yrand=-1;
                                }
                            }
                            else if(x+1<sizemap && CheckCellByLocation(Player1,x+1,y))
                            {
                                if(MapGame[y][x+1]!=3 )
                                {
                                    xrand=1;
                                    yrand=0;
                                }
                            }
                            else if(y-1>=0 && x+1<sizemap && CheckCellByLocation(Player1,x+1,y-1))
                            {
                                if(MapGame[y-1][x+1]!=3 )
                                {
                                    xrand=1;
                                    yrand=-1;
                                }
                            }
                            else if(x-1>=0  && CheckCellByLocation(Player1,x-1,y))
                            {
                                if(MapGame[y][x-1]!=3 )
                                {
                                    xrand=-1;
                                    yrand=0;
                                }
                            }
                            else if(y-1>=0 && x-1>=0 && CheckCellByLocation(Player1,x-1,y-1))
                            {
                                if(MapGame[y-1][x-1]!=3)
                                {
                                    xrand=-1;
                                    yrand=-1;
                                }
                            }
                        }
                        if(!xrand && !yrand)
                        {
                            printf("Sorry \nCould'nt find a place to split the new cell\n");
                        }
                        else
                        {
                            RemoveCellByName(Player1,current->cellule->name);
                            CelluleAppender(Player1,CreateNewCellule(RandString(7),40,x,y));
                            CelluleAppender(Player1,CreateNewCellule(RandString(7),40,x+xrand,y+yrand));
                        }
                    }
                    else
                    {
                        printf("Sorry \nYou have not enough energy to split\n");
                    }
                }
                else
                {
                    printf("Sorry \nThis is not an Splitting place\n");
                }

                break;
            case 3:
                if(MapGame[y][x]>15)
                {
                    MapGame[y][x]-=15;
                    current->cellule->energy+=15;
                }
                else if(MapGame[y][x]>4)
                {
                    current->cellule->energy=current->cellule->energy+MapGame[y][x];
                    MapGame[y][x]=0;
                }
                else if(MapGame[y][x]==0)
                {
                    printf("Sorry \nThe Energy of this place is finished !\n");
                }
                else
                {
                    printf("This is not an energy boost place !\n");
                }
                break;
            case 4:
                break;
            case 5:
                printf("Are you sure you want to close the game?\n[1]Yes\n[2]No\n");
                gets(tmp);
                temp=atoi(tmp);
                if(temp==1)
                    return 0;
                break;
            default:
                printf("Unknown Command!\n");
                break;
            }
            ShowMyMap(MapGame,sizemap);
            ShowMyCellsOnMap(MapGame,sizemap,Player1);

            //getch();
        }
    }
    else
    {
        while(1)
        {
            //Player 1 turn
            printf("Player 1 :\n");
            ShowPlayerCells(Player1,sizemap);
            char tmp[7];
            int temp;
            gets(tmp);
            temp=atoi(tmp);
            int i;
            struct cells* current=Player1->head;
            for(i=1; i<temp; i++)
                current=current->next;
            char *name=current->cellule->name;
            int x=current->cellule->x;
            int y=current->cellule->y;
            int energy=current->cellule->energy;
            ShowOptionsMenu(current,MapGame);
            gets(tmp);
            temp=atoi(tmp);
            switch (temp)
            {
            case 1:
                ShowMovementOptions(current,MapGame,sizemap,Player1,Player2);
                break;
            case 2:
                if(MapGame[y][x]==2)
                {
                    if(energy>80)
                    {
                        int xrand=0,yrand=0;
                        if(x%2)
                        {
                            if(y+1<sizemap && CheckCellByLocation(Player1,x,y+1))
                            {
                                if(MapGame[y+1][x]!=3)
                                {
                                    xrand=0;
                                    yrand=1;
                                }
                            }
                            else if(y-1>=0 && CheckCellByLocation(Player1,x,y-1))
                            {
                                if(MapGame[y-1][x]!=3 )
                                {
                                    xrand=0;
                                    yrand=-1;
                                }
                            }
                            else if(x+1<sizemap && CheckCellByLocation(Player1,x+1,y))
                            {
                                if(MapGame[y][x+1]!=3  )
                                {
                                    xrand=1;
                                    yrand=0;
                                }
                            }
                            else if(y+1<sizemap && x+1<sizemap && CheckCellByLocation(Player1,x+1,y+1))
                            {
                                if(MapGame[y+1][x+1]!=3 )
                                {
                                    xrand=1;
                                    yrand=1;
                                }
                            }
                            else if(x-1>=0 && CheckCellByLocation(Player1,x-1,y))
                            {
                                if(MapGame[y][x-1]!=3  )
                                {
                                    xrand=-1;
                                    yrand=0;
                                }
                            }
                            else if(y+1<sizemap && x-1>=0  && CheckCellByLocation(Player1,x-1,y+1))
                            {
                                if(MapGame[y+1][x-1]!=3 )
                                {
                                    xrand=-1;
                                    yrand=1;
                                }
                            }
                        }
                        else
                        {
                            if(y+1<sizemap && CheckCellByLocation(Player1,x,y+1))
                            {
                                if(MapGame[y+1][x]!=3)
                                {
                                    xrand=0;
                                    yrand=1;
                                }
                            }
                            else if(y-1>=0 && CheckCellByLocation(Player1,x,y-1))
                            {
                                if(MapGame[y-1][x]!=3)
                                {
                                    xrand=0;
                                    yrand=-1;
                                }
                            }
                            else if(x+1<sizemap && CheckCellByLocation(Player1,x+1,y))
                            {
                                if(MapGame[y][x+1]!=3 )
                                {
                                    xrand=1;
                                    yrand=0;
                                }
                            }
                            else if(y-1>=0 && x+1<sizemap && CheckCellByLocation(Player1,x+1,y-1))
                            {
                                if(MapGame[y-1][x+1]!=3 )
                                {
                                    xrand=1;
                                    yrand=-1;
                                }
                            }
                            else if(x-1>=0  && CheckCellByLocation(Player1,x-1,y))
                            {
                                if(MapGame[y][x-1]!=3 )
                                {
                                    xrand=-1;
                                    yrand=0;
                                }
                            }
                            else if(y-1>=0 && x-1>=0 && CheckCellByLocation(Player1,x-1,y-1))
                            {
                                if(MapGame[y-1][x-1]!=3)
                                {
                                    xrand=-1;
                                    yrand=-1;
                                }
                            }
                        }
                        if(!xrand && !yrand)
                        {
                            printf("Sorry \nCould'nt find a place to split the new cell\n");
                        }
                        else
                        {
                            RemoveCellByName(Player1,current->cellule->name);
                            CelluleAppender(Player1,CreateNewCellule(RandString(7),40,x,y));
                            CelluleAppender(Player1,CreateNewCellule(RandString(7),40,x+xrand,y+yrand));
                        }
                    }
                    else
                    {
                        printf("Sorry \nYou have not enough energy to split\n");
                    }
                }
                else
                {
                    printf("Sorry \nThis is not an Splitting place\n");
                }

                break;
            case 3:
                if(MapGame[y][x]>15)
                {
                    MapGame[y][x]-=15;
                    current->cellule->energy+=15;
                }
                else if(MapGame[y][x]>4)
                {
                    current->cellule->energy=current->cellule->energy+MapGame[y][x];
                    MapGame[y][x]=0;
                }
                else if(MapGame[y][x]==0)
                {
                    printf("Sorry \nThe Energy of this place is finished !\n");
                }
                else
                {
                    printf("This is not an energy boost place !\n");
                }
                break;
            case 4:
                break;
            case 5:
                printf("Are you sure you want to close the game?\n[1]Yes\n[2]No\n");
                gets(tmp);
                temp=atoi(tmp);
                if(temp==1)
                    return 0;
                break;
            default:
                printf("Unknown Command!\n");
                break;
            }
            ShowMyMap(MapGame,sizemap);
            ShowMyCellsOnMap(MapGame,sizemap,Player1);
            ShowMyCellsOnMapPlayer2(MapGame,sizemap,Player2);
            //---------------------------------------------------------
            //Player 2 turn
            {
                printf("Player 2 :\n");
                ShowPlayerCells(Player2,sizemap);
                char tmp[7];
                int temp;
                gets(tmp);
                temp=atoi(tmp);
                int i;
                struct cells* current=Player2->head;
                for(i=1; i<temp; i++)
                    current=current->next;
                char *name=current->cellule->name;
                int x=current->cellule->x;
                int y=current->cellule->y;
                int energy=current->cellule->energy;
                ShowOptionsMenu(current,MapGame);
                gets(tmp);
                temp=atoi(tmp);
                switch (temp)
                {
                case 1:
                    ShowMovementOptions(current,MapGame,sizemap,Player2,Player1);
                    break;
                case 2:
                    if(MapGame[y][x]==2)
                    {
                        if(energy>80)
                        {
                            int xrand=0,yrand=0;
                            if(x%2)
                            {
                                if(y+1<sizemap && CheckCellByLocation(Player2,x,y+1))
                                {
                                    if(MapGame[y+1][x]!=3)
                                    {
                                        xrand=0;
                                        yrand=1;
                                    }
                                }
                                else if(y-1>=0 && CheckCellByLocation(Player2,x,y-1))
                                {
                                    if(MapGame[y-1][x]!=3 )
                                    {
                                        xrand=0;
                                        yrand=-1;
                                    }
                                }
                                else if(x+1<sizemap && CheckCellByLocation(Player2,x+1,y))
                                {
                                    if(MapGame[y][x+1]!=3  )
                                    {
                                        xrand=1;
                                        yrand=0;
                                    }
                                }
                                else if(y+1<sizemap && x+1<sizemap && CheckCellByLocation(Player2,x+1,y+1))
                                {
                                    if(MapGame[y+1][x+1]!=3 )
                                    {
                                        xrand=1;
                                        yrand=1;
                                    }
                                }
                                else if(x-1>=0 && CheckCellByLocation(Player2,x-1,y))
                                {
                                    if(MapGame[y][x-1]!=3  )
                                    {
                                        xrand=-1;
                                        yrand=0;
                                    }
                                }
                                else if(y+1<sizemap && x-1>=0  && CheckCellByLocation(Player2,x-1,y+1))
                                {
                                    if(MapGame[y+1][x-1]!=3 )
                                    {
                                        xrand=-1;
                                        yrand=1;
                                    }
                                }
                            }
                            else
                            {
                                if(y+1<sizemap && CheckCellByLocation(Player2,x,y+1))
                                {
                                    if(MapGame[y+1][x]!=3)
                                    {
                                        xrand=0;
                                        yrand=1;
                                    }
                                }
                                else if(y-1>=0 && CheckCellByLocation(Player2,x,y-1))
                                {
                                    if(MapGame[y-1][x]!=3)
                                    {
                                        xrand=0;
                                        yrand=-1;
                                    }
                                }
                                else if(x+1<sizemap && CheckCellByLocation(Player2,x+1,y))
                                {
                                    if(MapGame[y][x+1]!=3 )
                                    {
                                        xrand=1;
                                        yrand=0;
                                    }
                                }
                                else if(y-1>=0 && x+1<sizemap && CheckCellByLocation(Player2,x+1,y-1))
                                {
                                    if(MapGame[y-1][x+1]!=3 )
                                    {
                                        xrand=1;
                                        yrand=-1;
                                    }
                                }
                                else if(x-1>=0  && CheckCellByLocation(Player2,x-1,y))
                                {
                                    if(MapGame[y][x-1]!=3 )
                                    {
                                        xrand=-1;
                                        yrand=0;
                                    }
                                }
                                else if(y-1>=0 && x-1>=0 && CheckCellByLocation(Player2,x-1,y-1))
                                {
                                    if(MapGame[y-1][x-1]!=3)
                                    {
                                        xrand=-1;
                                        yrand=-1;
                                    }
                                }
                            }
                            if(!xrand && !yrand)
                            {
                                printf("Sorry \nCould'nt find a place to split the new cell\n");
                            }
                            else
                            {
                                RemoveCellByName(Player2,current->cellule->name);
                                CelluleAppender(Player2,CreateNewCellule(RandString(7),40,x,y));
                                CelluleAppender(Player2,CreateNewCellule(RandString(7),40,x+xrand,y+yrand));
                            }
                        }
                        else
                        {
                            printf("Sorry \nYou have not enough energy to split\n");
                        }
                    }
                    else
                    {
                        printf("Sorry \nThis is not an Splitting place\n");
                    }

                    break;
                case 3:
                    if(MapGame[y][x]>15)
                    {
                        MapGame[y][x]-=15;
                        current->cellule->energy+=15;
                    }
                    else if(MapGame[y][x]>4)
                    {
                        current->cellule->energy=current->cellule->energy+MapGame[y][x];
                        MapGame[y][x]=0;
                    }
                    else if(MapGame[y][x]==0)
                    {
                        printf("Sorry \nThe Energy of this place is finished !\n");
                    }
                    else
                    {
                        printf("This is not an energy boost place !\n");
                    }
                    break;
                case 4:
                    break;
                case 5:
                    printf("Are you sure you want to close the game?\n[1]Yes\n[2]No\n");
                    gets(tmp);
                    temp=atoi(tmp);
                    if(temp==1)
                        return 0;
                    break;
                default:
                    printf("Unknown Command!\n");
                    break;
                }
            }
            ShowMyMap(MapGame,sizemap);
            ShowMyCellsOnMap(MapGame,sizemap,Player1);
            ShowMyCellsOnMapPlayer2(MapGame,sizemap,Player2);


            //getch();
        }

    }
    getch();
    return 0;
}
