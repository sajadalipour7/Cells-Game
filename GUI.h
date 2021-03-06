
#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED
void SixZeli(float x,float y)
{
    float h=(sqrt(3)/2)*50;
    float r=50/2;
    int arr[]= {x-r,y-h,x+r,y-h,x+2*r,y,x+r,y+h,x-r,y+h,x-2*r,y};
    fillpoly(6,arr);
}
void ShowMyMap(int **a,int n)
{
    float h=(sqrt(3)/2)*50;
    float r=50/2;
    int i,j,duty;
    int x=0;
    int y=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            switch (a[i][j])
            {
            case 4:
                setfillstyle(1,GREEN);
                break;
            case 3:
                setfillstyle(1,RED);
                break;
            case 2:
                setfillstyle(1,LIGHTCYAN);
                break;
            default:
                setfillstyle(1,BLUE);
                break;
            }
            if(x%2)
            {
                SixZeli(x*75+50,y*2*h+50+h);
                if(a[i][j]!=4 && a[i][j]!=3 && a[i][j]!=2)
                {
                    settextstyle(8,0,1);
                    char energ[4];
                    itoa(a[i][j],energ,10);
                    outtextxy(x*75+50-15,y*2*h+50+20+h,energ);
                }
            }
            else
            {
                SixZeli(x*75+50,y*2*h+50);
                if(a[i][j]!=4 && a[i][j]!=3 && a[i][j]!=2)
                {
                    settextstyle(8,0,1);
                    char energ[4];
                    itoa(a[i][j],energ,10);
                    outtextxy(x*75+50-15,y*2*h+50+20,energ);
                }

            }
            x++;
        }
        x=0;
        y++;
    }
}
void ShowMyCellsOnMap(int **MapGame,int sizemap,struct MyCells* Player)
{
    struct cells* current=Player->head;
    setfillstyle(1,BROWN);
    float h=(sqrt(3)/2)*50;
    float r=50/2;
    while(current!=NULL)
    {
        if((current->cellule->x)%2)
        {
            settextstyle(6,0,1);
            char energ[4];
            itoa(current->cellule->energy,energ,10);
            outtextxy((current->cellule->x)*75+50-20,(current->cellule->y)*2*h+50-35+h,energ);
            fillellipse((current->cellule->x)*75+50,(current->cellule->y)*2*h+50+h,10,10);
        }
        else
        {
            settextstyle(6,0,1);
            char energ[4];
            itoa(current->cellule->energy,energ,10);
            outtextxy((current->cellule->x)*75+50-20,(current->cellule->y)*2*h+50-35,energ);
            fillellipse((current->cellule->x)*75+50,(current->cellule->y)*2*h+50,10,10);
        }
        current=current->next;
    }
}
void ShowMyCellsOnMapPlayer2(int **MapGame,int sizemap,struct MyCells* Player)
{
    struct cells* current=Player->head;
    setfillstyle(1,YELLOW);
    float h=(sqrt(3)/2)*50;
    float r=50/2;
    while(current!=NULL)
    {
        if((current->cellule->x)%2)
        {
            settextstyle(6,0,1);
            char energ[4];
            itoa(current->cellule->energy,energ,10);
            outtextxy((current->cellule->x)*75+50-20,(current->cellule->y)*2*h+50-35+h,energ);
            fillellipse((current->cellule->x)*75+50,(current->cellule->y)*2*h+50+h,10,10);
        }
        else
        {
            settextstyle(6,0,1);
            char energ[4];
            itoa(current->cellule->energy,energ,10);
            outtextxy((current->cellule->x)*75+50-20,(current->cellule->y)*2*h+50-35,energ);
            fillellipse((current->cellule->x)*75+50,(current->cellule->y)*2*h+50,10,10);
        }
        current=current->next;
    }
}
void ShowMainMenu()
{
    printf("[1]Load\n[2]New single player game\n[3]New Multiplayer game\n[4]Time Trial Mode\n[5]Scoreboard\n[6]Exit\n");
}
void ShowOptionsMenu(struct cells* current,int **MapGame)
{
    printf("------ %s ------\n[1]Move\n",current->cellule->name);
    printf("[2]Split a cell");
    if(current->cellule->energy<=80 || MapGame[current->cellule->y][current->cellule->x]!=2)
    {
        printf("    Unavailable !");
    }
    printf("\n");
    printf("[3]Boost Energy");
    if(MapGame[current->cellule->y][current->cellule->x]==2 || MapGame[current->cellule->y][current->cellule->x]==3 || MapGame[current->cellule->y][current->cellule->x]==4)
    {
        printf("    Unavailable !");
    }
    printf("\n[4]Save\n[5]Exit\n");
}
void ShowOptionsMenuTimeMode(struct cells* current,int **MapGame)
{
    printf("------ %s ------\n[1]Move\n",current->cellule->name);
    printf("[2]Split a cell");
    if(current->cellule->energy<=80 || MapGame[current->cellule->y][current->cellule->x]!=2)
    {
        printf("    Unavailable !");
    }
    printf("\n");
    printf("[3]Boost Energy");
    if(MapGame[current->cellule->y][current->cellule->x]==2 || MapGame[current->cellule->y][current->cellule->x]==3 || MapGame[current->cellule->y][current->cellule->x]==4)
    {
        printf("    Unavailable !");
    }
    printf("\n[4]Exit\n");
}
void ShowMovementOptions(struct cells* current,int **MapGame,int sizemap,struct MyCells* Player,struct MyCells* Player2,int *flag)
{
    printf("[1]North\n[2]South\n[3]Northeast\n[4]Northwest\n[5]Southeast\n[6]Southwest\n");
    int x=current->cellule->x;
    int y=current->cellule->y;
    char tmp[5];
    int temp;
    gets(tmp);
    temp=atoi(tmp);
    switch (temp)
    {
    case 1:
        if(y-1>=0)
        {
            if(CheckCellByLocation(Player2,x,y-1) && CheckCellByLocation(Player,x,y-1) && MapGame[y-1][x]!=3){
                current->cellule->y--;
                *flag=1;
            }else{
                printf("Sorry !\nYou can't go there  !\n");
                *flag=0;
            }
        }
        else
        {
            printf("Heyyy!\nYou can't go outside the world !\n");
            *flag=0;
        }
        break;
    case 2:
        if(y+1<sizemap)
        {
            if(CheckCellByLocation(Player2,x,y+1) && CheckCellByLocation(Player,x,y+1) && MapGame[y+1][x]!=3)
            {
                current->cellule->y++;
                *flag=1;
            }
            else
            {
                printf("Sorry !\nYou can't go there  !\n");
                *flag=0;
            }
        }
        else
        {
            printf("Heyyy!\nYou can't go outside the world !\n");
            *flag=0;
        }
        break;
    case 3:
        if(x%2)
        {
            if(x+1<sizemap)
            {
                if(CheckCellByLocation(Player2,x+1,y) && CheckCellByLocation(Player,x+1,y) && MapGame[y][x+1]!=3)
                {
                    current->cellule->x++;
                    *flag=1;
                }
                else
                {
                    printf("Sorry !\nYou can't go there  !\n");
                    *flag=0;
                }
            }
            else
            {
                printf("Heyyy!\nYou can't go outside the world !\n");
                *flag=0;
            }
        }
        else
        {
            if(x+1<sizemap && y-1>=0)
            {
                if(CheckCellByLocation(Player2,x+1,y-1) && CheckCellByLocation(Player,x+1,y-1) && MapGame[y-1][x+1]!=3)
                {
                    current->cellule->x++;
                    current->cellule->y--;
                    *flag=1;
                }
                else
                {
                    printf("Sorry !\nYou can't go there  !\n");
                    *flag=0;
                }
            }
            else
            {
                printf("Heyyy!\nYou can't go outside the world !\n");
                *flag=0;
            }
        }
        break;

    case 4:
        if(x%2)
        {
            if(x-1>=0)
            {
                if(CheckCellByLocation(Player2,x-1,y) && CheckCellByLocation(Player,x-1,y) && MapGame[y][x-1]!=3)
                {
                    current->cellule->x--;
                    *flag=1;
                }
                else
                {
                    printf("Sorry !\nYou can't go there  !\n");
                    *flag=0;
                }
            }
            else
            {
                printf("Heyyy!\nYou can't go outside the world !\n");
                *flag=0;
            }
        }
        else
        {
            if(x-1>=0 && y-1>=0)
            {
                if(CheckCellByLocation(Player2,x-1,y-1) && CheckCellByLocation(Player,x-1,y-1) && MapGame[y-1][x-1]!=3)
                {
                    current->cellule->x--;
                    current->cellule->y--;
                    *flag=1;
                }
                else
                {
                    printf("Sorry !\nYou can't go there  !\n");
                    *flag=0;
                }
            }
            else
            {
                printf("Heyyy!\nYou can't go outside the world !\n");
                *flag=0;
            }
        }
        break;

    case 5:
        if(x%2)
        {
            if(x+1<sizemap && y+1<sizemap)
            {
                if(CheckCellByLocation(Player2,x+1,y+1) && CheckCellByLocation(Player,x+1,y+1) && MapGame[y+1][x+1]!=3)
                {
                    current->cellule->x++;
                    current->cellule->y++;
                    *flag=1;
                }
                else
                {
                    printf("Sorry !\nYou can't go there  !\n");
                    *flag=0;
                }
            }
            else
            {
                printf("Heyyy!\nYou can't go outside the world !\n");
                *flag=0;
            }

        }
        else
        {
            if(x+1<sizemap)
            {
                if(CheckCellByLocation(Player2,x+1,y) && CheckCellByLocation(Player,x+1,y) && MapGame[y][x+1]!=3)
                {
                    current->cellule->x++;
                    *flag=1;
                }
                else
                {
                    printf("Sorry !\nYou can't go there  !\n");
                    *flag=0;
                }
            }
            else
            {
                printf("Heyyy!\nYou can't go outside the world !\n");
                *flag=0;
            }

        }
        break;
    case 6:
        if(x%2)
        {
            if(x-1>=0 && y+1<sizemap)
            {
                if(CheckCellByLocation(Player2,x-1,y+1) && CheckCellByLocation(Player,x-1,y+1) && MapGame[y+1][x-1]!=3)
                {
                    current->cellule->x--;
                    current->cellule->y++;
                    *flag=1;
                }
                else
                {
                    printf("Sorry !\nYou can't go there  !\n");
                    *flag=0;
                }
            }
            else
            {
                printf("Heyyy!\nYou can't go outside the world !\n");
                *flag=0;
            }

        }
        else
        {
            if(x-1>=0)
            {
                if(CheckCellByLocation(Player2,x-1,y) && CheckCellByLocation(Player,x-1,y) && MapGame[y][x-1]!=3)
                {
                    current->cellule->x--;
                    *flag=1;
                }
                else
                {
                    printf("Sorry !\nYou can't go there !\n");
                    *flag=0;
                }
            }
            else
            {
                printf("Heyyy!\nYou can't go outside the world !\n");
                *flag=0;
            }

        }
        break;

    default:
        printf("Unknown Command !\n");
        *flag=0;
        break;
    }
}
char * RandString(int n)
{
    char *str = (char*)malloc((n+1) * sizeof(char));
    int i;
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (i = 0; i < n; i++)
    {
        int key = rand() % (sizeof(charset) / sizeof(char) - 1);
        str[i] = charset[key];
    }
    str[n] = '\0';
    return str;
}

#endif // GUI_H_INCLUDED
