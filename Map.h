#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
int** MapReader(int **a,char *filename,int *sizemap){
    FILE *fp=fopen(filename,"rb");
    int n,x,y,i;
    char situation;
    fread(&n,sizeof(int),1,fp);
    *sizemap=n;
    a=(int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++)
         a[i] = (int *)malloc(n * sizeof(int));
    for(y=0;y<n;y++){
        for(x=0;x<n;x++){
            fread(&situation,sizeof(char),1,fp);
            switch (situation){
            case '1':
                a[y][x]=100;
                break;
            case '2':
                a[y][x]=2;
                break;
            case '3':
                a[y][x]=3;
                break;
            case '4':
                a[y][x]=4;
                break;
            default:
                a[y][x]=situation;
                break;
            }
        }
    }
    return a;
}
void MapPrinterConsole(int **a,int n){
    int x,y;
    for(y=0;y<n;y++){
        for(x=0;x<n;x++)
            printf("%d ",a[y][x]);
        printf("\n");
    }
}


#endif // MAP_H_INCLUDED
