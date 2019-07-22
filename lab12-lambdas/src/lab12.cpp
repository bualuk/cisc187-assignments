#include <cstring>
#include <iostream>
#include <string>

// Try this:
//
// Rewrite this program to use lambdas to perform the rotation instead of traditional function calls

// a pointer to the function that will transform a character
using transform = char (*)(const char c);

// forward declarations
static void usage(const char* name);
static void help (const char* name);

// rotate a character 13 places in the alphabet
// This function assumes a basic 26 letter Latin alphabet
char rot13(const char c) {
    if (!std::isalpha(c)) return c;   // if not a Latin letter, do nothing & return the current char

    // in order to rotate upper or lower case
    // need to know where the alphabet 'starts'
    const char start = std::islower(c) ? 'a' : 'A';
    return (c - start + 13) % 26 + start;
}

// rotate a character 47 places in the set of printable ASCII characters
char rot47(const char c) {
    // first printable character = 33 = '!'
    static constexpr char start = '!';
    if (c < start) return c;
    return (c - start + 47) % 94 + start;
}

// Use either a 'character handler' (rot13 or rot47)
void render_text(std::string message, transform handler) {
    for (const auto& c: message) {
        std::cout << handler(c);
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    // Define a default a 'character handler'
    // the variable 'handler' provides an option to swap in different encryption function
    transform handler = rot13;

    for (int i=1; i < argc; ++i) {
        if (!std::strcmp(argv[i], "-h")) {
            help(*argv);
        } else if (!std::strcmp(argv[i], "-l")) {
            handler = rot13;
        } else if (!std::strcmp(argv[i], "-f")) {
            handler = rot47;
        } else {
            usage(*argv);
            exit(-1);
        }
    }

    std::string message;
    while (getline(std::cin,message)) {
        render_text(message, handler);
    }
}

static void usage(const char* name) {
    std::cerr << "Encrypt or decrypt a single line of text read from standard input\n"
        << "Usage: " << name << " [-h|l|f]\n";
}

static void help (const char* name) {
    usage(name);
    std::cerr << "Options:\n"
        << "  -h   Show this text\n"
        << "  -l   En(de)crypt using the Latin characters ([A-Z,a-z]\n"
        << "         (default)\n"
        << "  -f   En(de)crypt using the Full set of printable ASCII characters\n"
        << "\nRunning with no input from standard in enters 'interactive mode'.\n"
        << "Text can be entered one per line.\n"
        << "The program runs until 'CTRL+C' is entered or EOF is reached.\n\n"
        << "Running on plain text creates cipher text\n"
        << "Running on cipher text creates plain text\n\n";
    exit(0);
}


