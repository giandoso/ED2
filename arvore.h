/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arvore.h
 * Author: 2019.1.08.041
 *
 * Created on 31 de Outubro de 2019, 16:16
 */

#ifndef ARVORE_H
#define ARVORE_H

#include<fstream>
#include <iostream>

using namespace std;

class No { //Nó da Árvore
public:
    No(int valor); //Construtor
    ~No(); //Destrutor
    void Pre_Ordem(No *raiz);
    void Pos_Ordem(No *raiz);
    int QtdFolhas(No *raiz);
    void Em_Ordem(No *raiz);
    bool Busca(int valor, No *raiz);
    No *Captura_Maximo(No *raiz);
    No *Remove(int valor, No *raiz, No *pai);
    No *Insere(No *raiz, No *n);
    int dado;
    No *esq, *dir;
};

class Arvore {
public:
    Arvore();
    ~Arvore();
    void Pre_Ordem();
    void Pos_Ordem();
    void Em_Ordem();
    void Insere(int valor);
    bool Busca(int valor);
    void Estado();
    bool Remove(int valor);
    No *Captura_Maximo();
    No *raiz;
    int qtde;
};

// =============== MANIPULAÇÃO DE ARQUIVOS================================================

bool readFile(std::ifstream &ifile, std::string strFile);
bool writeFile(ofstream& file, std::string strFile);
bool writeFileFinal(ofstream& file, string strFile);
#endif /* ARVORE_H */

