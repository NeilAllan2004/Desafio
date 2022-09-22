#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
unsigned char armarios=0,mask=1, teste;
int opcao, num, desocupar,i;
srand(time(NULL));
do{
    printf("-------------------\n1.Ocupar um armário\n2.Desoculpar um armário\n3.Sair\nDigite a operação que você deseja realizar: \n");
    scanf("%d",&opcao);
    switch(opcao){
        case 1:
            do{
                num=rand()%8;
                mask=mask<<num;
                teste=armarios | mask;
                mask=1;
                if (armarios==255){
                    printf("-------------------\nTodos os armários estão ocupados.\n");
                    num=9;
                }
                else if(armarios!=teste){
                    armarios=teste;
                    printf("-------------------\nO armário %d foi reservado.\n",num+1);
                    num=9;
                }
            }while(num!=9);
            break;
        case 2:
            printf("-------------------\nDigite o armário que você deseja desocupar: \n");
            scanf("%d",&desocupar);
            mask=mask<<(desocupar-1);
            teste=armarios&~mask;
            mask=1;
            if(armarios==0){
                printf("-------------------\nTodos os armários estão desocupados.\n");
            }
            else if(teste==armarios){
                printf("-------------------\nEsse armário já está desocupado.\n");
            }
            else{
                armarios=teste;
                printf("-------------------\nO armário %d agora está desocupado.\n",desocupar);
            }
            break;
        case 3:
            printf("-------------------\nPrograma encerrado.\n-------------------\n");
            break;
        default:
            printf("-------------------\nOpção inválida.\n");
            continue;
    }
}while(opcao!=3);

return 0;
}