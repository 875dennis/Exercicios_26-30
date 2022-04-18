//Grupo C05 - Alunos: Dennis Almeida, Lucas do Nascimento, Tatiana Gonçalves

#define ex5

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef ex1
/*
1 - Escreva um programa que receba via teclado 2 numeros inteiros e
    imprima-os no video com o resultado das 4 operacoes aritmeticas.
*/

main()
{
    setlocale(LC_ALL,"");

    int num1, num2;
    char sair;
do{
    printf("Digite dois números\n");
    printf("1º número: ");
    scanf("%d",&num1);
    printf("2º número: ");
    scanf("%d",&num2);

    operacoes(num1,num2);

    printf("\n\nDeseja continuar? (s/n): ");
    scanf("%s",&sair);
    getchar();
}while((sair=='s') || (sair=='S'));

    printf("\t\tFIM DO PROGRAMA\n\n");
}

int operacoes(int num1, int num2)
{
    int soma,sub,mult;
    float divisao;

    soma = num1 + num2;
    sub = num1 - num2;
    mult = num1 * num2;
    divisao = (float)num1 / num2;

    printf("\nAs operações aritméticas e os resultados são: \n");
    printf("\tSoma: %d\n",soma);
    printf("\tSubtração: %d\n",sub);
    printf("\tMultiplicação: %d\n",mult);
    printf("\tDivisão: %.2f\n",divisao);
}

#endif // ex1


#ifdef ex2

/*
2 - Reescreva o exercicio anterior utilizando operadores de atribuicao
    composta.
*/

main()
{
    setlocale(LC_ALL,"");

    int num1, num2;
    char sair;
do{
    printf("Digite dois números\n");
    printf("1º número: ");
    scanf("%d",&num1);
    printf("2º número: ");
    scanf("%d",&num2);

    operacoes(num1,num2);

    printf("\n\nDeseja continuar? (s/n): ");
    scanf("%s",&sair);
    getchar();
}while((sair=='s') || (sair=='S'));

    printf("\t\tFIM DO PROGRAMA\n\n");

}

int operacoes(int num1, int num2)
{
    int soma=num1,sub=num1,mult=num1;
    float divisao=num1;

    soma += num2;
    sub -= num2;
    mult *= num2;
    divisao /= num2;

    printf("\nAs operações aritméticas e os resultados são: \n");
    printf("\tSoma: %d\n",soma);
    printf("\tSubtração: %d\n",sub);
    printf("\tMultiplicação: %d\n",mult);
    printf("\tDivisão: %.2f\n",divisao);

}

#endif // ex2

#ifdef ex3
/*
3 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
    data (dia, mes e ano) atual.
*/

int validarData(int dia, int mes, int anoNasc, int anoAtual) {
    if(dia <= 0 || dia > 31) {
        printf("Dia invalido! \n");
        return 1;
    }
    if(mes <= 0 || mes > 12) {
        printf("Mes invalido! \n");
        return 1;
    }
    if(anoNasc < 1900 || anoNasc > anoAtual) {
        printf("Ano invalido ou menor que 1900!\n");
        return 1;
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL,"");

        int diaNascimento, diaAtual, mesNascimento, mesAtual, anoNascimento, anoAtual, dias = 0;
        int idade[3] = {0,0,0}, contMes_Atual, contMes_Nascimento;
        int diasDosMeses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        char sair;
do{
        do {
            printf("Digite o dias do seu nascimento:\n");
            scanf("%d", &diaNascimento);
            printf("Digite o mês que você nasceu:\n");
            scanf("%d", &mesNascimento);
            printf("Digite o ano que você nasceu:\n");
            scanf("%d", &anoNascimento);
        }while( validarData(diaNascimento, mesNascimento, anoNascimento, anoNascimento) );
        do{
            printf("\nDigite o dia atual:\n");
            scanf("%d", &diaAtual);
            printf("Digite o mes atual:\n");
            scanf("%d", &mesAtual);
            printf("Digite o ano atual:\n");
            scanf("%d", &anoAtual);
        }while( validarData(diaAtual, mesAtual, anoNascimento, anoAtual) );

        if(diaAtual > diaNascimento) {
           dias += diaAtual - diaNascimento;
        }
        if (diaNascimento > diaAtual) {
            int diasMeses = 0, rest = 0;
            diasMeses = diasDosMeses[mesNascimento-1];
            rest = diasMeses - (diaNascimento - diaAtual);
            dias += rest - diasMeses;
        }
        idade[0] = dias;

        for (contMes_Atual = 0; contMes_Atual < mesAtual - 1; contMes_Atual++) {
            dias += diasDosMeses[contMes_Atual];
        }

        int diasRestantesDoAno = 0;
        for (contMes_Nascimento = 0; contMes_Nascimento< mesNascimento - 1; contMes_Nascimento++) {
            diasRestantesDoAno += diasDosMeses[contMes_Nascimento];
        }
        idade[1] = contMes_Atual + 12 - contMes_Nascimento;
        dias += 365 - diasRestantesDoAno;

        int anos = anoAtual - anoNascimento;
        idade[2] = anos - 1;
        dias += (anos-1) * 365 + anos / 4;

        printf("\nIdade: %i anos, %i meses e %i dias. \n", idade[2], idade[1], idade[0]);
        printf("\nBonus");
        printf("\nPassou por %i anos bissextos:", (anos / 4) );
        printf("\nBonus: vc viveu %i dias\n", dias);

    printf("\n\nDeseja continuar? (s/n): ");
    scanf("%s",&sair);
    getchar();
}while((sair=='s') || (sair=='S'));

 printf("\t\tFIM DO PROGRAMA\n\n");

}

#endif // ex3

#ifdef ex4
/*
4 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
    video no formato decimal e hexadecimal.
*/

main()
{
    setlocale(LC_ALL,"");

    int num1,num2;
    char sair;

do{
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    printf("\n\nOs númeors digitados foram %d e %d\n",num1,num2);
    printf("Operador bit a bit AND\n");
    printf("Decimal: %d\n",num1&num2);
    printf("Hexadecimal: 0x%x\n\n",num1&num2);

    printf("Operador bit a bit OU\n");
    printf("Decimal: %d\n",num1|num2);
    printf("Hexadecimal: 0x%x\n\n",num1|num2);

    printf("Operador bit a bit OU EXCLUSIVO\n");
    printf("Decimal: %d\n",num1^num2);
    printf("Hexadecimal: 0x%x\n\n",num1^num2);

    printf("\n\nDeseja continuar? (s/n): ");
    scanf("%s",&sair);
    getchar();
}while((sair=='s') || (sair=='S'));

 printf("\t\tFIM DO PROGRAMA\n\n");

}

#endif // ex4


#ifdef ex5
/*
5 - Escreva um programa que receba via teclado um valor e tenha o menu abaixo.
       1 - transforma graus Celsius em Fahrenheit e Kelvin
       2 - transforma graus Fahrenheit em Celsius e Kelvin
       3 - transforma graus Kelvin em Celsius e Fahrenheit
    Cada opcao de menu deve chamar uma funcao que retorna o resultado da
    conversao. O resultado deve ser mostrado na funcao main().
*/
float celsiusFahr(float graus)
{
    float result;

    result = (graus * 9/5) + 32;
    return result;
}

float celsiusKelvin(float graus)
{
    float result;

    result = graus + 273.15;
    return result;
}

float fahrCelsius(float graus)
{
    float result;

    result = (graus - 32) * 5/9 ;
    return result;
}

float fahrKelvin(float graus)
{
    float result;

    result = (graus - 32) * 5/9 + 273.15;
    return result;
}

float kelvinCelsius(float graus)
{
    float result;

    result = graus - 273.15;
    return result;
}

float kelvinFahr(float graus)
{
    float result;

    result = (graus - 273.15) * 9/5 + 32;
    return result;
}

main()
{
    setlocale(LC_ALL,"");

    float graus,conv1,conv2;
    int opcao;
    char sair;

do{
    printf("\nEscolha uma das opções abaixo\n\n");
    printf("\t1 - transforma graus Celsius em Fahrenheit e Kelvin\n");
    printf("\t2 - transforma graus Fahrenheit em Celsius e Kelvin\n");
    printf("\t3 - transforma graus Kelvin em Celsius e Fahrenheit\n\n");
    printf("Digite a opcão dejesada: ");
    scanf("%d",&opcao);

    switch(opcao)
    {
        case 1:
            printf("\nDigite o graus Celsius: ");
            scanf("%f",&graus);

            conv1 = celsiusFahr(graus);
            conv2 = celsiusKelvin(graus);

            printf("\n%.2f Graus Celsius para Fahrenheit: %.2f\n",graus,conv1);
            printf("%.2f Graus Celsius para Kelvin: %.2f\n\n",graus,conv2);
            break;

        case 2:
            printf("\nDigite o graus Fahrenheit: ");
            scanf("%f",&graus);

            conv1 = fahrCelsius(graus);
            conv2 = fahrKelvin(graus);

            printf("\n%.2f Graus Fahrenheit para Celsius: %.2f\n",graus,conv1);
            printf("%.2f Graus Fahrenheit para Kelvin: %.2f\n\n",graus,conv2);
            break;

        case 3:
            printf("\nDigite o graus Kelvin: ");
            scanf("%f",&graus);

            conv1 = kelvinCelsius(graus);
            conv2 = kelvinFahr(graus);

            printf("\n%.2f Graus Kelvin para Celsius: %.2f\n",graus,conv1);
            printf("%.2f Graus Kelvin para Fahrenheit: %.2f\n\n",graus,conv1);
            break;

        default:
            printf("Opção inválida\n");
    }

    printf("\n\nDeseja continuar? (s/n): ");
    scanf("%s",&sair);
    getchar();
}while((sair=='s') || (sair=='S'));

    printf("\t\tFIM DO PROGRAMA\n\n");
}

#endif // ex5
