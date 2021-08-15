#include <stdio.h>
#include <stdlib.h>
 
//Quantidade de cada peca
int peoes = 0;
int cavalos = 0;
int torres = 0;
int bispos = 0;
int reis = 0;
int rainhas = 0;
 
//Prototipos
void mostrar_tabuleiro(int[8][8]);
int escolher_peca();
void botar_peca_tabuleiro(int peca, int tabuleiro[8][8]);
 
int main()
{
       int tabuleiro[8][8];
//Inicializando a matriz
       for (int x = 0; x < 8; x++) {
             for (int y = 0; y < 8; y++) {
                    tabuleiro[x][y] = 0;
             }
       }
 //Loop principal
       while (1) {
             int opcao;
 		//Menu
             printf("(1) Botar peça no tabuleiro\n");
             printf("(2) Mostrar tabuleiro\n");
             printf("(3) Quantidade de peças\n");
             printf("(4) Sair\n");
             printf("> ");
             scanf_s("%d", &opcao);
 
             if (opcao == 1) {
                    printf("Escolha uma peça:\n");
                    int peca = escolher_peca();
                    printf("Escolha onde botar no tabuleiro\n");
                    botar_peca_tabuleiro(peca, tabuleiro);
             }
             else if (opcao == 2) {
                    mostrar_tabuleiro(tabuleiro);
             }
             else if (opcao == 3) {
                    printf("Quantidade de peças:\n");
                    printf("Peões: %d\nCavalos: %d\nTorres: %d\nBispos: %d\nReis: %d\nRainhas: %d\n\n", peoes, cavalos, torres, bispos, reis, rainhas);
             }
             else if (opcao == 4) {
                    break;
             }
             else {
                    printf("Opção inválida!\n");
             }
 
       }
 
       printf("\n");
       system("pause");
       return 1;
}
 
 //Funcao que mostra o tabuleiro na tela
void mostrar_tabuleiro(int tabuleiro[8][8])
{
       printf("Peças:\n");
       printf("0: Vazio\n1: Peão\n2: Cavalo\n3: Torre\n4: Bispo\n5: Rei\n6: Rainha\n\n");
 	
//For aninhado para percorrer toda matriz e mostrar na tela
       for (int x = 0; x < 8; x++) {
             for (int y = 0; y < 8; y++) {
                    int peca = tabuleiro[x][y];
                    printf("%d", peca);
             }
             printf("\n");
       }
       printf("\n");
}
 //Funcao para escolher a peca
int escolher_peca()
{
       int peca = 0;
       printf("Peças:\n");
       printf("0: Vazio\n1: Peão\n2: Cavalo\n3: Torre\n4: Bispo\n5: Rei\n6: Rainha\n\n");
       printf("Escolha a peça:\n");
       printf(">");
       scanf_s("%d", &peca);
       return peca;
}
 //Funcao para botar peca no tabuleiro
void botar_peca_tabuleiro(int peca, int tabuleiro[8][8])
{
       int x = 0;
       int y = 0;
       printf("Escolha uma posição valida para X (0-7)\n");
       scanf_s("%d", &x);
	//Verifica se a posicao é valida
       while (x < 0 || x > 7) {
             printf("Posição inválida! Por favor, um numero entre 0 e 7: ");
             scanf_s("%d", &x);
       }
       printf("Escolha uma posição valida para Y (0-7)\n");
       scanf_s("%d", &y);
       while (y < 0 || y > 7) {
             printf("Posição inválida! Por favor, um numero entre 0 e 7: ");
             scanf_s("%d", &y);
       }
 
       //Aumenta peça escolhida
       if (peca == 1)peoes++;
       else if (peca == 2)cavalos++;
       else if (peca == 3)torres++;
       else if (peca == 4)bispos++;
       else if (peca == 5)reis++;
       else if (peca == 6)rainhas++;
 
       //Diminui peça substituida
       int peca_atual = tabuleiro[x][y];
       if (peca_atual == 1)peoes--;
       else if (peca_atual == 2)cavalos--;
       else if (peca_atual == 3)torres--;
       else if (peca_atual == 4)bispos--;
       else if (peca_atual == 5)reis--;
       else if (peca_atual == 6)rainhas--;
 
       tabuleiro[x][y] = peca;
}
