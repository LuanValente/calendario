#include <stdio.h>

int main() {
    // Obter o ano e o mês do usuário
    int ano, mes;
    printf("Digite o ano: ");
    scanf("%d", &ano);
    printf("Digite o mes (1 a 12): ");
    scanf("%d", &mes);

    // Definir o primeiro dia da semana do mês
    int primeiroDia = ((ano - 1) * 365 + (ano - 1) / 4 - (ano - 1) / 100 + (ano - 1) / 400 + 1) % 7;

    // Definir o número de dias no mês
    int numDias;
    if (mes == 2) {
        if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
            numDias = 29;
        } else {
            numDias = 28;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        numDias = 30;
    } else {
        numDias = 31;
    }

    // Imprimir o calendário
    printf("\n");
    printf("        %s %d\n", mes == 1 ? "Janeiro" : mes == 2 ? "Fevereiro" : mes == 3 ? "Março" : mes == 4 ? "Abril" : mes == 5 ? "Maio" : mes == 6 ? "Junho" : mes == 7 ? "Julho" : mes == 8 ? "Agosto" : mes == 9 ? "Setembro" : mes == 10 ? "Outubro" : mes == 11 ? "Novembro" : "Dezembro", ano);
    printf(" Dom Seg Ter Qua Qui Sex Sab\n");

    int dia;
    for (dia = 1; dia <= numDias; dia++) {
        if (dia == 1) {
            int i;
            for (i = 0; i < primeiroDia; i++) {
                printf("    ");
            }
        }
        printf("%4d", dia);
        if ((dia + primeiroDia) % 7 == 0 || dia == numDias) {
            printf("\n");
        }
    }

    return 0;
}