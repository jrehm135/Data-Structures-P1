
#include "search.h"

int main(int argc, char *argv[])
{
	std::string word;
	std::string confirm;
	std::string fulltext;
	std::vector<std::string>  arguments;
	std::ifstream file;
	file.open(argv[1]);
	if (file.is_open())
	{
		while (std::getline(file, fulltext))
		{
			std::transform(fulltext.begin(), fulltext.end(), fulltext.begin(), ::tolower);
			arguments.push_back(fulltext);
			//The while statement runs as long as there are strings to grab from a file
			//The rest of the loop changes each string to lowercase, then places it in the vector arguments
		}
		file.close();
	}

	std::cout << "Search for strings by partial match \nType Ctrl-Z to halt\n";
	while (std::cin >> word)
	{
		SearchResultType<std::string> searcher = iterative_binary_search(arguments, word);
		std::string result = searcher.value;
		bool filter = searcher.found;

		if (filter)
		{
			std::cout << "found: accepting " << word << "\n";
		}
		//This runs if the value was found
		else 
		{
			std::cout << "not found: accept " << result << "? Y/N" << "\n";
			bool cheese = false;
			while (!cheese)
			{
				std::cin >> confirm;
				if (confirm == "y" || confirm == "Y" || confirm == "yes" || confirm == "Yes" || confirm == "YES")
				{
					std::cout << "ok: accepting " << result << "\n";
					cheese = true;
				}
				else if (confirm == "n" || confirm == "N" || confirm == "no" || confirm == "No" || confirm == "NO")
				{
					std::cout << "ok: rejecting " << result << "\n";
					cheese = true;
				}
				else std::cout << "Sorry, command not recognized. Try again" << "\n";
			}
			//This runs until either Yes or No are entered, to confirm whether or not the closest value was ok
		}

		std::cout << "Search for strings by partial match" << "\n" << "Type Ctrl-Z to halt" << "\n";
		//This line was placed at the end so that it runs before the Cin at the top of the loop
	}
	return 0;
}


