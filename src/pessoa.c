#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    return round(difftime(hoje,convertido) / 60 / 60 / 24 / 365);
}

const char *inverte_nome(Pessoa* pessoa)
{
    return "a";
}