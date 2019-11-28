/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2019.1.08.041
 *
 * Created on 31 de Outubro de 2019, 16:15
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "arvore.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Arvore *arv = new Arvore;

    //Controle de arquivo (Abrindo arquivo e fazendo sua leitura)
    int control = 0; // 0 for test read file, 1 for manual insertion
    if (control) {
        arv->Insere(29);
        arv->Insere(15);
        arv->Insere(27);
        arv->Insere(10);
        arv->Insere(23);
        cout << arv->Remove(29) << " ";
        cout << arv->Remove(27) << " "; //TODO remoção da segunda raiz
        //cout << arv->Busca(16) << " ";
        //arv->Insere(99);
    } else {
        ofstream outFile;
        ifstream dados;
        bool status;
        int tam = 0;
        char op;
        int valor;

        status = readFile(dados, "arquivo.txt");
        //Teste de abertura de arquivo
        if (!status) {
            cout << "Arquivo não pode ser aberto para leitura." << endl;
            cout << "Programa terminando..." << endl;
        } else {
            //Leitura do arquivo       
            dados >> op;
            while (!dados.eof()) {
                switch (op) {
                        //inserir, remover, buscar e estado
                    case 'i':
                    {
                        dados >> tam;
                        for (int j = 0; j < tam; j++) {
                            dados >> valor;
                            arv->Insere(valor);
                            cout << "inserindo: " << valor << endl;
                        }
                        dados >> op;
                        break;
                    }

                    case 'r':
                    {
                        dados >> tam;
                        for (int j = 0; j < tam; j++) {
                            dados >> valor;
                            arv->Remove(valor);
                        }
                        dados >> op;
                        break;
                    }

                    case 'b':
                    {

                        dados >> tam;
                        for (int i = 0; i < tam; i++) {
                            dados >> valor;
                            int busca = arv->Busca(valor);
                            if (busca == 1)
                                cout << "O valor: " << valor << " esta na arvore." << endl;
                            else
                                cout << "O valor: " << valor << " não esta na arvore." << endl;
                        }
                        dados >> op;
                        break;
                    }

                    case 'e':
                    {
                        break;
                    }

                    default:
                    {
                        break;
                    }
                }
            }
        }
    }
    arv->Em_Ordem();
    return 0;
}

