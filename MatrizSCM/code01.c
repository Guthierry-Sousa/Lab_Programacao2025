#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int dim;
    int **pMatriz;

} dataMatriz;

typedef struct{

    int l;
    int c;
    char tipo[3];
    int maxValue;

}Imagem;

int ** alocarMatriz(dataMatriz *);
int ** lerImagem(Imagem *);
void suavizarMedia(int **, int **, Imagem);
int tratarBordas(int **, int , int , Imagem);
void salvarImagem(int **, Imagem);
void gerarMatrizSCM(int **, int **, int **, Imagem);

int main(int argc, char **argv){

    dataMatriz dadosS;

    Imagem matriz;

    // Alocação e leitura da imagem
    int **img = lerImagem(&matriz);
    if(matriz.l != matriz.c){

        printf("\nA matriz não é quadrada!\n");
        exit(1);

    }

    // Alocação da matriz suavizada
    dadosS.dim = matriz.l;
    int **matrizS = alocarMatriz(&dadosS);

    // Aplicação do filtro de suavização
    suavizarMedia(img, matrizS, matriz);

    // Salvar Imagem  suavizada
    salvarImagem(matrizS, matriz);

    // Matriz SCM

    int max = matriz.maxValue + 1;

    int **M = NULL;
    if(!(M = calloc(max, sizeof(int *)))){

        printf("\nMemória Indisponível\n");
        exit(8);

    }

    for(int i = 0; i<max; i++){

        if(!(M[i] = calloc(max, sizeof(int)))){

            printf("\nMemória Indisponível\n");
            exit(9);

        }
    }

    gerarMatrizSCM(M, img, matrizS, matriz);

    // Liberação de memória
    for (int i = 0; i < matriz.l; i++) free(img[i]);
    free(img);

    for (int i = 0; i < dadosS.dim; i++) free(matrizS[i]);
    free(matrizS);

    for (int i = 0; i < max; i++) free(M[i]);
    free(M);

    printf("\n\nCódigo Finalizado.\n\n");

    return 0;
}

int ** alocarMatriz(dataMatriz *M){

    M->pMatriz = (int **) malloc(sizeof(int *) * M->dim);

    if(M->pMatriz == NULL){
        printf("\nMemória Indisponível\n");
        exit(2);
    }

    for(int i = 0; i< M->dim; i++){

        M->pMatriz[i] = (int *) malloc(sizeof(int) * M->dim);

        if(M->pMatriz[i] == NULL){
            printf("\nMemória Indisponível\n");
            exit(3);
        }
    }

    return M->pMatriz;
}

int ** lerImagem(Imagem *imagem){

    int **img;

    // Leitura da imagem

    FILE *fin = NULL;
    if(!(fin = fopen("entrada.pgm", "r"))){
        perror("\nNão foi possível abrir imagem\n");
        exit(4);
    }

    // 1 - Cabeçalho
    fscanf(fin, "%s", imagem->tipo);
    fscanf(fin, "%d %d", &imagem->c, &imagem->l);
    fscanf(fin, "%d", &imagem->maxValue);

    // 2 - Alocar memória para a imagem

    img = (int **) malloc(sizeof(int *) * imagem->l);

    if(img == NULL){
        printf("\nMemória Indisponível\n");
        exit(5);
    }

    for(int i = 0; i< imagem->l; i++){

        img[i] = (int *) malloc(sizeof(int) * imagem->c);

        if(img[i] == NULL){
            printf("\nMemória Indisponível\n");
            exit(6);
        }
    }

    // 3 - Leitura da imagem
    for(int i = 0; i<imagem->l; i++){
        for(int j = 0; j<imagem->c; j++){

            fscanf(fin, "%d", &img[i][j]);

        }
    }
    fclose(fin);

    return img;

}

int tratarBordas(int ** entrada, int x, int y, Imagem imagem){

    if(x<0 || y < 0 || x >= imagem.c || y >= imagem.l){
        return 0;
    }

    return entrada[y][x];

}

void suavizarMedia(int **entrada, int **saida, Imagem imagem){

    int dx, dy;

    for(int y = 0; y < imagem.l; y++){

        for(int x = 0; x < imagem.c; x++){

            int soma = 0;

            // Filtro média 3x3
            for(dy = -1; dy <= 1; dy++){
                for(dx = -1; dx <= 1; dx++){
                    soma += tratarBordas(entrada, x + dx, y + dy, imagem);
                }
            }
            saida[y][x] = soma/9; // Média simples
        }
    }
}

void salvarImagem(int **img_saida, Imagem imagem){

    FILE *fout = NULL;

    if(!(fout = fopen("saida.pgm", "w"))){
        perror("\nNão foi possível criar arquivo.\n");
        exit(7);
    }

    fprintf(fout, "%s\n", imagem.tipo);
    fprintf(fout, "%d %d\n",imagem.c, imagem.l);
    fprintf(fout, "%d\n", imagem.maxValue);

    for(int i = 0; i < imagem.l; i++){
        for(int j = 0; j < imagem.c; j++){

            fprintf(fout, "%d ", img_saida[i][j]);

        }

        fprintf(fout, "\n");

    }

    fclose(fout);
}

void gerarMatrizSCM(int **M, int **imgI, int **imgS, Imagem imagem){

    // Preenchendo a matriz
    for(int i = 0; i < imagem.l; i++){
        for(int j = 0; j < imagem.c; j++){

            int a = imgI[i][j];
            int b = imgS[i][j];

            M[a][b] += 1;
        }
    }

    int max = imagem.maxValue + 1;

    // Pegar o maior valor
    int maiorValor = 0;
    for(int i = 0; i < max; i++){
        for(int j = 0; j < max; j++){

            if(M[i][j] > maiorValor){
                maiorValor = M[i][j];
            }
            
        }
    }

    // Salvando a matriz em um arquivo
    FILE *scm = NULL;

    if(!(scm = fopen("matrizSCM.pgm", "w"))){
        perror("\nNão foi possível abrir arquivo.\n");
        exit(10);
    }

    fprintf(scm, "%s\n", imagem.tipo);
    fprintf(scm, "%d %d\n",max, max);
    fprintf(scm, "%d\n", maiorValor);

    for(int i = 0; i < imagem.maxValue; i++){
        for(int j = 0; j < imagem.maxValue; j++){

            fprintf(scm, "%d ", M[i][j]);

        }

        fprintf(scm, "\n");

    }
    fclose(scm);

}