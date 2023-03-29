#include<iostream>

class GameBoard
{
    private:
        bool matrix[200][200];

    public:
        GameBoard(/* args */){
            for(int i=0; i<200; i++){
                for(int j=0; j<200; j++){
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
            for(int i=0; i<200; i++){
                for(int j=0; j<200; j++){
                    // char a = (matrix[i][j])? '#' : '.';
                    // std::cout << a;
                    if(matrix[i][j] == 1){
                        std::cout << i << "-" << j << ",";
                    }

                }
                // std::cout << std::endl;
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

            if(board->get_cell_state(x,y) == 1){
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
            int points_to_check[16];
            for(int i=0; i<8; i++){
                points_to_check[i*2] = -1;
                points_to_check[i*2+1] = -1;
            }
            for(int i=0; i<8; i++){
                int x1 = x + points[i*2];
                int y1 = y + points[i*2+1];
                if(x1 >= 0 && x1 < 200 && y1 >= 0 && y1 < 200){
                    if(board->get_cell_state(x1,y1) == 1){
                        count++;
                    }
                }
            }
            return count;
        }
};

class God1: public GameLogic{
    public:
        int god(GameBoard* board,int x, int y){
            int count = check_immediate_alive_neighbours(board,x, y);
            if(count > 3 and count < 7 ){
                return 1;
            }
            else{
                return 0;
            }
        }
};

class God2: public GameLogic{
    public:
        int god(GameBoard* board,int x, int y){
            int count = check_immediate_alive_neighbours(board,x, y);
            if(count == 3 || count == 5 || count == 7){
                return 1;
            }

            else return 0;
        }
};

class GameOfLife{
    private:
        GameBoard* board;
        GameLogic* logic;
    public:
        GameOfLife(int logic_type){
            this->board = new GameBoard();

            if(logic_type == 1){
                this->logic = new God1();
            }
            else if(logic_type == 2){
                this->logic = new God2();
            }
            else{
                this->logic = new GameLogic();
            }
            // this->logic = new God0();
            // this->logic = new GameLogic();

            for(int i=0; i<200; i++){
                for(int j=0; j<200; j++){
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
            bool temp[200][200];
            for(int i=0; i<200; i++){
                for(int j=0; j<200; j++){
                    int state = logic->god(board,i,j);
                    temp[i][j] = state;
                }
            }

            for(int i=0; i<200; i++){
                for(int j=0; j<200; j++){
                    this->board->set_cell_state(i,j,temp[i][j]);
                }
            }
        }
        void start_game(){
           for(int i=0; i<100; i++){
               run_frame();
               this->board->print_frame();
           }
        }
};

int main(){
    GameOfLife game(1);
    game.start_game();
    return 0;
}