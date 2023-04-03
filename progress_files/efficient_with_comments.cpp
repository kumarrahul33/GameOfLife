#include<iostream>
#define MATRIX_SIZE 256 
#define M2 8 
#define BLOCK_SIZE 16 
#define B2 4 
using namespace std;
// q: how to make a constant in c++?
// a: use #define
// q: how?

// bool temp[MATRIX_SIZE][MATRIX_SIZE];
// bool matrix[MATRIX_SIZE][MATRIX_SIZE];
int coordinates_mapping[MATRIX_SIZE][MATRIX_SIZE];
int get_cell_number(int x, int y){
    // x = (x + MATRIX_SIZE)%MATRIX_SIZE;
    // y = (y + MATRIX_SIZE)%MATRIX_SIZE;
    // return (((x/BLOCK_SIZE) * MATRIX_SIZE/BLOCK_SIZE + (y/BLOCK_SIZE)%(MATRIX_SIZE/BLOCK_SIZE))*BLOCK_SIZE*BLOCK_SIZE + (x%BLOCK_SIZE)*BLOCK_SIZE + y%BLOCK_SIZE);
    x = (x + MATRIX_SIZE) & (MATRIX_SIZE - 1);
    y = (y + MATRIX_SIZE) & (MATRIX_SIZE - 1);
    unsigned int block_index = ((x >> B2) * (MATRIX_SIZE >> B2)) + ((y >> B2) & ((MATRIX_SIZE >> B2) - 1));
    unsigned int cell_index = ((x & (BLOCK_SIZE - 1)) << B2) + (y & (BLOCK_SIZE - 1));
    // return (block_index << (B2<<1)) | cell_index;
    int index = (block_index << (B2 << 1)) | cell_index;
    return index;
}

bool get_cell_state(int x, int y,bool* matrix){
    x = (x + MATRIX_SIZE) & (MATRIX_SIZE - 1);
    y = (y + MATRIX_SIZE) & (MATRIX_SIZE - 1);
    unsigned int block_index = ((x >> B2) * (MATRIX_SIZE >> B2)) + ((y >> B2) & ((MATRIX_SIZE >> B2) - 1));
    unsigned int cell_index = ((x & (BLOCK_SIZE - 1)) << B2) + (y & (BLOCK_SIZE - 1));
    // return (block_index << (B2<<1)) | cell_index;
    int index = (block_index << (B2 << 1)) | cell_index;
    return *(matrix + index);
    
}
void set_cell_state(int x, int y, bool state, bool* matrix){
    // x = (x + MATRIX_SIZE) & (MATRIX_SIZE - 1);
    // y = (y + MATRIX_SIZE) & (MATRIX_SIZE - 1);
    // unsigned int block_index = ((x >> B2) * (MATRIX_SIZE >> B2)) + ((y >> B2) & ((MATRIX_SIZE >> B2) - 1));
    // unsigned int cell_index = ((x & (BLOCK_SIZE - 1)) << B2) + (y & (BLOCK_SIZE - 1));
    // // return (block_index << (2 * B2)) | cell_index;
    // int index = (block_index << (B2 << 1)) | cell_index;
    // *(matrix + index) = state;
    *(matrix + coordinates_mapping[x][y]) = state;
}

void initialise(bool* temp, bool* matrix){
    // for(int i=0; i<MATRIX_SIZE; i++){
    //     for(int j=0; j<MATRIX_SIZE; j++){
    //         coordinates_mapping[i][j] = make_pair(i,j);
    //     }
    // }
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for(int j=0; j< MATRIX_SIZE; j++){
            coordinates_mapping[i][j] = get_cell_number(i,j);
        }
    }
    

    for(int i=0; i<MATRIX_SIZE; i++){
        for(int j=0; j<MATRIX_SIZE; j++){
            // set_cell_state(i,j,0,temp);
            // set_cell_state(i,j,0,matrix);
            *(temp + ((i/BLOCK_SIZE) * MATRIX_SIZE/BLOCK_SIZE + (j/BLOCK_SIZE)%(MATRIX_SIZE/BLOCK_SIZE))*BLOCK_SIZE*BLOCK_SIZE + (i%BLOCK_SIZE)*BLOCK_SIZE + j%BLOCK_SIZE) = 0;
            *(matrix + ((i/BLOCK_SIZE) * MATRIX_SIZE/BLOCK_SIZE + (j/BLOCK_SIZE)%(MATRIX_SIZE/BLOCK_SIZE))*BLOCK_SIZE*BLOCK_SIZE + (i%BLOCK_SIZE)*BLOCK_SIZE + j%BLOCK_SIZE) = 0;
            }
    }
}

void take_input(bool* matrix){
    int size;
    cin >> size;
    for(int i=0; i<size; i++){
        int x,y;
        cin >> x >> y;
        // set_cell_state(x,y,1,matrix);
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
            // cout << get_cell_state(i,j, &matrix[0][0])?"#":".";
            // if(get_cell_state(i,j, matrix)) cout << "#";
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
            // std::cout << i << " " << j << " " << i*BLOCK_SIZE + j << std::endl;
            for(int k = 0; k < BLOCK_SIZE; k++){
                for(int l = 0; l < BLOCK_SIZE; l++){
                    if(*(matrix + coordinates_mapping[i*BLOCK_SIZE + k][j*BLOCK_SIZE + l])) cout << i*BLOCK_SIZE + k << " " << j*BLOCK_SIZE + l << ",";
                }
            }
        }
    }
    cout << '\n';
}

// int count_neighbours(int x, int y, bool* matrix){
//     return count;
// }

bool god(int x, int y,bool* matrix){
    // int count = count_neighbours(x,y, matrix);
    int count = 0;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0) continue;
            // if(get_cell_state(x+i,y+j, matrix)) count++;
        // cout << "here" <<endl;
        // cout << x+i << " " << y+j << endl; 
        // cout << coordinates_mapping[x+i][y+j] << endl;
        int x1 = (x+i + MATRIX_SIZE) & (MATRIX_SIZE - 1);
        int y1 = (y+j + MATRIX_SIZE) & (MATRIX_SIZE - 1);
        // if(x == 1 && y == 2){
        //     cout << x1 << " " << y1 << endl;
        //     cout << *(matrix + coordinates_mapping[x1][y1]) << endl;
        // } 
            if(*(matrix + coordinates_mapping[x1][y1])) count++;
        }
    }
    // if(get_cell_state(x,y,matrix)){
    // x = (x + MATRIX_SIZE) & (MATRIX_SIZE - 1);
    // y = (y + MATRIX_SIZE) & (MATRIX_SIZE - 1);
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
            // std::cout << i << " " << j << " " << i*BLOCK_SIZE + j << std::endl;
            for(int k = 0; k < BLOCK_SIZE; k++){
                for(int l = 0; l < BLOCK_SIZE; l++){
                    // set_cell_state(i*BLOCK_SIZE + k, j*BLOCK_SIZE + l, god(i*BLOCK_SIZE + k, j*BLOCK_SIZE + l, matrix), temp);
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
    // for(int i = 0; i < MATRIX_SIZE; i++){
    //     for(int j = 0; j < MATRIX_SIZE; j++){
    //         cout << coordinates_mapping[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    take_input(matrix);
    // print_board(matrix);
    for(int i=0; i<1000; i++){
        // print_board(matrix);
        print_frame_efficient(matrix);
        // print_board(matrix);
        run_frame(matrix, temp);
    // cout << "Initial Board" << endl;
    }
    return 0;
}