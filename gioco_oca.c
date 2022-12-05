/*
simulazione del gioco dell'oca:

    -un dado
    -il gioco deve gestire 5 giocatori
    -per ogni giocatore:
        -nome
        -posizione
        -vittoria
    -gioco
        -tirare il dado
        -muovere il giocatore
        -controllare se il giocatore ha vinto
        -se il giocatore ha vinto, terminare il gioco
        -se il giocatore non ha vinto, continuare il gioco

    il giocatore vince se arriva alla casella 60
    il giocatore va avanti di un numero di caselle pari al numero uscito dal dado se risponde correto alla domanda
    la domanda viene generata in modo casuale
    il dado va da 1 a 6
    il giocatore si muove di un numero di caselle pari al valore del dado
    a ogni turno, viene stampato il tabellone con le posizioni dei giocatori aggiornate
    il tabellone viene stampato ogni volta che un giocatore muove
    */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GIOCATORI 5
#define NUM_CASELLE 60
#define RISPOSTA_OK -1

typedef struct {
    char nome[20];
    int posizione;
    int vittoria;
} giocatore;

/*----global------*/
int risposta;
int dado;
/*----------------*/

/*--------------prototipi-------------*/
void stampa_tabellone(giocatore giocatori[]);
void genera_domanda();
void genera_dado();
void muovi_giocatore(giocatore *g);
void controlla_vittoria(giocatore *g);
/*------------------------------------*/

int main() {
    giocatore giocatori[NUM_GIOCATORI];
    int i;

    srand(time(NULL));

    for (i = 0; i < NUM_GIOCATORI; i++) {
        printf("Inserisci il nome del giocatore %d: ", i + 1);
        scanf("%s", giocatori[i].nome);
        giocatori[i].posizione = 0;
        giocatori[i].vittoria = 0;
    }
    
    while (1) {
        for (i = 0; i < NUM_GIOCATORI; i++) {
            if (giocatori[i].vittoria == 0) {
                printf("E' il turno di %s\n", giocatori[i].nome);
                genera_domanda();
                genera_dado();
                muovi_giocatore(&giocatori[i]);
                controlla_vittoria(&giocatori[i]);
                stampa_tabellone(giocatori);
            }
        }
    }
    return 0;
}

void stampa_tabellone(giocatore giocatori[]) {
    int i, j;

    for (i = 0; i < NUM_GIOCATORI; i++) {
        for (j = 0; j < NUM_CASELLE; j++) {
            if (giocatori[i].posizione == j) {
                printf("%s ", giocatori[i].nome);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

void genera_domanda() {
    int domanda;

    domanda = rand() % 3;

    switch (domanda) {
        case 0:
            printf("Quanto fa 2 + 2? ");
            scanf("%d", &risposta);
            if (risposta == 4) {
                printf("Risposta corretta!\n");
                risposta=RISPOSTA_OK;
            } else {
                printf("Risposta sbagliata!\n");
            }
            break;
        case 1:
            printf("Quanto fa 3 + 3? ");
            scanf("%d", &risposta);
            if (risposta == 6) {
                printf("Risposta corretta!\n");
                risposta=RISPOSTA_OK;
            } else {
                printf("Risposta sbagliata!\n");
            }
            break;
        case 2:
            printf("Quanto fa 4 + 4? ");
            scanf("%d", &risposta);
            if (risposta == 8) {
                printf("Risposta corretta!\n");
                risposta=RISPOSTA_OK;
            } else {
                printf("Risposta sbagliata!\n");
            }
            break;
    }
}

void genera_dado() {
    dado = rand() % 6 + 1;

    /*printf con testo in grassetto*/
    printf("\033[1m");
    printf("Il dado ha fatto %d\n", dado);
    printf("\033[0m");
}

void muovi_giocatore(giocatore *g) {

    if (risposta == -1) {
        g->posizione += dado;
    } else {
        g->posizione += 0;
    }
}

void controlla_vittoria(giocatore *g) {
    if (g->posizione >= NUM_CASELLE) {
        g->vittoria = 1;
        printf("Il giocatore %s ha vinto!\n", g->nome);
        exit(0);
    }
}








