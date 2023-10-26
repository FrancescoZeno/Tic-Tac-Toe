/**================================================================================================
 * *                                           INFO
 *  Autore: Francesco Zeno
 *  @email: zkekko11@gmail.com
 *  File:   main.cpp
 *  Vers: 1.0
 *  Data:  26/10/2023
 *  Descrizione: Tic-Tac-Toe
 * ?
 *================================================================================================**/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include "supporto_grafica.h"
#define n 3
using namespace std;
Color color;
void testo();
void strutturaTris(char tab[][n]);
void griglia(char tab[][n]);
void posizione(char tab[][n], int &x, int &y);
void player(char tab[][n], int &x, int &y);
void informazioni(int &punti_1, int &punti_2, int &round);
bool logica(char tab[n][n], char simbolo);
bool oriz(char tab[n][n], char simbolo);
bool vert(char tab[n][n], char simbolo);
bool diag(char tab[n][n], char simbolo);
bool antiDiag(char tab[n][n], char simbolo);
bool piena(char tab[][n]);
int main()
{
    _UTF_16
    cl();

    char tab[n][n];
    strutturaTris(tab);

    int punti_1 = 0;
    int punti_2 = 0;
    int round = 1;
    testo();
    while (true)
    {
        cl();
        informazioni(punti_1, punti_2, round);
        griglia(tab);

        int x, y;
        posizione(tab, x, y);
        player(tab, x, y);
        if (piena(tab))
        {
            cl();
            griglia(tab);
            cout << "La partita e' finita in pareggio!" << endl;
            informazioni(punti_1, punti_2, round);
            strutturaTris(tab);
            round++;
            system("pause");
        }
        else if (logica(tab, 'X'))
        {
            cl();
            griglia(tab);
            cout << "Giocatore 1 (X) ha vinto!" << endl;
            punti_1++;
            informazioni(punti_1, punti_2, round);
            strutturaTris(tab);
            round++;
            system("pause");
        }
        else if (logica(tab, 'O'))
        {
            cl();
            griglia(tab);
            cout << "Giocatore 2 (O) ha vinto!" << endl;
            punti_2++;
            informazioni(punti_1, punti_2, round);
            strutturaTris(tab);
            round++;
            system("pause");
        }
    }
    cin.get();
    return 0;
}
void testo()
{
    cout << color.bold_on() << "Regole del gioco: " << color.bold_off() << endl;
    Sleep(300);
    cout << "\n• Il gioco e' composto da una matrice di 3x3 che deve essere riempiti con i simboli: 'X' o 'O' ";
    Sleep(300);
    cout << "\n• Ad ogni turno, scegliere un unica casella libera. ";
    Sleep(500);
    cout << "\n• Per eseguire un tris bisogna avere una combinazione di simboli (3) di fila nelle seguenti disposizioni: ";
    Sleep(300);
    cout << "\n\t‣ Orizzontale";
    Sleep(300);
    cout << " \n\t‣ Verticale";
    Sleep(300);
    cout << "\n\t‣ Diagonale";
    Sleep(200);
    cout << color.bold_on() << "\nBatti invio per iniziare a giocare . . . " << color.bold_off();
    cin.get();
    cl();
    cout << color.bold_on() << "\nBUON DIVERTIMENTO " << color.bold_off();
    Sleep(1500);
    cl();
}
void strutturaTris(char tab[][n])
{
    int conta = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tab[i][j] = conta + '0';
            ++conta;
        }
    }
}
void griglia(char tab[][n])
{
    for (int i = 0; i < n; i++)
    {
        color.foreground(GREEN);
        cout << setw(6) << " | " << setw(6) << " | " << endl;
        color.reset();
        for (int j = 0; j < n; j++)
        {
            if (tab[i][j] == 'X')
            {
                color.foreground(YELLOW);
            }
            else if (tab[i][j] == 'O')
            {
                color.foreground(RED);
            }
            cout << " " << color.bold_on() << tab[i][j] << color.bold_off();
            color.foreground(GREEN);
            if (j < n - 1)
            {
                cout << setw(4) << "  | ";
            }
            else
            {
                cout << endl;
            }
            color.reset();
        }
        if (i < n - 1)
        {
            color.foreground(GREEN);
            cout << setw(0) << "____|_____|____" << endl;
            color.reset();
        }
    }
    cout << endl;
}

void posizione(char tab[][n], int &x, int &y)
{
    cout << "Scegli una posizione (1-9) > ";
    int scelta;
    cin >> scelta;
    switch (scelta)
    {
    case 1:
        x = 0;
        y = 0;
        break;
    case 2:
        x = 0;
        y = 1;
        break;
    case 3:
        x = 0;
        y = 2;
        break;
    case 4:
        x = 1;
        y = 0;
        break;
    case 5:
        x = 1;
        y = 1;
        break;
    case 6:
        x = 1;
        y = 2;
        break;
    case 7:
        x = 2;
        y = 0;
        break;
    case 8:
        x = 2;
        y = 1;
        break;
    case 9:
        x = 2;
        y = 2;
        break;
    default:
        cout << "Scelta non valida. Riprova." << endl;
        posizione(tab, x, y);
    }
}

void player(char tab[][n], int &x, int &y)
{
    static bool alternatore = true;
    bool trv = false;
    do
    {
        if (tab[x][y] >= '0' && tab[x][y] <= '9')
        {
            trv = true;
            if (alternatore)
            {
                tab[x][y] = 'X';
            }
            else
            {
                tab[x][y] = 'O';
            }
            alternatore = !alternatore;
        }
        else
        {
            cout << "\t!!\n";
            cout << "POSIZIONE OCCUPATA\n";
            posizione(tab, x, y);
        }
    } while (!trv);
}
void informazioni(int &punti_1, int &punti_2, int &round)
{
    cout << color.bold_on() << "Roud: ";
    cout << round << color.bold_off() << endl;
    color.foreground(GREEN);
    cout << color.bold_on() << "PLY1: " << color.bold_off();
    color.reset();
    cout << color.bold_on() << punti_1 << color.bold_off();
    color.foreground(RED);
    cout << setw(8) << color.bold_on() << "PLY2: " << color.bold_off();
    color.reset();
    cout << color.bold_on() << punti_2 << color.bold_off() << endl;
    cout << color.bold_on() << "------------------\n\n"
         << color.bold_off();
}
bool oriz(char tab[n][n], char simbolo)
{
    bool trovato = false;
    int x = -1; // Inizializzato con un valore non valido

    for (int i = 0; i < n && !trovato; i++)
    {
        bool vittoria = true;
        for (int j = 0; j < n; j++)
        {
            if (tab[i][j] != simbolo)
            {
                vittoria = false;
                break; // Esci dal ciclo interno se la riga non è vincente
            }
        }

        if (vittoria)
        {
            trovato = true;
            x = i;
        }
    }

    if (trovato)
    {
        for (int j = 0; j < n; j++)
        {
            tab[x][j] = '-';
        }
    }

    return trovato;
}
bool vert(char tab[n][n], char simbolo)
{
    bool trovato = false;
    int x = -1; // Inizializzato con un valore non valido

    for (int j = 0; j < n && !trovato; j++)
    {
        bool vittoria = true;
        for (int i = 0; i < n; i++)
        {
            if (tab[i][j] != simbolo)
            {
                vittoria = false;
                break; // Esci dal ciclo interno se la colonna non è vincente
            }
        }

        if (vittoria)
        {
            trovato = true;
            x = j;
        }
    }

    if (trovato)
    {
        for (int i = 0; i < n; i++)
        {
            tab[i][x] = '|';
        }
    }

    return trovato;
}
bool diag(char tab[n][n], char simbolo)
{
    bool trovato = false;
    bool win;
    int i = 0, conta = 0, conta2 = 0;
    for (int j = 0; j < n; j++)
    {
        if (tab[i][j] == simbolo)
            conta++;
        else
            conta2++;
        i++;
    }
    if (conta == 3)
        trovato = true;
    else
        trovato = false;
    win = trovato;
    if (win)
    {
        i = 0;
        for (int j = 0; j < n; j++)
        {
            tab[i][j] = '\\';
            i++;
        }
    }
    return trovato;
}
/*================================= logica diagonale 2 ===============================*/
bool antiDiag(char tab[n][n], char simbolo)
{
    bool trovato = false;
    bool win;
    int i = n - 1, conta = 0, conta2 = 0;
    for (int j = 0; j < n; j++)
    {
        if (tab[i][j] == simbolo)
            conta++;
        else
            conta2++;
        i--;
    }
    if (conta == 3)
        trovato = true;
    else
        trovato = false;
    win = trovato;
    if (win)
    {
        i = n - 1;
        for (int j = 0; j < n; j++)
        {
            tab[i][j] = '/';
            i--;
        }
    }
    return trovato;
}
bool piena(char tab[][n])
{
    bool trovato = false;
    int conta = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tab[i][j] == 'X' || tab[i][j] == 'O')
                conta++;
        }
    }
    if (conta >= 9)
        trovato = true;
    else
        trovato = false;
    return trovato;
}
bool logica(char tab[n][n], char simbolo)
{
    bool o = oriz(tab, simbolo);
    bool v = vert(tab, simbolo);
    bool d = diag(tab, simbolo);
    bool d1 = antiDiag(tab, simbolo);
    bool p = piena(tab);
    return o || v || d || d1 || p;
}
