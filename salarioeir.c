
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
 
       char nome[256];
       float salario, deducao, imposto_devido;
       printf("Digite seu nome: ");
       scanf_s("%s", nome, 256);
       while (1)
       {
             printf("Digite seu salario: ");
             scanf_s("%f", &salario);
 		
//Calcula a deducao de acordo com a faixa de salario
             if (salario <= 1637.11f) {
                    deducao = 0;
             }
             else if (salario <= 2453.50f) {
                    deducao = salario * 0.075f;
             }
             else if (salario <= 3271.38f) {
                    deducao = salario * 0.15f;
             }
             else if (salario <= 4087.65f) {
                    deducao = salario * 0.225f;
             }
             else {
                    deducao = salario * 0.25f;
             }
//Diminui do salario a deducao, para conseguir o imposto devido
             imposto_devido = salario - deducao;
             printf("Sua dedução é de %f\n", deducao);
             printf("Seu imposto devido é %f\n", imposto_devido);
       }
}
