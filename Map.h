#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
int** MapReader(int **a,char *filename,int *sizemap)
{
    FILE *fp=fopen(filename,"rb");
    int n,x,y,i;
    char situation;
    fread(&n,sizeof(int),1,fp);
    *sizemap=n;
    a=(int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++)
        a[i] = (int *)malloc(n * sizeof(int));
    for(y=0; y<n; y++)
    {
        for(x=0; x<n; x++)
        {
            fread(&situation,sizeof(char),1,fp);
            switch (situation)
            {
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
                int dummy=0;
                //printf("%d\n",situation);
                if(situation<0)
                    dummy+=256;
                a[y][x]=dummy+situation-'0';
                break;
            }
        }
    }
    fclose(fp);
    return a;
}
void SaveMap(int **a,char *filename,int sizemap)
{
    int n=sizemap;
    FILE *fp=fopen(filename,"wb");
    fwrite(&n,sizeof(int),1,fp);
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            char x=a[i][j]+'0';
            fwrite(&x,sizeof(char),1,fp);
        }
    }
    fclose(fp);
}
void SaveCellsData(struct MyCells* Player,char* filename)
{
    FILE *fp=fopen(filename,"wb");
    struct cells* current=Player->head;
    fwrite(&(Player->length),sizeof(int),1,fp);
    while(current!=NULL)
    {
        fwrite(current->cellule,sizeof(struct cellule),1,fp);
        current=current->next;
    }
    fclose(fp);
}
void CreateRandomMap(char *mapname,int sizemap)
{
    FILE *fp=fopen(mapname,"wb");
    int n=sizemap,i,j;
    fwrite(&n,sizeof(int),1,fp);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            char x='1'+rand()%4;
            fwrite(&x,sizeof(char),1,fp);
        }
    }
    fclose(fp);
}
void MapPrinterConsole(int **a,int n)
{
    int x,y;
    for(y=0; y<n; y++)
    {
        for(x=0; x<n; x++)
            printf("%d ",a[y][x]);
        printf("\n");
    }
}


#endif // MAP_H_INCLUDED
