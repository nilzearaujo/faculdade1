#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
void calc_hexa(float L, float* area, float* perimetro);
 
int main()
{
       float lado, area, perimetro;
       lado = area = perimetro = 0;
 
       while (lado >= 0)
       {
             printf("Digite o lado do hexagono: ");
             scanf_s("%f", &lado);
             if (lado <= 0) continue;
             calc_hexa(lado, &area, &perimetro);
 
             printf("A area é: %f e o perimetro é: %f\n", area, perimetro);
       }
}
 
void calc_hexa(float L, float* area, float* perimetro)
{
       *perimetro = 6 * L;
 	//Variaveis para facilitar o calculo
       float raiz_de_3 = sqrt(3);
       float lado_quadrado = pow(L, 2);
//Calculo da area utilizando as variaveis anteriores
       *area = (3 * lado_quadrado * raiz_de_3) / 2;
}
