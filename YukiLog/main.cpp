#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

//#include "constants.h"
//#include "date.h"

int main()
{
	using namespace std;
#if 0
	Date date1;
	Date date2(2000, 1, 1);
	cout << date1 << '\t' << date2 << '\n';
	cin >> date1;
	int year, month, day;
	cin >> year >> month >> day;
	date2.SetDate(year, month, day);
	cout << date1 << '\t' << date2 << '\n';
#endif

#if 0
	ofstream outf("Sample.dat");
	// If we couldn't open the output file stream for writing
	if (!outf)
	{
		// Print an error and exit
		cerr << "Uh oh, Sample.dat could not be opened for writing!" << endl;
		std::cin.get();
		exit(1);
	}
#endif



	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

  return 0;
}

