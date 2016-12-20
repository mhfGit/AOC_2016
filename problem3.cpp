#include <iostream>
#include <fstream>
#include <stdlib.h>

int main()
{
	std::fstream input_file("problem3_input.txt");

	char inst[256];
	int total = 0;
	int oneside;
	int secside;
	int thirdside;
	while (!input_file.eof()) {
		input_file.getline(inst, 256);
		oneside = atoi(inst);
		char * temp = inst + 5;
		secside = atoi(temp);
		temp = inst + 10;
		thirdside = atoi(temp);

		if (oneside + secside < thirdside) {
			continue;
		}
		else if (secside + thirdside < oneside) {
			continue;
		}
		else if (thirdside + oneside < secside) {
			continue;
		}
		else {
			total++;
		}
	}
	std::cout << total << "\n";
	input_file.close();
	return 0;
}