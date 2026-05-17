// Resolviendo Sudoku
// Algoritmo: Simulated Annealing

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Estructura para agrupar el estado completo del problema
struct SudokuState {
    vector<vector<int>> board;
    // Guarda las coordenadas de las celdas que podemos modificar (mutables),
    // agrupadas por su bloque de 3x3 (índices del 0 al 8).
    vector<vector<pair<int, int>>> mutable_cells_by_block;
};

// Prototipos
void print_sudoku_state(const vector<vector<int>>& board);
SudokuState init_sudoku(const vector<vector<int>>& initial_board);

int main() {
    // Definimos el estado inicial usando vectores
    vector<vector<int>> initial_board = {
        {0, 0, 0, 2, 6, 0, 7, 0, 1},
        {6, 8, 0, 0, 7, 0, 0, 9, 0},
        {1, 9, 0, 0, 0, 4, 5, 0, 0},
        {8, 2, 0, 1, 0, 0, 0, 4, 0},
        {0, 0, 4, 6, 0, 2, 9, 0, 0},
        {0, 5, 0, 0, 0, 3, 0, 2, 8},
        {0, 0, 9, 3, 0, 0, 0, 7, 4},
        {0, 4, 0, 0, 5, 0, 0, 3, 6},
        {7, 0, 3, 0, 1, 8, 0, 0, 0}
    };

    // Inicializamos el estado
    SudokuState state = init_sudoku(initial_board);

    cout << "Estado inicial (Celdas vacias rellenadas sin repetir en 3x3):\n";
    print_sudoku_state(state.board);

    return 0;
}

// Función que extrae toda la lógica de inicialización
SudokuState init_sudoku(const vector<vector<int>>& initial_board) {
    SudokuState state;
    state.board = initial_board;
    state.mutable_cells_by_block.resize(9);

    // Iteramos por cada bloque de 3x3
    for (int block_i = 0; block_i < 3; block_i++) {
        for (int block_j = 0; block_j < 3; block_j++) {
            
            int block_index = block_i * 3 + block_j;
            vector<bool> is_present(10, false);
            vector<pair<int, int>> empty_cells;

            // 1. Identificar qué números ya existen y qué coordenadas están vacías en este bloque
            for (int i = block_i * 3; i < block_i * 3 + 3; i++) {
                for (int j = block_j * 3; j < block_j * 3 + 3; j++) {
                    if (state.board[i][j] != 0) {
                        is_present[state.board[i][j]] = true;
                    } else {
                        empty_cells.push_back({i, j});
                    }
                }
            }

            // 2. Recolectar los números del 1 al 9 que faltan en este bloque
            vector<int> missing_numbers;
            for (int n = 1; n <= 9; n++) {
                if (!is_present[n]) {
                    missing_numbers.push_back(n);
                }
            }

            // 3. Rellenar las celdas vacías del tablero directamente y guardar sus coordenadas como mutables
            for (size_t k = 0; k < empty_cells.size(); k++) {
                int r = empty_cells[k].first;
                int c = empty_cells[k].second;
                
                state.board[r][c] = missing_numbers[k]; // Modificamos el tablero in-place
                state.mutable_cells_by_block[block_index].push_back({r, c});
            }
        }
    }
    
    return state;
}

// Imprimir el tablero es ahora mucho más directo
void print_sudoku_state(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) cout << "-----------------------\n";
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) cout << "| ";
            cout << board[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "-----------------------\n";
}

bool accept(float d_energy, float temp) {
    // TODO: Implementar lógica de aceptación
    return true;
}