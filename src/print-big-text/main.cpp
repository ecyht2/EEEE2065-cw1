#include <iostream>
#include "big-text.h"

using namespace std;

int main(int argc, char *argv[]) {
    // Intializing the BigText class
    BigText printer;

    // Looping all argv
    for (int i = 1; i < argc; i++) {
        // Printing out the string
        cout << "string=\"" << argv[i] << '"' << endl;
        // Setting the text and printing the asii-art representation
        printer.setText(argv[i]).print();
    }

    return 0;
}
