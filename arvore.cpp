/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<cstdlib>
#include<fstream>
#include <iostream>
#include <stdbool.h>
#include <string>

#include"arvore.h"

using namespace std;

Arvore::Arvore() {
    raiz = NULL;
    qtde = 0;
}

Arvore::~Arvore() {

}

void Arvore::Pre_Ordem() {
    raiz->Pre_Ordem(raiz);
}

void Arvore::Pos_Ordem() {
    raiz->Pos_Ordem(raiz);
}

void Arvore::Em_Ordem() {
    raiz->Em_Ordem(raiz);
}

void Arvore::Estado(){
    //TODO
}

void Arvore::Insere(int valor) {
    No *n = new No(valor);
    if (qtde == 0) {
        raiz = n;
        qtde++;
        return;
    }
    if (!Busca(valor)) {
        qtde++;
        raiz->Insere(raiz, n);
    }
}

bool Arvore::Busca(int valor) {
    return raiz->Busca(valor, raiz);
}

bool Arvore::Remove(int valor) {
    if (raiz->Busca(valor, raiz)) {
        return raiz->Remove(valor, raiz, NULL);
    }
    return false;
}

No * Arvore::Captura_Maximo() {
    return raiz->Captura_Maximo(raiz);
}

No::No(int valor) {
    dado = valor;
    esq = NULL;
    dir = NULL;
}

No::~No() {

}

No * No::Insere(No *raiz, No * n) {
    if (raiz == NULL)
        return n;
    if (raiz->dado > n->dado)
        raiz->esq = Insere(raiz->esq, n);
    else
        raiz->dir = Insere(raiz->dir, n);
    return raiz;
}

void No::Estado(No *raiz){
    //TODO
}

void No::Pre_Ordem(No *raiz) {
    if (raiz) {
        cout << raiz->dado << " ";
        Pre_Ordem(raiz->esq);
        Pre_Ordem(raiz->dir);
    }
}

void No::Pos_Ordem(No *raiz) {
    if (raiz) {
        Pos_Ordem(raiz->esq);
        Pos_Ordem(raiz->dir);
        cout << raiz->dado << " ";
    }
}

void No::Em_Ordem(No *raiz) {
    if (raiz) {
        Em_Ordem(raiz->esq);
        cout << raiz->dado << " ";
        Em_Ordem(raiz->dir);
    }
}

bool No::Busca(int valor, No *raiz) {
    if (raiz) {
        if (raiz->dado == valor)
            return true;
        if (raiz->dado > valor)
            return Busca(valor, raiz->esq);
        else
            return Busca(valor, raiz->dir);
    } else return false;
}

No *No::Captura_Maximo(No* raiz) {
    if (raiz->dir == NULL) {
        return raiz;
    }
    if (raiz) {
        return Captura_Maximo(raiz->dir);
        //        return Captura_Maximo(raiz->esq, maior);
    }

}

bool No::Remove(int valor, No *raiz, No *pai) {
    if (raiz == NULL) {
        return false;
    }
    if (valor == raiz->dado) {
        No *aux = raiz;
        if (raiz->esq == NULL || raiz->dir == NULL) {
            //delete one child
            if (raiz->esq == NULL && raiz->dir == NULL) {
                // nao tem filho
                if (raiz->dado > pai->dado) {
                    // filho dir
                    pai->dir = NULL;
                    free(raiz);
                } else {
                    // filho esq
                    pai->esq = NULL;
                    free(raiz);
                }
                return true;
            } else if (raiz->dir == NULL) {
                // tem um filho a esquerda
                if (raiz->dado > pai->dado) {
                    // filho dir
                    pai->dir = raiz->esq;
                    free(raiz);
                } else {
                    // filho esq
                    pai->esq = raiz->esq;
                    free(raiz);
                }
                return true;
            } else if (raiz->esq == NULL) {
                // tem um filho a direita
                if (raiz->dado > pai->dado) {
                    // filho dir
                    pai->dir = raiz->dir;
                    free(raiz);
                } else {
                    // filho esq
                    pai->esq = raiz->dir;
                    free(raiz);
                }
                return true;
            }
        } else {
            //TODO problema qdo no for raiz da arv
            // tem dois filhos
            aux = Captura_Maximo(raiz->esq); // TEM QUE VE ESSA PORRA
            raiz->dado = aux->dado;
            raiz->esq->Remove(aux->dado, raiz->esq, raiz);
            free(aux);
            return true;
        }
    } else if (valor < raiz->dado) {
        return Remove(valor, raiz->esq, raiz);
    } else {
        return Remove(valor, raiz->dir, raiz);
    }
}


// =============== MANIPULAÇÃO DE ARQUIVOS================================================

bool writeFile(ofstream& file, string strFile) { // Abrir Arquivo para Escrita NO FINAL
    file.open(strFile, ios::ate | ios::app);
    return !(file.fail() || !file.is_open() || !file.good());
}

bool writeFileFinal(ofstream& file, string strFile) { // Abrir Arquivo para Escrita NO COMEÇO
    file.open(strFile);
    return !(file.fail() || !file.is_open() || !file.good());
}

bool readFile(std::ifstream &ifile, std::string strFile) { // Abrir Arquivo para Leitura
    ifile.open(strFile);
    return !(ifile.fail() || !ifile.is_open() || !ifile.good());
}