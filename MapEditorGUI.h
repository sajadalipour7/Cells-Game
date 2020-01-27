#ifndef MAPEDITORGUI_H_INCLUDED
#define MAPEDITORGUI_H_INCLUDED

void MapRawCreator(int sizemap,char name[20])
{
    int n=sizemap;

    float h=(sqrt(3)/2)*50;
    float r=50/2;
    int i,j;
    int **a;
    a=(int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++)
        a[i] = (int *)malloc(n * sizeof(int));

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            a[i][j]=4;
    printf("--------------------------------------------\nInstructions :\nLeftClick : Forbidden place\nRightClick : Energy place\nScrollButtonClick : Mitosis place\nDoubleLeftClick : Normal place\n");
    printf("********When your customizing finished just press any key********\n");
    initwindow(800,800);
    HWND hWnd, hWndChild;
    hWnd = FindWindow(NULL, "Windows BGI");
    hWndChild = GetWindow(hWnd, GW_CHILD);
    SendMessage((HWND) hWnd, WM_SETTEXT,0, (LPARAM)"Map Editor");
    ShowMyMap(a,n);
    while(!kbhit())
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            int x=mousex();
            int y=mousey();
            int ything=(int)(2*h);
            if(!(x%2))
            {
                a[(int)(y/ything)][x/75]=3;
                //printf("X:%d Y:%d\nArrayX:%d ArrayY:%d\n",x,y,x/75,(int)(y/ything));
            }
            else
            {
                a[(int)((y-h)/ything)][x/75]=3;
                //printf("X:%d Y:%d\nArrayX:%d ArrayY:%d\n",x,y,x/75,(int)((y-h)/ything));
            }
            ShowMyMap(a,n);
            clearmouseclick(WM_LBUTTONDOWN);
        }
        else if(ismouseclick(WM_RBUTTONDOWN))
        {
            int x=mousex();
            int y=mousey();
            int ything=(int)(2*h);
            if(!(x%2))
            {
                a[(int)(y/ything)][x/75]=100;

            }
            else
            {
                a[(int)((y-h)/ything)][x/75]=100;

            }
            ShowMyMap(a,n);
            clearmouseclick(WM_RBUTTONDOWN);
        }
        else if(ismouseclick(WM_MBUTTONDOWN))
        {
            int x=mousex();
            int y=mousey();
            int ything=(int)(2*h);
            if(!(x%2))
            {
                a[(int)(y/ything)][x/75]=2;

            }
            else
            {
                a[(int)((y-h)/ything)][x/75]=2;

            }
            ShowMyMap(a,n);
            clearmouseclick(WM_MBUTTONDOWN);
        }
        else if(ismouseclick(WM_LBUTTONDBLCLK))
        {
            int x=mousex();
            int y=mousey();
            int ything=(int)(2*h);
            if(!(x%2))
            {
                a[(int)(y/ything)][x/75]=4;

            }
            else
            {
                a[(int)((y-h)/ything)][x/75]=4;

            }
            ShowMyMap(a,n);
            clearmouseclick(WM_LBUTTONDBLCLK);
        }

    }
    closegraph();
    printf("Please enter your ideal save name\n");
    gets(name);
    FILE *fp=fopen(name,"wb");
    fwrite(&n,sizeof(int),1,fp);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[i][j]==100)
                a[i][j]=1;
            char x=a[i][j]+'0';
            fwrite(&x,sizeof(char),1,fp);
        }
    }
    fclose(fp);

}

#endif // MAPEDITORGUI_H_INCLUDED
