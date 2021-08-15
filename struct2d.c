
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
//Definindo a struct
struct ponto2d {
       float x;
       float y;
};
 
//Prototipos
struct ponto2d definir_ponto();
void mostrar_distancia(struct ponto2d ponto_inicial, struct ponto2d ponto_final);
 
int main()
{
       //Definindo variaveis iniciais
       int opcao = 0;
       struct ponto2d ponto_inicial = { 0,0 };
       struct ponto2d ponto_final = { 0,0 };
 
       //Loop principal
       while (opcao != 4)
       {
             //Menu
             printf("[1] - Digitar os valores do primeiro ponto\n");
             printf("[2] - Digitar os valores do segundo ponto\n");
             printf("[3] - Mostrar a distância entre os pontos\n");
             printf("[4] - Sair\n");
             scanf_s("%d", &opcao);
 
             if (opcao == 1) {
                    ponto_inicial = definir_ponto();
             }
             else if (opcao == 2) {
                    ponto_final = definir_ponto();
             }
             else if (opcao == 3) {
                    mostrar_distancia(ponto_inicial, ponto_final);
             }
             else if (opcao == 4) continue;
             else printf("Opcao invalida!");
       }
}
 
//Funcao para definir o ponto
struct ponto2d definir_ponto()
{
       struct ponto2d ponto;
       printf("Defina o x do ponto: ");
       scanf_s("%f", &ponto.x);
       printf("Defina o y do ponto: ");
       scanf_s("%f", &ponto.y);
       return ponto;
}
 
//Funcao que calcula a distancia
void mostrar_distancia(struct ponto2d ponto_inicial, struct ponto2d ponto_final)
{
       float distancia = 0;
 
       //Convertendo para float, pois pow e sqrt retornam double
       float calc_x = (float)pow((float)ponto_inicial.x - (float)ponto_final.x, 2);
       float calc_y = (float)pow((float)ponto_inicial.y - (float)ponto_final.y, 2);
       distancia = (float)sqrt((float)calc_x + (float)calc_y);
 
       printf("%f\n", distancia);
}
