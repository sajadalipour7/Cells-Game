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
void RemoveCellByName(struct MyCells* MyCells,char* name){
    struct cells* current=MyCells->head;
    if(!strcmp(current->cellule->name,name)){
        MyCells->head=current->next;
        free(current->cellule);
        free(current);
    }else{
        while(current->next!=NULL && strcmp(current->next->cellule->name,name)){
            current=current->next;
        }
        if(current->next!=NULL){
            struct cells* tmp=current->next;
            current->next=current->next->next;
            free(tmp->cellule);
            free(tmp);
            MyCells->length--;
        }
    }
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

#endif // LINKEDLIST_H_INCLUDED
