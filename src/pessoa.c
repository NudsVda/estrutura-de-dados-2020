#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

Pessoa* cria_pessoa(char *nome,struct tm data_nascimento) 
{
    Pessoa* p = (Pessoa*) malloc (sizeof(Pessoa));
    if (p == NULL) {
        printf ("Memória insuficiente\n");
        exit(1);
    }
    p->nome = nome;    
    p->data_nascimento = data_nascimento;
    return p;
}

int calcula_idade(Pessoa* pessoa)
{    
    time_t hoje = time(0);       
    
    time_t convertido = mktime(&pessoa->data_nascimento);          
    return floor(difftime(hoje,convertido) / 60 / 60 / 24 / 365);
}

char* inverte_nome(Pessoa* pessoa)
{
    char *invertido;
    int i = 0, j = 0, k = 0;
    int posicao_espaco = 0;

    char *nome = pessoa->nome;
    while(i < strlen(nome) || posicao_espaco == 0 ) {
        if (nome[i] == ' ') {
            posicao_espaco = i;
        }
        i++;        
    }
    j = posicao_espaco + 1;
    i = 0;
    while (j > posicao_espaco & j < strlen(nome))
    {
        invertido[i] = nome[j];
        i++;
        j++;
    }
    invertido[i++] = ' ';
    j = 0;
    while (j < posicao_espaco) {
        invertido[i++] = nome[j];
        j++;        
    }
    
    return invertido;

}