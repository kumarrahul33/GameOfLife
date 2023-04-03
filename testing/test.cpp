#include<iostream>
#include<cmath>
#define MATRIX_SIZE 2048 
#define M2 11
#define BLOCK_SIZE 64 
#define B2 6
using namespace std;

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

int arr[MATRIX_SIZE][MATRIX_SIZE];
int get_cell_state(int x, int y){
    x = (x + MATRIX_SIZE)%MATRIX_SIZE;
    y = (y + MATRIX_SIZE)%MATRIX_SIZE;
    return (((x/BLOCK_SIZE) * MATRIX_SIZE/BLOCK_SIZE + (y/BLOCK_SIZE)%(MATRIX_SIZE/BLOCK_SIZE))*BLOCK_SIZE*BLOCK_SIZE + (x%BLOCK_SIZE)*BLOCK_SIZE + y%BLOCK_SIZE);
}
// int get_cell_state_2(int x, int y){
//     x = (x + MATRIX_SIZE) & (MATRIX_SIZE - 1);
//     y = (y + MATRIX_SIZE) & (MATRIX_SIZE - 1);
//     unsigned int block_index = ((x >> B2) * (MATRIX_SIZE >> B2)) + ((y >> B2) & ((MATRIX_SIZE >> B2) - 1));
//     unsigned int cell_index = ((x % BLOCK_SIZE) << B2) + (y % BLOCK_SIZE);
//     return (block_index << (2 * B2)) + cell_index;
// }
int get_cell_state_2(int x, int y){
    x = (x + MATRIX_SIZE) & (MATRIX_SIZE - 1);
    y = (y + MATRIX_SIZE) & (MATRIX_SIZE - 1);
    unsigned int block_index = ((x >> B2) * (MATRIX_SIZE >> B2)) + ((y >> B2) & ((MATRIX_SIZE >> B2) - 1));
    unsigned int cell_index = ((x & (BLOCK_SIZE - 1)) << B2) + (y & (BLOCK_SIZE - 1));
    return (block_index << (B2 << 1)) | cell_index;
}


// // int get_cell_state_2(int x, int y){
// //     x = (x + MATRIX_SIZE) & (MATRIX_SIZE - 1);
// //     y = (y + MATRIX_SIZE) & (MATRIX_SIZE - 1);
// //     unsigned int block_index = ((x >> B2) << M2) + ((y >> B2) % (MATRIX_SIZE >> B2 - 1));
// //     unsigned int cell_index = ((x % BLOCK_SIZE) << B2) + (y % BLOCK_SIZE);
// //     unsigned int matrix_index = (block_index << (2 * B2)) + cell_index;
// //     return  matrix_index;
// }

// int get_cell_state_2(int x, int y){
//     x = (x + MATRIX_SIZE)%MATRIX_SIZE;
//     y = (y + MATRIX_SIZE)%MATRIX_SIZE;
//     // int second_term = y_bs % (len-1);
//     // unsigned final_term = (((x>>B2) << M2)>>(B2) +(y>>B2)&((MATRIX_SIZE>>B2)-1))<<(B2+1) + (x%(BLOCK_SIZE-1)<<B2) + y&(BLOCK_SIZE-1);
//     unsigned a1 ;
//     if(M2-2*B2 > 0) a1 = floor(x<< (M2-(2*B2)));
//     else a1 = floor(x>> (2*B2-M2));
//     int temp1 = floor(y>>B2);
//     unsigned a2 = (temp1)&((MATRIX_SIZE>>B2)-1);
//     unsigned t2 = (a1 + a2);
//     t2 = t2 << (2*B2);
//     // cout << "a2:" << a2 << endl;
//     // cout << "a1:" << a1 << endl;

//     int b1 = x&(BLOCK_SIZE-1);
//     int t1 = b1 << B2;

//     int t = y&(BLOCK_SIZE-1);
//     // return (x<< (M2-(B2+1)) +(y>>B2)&((MATRIX_SIZE>>B2)-1))<<(B2+1) + (x%(BLOCK_SIZE-1)<<B2) + y&(BLOCK_SIZE-1);
//     return t2 + t1 + t;
//     // return a3+a1+b;
    
// }
// void set_cell_state(int x, int y, bool state, bool* matrix){
//     *(matrix + ((x/BLOCK_SIZE) * MATRIX_SIZE/BLOCK_SIZE + (y/BLOCK_SIZE)%(MATRIX_SIZE/BLOCK_SIZE))*BLOCK_SIZE*BLOCK_SIZE + (x%BLOCK_SIZE)*BLOCK_SIZE + y%BLOCK_SIZE) = state;
// }
int main(int argc, char const *argv[])
{
    int i = 0;
    int j = 1;
    // cout << i << " " << j << endl;
    // cout << get_cell_state(i,j) << endl;
    // cout << get_cell_state_2(i,j) << endl;
    // get_cell_state_2(i,j);

    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            if(get_cell_state(i,j)!=get_cell_state_2(i,j)){
                cout << i << " " << j << endl;
                cout << get_cell_state(i,j) << endl;
                cout << get_cell_state_2(i,j) << endl;
                cout << "wrong" << endl;
                return 0;
            }
        }
    }
    
    // for(int i = 0; i < MATRIX_SIZE; i++){
    //     for(int j = 0; j < MATRIX_SIZE; j++){
    //         arr[i][j] = get_cell_state(i,j);
    //     }
    // }

    // for (int i = 0; i < MATRIX_SIZE/BLOCK_SIZE; i++)
    // {
    //     for(int j = 0; j < MATRIX_SIZE/BLOCK_SIZE; j++){
    //         // std::cout << i << " " << j << " " << i*BLOCK_SIZE + j << std::endl;
    //         for(int k = 0; k < BLOCK_SIZE; k++){
    //             for(int l = 0; l < BLOCK_SIZE; l++){
    //                 // arr[i*BLOCK_SIZE+k][j*BLOCK_SIZE+l] = get_cell_state(i*BLOCK_SIZE+k,j*BLOCK_SIZE+l);
    //                 cout << arr[i*BLOCK_SIZE+k][j*BLOCK_SIZE+l] << " ";
    //             }
    //         }
    //     }
    // }
    // cout << endl;

    // // print(get_cell_state(-1,-1))
    // cout << get_cell_state(-1,24) << endl;


        
    
    // int size = 1024;
    // {
    //     for(int j = 0; j < size/64; j++){
    //         // std::cout << i << " " << j << " " << i*64 + j << std::endl;
    //         for(int k = 0; k < 64; k++){
    //             for(int l = 0; l < 64; l++){
    //                 std::cout << i*64 + k << " " << j*64 + l << " " << std::endl;
    //             }
    //         }
    //     }
    // }
    // int x = 6;
    // int y = 8;
    // int point = ((x/BLOCK_SIZE) * (MATRIX_SIZE/BLOCK_SIZE) + y/(BLOCK_SIZE))*BLOCK_SIZE*BLOCK_SIZE + (x%BLOCK_SIZE)*BLOCK_SIZE + y%BLOCK_SIZE;
    // cout << point << endl;
    // cout << x/BLOCK_SIZE;
    // cout << endl;
    // cout << y/(MATRIX_SIZE/BLOCK_SIZE);
    // cout << endl;
    // cout << x%BLOCK_SIZE << endl;
    // cout << (point < MATRIX_SIZE*MATRIX_SIZE) << endl;
    // cout << endl;

    
}
