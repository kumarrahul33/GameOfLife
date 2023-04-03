#include<iostream>
#define MATRIX_SIZE 2048 
bool temp[MATRIX_SIZE][MATRIX_SIZE];
// q: how to make a constant in c++?
// a: use #define
// q: how?

class GameBoard
{
    private:
        bool matrix[MATRIX_SIZE][MATRIX_SIZE];

    public:
        GameBoard(/* args */){
            for(int i=0; i<MATRIX_SIZE; i++){
                for(int j=0; j<MATRIX_SIZE; j++){
                    matrix[i][j] = 0;
                }
            }
        };

        int get_cell_state(int x, int y){
            return matrix[x][y];
        }

        void set_cell_state(int x, int y, int state){
            matrix[x][y] = state;
        }


        void print_frame(){
            for(int i=0; i<MATRIX_SIZE; i++){
                for(int j=0; j<MATRIX_SIZE; j++){
                    if(matrix[i][j] == 1){
                        std::cout << i << " " << j << ",";
                    }

                }
            }
            std::cout << std::endl;
        }

};


class GameLogic{
    protected:
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
    public:
        GameLogic(){};
        // int god(GameBoard* board,int x, int y){

        // };
        virtual int god(GameBoard* board,int x, int y){
            int count = check_immediate_alive_neighbours(board,x, y);

            // std::cout << count << "--" << x << " " << y << std::endl;
            if(board->get_cell_state(x,y) == 1){
                // std::cout << count << "--" << x << " " << y << std::endl;
                if(count == 2 || count == 3){
                    // std::cout << x << " - " << y << std::endl;
                    // std::cout << x << " - " << y << std::endl;

                    return 1;
                }
                else{
                    return 0;
                }
            }
            else{
                if(count == 3){
                    // std::cout << x << " - " << y << std::endl;
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }

        int check_immediate_alive_neighbours(GameBoard* board,int x, int y){
            int count = 0;
            // initializing the points to be checked for the given point
            int points_to_check[16];
            for(int i=0; i<8; i++){
                points_to_check[i*2] = -1;
                points_to_check[i*2+1] = -1;
            }
            for(int i=0; i<8; i++){
                int x1 = x + points[i*2];
                int y1 = y + points[i*2+1];
                x1 = (x1+MATRIX_SIZE)%MATRIX_SIZE;
                y1 = (y1+MATRIX_SIZE)%MATRIX_SIZE;
                if(board->get_cell_state(x1,y1) == 1){
                    count++;
                }
            }
            return count;
        }
};

class GameOfLife{
    private:
        GameBoard* board;
        GameLogic* logic;
    public:
        GameOfLife(int logic_type){
            this->board = new GameBoard();

                this->logic = new GameLogic();

            for(int i=0; i<MATRIX_SIZE; i++){
                for(int j=0; j<MATRIX_SIZE; j++){
                    this->board->set_cell_state(i,j,0);
                }
            }


            int size_of_input;
            std:: cin >> size_of_input;

            int x, y;
            for (int i = 0; i < size_of_input; i++)
            {
                std::cin >> x >> y;
                this->board->set_cell_state(x,y,1);
            }
        };

        void run_frame(){
            for(int i=0; i<MATRIX_SIZE; i++){
                for(int j=0; j<MATRIX_SIZE; j++){
                    int state = logic->god(board,i,j);
                    temp[i][j] = state;
                }
            }

            for(int i=0; i<MATRIX_SIZE; i++){
                for(int j=0; j<MATRIX_SIZE; j++){
                    this->board->set_cell_state(i,j,temp[i][j]);
                }
            }
        }
        void start_game(){
           for(int i=0; i<100 ; i++){
            //    this->board->print_frame();
               run_frame();
           }
        }
        void test_game(){
            this->board->print_frame();
            run_frame();
            // this->board->print_frame();
        }
};

int main(){
    GameOfLife game(0);
    game.start_game();
    // game.test_game();
    return 0;
}