
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
                    outtextxy(x*75+50-10,y*2*h+50+20+h,energ);
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
        if((current->cellule->x)%2)
            fillellipse((current->cellule->x)*75+50,(current->cellule->y)*2*h+50+h,10,10);
        else
            fillellipse((current->cellule->x)*75+50,(current->cellule->y)*2*h+50,10,10);
        current=current->next;
    }
}
void ShowMainMenu()
{
    printf("[1]Load\n[2]New single player game\n[3]New Multiplayer game\n[4]Exit\n");
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
