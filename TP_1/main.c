#include <stdio.h>
#include <stdlib.h>
#include "funcionesTP1.h"

int main()
{
    float num1, num2;
    int opcion, flag1=0, flag2=0;
    do
    {
        if(flag1==1 && flag2==0)
        {
            printf("\n1.Ingresar 1er operando(A=%.2f)\n2.Ingresar 2do operando(B=y)\n3.Calcular la suma(A+B)\n4.Calcular la resta(A-B)\n5.Calcular la division(A/B)\n6.Calcular la multiplicacion(A*B)\n7.Calcular el factorial(A!)\n8.Calcular todas las operaciones\n9.Salir\nElija una opcion: ",num1);
        }
        else if(flag2==1 && flag1==0)
        {
            printf("\n1.Ingresar 1er operando(A=x)\n2.Ingresar 2do operando(B=%.2f)\n3.Calcular la suma(A+B)\n4.Calcular la resta(A-B)\n5.Calcular la division(A/B)\n6.Calcular la multiplicacion(A*B)\n7.Calcular el factorial(A!)\n8.Calcular todas las operaciones\n9.Salir\nElija una opcion: ",num2);
        }
        else if(flag1==1 && flag2==1)
        {
            printf("\n1.Ingresar 1er operando(A=%.2f)\n2.Ingresar 2do operando(B=%.2f)\n3.Calcular la suma(A+B)\n4.Calcular la resta(A-B)\n5.Calcular la division(A/B)\n6.Calcular la multiplicacion(A*B)\n7.Calcular el factorial(A!)\n8.Calcular todas las operaciones\n9.Salir\nElija una opcion: ",num1,num2);
        }
        else
        {
            printf("\n1.Ingresar 1er operando(A=x)\n2.Ingresar 2do operando(B=y)\n3.Calcular la suma(A+B)\n4.Calcular la resta(A-B)\n5.Calcular la division(A/B)\n6.Calcular la multiplicacion(A*B)\n7.Calcular el factorial(A!)\n8.Calcular todas las operaciones\n9.Salir\nElija una opcion: ");
        }
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1: system("cls");
                    printf("Ingrese 1er operando: ");
                    scanf("%f",&num1);
                    flag1=1;
                    break;
            case 2: system("cls");
                    printf("Ingrese 2do operando: ");
                    scanf("%f",&num2);
                    flag2=1;
                    break;
            case 3: system("cls");
                    if(flag1==1 && flag2==1)
                    {
                        printf("\nLa suma es: %.2f",suma(num1,num2));
                    }
                    else
                    {
                        printf("\nDebe ingresar 2 operandos.");
                    }
                    break;
            case 4: system("cls");
                    if(flag1==1 && flag2==1)
                    {
                        printf("\nLa resta es: %.2f",resta(num1,num2));
                    }
                    else
                    {
                        printf("\nDebe ingresar 2 operandos.");
                    }
                    break;
            case 5: system("cls");
                    if(flag1==1 && flag2==1)
                    {
                        if(num2==0)
                        {
                            printf("\nNo se puede divir por cero.\n");
                        }
                        else
                        {
                          printf("\nLa division es: %.2f",division(num1,num2));
                        }
                    }
                    else
                    {
                        printf("\nDebe ingresar 2 operandos.");
                    }
                    break;
            case 6: system("cls");
                    if(flag1==1 && flag2==1)
                    {
                        printf("\nLa multiplicacion es: %.2f",multiplicacion(num1,num2));
                    }
                    else
                    {
                        printf("\nDebe ingresar 2 operandos.");
                    }
                    break;
            case 7: system("cls");
                    if(flag1==1)
                    {
                        if(factorial(num1)!=0)
                        {
                          printf("\nEl factorial es: %d",factorial(num1));
                        }
                    }
                    else
                    {
                        printf("\nDebe ingresar el 1er operando.");
                    }
                    break;
            case 8: system("cls");
                    if(flag1==1 && flag2==1)
                    {
                        printf("\nLa suma es: %.2f\n",suma(num1,num2));
                        printf("\nLa resta es: %.2f\n",resta(num1,num2));
                        if(num2==0)
                        {
                            printf("\nNo se puede divir por cero.\n");
                        }
                        else
                        {
                          printf("\nLa division es: %.2f\n",division(num1,num2));
                        }
                        printf("\nLa multiplicacion es: %.2f\n",multiplicacion(num1,num2));
                        if(factorial(num1)!=0)
                        {
                          printf("\nEl factorial es: %d",factorial(num1));
                        }
                    }
                    else
                    {
                        printf("\nDebe ingresar 2 operandos.");
                    }
                    break;
            case 9: printf("\nSalir\n");
                    break;
            default: system("cls");
                     printf("\nLa opcion no es valida\n");
                     break;
        }
        printf("\n-------------------------------------\n");
        system("pause");
        system("cls");
    }while(opcion!=9);

    return 0;
}
