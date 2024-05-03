#include "StrOutput.h"

void StrOutput::pIO(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		std::cout << str[i];
		Sleep(5);
	}
}

/*


	s = str;
	for (size_t i = 0; i < (*s).size(); i++)
	{
		std::cout << str[i];
		Sleep(100);
	}
*/


