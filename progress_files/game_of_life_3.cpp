#include<iostream>
#define MATRIX_SIZE 1024 
int points_to_check[16];
int points[16] = {
    -1, -1,
    -1, 0,
    -1, 1,
    0, -1,
    0, 1,
    1, -1,
    1, 0,
    1, 1
};
// q: how to make a constant in c++?
// a: use #define
// q: how?

bool** get_matrix(){
    bool** matrix = new bool*[MATRIX_SIZE];
    for(int i=0; i<MATRIX_SIZE; i++){
        matrix[i] = new bool[MATRIX_SIZE];
    }
    return matrix;
}

void set_initial_state(bool** matrix){
    int size_of_input;
    std:: cin >> size_of_input;

    int x, y;
    for (int i = 0; i < size_of_input; i++)
    {
        std::cin >> x >> y;
        matrix[x][y] = 1;
    }
}

void print_matrix(bool** matrix){
    for(int i=0; i<MATRIX_SIZE; i++){
        for(int j=0; j<MATRIX_SIZE; j++){
            if(matrix[i][j] == 1){
                std::cout << i << "-" << j << ",";
            }
        }
    }
    std::cout << std::endl;
}

void set_matrix(bool** matrix, bool** temp){
    for(int i=0; i<MATRIX_SIZE; i++){
        for(int j=0; j<MATRIX_SIZE; j++){
            matrix[i][j] = temp[i][j];
        }
    }
}

bool get_next_state_of_cell(int x, int y, bool** matrix){
    int count = 0;
    // initializing the points to be checked for the given point
    for(int i=0; i<16; i++){
        points_to_check[i] = -1;
        points_to_check[i+1] = -1;
    }
    for(int i=0; i<16; i+=2){
        int x_to_check = x + points[i];
        int y_to_check = y + points[i+1];
        if(x_to_check >= 0 && x_to_check < MATRIX_SIZE && y_to_check >= 0 && y_to_check < MATRIX_SIZE){
            if(matrix[x_to_check][y_to_check] == 1){
                count++;
            }
        }
    }

    if(matrix[x][y] == 1){
        if(count == 2 || count == 3){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(count == 3){
            return 1;
        }
        else{
            return 0;
        }
    }
}

void run_frame(bool** matrix1, bool** matrix2){
    for(int i=0; i<MATRIX_SIZE; i++){
        for(int j=0; j<MATRIX_SIZE; j++){
            matrix2[i][j] = get_next_state_of_cell(i, j, matrix1);
        }
    }
}


int main(){
    bool** matrix = get_matrix();
    bool** temp = get_matrix();
    set_initial_state(matrix);
    print_matrix(matrix);
    for(int i=0; i<100; i++){
        run_frame(matrix, temp);
        print_matrix(temp);
        set_matrix(matrix, temp);
    }
    return 0;
}