#include <iostream>
#include <cstdlib>
#define FIRST_CHAR 0
#define NORTH   0
#define EAST    1
#define SOUTH   2
#define WEST    3
void change_dir(int &, char);
int main(int argc, char *argv[])
{
        int curr_inst = 1;      //current instruction we are calculating in
                                //order to update the x and y position.
                                //initialized to 1 because element 0 of argv
                                //is the object file name.
        int x_pos = 0;          //origin starts at (0,0)
        int y_pos = 0;
        int dir = 0;
        int block_step = 0;
        while(argv[curr_inst] != NULL){
                block_step = std::atoi(argv[curr_inst]+1);
                char new_dir = argv[curr_inst][FIRST_CHAR];
                change_dir(dir,new_dir);
                if(dir == NORTH){
                        y_pos += block_step;
                }
                else if(dir == EAST){
                        x_pos += block_step;
                }
                else if(dir == SOUTH){
                        y_pos -= block_step;
                }
                else{
                        x_pos -= block_step;
                }
                curr_inst++;
        }
        std::cout << "Total Block Distance: " << x_pos + y_pos << "\n";
        return 0;
}
void change_dir(int &dir, char new_dir){
        if(new_dir == 'R'){
                dir = (dir + 1) % 4;
        }
        else{
                dir = (dir + 3) % 4;
        }
}

