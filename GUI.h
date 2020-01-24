
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
    int i,j,x=0,y=0;
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
void ShowMyCellsOnMap(int **MapGame,int sizemap,struct MyCells* Player){
    struct cells* current=Player->head;
    setfillstyle(1,BROWN);
    float h=(sqrt(3)/2)*50;
    float r=50/2;
    while(current!=NULL){
        if((current->cellule->x)%2){
            settextstyle(6,0,1);
            char energ[4];
            itoa(current->cellule->energy,energ,10);
            outtextxy((current->cellule->x)*75+50-20,(current->cellule->y)*2*h+50-35+h,energ);
            fillellipse((current->cellule->x)*75+50,(current->cellule->y)*2*h+50+h,10,10);
        }else{
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
    printf("[1]Load\n[2]New single player game\n[3]New Multiplayer game\n[4]Exit\n");
}
void ShowOptionsMenu(struct cells* current,int **MapGame){
    printf("[1]Move\n");
    printf("[2]Split a cell");
    if(current->cellule->energy<=80){
        printf("    Unavailable !");
    }
    printf("\n");
    printf("[3]Boost Energy");
    if(MapGame[current->cellule->y][current->cellule->x]==2 || MapGame[current->cellule->y][current->cellule->x]==3 || MapGame[current->cellule->y][current->cellule->x]==4){
        printf("    Unavailable !");
    }
    printf("\n[4]Save\n[5]Exit\n");
}
void ShowMovementOptions(struct cells* current,int **MapGame){
    int x=current->cellule->x;
    int y=current->cellule->y;
    printf("[1]North\n[2]South\n[3]Northeast\n[4]Northwest\n[5]Southeast\n[6]Southwest\n");
    char tmp[5];
    int temp;
    gets(tmp);
    temp=atoi(tmp);
    switch (temp){
    case 1:
        current->cellule->y--;
        break;
    case 2:
        current->cellule->y++;
        break;
    case 3:
        current->cellule->x++;
        if(!(x%2))
            current->cellule->y--;
        break;
    case 4:
        current->cellule->x--;
        if(!(x%2))
            current->cellule->y--;
        break;
    case 5:
        current->cellule->x++;
        if(x%2)
            current->cellule->y++;
        break;
    case 6:
        current->cellule->x--;
        if(x%2)
            current->cellule->y++;
        break;
    default:
        printf("Unknown Command !\n");
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
