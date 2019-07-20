# include <stdio.h>
# include <stdlib.h>

struct listNode{  ///lista autoreferenciada
    char data;
    struct listNode *nextPtr;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

void inserta(LISTNODEPTR *, char);
char borrar(LISTNODEPTR *, char);
int isEmpty(LISTNODEPTR);
void instructions(void);

main(){
    LISTNODEPTR startPtr=NULL;
    int choice;
    char item;

    instructions();
    printf("?");
    scanf("%d", &choice);

    while(choice!=3){
        switch(choice){
            case 1:
                printf("Ingresa un caracter: ");
                scanf("\n%c", &item);
                inserta(&startPtr, item);
                printList(startPtr);
                break;
            case 2:
                if(!isEmpty(startPtr)){
                    printf("Ingresa el caracter a eliminar: ");
                    scanf("\n%c", &item);

                    if(borrar(&startPtr,item)){
                        printf("%c borrado.\n", item);
                        printList(startPtr);
                    }
                    else
                        printf("%c no se encontro.\n\n", item);
                }
                else
                    printf("La lista esta vacia.\n\n");
                break;
            default:
                printf("Opcion invalida.\n\n");
                instructions();
                break;
        }

        printf("? ");
        scanf("%d", &choice);
    }

    printf("Terminamos.\n");
    return 0;
}

//Imprime las instrucciones
void instructions(void){
    printf("Ingresa tu opcion: \n"
           "    1 para insertar un elemento en la lista.\n"
           "    2 para borrar un elemento de la lista.\n"
           "    3 para finalizar.\n");
}

//inserta un nuevo valor dentro de la lista ordenada
void inserta(LISTNODEPTR *sPtr, char value){
    LISTNODEPTR newPtr, previousPtr, currentPtr;

    newPtr=malloc(sizeof(LISTNODE));

    if(newPtr != NULL){ //hay espacio disponible
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        previousPtr = NULL;
        currentPtr = *sPtr;

        while(currentPtr != NULL && value>currentPtr->data){
            previousPtr = currentPtr;  //vamos hacia ....   //localizando posicion donde debe ser insertado el caracter
            currentPtr = currentPtr->nextPtr;  //... siguiente nodo
        }

        if(previousPtr == NULL){
            newPtr->nextPtr = *sPtr;   //condicion de frontera por si es el primero
            *sPtr = newPtr;
        }
        else{
            previousPtr->nextPtr = newPtr;   //se redirecciona a donde apunta previous y current
            newPtr->nextPtr = currentPtr;
        }
    }
    else
        printf("%c no se inserto. No hay memoria suficiente.\n");
}

//Borra un elemento de la lista
char borrar(LISTNODEPTR *sPtr, char value){
    LISTNODEPTR previousPtr, currentPtr, tempPtr;

    if(value==(*sPtr)->data){
        tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;  //de-thread the node
        free(tempPtr);
        return value;
    }
    else{
        previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextPtr;

        while(currentPtr != NULL && currentPtr->data != value){
            previousPtr = currentPtr;  //vamos hacia ....
            currentPtr = currentPtr->nextPtr;  //... siguiente nodo
        }

        if(currentPtr != NULL){
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }
    return '\0';
}

//Regresa 1 si la lista esta vacia, 0 de lo contrario
int isEmpty(LISTNODEPTR sPtr){
    return sPtr == NULL;
}

//Imprimimos la lista
void printList(LISTNODEPTR currentPtr){
    if(currentPtr == NULL)
        printf("La lista esta vacia.\n");
    else{
        printf("La lista es: \n");

        while(currentPtr != NULL){
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL.\n");
    }
}
