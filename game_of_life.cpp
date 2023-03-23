#include<iostream>

class Game{
    protected:
        int matrix[200][200];

        virtual int god(int x, int y) = 0;

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

        int check_immediate_alive(int x, int y){
            int count = 0;
            int points_to_check[16];
            for(int i=0; i<8; i++){
                points_to_check[i*2] = -1;
                points_to_check[i*2+1] = -1;

                int _x = x + points[i*2];
                int _y = y + points[i*2 + 1];

                if(!(_x >= 200 || _x < 0 || _y >= 200 || _y < 0)){
                    points_to_check[i*2] = _x;
                    points_to_check[i*2 + 1] = _y;
                }
            }

            for (int i=0; i < 16; i+=2)
            {
                if(points_to_check[i] != -1 && points_to_check[i+1] != -1){
                    if(matrix[points_to_check[i]][points_to_check[i+1]] == 1){
                        // std::cout << "found one at : " << points_to_check[i] << " - " << points_to_check[i+1] << std::endl;
                        count++;
                    }
                }
            }

            if(x == 99 && y == 101){
                for (int i = 0; i < 16; i+=2)
                {
                    // std::cout << "points to check:" << points_to_check[i] << " - " << points_to_check[i+1] << std::endl;
                }
            }
            return count;
        };

    public:
        Game(){
            for(int i=0; i<200; i++){
                for(int j=0; j<200; j++){
                    matrix[i][j] = 0;
                }
            }

            int size_of_input;
            std:: cin >> size_of_input;
            std::cout << size_of_input << std::endl;

            int x, y;
            for (int i = 0; i < size_of_input; i++)
            {
                std::cin >> x >> y;
                std::cout << x << " - " << y << "--" << std::endl;
                matrix[x][y] = 1;
            }
            // take input from the user
        }



        void run_game_iteration(){
            int temp[200][200];
            for (int i = 0; i < 200; i++)
            {
                for (int j = 0; j < 200; j++)
                {
                    if(god(i, j) == 1){
                    // std::cout << "checking on : " << i << " - " << j << std::endl;
                        temp[i][j] = 1;
                    }
                    else{
                        temp[i][j] = 0;
                    }
                }
            }

            for(int i=0; i<200; i++){
                for(int j=0; j<200; j++){
                    matrix[i][j] = temp[i][j];
                }
            }

            print();
        }

        void print(){
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

class GameOfLife: public Game{
    public:
        int god(int x, int y){
            int count = check_immediate_alive(x, y);
            if(x == 99 && y == 101){
                // std::cout << x << " - " << y << std::endl;
                // std::cout << count << std::endl;
            }

            if(matrix[x][y] == 1){
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
};

class GameOfLife1: public Game{
    public:

        int god(int x, int y){
            int count = check_immediate_alive(x, y);
            if(count == 2){
                return matrix[x][y];
            }

            else return !matrix[x][y];
        }
};

class GameOfLife2: public Game{
    public:
        int god(int x, int y){
            int count = check_immediate_alive(x, y);
            if(count > 3 and count < 7 ){
                return 1;
            }
            else{
                return 0;
            }
        }
};

int main(){
    GameOfLife game;
    game.print();
    game.print();
    // std::cout << std::endl << std::endl;
    for(int i=0; i<100; i++){
        game.run_game_iteration();
        // std::cout << std::endl << std::endl;
    }
    return 0;
}