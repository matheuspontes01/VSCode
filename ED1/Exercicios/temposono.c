#include <stdio.h>
#include <stdlib.h>

int calcular_minutos(int hora_atual, int minuto_atual, int hora_alarme, int minuto_alarme) {
    int tempo = 0;
    if (hora_atual < 0 || hora_alarme < 0) {
        printf("hora invalida.\n");
        return 0;
    }
    if (minuto_atual < 0 || minuto_alarme < 0) {
        printf("minuto invalido.\n");
        return 0;
    }

    hora_atual = hora_atual*60;
    hora_alarme = hora_alarme*60;

    int horario_atual = hora_atual + minuto_atual;
    int horario_alarme = hora_alarme + minuto_alarme;

    if (horario_alarme - horario_atual < 0) {
        horario_atual = 1440 - horario_atual;
        tempo = horario_alarme + horario_atual;
    } else {
        tempo = horario_alarme - horario_atual;
    } 

    return tempo;
}

int main() {
    int H1, M1, H2, M2;
    char op;
    while (1) {
        printf("Hora atual / Minuto atual | Hora do alarme programado / Minuto do alarme programado: \n");
        scanf("%d %d %d %d", &H1, &M1, &H2, &M2);

        if (H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0) {
            break;
        }

        if ((H1 > 23 || M1 > 59) || (H2 > 23 || M2 > 59)) {
            printf("Entrada invalida\n");
            continue;
        }

        printf("Tempo para descanso: %d\n", calcular_minutos(H1, M1, H2, M2));
    } 
    return 0;
}