#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    int NumCaracterTexto = 0, NumEspaço = 0, NumPalavras = 0, Ponto = 0, PontoFinal = 0, Esclamação = 0, PontoEsclamação = 0,
    Interrogação = 0, PontoInterrogação = 0;

    float L = 0, S = 0, NumeroCaracter = 0, Frases = 0;

    float indice = 0;

    string texto = get_string("Digite o testo para análise: \n");

    while (texto[NumCaracterTexto] != '\0')
    {
        ++NumCaracterTexto;
    }

    while (texto[NumEspaço] != '\0')
    {++NumEspaço;
        if(texto[NumEspaço] == ' '  || texto[NumEspaço] == '"')
        {
            ++NumPalavras;
        }
    }
    NumCaracterTexto = NumCaracterTexto - NumPalavras;
    NumPalavras = NumPalavras + 1;

    while (texto[Ponto] != '\0')
    {++Ponto;
        if (texto[Ponto] == '.')
        {
            ++PontoFinal;
        }
    }

    while (texto[Esclamação] != '\0')
    {++Esclamação;
        if (texto[Esclamação] == '!')
        {
            ++PontoEsclamação;
        }
    }

    while (texto[Interrogação] != '\0')
    {++Interrogação;
        if (texto[Interrogação] == '?')
        {
            ++PontoInterrogação;
        }
    }

    NumeroCaracter = NumCaracterTexto;
    Frases = PontoFinal + PontoEsclamação + PontoInterrogação;

    /* Indice de Coleman-Liau
    indice = (0.0588 * L) - (0.296 * S) - 15.8 */

    L = (NumeroCaracter / NumPalavras) * 100;
    S = (Frases / NumPalavras) * 100;

    printf("L = %f \n", L);
    printf("S = %f \n", S);

    indice = (((0.0588 * L) - (0.296 * S)) - 15.8);

    if (indice <= 1)
    {
        printf("Grade 1 \n");
    }
    else
    {
    printf("Grade %0.f \n", indice);
    }
    printf("O texto possuí %i caracter \n", NumCaracterTexto);
    printf("O texto possuí %i palavras \n", NumPalavras);
    printf("O texto possuí %0.f frases \n", Frases);
}