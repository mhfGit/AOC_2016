#include "stdafx.h"
#include <iostream>
#include <fstream>

/*
*	The keypad layout of the problem is as follows:
*			1 2 3
*			4 5 6
*			7 8 9
*	We will use this layout to determine the code for entering into the bathroom.
*	The input sequence of up, down, left and right will reveal the code to the bathroom.
*/
int main()
{
	std::fstream input_file("problem2_input.txt");
	int curr_digit = 5;			//starting position on the keypad 
	int curr_row = 1;			//starting position on the keypad
	int mod_dec = 0;			//modified decrement - will be changed based on the current row we are in
	char inst;
	while (!input_file.eof()) {
		input_file.get(inst);
		if (inst == 'U') {
			if (curr_row > 0) {				//This keeps curr_row from underflowing - min value of curr_row is 0
				curr_row--;
				curr_digit = curr_digit - 3;
			}
		}
		else if (inst == 'D') {
			if (curr_row < 2) {				//This keeps curr_row from overflowing - max value of curr_row is 2.
				curr_row++;
				curr_digit = curr_digit + 3;
			}
		}
		else if (inst == 'R') {
			mod_dec = ((~curr_row & 3) - 1) * 3 + 1;		//This gets the value of the first element of each row
			if (curr_digit + mod_dec < 10) {
				curr_digit++;
			}
		}
		else if (inst == 'L') {
			mod_dec = curr_row * 3 + 1;		//This gets the value of the first element of each row
			if (curr_digit - mod_dec > 0) {
				curr_digit--;
			}
		}
		else if (inst == '\n') {
			std::cout << curr_digit;
		}
		else {
			std::cout << "ERROR: Character not recognized";
		}

	}
	std::cout << "\n";
	input_file.close();
	return 0;
}