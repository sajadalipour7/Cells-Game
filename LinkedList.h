#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED


//Structures
struct cellule
{
    char name[30];
    int energy;
    int x;
    int y;
};
struct cells
{
    struct cellule* cellule;
    struct cells* next;
};
struct MyCells
{
    int length;
    struct cells* head;
};
struct PlayerScoreboard
{
    int score;
    char name[20];
};
void bubblesort(struct PlayerScoreboard players[],int n)
{
    int j,i;
    for(j=0;j<n;j++){
        for(i=0;i<n-1;i++){
            if(players[i].score<players[i+1].score ){
                int tempscore=players[i].score;
                char tempname[20];
                strcpy(tempname,players[i].name);
                players[i].score=players[i+1].score;
                strcpy(players[i].name,players[i+1].name);
                players[i+1].score=tempscore;
                strcpy(players[i+1].name,tempname);
            }
        }
    }
}
//Functions
struct MyCells *CreateNewCellsList()
{
    struct MyCells*CelsList = (struct MyCells*)malloc(sizeof(struct MyCells));
    CelsList->length=0;
    CelsList->head=NULL;
    return CelsList;
}
struct cellule* CreateNewCellule(char *name,int energy,int x,int y)
{
    struct cellule* NewCellule=(struct cellule*)malloc(sizeof(struct cellule));
    strcpy(NewCellule->name,name);
    NewCellule->energy=energy;
    NewCellule->x=x;
    NewCellule->y=y;
    return NewCellule;
}
void CelluleAppender(struct MyCells * MyCells, struct cellule *cellule)
{
    struct cells *NewCell = (struct cells*)malloc(sizeof(struct cells));
    NewCell->next = NULL;
    NewCell->cellule=cellule;
    MyCells->length++;
    if (MyCells->head == NULL)
    {
        MyCells->head = NewCell;
    }
    else
    {
        struct cells *current = MyCells->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = NewCell;
    }
}
void RemoveCellByName(struct MyCells* MyCells,char* name)
{
    struct cells* current=MyCells->head;
    if(!strcmp(current->cellule->name,name))
    {
        MyCells->head=current->next;
        free(current->cellule);
        free(current);
    }
    else
    {
        while(current->next!=NULL && strcmp(current->next->cellule->name,name))
        {
            current=current->next;
        }
        if(current->next!=NULL)
        {
            struct cells* tmp=current->next;
            current->next=current->next->next;
            free(tmp->cellule);
            free(tmp);
            MyCells->length--;
        }
    }
}
int CheckCellByLocation(struct MyCells* Player,int x,int y)
{
    struct cells* current=Player->head;
    while(current!=NULL)
    {
        if(current->cellule->x==x && current->cellule->y==y)
        {
            return 0;
        }
        current=current->next;
    }
    return 1;
}
void ShowMyCells(struct MyCells* MyCells)
{
    struct cells* current= MyCells->head;
    while(current!=NULL)
    {
        printf("Name : %s\n",current->cellule->name);
        printf("Energy : %d\n",current->cellule->energy);
        printf("X Position : %d\n",current->cellule->x);
        printf("Y Position : %d\n",current->cellule->y);
        current=current->next;
    }
}

void ShowPlayerCells(struct MyCells* MyCells,int sizemap)
{
    printf("Please choose one of your cells:\n");
    struct cells* current= MyCells->head;
    int i=0;
    int j=0;
    while(current!=NULL)
    {
        printf("[%d] %s ( %d , %d )  Energy Level : %d\n",i+1,current->cellule->name,current->cellule->x,sizemap-1-current->cellule->y,current->cellule->energy);
        current=current->next;
        i++;
    }
}
int SumScoresCells(struct MyCells* Player){
    struct cells* current=Player->head;
    int sum=0;
    while(current!=NULL){
        sum+=current->cellule->energy;
        current=current->next;
    }
    return sum;
}


#endif // LINKEDLIST_H_INCLUDED
