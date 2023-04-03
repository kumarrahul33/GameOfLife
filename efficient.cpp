#include<iostream>
#define MATRIX_SIZE 2048 
#define M2 11 
#define BLOCK_SIZE 32 
#define B2 5 
using namespace std;

int coordinates_mapping[MATRIX_SIZE][MATRIX_SIZE];

int get_cell_number(int x, int y){
    x = (x + MATRIX_SIZE) & (MATRIX_SIZE - 1);
    y = (y + MATRIX_SIZE) & (MATRIX_SIZE - 1);
    unsigned int block_index = ((x >> B2) * (MATRIX_SIZE >> B2)) + ((y >> B2) & ((MATRIX_SIZE >> B2) - 1));
    unsigned int cell_index = ((x & (BLOCK_SIZE - 1)) << B2) + (y & (BLOCK_SIZE - 1));
    int index = (block_index << (B2 << 1)) | cell_index;
    return index;
}

void initialise(bool* temp, bool* matrix){
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for(int j=0; j< MATRIX_SIZE; j++){
            coordinates_mapping[i][j] = get_cell_number(i,j);
        }
    }
    

    for(int i=0; i<MATRIX_SIZE; i++){
        for(int j=0; j<MATRIX_SIZE; j++){
            *(temp + i*MATRIX_SIZE + j) = 0;
            *(matrix + i*MATRIX_SIZE + j) = 0;
            }
    }
}

void take_input(bool* matrix){
    int size;
    cin >> size;
    for(int i=0; i<size; i++){
        int x,y;
        cin >> x >> y;
        *(matrix + coordinates_mapping[x][y]) = 1;
    }
    int x,y;
}

void print_frame(bool* matrix){
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for(int j = 0; j < MATRIX_SIZE; j++){
            if(*(matrix + coordinates_mapping[i][j])) cout << i << " " << j << ",";
        }
    }
    std::cout << std::endl;
}

void print_board(bool* matrix){
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for(int j = 0; j < MATRIX_SIZE; j++){
            if(*(matrix + coordinates_mapping[i][j])) cout << "#";
            else cout << ".";
        }
    std::cout << std::endl;
    }
    std::cout << std::endl;
}

void print_frame_efficient(bool* matrix){
    for (int i = 0; i < MATRIX_SIZE>>B2; i++)
    {
        for(int j = 0; j < MATRIX_SIZE>>B2; j++){
            for(int k = 0; k < BLOCK_SIZE; k++){
                for(int l = 0; l < BLOCK_SIZE; l++){
                    if(*(matrix + coordinates_mapping[i*BLOCK_SIZE + k][j*BLOCK_SIZE + l])) cout << i*BLOCK_SIZE + k << " " << j*BLOCK_SIZE + l << ",";
                }
            }
        }
    }
    cout << '\n';
}

bool god(int x, int y,bool* matrix){
    int count = 0;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0) continue;
        int x1 = (x+i + MATRIX_SIZE) & (MATRIX_SIZE - 1);
        int y1 = (y+j + MATRIX_SIZE) & (MATRIX_SIZE - 1);
            if(*(matrix + coordinates_mapping[x1][y1])) count++;
        }
    }
    if(*(matrix + coordinates_mapping[x][y])){ 
        return (count == 2 || count == 3);
    }
    else{
        return count == 3;
    }
}

void run_frame(bool* matrix, bool* temp){
    for (int i = 0; i < MATRIX_SIZE>>B2; i++)
    {
        for(int j = 0; j < MATRIX_SIZE>>B2; j++){
            for(int k = 0; k < BLOCK_SIZE; k++){
                for(int l = 0; l < BLOCK_SIZE; l++){
                    *(temp + coordinates_mapping[i*BLOCK_SIZE + k][j*BLOCK_SIZE + l]) = god(i*BLOCK_SIZE + k, j*BLOCK_SIZE + l, matrix);
                }
            }
        }
    }
    for(int i=0; i<MATRIX_SIZE; i++){
        for(int j=0; j<MATRIX_SIZE; j++){
            *(matrix + i*MATRIX_SIZE + j) = *(temp + i*MATRIX_SIZE + j);
        }
    }
}

int main(){
    bool* temp = new bool[MATRIX_SIZE*MATRIX_SIZE];
    bool* matrix= new bool[MATRIX_SIZE*MATRIX_SIZE];
    initialise(temp, matrix);
    take_input(matrix);
    for(int i=0; i<1000; i++){
        print_frame_efficient(matrix);
        run_frame(matrix, temp);
    }
    return 0;
}