// Author: Alexander Taylor
// Purpose: Implement the program for homework one in CS-1220
// Date: 11 January 2023


#include <iostream>
#include <string>
using namespace std;

int zymain(int, char**);
void reverse(char*, char*);

int main(int argc, char** argv) {

    return zymain(argc, argv);
}

int zymain(int argc, char** argv) {
    // Check that we have the right number of arguments
    if (argc != 4) {
        std::cerr << "Usage: Received " << argc << " argument" <<
            (argc == 1 ? "" : "s") << ", expected 4. (error code 1)";

        return 1;
    }

    size_t frontIndex;
    size_t rearIndex;
    std::string inputString = argv[1];

    // Convert the strings to integers with exception checking
    try {
        frontIndex = std::stoi(argv[2]);
        rearIndex = std::stoi(argv[3]);
    }
    catch (std::invalid_argument const&) {
        std::cerr << "Usage: One or more of the indicies" <<
            " are not a number. (error code 2)";

        return 2;
    }

    // Make sure that the indicies are valid for the string
    if (frontIndex < 0 || rearIndex < 0) {
        std::cerr << "Usage: One or more of the indicies" <<
            " are less than zero. (error code 3)";

        return 3;
    }
    if (frontIndex > rearIndex) {
        std::cerr << "Usage: Front index is greater" <<
            " than the rear index. (error code 3)";

        return 3;
    }
    if (rearIndex >= inputString.length()) {
        std::cerr << "Usage: rear index (" << rearIndex <<
            ") must be less than the length of \"" <<
            argv[1] << "\" (error code 4)";

        return 4;
    }

    // Get the char pointers for the strings
    char* front = &inputString[frontIndex];
    char* rear = &inputString[rearIndex];

    // Reverse the portion of the string that the user requested
    reverse(front, rear);

    // Output to standard out
    std::cout << "Reversing \"" << argv[1] << "\" from index " <<
        frontIndex << " to index " << rearIndex << " yields \"" <<
        inputString << "\"";

    return 0;
}

void reverse(char* front, char* rear) {
    // Recursion base case
    if (front >= rear) {
        return;
    }
    // Call the function with the next pointers
    reverse(&front[1], &rear[-1]);

    // Reverse the characters
    char temp = front[0];
    front[0] = rear[0];
    rear[0] = temp;
}