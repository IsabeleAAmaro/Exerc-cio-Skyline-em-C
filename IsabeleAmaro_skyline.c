#include <stdio.h>
 
typedef struct s_predio {
    int y;
    int x1;
    int x2;
} predio;

int lerPredio(predio entrada[], int n) {
    int final = 0;
    int k;
    for(k = 0; k < n; k++) {
        printf("Digite x1: ");
        scanf("%d", &entrada[k].x1);
        printf("Digite x2: ");
        scanf("%d", &entrada[k].x2);
        printf("Digite altura: ");
        scanf("%d", &entrada[k].y);
        
        if(final < entrada[k].x2){
        final = entrada[k].x2;
        }
       
        if(entrada[k].x1 > entrada[k].x2) {
            printf("\nx1 não pode ser maior que x2.");
        }
       
        if(entrada[k].y < 0) {
            printf("\nA altura não pode ser menor que 0.");
    }
}
    return final;
}

void formandoSkyline (predio entrada[], int tam, int largura) {
printf("(%d, %d)", entrada[0].x1, entrada[0].y);
int ponteiro_x1 = entrada[0].x1;
int ponteiro_x2 = entrada[0].x2;
int altura_maxima = entrada[0].y;
int ind_inicio = 1;
int ind_fim = 0;
int flag = 0;
int controlador_height = 0;
int continuar = 0;
int checagem = 0;
int i, j, h, g;

for (i = ponteiro_x1; i <= largura; i++){
    if (i < ponteiro_x1){
        continue;
    }
    
    if (ponteiro_x1 != ponteiro_x2) {
    if ((ind_inicio == ind_fim) && (altura_maxima == 0)){
                altura_maxima = entrada[ind_inicio].y;
                printf("(%d, %d)", entrada[ind_fim].x1, entrada[ind_fim].y);
                ponteiro_x1++;
                continue;
        }
    }
    
    if (ponteiro_x1 == ponteiro_x2){
        if (ind_inicio == ind_fim) {
            if (ind_fim == (tam - 1)){
                printf("(%d, %d)", largura,0);
                continue;
            }else{
                printf("(%d, %d)",entrada[ind_fim].x2, 0);
                ind_inicio++;
                ind_fim++;
                ponteiro_x1 = entrada[ind_fim].x1;
                ponteiro_x2 = entrada[ind_fim].x2;
                altura_maxima = 0;
                continue;
            }
        }else{ 
            ind_inicio++;
            if((ind_inicio == ind_fim) && (ponteiro_x2 == entrada[ind_inicio - 1].x2)){
            altura_maxima = entrada[ind_inicio].y;
            printf("(%d, %d)", ponteiro_x1 , entrada[ind_inicio].y);
            continuar++;
            }
            if (ponteiro_x2 > entrada[ind_inicio].x2){
                do{
                    ind_inicio++;
                }while(ponteiro_x2 > entrada[ind_inicio].x2);
                ponteiro_x2 = entrada[ind_inicio].x2;
            }else{
                for(g = ind_inicio; g <= ind_fim; g++){
                        if (entrada[g].x2 > ponteiro_x2){
                            ponteiro_x2 = entrada[g].x2;
                        }
                }
            }
            if (continuar == 1){
            continuar = 0;
            ponteiro_x1++;
            continue;
            }
        }
    }
   
    if(ind_inicio != ind_fim) {
        if (ind_inicio > ind_fim){
        ind_inicio = ind_fim;
        }
        for(j = ind_inicio; j <= ind_fim; j++){
            if (ponteiro_x1 == entrada[j].x2){
                checagem++;
                if(altura_maxima == entrada[j].y){
                    flag = j;
                    controlador_height = altura_maxima;
                    altura_maxima = 0;
                    for(h = ind_inicio; h <= ind_fim; h++){
                        if (h == flag){
                            continue;
                        }
                        if (entrada[h].y > altura_maxima){
                            altura_maxima = entrada[h].y;
                        }
                    }
                    if (altura_maxima != controlador_height){
                    printf("(%d, %d)", entrada[flag].x2, altura_maxima);
                        break;
                    }else{
                        flag == 0;
                        break;
                    }
                }
            }
        }
        if(checagem >= 1){
        ind_inicio++;
        checagem = 0;
        }
        
        if (flag != 0){
        flag = 0;
        controlador_height = 0;
        ponteiro_x1++;
        continue;
        }
    }
   
if (ind_fim <= tam - 1){
    if (ponteiro_x1 == entrada[ind_fim + 1].x1){
            ind_fim++;
        if (altura_maxima < entrada[ind_fim].y){
            altura_maxima = entrada[ind_fim].y;
            printf("(%d, %d)", entrada[ind_fim].x1, entrada[ind_fim].y);
                ponteiro_x1++;
                continue;
            }
        }
    }
ponteiro_x1++;
}
}

int main() {
    int N, largura;
    printf("Digite N: ");
    scanf("%d", &N);
    predio entrada[N];
    largura = lerPredio(entrada,N);
    formandoSkyline(entrada,N,largura);
    return 0;
}
