
#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED
void SixZeli(float x,float y){
    float h=(sqrt(3)/2)*50;
    float r=50/2;
    int arr[]={x-r,y-h,x+r,y-h,x+2*r,y,x+r,y+h,x-r,y+h,x-2*r,y};
    fillpoly(6,arr);
}
void ShowMyMap(int **a,int n){
    float h=(sqrt(3)/2)*50;
    float r=50/2;
    int i,j,x=0,y=0;
    for(i=n-1;i>=0;i--){
        for(j=0;j<n;j++){
            switch (a[i][j]){
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
            SixZeli(x*100+50,y*2*h+50);
            x++;
        }
        x=0;
        y++;
    }
}
void ShowMainMenu(){
    printf("[1]Load\n[2]New single player game\n[3]New Multiplayer game\n[4]Exit\n");
}


#endif // GUI_H_INCLUDED
