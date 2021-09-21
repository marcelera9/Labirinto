// Marcelo Luiz M. Evangelista

#include <iostream>
#include <stack> // Pilha padrao do C++
#include <cstdlib>
using namespace std;

struct Cordenadas {
    int x, y;
};

bool MazeSolution(int lab[20][21], stack<Cordenadas> p);
void PrintMaze(int lab[20][21]);

int main() {
    /* 0 Caminho vazio
    1 Entrada
    2 Saida
    4 Parede
    5 Caminho percorrido */

    int lab[20][21] = {
            4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
            4,0,0,0,0,0,4,0,0,0,0,0,4,0,0,0,0,0,4,0,4,
            4,4,0,4,4,0,4,4,4,4,4,0,4,0,4,0,4,0,0,0,4,
            4,0,0,0,4,0,0,0,0,0,0,0,4,4,4,0,4,4,4,0,4,
            4,0,4,0,4,0,4,4,4,4,4,4,4,0,0,0,4,0,0,0,4,
            4,0,4,0,0,0,4,0,0,0,4,0,4,0,4,0,0,0,4,0,4,
            4,0,4,4,4,4,4,0,4,0,4,0,0,0,4,4,4,4,4,0,4,
            4,0,4,0,0,0,0,0,4,0,4,4,4,0,0,4,0,0,0,0,4,
            4,0,4,0,4,0,4,0,4,0,0,0,4,4,0,4,4,0,4,4,4,
            4,0,4,0,4,4,4,0,4,0,4,0,0,0,0,0,4,0,0,0,4,
            1,0,4,0,4,0,4,0,4,0,4,4,4,4,4,0,4,4,4,0,4,
            4,0,0,0,0,0,4,0,4,0,0,0,4,0,4,0,4,0,0,0,4,
            4,0,4,4,4,4,4,0,4,4,4,0,4,0,4,4,4,0,4,0,4,
            4,0,4,0,0,0,0,0,0,0,4,0,4,0,0,0,4,0,4,0,4,
            4,0,0,0,4,4,4,0,4,0,4,0,4,4,4,0,4,0,4,0,4,
            4,4,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,4,4,
            4,0,4,0,0,0,4,0,4,0,0,0,4,0,0,0,4,0,0,0,4,
            4,0,4,4,4,0,4,4,4,4,4,4,4,4,4,0,4,4,4,0,4,
            4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,
            4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,2,4};

    stack<Cordenadas> p;

    // Entrada do labirinto x=10; y=0;
    Cordenadas entrada = Cordenadas({ 10, 0 });
    p.push(entrada);

    int op = -1;
    bool find = false;

    do {
        cout << endl << "****************  Labirinto  **************** " << endl << endl;
        cout << " 1 - START" << endl;
        cout << " 2 - EXIT" << endl << endl;
        cout << " Escolha uma opcao: " << endl;
        cin >> op;

        switch (op) {
            case 1:{
                if (!find) {
                    // Faça enquanto encontrou = false:
                    do {
                        system("cls");
                        cout << "EXIT NOT FOUND." << endl;
                        // Retorna encontrou = true se achar a saida
                        find = MazeSolution(lab, p);
                    } while (find);

                    if (!find) {
                        PrintMaze(lab); // ATENCAO
                        cout << endl << "EXIT FOUND" << endl;
                        system("pause");
                        break;
                    }
                } else {
                    cout << "MAZE SOLVED" << endl;
                    break;
                }
                break;
            }

            case 2:{
                system("cls");
                cout << "Exit" << endl;
                return 0;
            }

            default: {
                system("cls");
                cout << "Opcao invalida" << endl;
            }
        }
    } while (op != 2 || !find);
}

void PrintMaze(int lab[20][21]) {
    system("cls");
    int linha, coluna;

    for (linha = 0; linha <= 20; linha++) {
        for (coluna = 0; coluna < 21; coluna++) {
            if (lab[linha][coluna] == 0) { cout << " "; }
            if (lab[linha][coluna] == 4) { cout << "X"; }
            if (lab[linha][coluna] == 1) { cout << "E"; }
            if (lab[linha][coluna] == 2) { cout << "S"; }
            if (lab[linha][coluna] == 5) { cout << "."; }
            if (lab[linha][coluna] == 6) { cout << " "; }
            if (lab[linha][coluna] == 7) { cout << "-"; }
        }
        cout << endl;
    }
    cout << endl;
}

bool MazeSolution(int lab[20][21], stack<Cordenadas> p) {

    PrintMaze(lab);
    cout << "Entrada: (10,0)" << endl;
    cout << "Saida: (19,19)" << endl;
    cout << endl << endl;
    do{
        bool aux = false;
        for (int i = p.top().y - 1; i <= p.top().y + 1; i++) {
            if (aux) {
                break;
            }
            // Verifica se esta dentro do intervalo do labirinto
            if (i >= 0 || i <= 21) {
                if (lab[j][i+1] == 0) {
                    // ++i;
                    // Se for caminho vazio -> Seta posicao com valor = 7
                    lab[p.top().x][i] = 7;

                    // Push na pilha a posicao com valor 7
                    p.push(Cordenadas({ (int)i, (int)p.top().x }));
                    aux = true;
                    break;
                    // 2 = Saida
                } if (lab[p.top().x][i] == 2) {
                    // Se for caminho vazio -> Seta posicao com valor = 5
                    lab[p.top().x][p.top().y] = 5;
                    // Retorna true para a funcao MazeSolution
                    // ENCONTROU A SAIDA!
                    return true;
                }

                // Se nao estiver no intervalo do labirinto ele 'breaks on iteration'
            }
            else {
                continue;
            }
        }
        for (int j = p.top().x - 1; j <= p.top().x + 1; j++) {
            if (aux)
                break;

            if (j >= 0 || j <= 20) {
                if (lab[j][p.top().y] == 0) {
                    // Se for caminho vazio -> Seta posicao com valor = 7
                    lab[j][p.top().y] = 7;
                    // Push na pilha a posicao com valor 7
                    p.push(Cordenadas({ (int)p.top().y, (int)j }));
                    aux = true;
                    break;
                    // 2 = Saida
                }
                if (lab[j][p.top().y] == 2) {
                    // Se for caminho vazio -> Seta posicao com valor = 5
                    lab[p.top().x][p.top().y] = 5;
                    // Retorna true para a funcao MazeSolution
                    return true;
                } else {
                    continue;
                }
            }
        }
        if (!aux) {
            lab[p.top().x][p.top().y] = 6;
            p.pop();
        }
        // Se caminho estiver vazio o codigo tera percorrido todos os caminhos possiveis
    } while (!p.empty());
    return false;
}