#include<iostream>

class Game{
    private:
        int matrix[200][200];

        int god(int x, int y);

    public:
        Game(){
            for(int i=0; i<200; i++){
                for(int j=0; j<200; j++){
                    matrix[i][j] = 0;
                }
            }

            int size_of_input;
            std:: cin >> size_of_input;

            int x, y;
            for (int i = 0; i < size_of_input; i++)
            {
                std::cin >> x >> y;
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
                    std::cout << matrix[i][j] << " ";
                }
                std::cout << endl;
            }
        }
};

class GameOfLife: private Game{
    public:
        // GameOfLife1(): Game(){
        //     // constructor
        // }

        int god(int x, int y){
            int count = 0;
            if(matrix[x-1][y-1] == 1){
                count++;
            }
            if(matrix[x-1][y] == 1){
                count++;
            }
            if(matrix[x-1][y+1] == 1){
                count++;
            }
            if(matrix[x][y-1] == 1){
                count++;
            }
            if(matrix[x][y+1] == 1){
                count++;
            }
            if(matrix[x+1][y-1] == 1){
                count++;
            }
            if(matrix[x+1][y] == 1){
                count++;
            }
            if(matrix[x+1][y+1] == 1){
                count++;
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
};

class GameOfLife2: private Game{
    public:
        // GameOfLife2(): Game(){
        //     // constructor
        // }

        int god(int x, int y){
            int count = 0;
            if(matrix[x-1][y-1] == 1){
                count++;
            }
            if(matrix[x-1][y] == 1){
                count++;
            }
            if(matrix[x-1][y+1] == 1){
                count++;
            }
            if(matrix[x][y-1] == 1){
                count++;
            }
            if(matrix[x][y+1] == 1){
                count++;
            }
            if(matrix[x+1][y-1] == 1){
                count++;
            }
            if(matrix[x+1][y] == 1){
                count++;
            }
            if(matrix[x+1][y+1] == 1){
                count++;
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
};