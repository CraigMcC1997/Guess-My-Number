#include "Instructions_Handler.h"

int Instructions::GetInstructionSize()
{
	return instuction_line_count;
}

string* Instructions::GetInstructions()
{
	return instructions;
}

/**
 * Save scores to text file.
 *
 */
void Instructions::displayInstructions()
{
	for (auto& i : instructions)
	{
		cout << i << endl;
	}
}

void Instructions::updateInstructions(string* updated_text)
{
	int count{};
	for (auto& i : instructions)
	{
		i = updated_text[count];
		count++;
	}
}
