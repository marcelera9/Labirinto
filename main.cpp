#include <iostream>
#include <array>
#include <vector>
#include <stack>

using namespace std;

struct Coordenadas {
    int x,y;
};

int main() {
    stack<Coordenadas> s;
    int i,j;

    vector<string> labirinto = {
            "XXXXXXXXXXXXXXXXXXXXX",
            "X     X     X     X X",
            "XX XX XXXXX X X X   X",
            "X   X       XXX XXX X",
            "X X X XXXXXXX   X   X",
            "X X   X   X X X   X X",
            "X XXXXX X X   XXXXX X",
            "X X     X XXX  X    X",
            "X X X X X   XX XX XXX",
            "X X XXX X X     X   X",
            "E X X X X XXXXX XXX X",
            "X     X X   X X X   X",
            "X XXXXX XXX X XXX X X",
            "X X       X X   X X X",
            "X   XXX X X XXX X X X",
            "XXX X X X X X X X XXX",
            "X X   X X   X   X   X",
            "X XXX XXXXXXXXX XXX X",
            "X                 X X",
            "XXXXXXXXXXXXXXXXXXXSX"
    };

    cout << "Marcelo Luiz M. E." << endl;
    cout << "Labirinto" << endl;
    for (i=0; i<20; ++i){
        cout << endl;
        for (j=0; j<21; ++j){
            cout << labirinto[i][j];
        }
    }

    Coordenadas entrada = Coordenadas({10,0});
    s.push(entrada);
}

bool testaSolucao (vector<string> labirinto, stack<Coordenadas> s) {
    do {
        
    } while (!s.empty());
    return false;
}
