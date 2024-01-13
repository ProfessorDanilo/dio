#include <stdio.h>

/*fiz o programa sem auxílio do ChatGpt*/
int main ()
{
    char opcao;
    float resultado, num1, num2;
    printf("escolha a operacao (+, -, *, /)\n");
    scanf("%c", &opcao);
    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);
    printf("Digite o segundo numero: ");
    scanf("%f", &num2);
    switch(opcao)
    {
    case '+':
        resultado = num1 + num2;
        printf("O resultado da operacao e': %0.2f", resultado);
        break;
    case '-':
        resultado = num1 - num2;
        printf("O resultado da operacao e': %0.2f", resultado);
        break;
    case '*':
        resultado = num1 * num2;
        printf("O resultado da operacao e': %0.2f", resultado);
        break;
    case '/':
        if(num2==0) printf("nao se pode dividir por zero");
        else
        {
            resultado = num1 / num2;
            printf("O resultado da operacao e': %0.2f", resultado);
        }
        break;
    default:
        printf("nenhuma opcao selecionada\n");
        break ;
    }
}
