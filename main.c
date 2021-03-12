/* N�O MODIFIQUE O C�DIGO ABAIXO */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

   /* prototypes */
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[]);
void print_deck(const int wDeck[][13], const char* wFace[], const char* wSuit[], const int Ncolumns);

/* N�O MODIFIQUE O C�DIGO ACIMA */

/* Constantes */

// A constante Num_Colunas define o valor de Ncolums,
// � um dos valores passados para a fun��o print_deck
// Voc� pode e deve modificar este valor desta constante
// para testar o seu c�digo da fun��o print_deck

#define Num_Colunas 2

/* N�O MODIFIQUE O C�DIGO ABAIXO */

int main(int argc, char** argv)
{
    /* initialize suit array */
    const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

    /* initialize face array */
    const char* face[13] =
    { "Ace", "Deuce", "Three", "Four",
      "Five", "Six", "Seven", "Eight",
      "Nine", "Ten", "Jack", "Queen", "King" };

    /* initialize deck array */
    int deck[4][13] = { 0 };

    /* definida a quantidade de colunas para impress�o */
    int Ncolunas = Num_Colunas;

    /* suporte ao script de testes */
    // argv[1] string com a quantidade de colunas
    // argv[2] string com o argumento do suporte ao scrit de testes
    // argv[3] string com as posi��es das cartas no deck
    if (*argv[1] == '1') {
        Ncolunas = atoi(argv[2]);
        char* deckchar = argv[3];
        char buffer[3] = "";
        int u, v = 0, n = 0;
        for (u = 0; deckchar[u] != '\0'; ++u) {
            if (deckchar[u] == ' ') {
                buffer[v] = '\0';
                deck[n / 13][n % 13] = atoi(buffer);
                n++;
                v = 0;
            }
            else if (deckchar[u] < '0' || deckchar[u] > '9') {
                break;
            }
            else {
                buffer[v] = deckchar[u];
                v++;
            }
        }
        if (n < 52) {
            buffer[v] = '\0';
            deck[n / 13][n % 13] = atoi(buffer);
        }
       
    }
    else {
        srand(time(0)); /* seed random-number generator */
        shuffle(deck);
    }
    
    print_deck(deck, face, suit, Ncolunas);

    return 0; /* indicates successful termination */

} /* end main */

/* shuffle cards in deck */
void shuffle(int wDeck[][13])
{
    int row;    /* row number */
    int column; /* column number */
    int card;   /* counter */

    /* for each of the 52 cards, choose slot of deck randomly */
    for (card = 1; card <= 52; card++) {

        /* choose new random location until unoccupied slot found */
        do {
            row = rand() % 4;
            column = rand() % 13;
        } while (wDeck[row][column] != 0); /* end do...while */

        /* place card number in chosen slot of deck */
        wDeck[row][column] = card;
    } /* end for */

} /* end function shuffle */

/* deal cards in deck */
void deal(const int wDeck[][13], const char* wFace[],
    const char* wSuit[])
{
    int card;   /* card counter */
    int row;    /* row counter */
    int column; /* column counter */

    /* deal each of the 52 cards */
    for (card = 1; card <= 52; card++) {

        /* loop through rows of wDeck */
        for (row = 0; row <= 3; row++) {

            /* loop through columns of wDeck for current row */
            for (column = 0; column <= 12; column++) {

                /* if slot contains current card, display card */
                if (wDeck[row][column] == card) {
                    fprintf(stderr, "%5s of %-8s%c", wFace[column], wSuit[row],
                        card % 2 == 0 ? '\n' : '\t');
                } /* end if */

            } /* end for */

        } /* end for */

    } /* end for */

} /* end function deal */

void print_deck(const int wDeck[][13], const char* wFace[], const char* wSuit[], const int Ncolumns) {

    /* N�O MODIFIQUE O C�DIGO ACIMA */

    /* Apague a linha abaixo com a chamada da fun��o deal e ...*/

    deal(wDeck, wFace, wSuit); // Esta chamada de fun��o s� est� aqui como exemplo.

    /* ... implemente o corpo da fun��o print_deck */

    /* N�O MODIFIQUE O C�DIGO ABAIXO */
}

/*
    INSTRU��ES PARA O EXERC�CIO

        A fun��o deal imprime imprime as cartas do monte (deck) em duas colunas. Trata-se do
    mesmo exemplo demonstrado em aula, que corresponde ao exemplo da figura 7.24 do nosso
    livro texto.
        Neste programa, um c�digo inicial � fornecido e voc� deve atentar-se para modificar
    apenas as partes do c�digo delimitadas pelos coment�rios. Este c�digo inicial possui a
    fun��o print-deck que chama a fun��o deal e reproduz o resultado do exemplo da figura 7.24
        A fun��o deal imprime as cartas em um formato onde a palavra of permanece na mesma
    posi��o para ambas as colunas de impress�o.
        Sua tarefa � implementar a fun��o print_deck que dever� imprimir o deck de cartas em uma,
    duas ou tr�s colunas, dependendo se o valor passado para o seu par�metro Ncolumns for 1, 2,
    ou 3, respectivamente. Qualquer outro valor de Ncolumns dever� resultar na impress�o em
    uma coluna.
        A fun��o print-deck dever� obedecer as mesmas regras de impress�o das colunas utilizadas
    na implementa��o da fun��o deal.
        Adicionalmente, voc� deve atentar-se para o fato que ap�s a impress�o da string relativa 
    a �ltima carta, a fun��o deve imprimir um <enter> (pula linha '\n'), como o faz no exemplo de 
    duas colunas implementado na fun��o deal.
*/