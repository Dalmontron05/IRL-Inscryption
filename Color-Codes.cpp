//* ANSI text color escape code constants

// Imports
#include <iostream>
#include <string>

using namespace std;

// Functions
class ColorCodes
{
public:
    // Reset
    string RESET = "\033[0m"; // Text Reset

    // Regular Colors
    string BLACK = "\033[0;30m";   // BLACK
    string RED = "\033[0;31m";     // RED
    string GREEN = "\033[0;32m";   // GREEN
    string YELLOW = "\033[0;33m";  // YELLOW
    string BLUE = "\033[0;34m";    // BLUE
    string PURPLE = "\033[0;35m";  // PURPLE
    string CYAN = "\033[0;36m";    // CYAN
    string WHITE = "\033[0;37m";   // WHITE

    // Bold
    string BLACK_BOLD = "\033[1;30m";  // BLACK
    string RED_BOLD = "\033[1;31m";    // RED
    string GREEN_BOLD = "\033[1;32m";  // GREEN
    string YELLOW_BOLD = "\033[1;33m"; // YELLOW
    string BLUE_BOLD = "\033[1;34m";   // BLUE
    string PURPLE_BOLD = "\033[1;35m"; // PURPLE
    string CYAN_BOLD = "\033[1;36m";   // CYAN
    string WHITE_BOLD = "\033[1;37m";  // WHITE

    // Underline
    string BLACK_UNDERLINED = "\033[4;30m";  // BLACK
    string RED_UNDERLINED = "\033[4;31m";    // RED
    string GREEN_UNDERLINED = "\033[4;32m";  // GREEN
    string YELLOW_UNDERLINED = "\033[4;33m"; // YELLOW
    string BLUE_UNDERLINED = "\033[4;34m";   // BLUE
    string PURPLE_UNDERLINED = "\033[4;35m"; // PURPLE
    string CYAN_UNDERLINED = "\033[4;36m";   // CYAN
    string WHITE_UNDERLINED = "\033[4;37m";  // WHITE

    // Background
    string BLACK_BACKGROUND = "\033[40m";  // BLACK
    string RED_BACKGROUND = "\033[41m";    // RED
    string GREEN_BACKGROUND = "\033[42m";  // GREEN
    string YELLOW_BACKGROUND = "\033[43m"; // YELLOW
    string BLUE_BACKGROUND = "\033[44m";   // BLUE
    string PURPLE_BACKGROUND = "\033[45m"; // PURPLE
    string CYAN_BACKGROUND = "\033[46m";   // CYAN
    string WHITE_BACKGROUND = "\033[47m";  // WHITE

    // High Intensity
    string BLACK_BRIGHT = "\033[0;90m";  // BLACK
    string RED_BRIGHT = "\033[0;91m";    // RED
    string GREEN_BRIGHT = "\033[0;92m";  // GREEN
    string YELLOW_BRIGHT = "\033[0;93m"; // YELLOW
    string BLUE_BRIGHT = "\033[0;94m";   // BLUE
    string PURPLE_BRIGHT = "\033[0;95m"; // PURPLE
    string CYAN_BRIGHT = "\033[0;96m";   // CYAN
    string WHITE_BRIGHT = "\033[0;97m";  // WHITE

    // Bold High Intensity
    string BLACK_BOLD_BRIGHT = "\033[1;90m"; // BLACK
    string RED_BOLD_BRIGHT = "\033[1;91m";   // RED
    string GREEN_BOLD_BRIGHT = "\033[1;92m"; // GREEN
    string YELLOW_BOLD_BRIGHT = "\033[1;93m";// YELLOW
    string BLUE_BOLD_BRIGHT = "\033[1;94m";  // BLUE
    string PURPLE_BOLD_BRIGHT = "\033[1;95m";// PURPLE
    string CYAN_BOLD_BRIGHT = "\033[1;96m";  // CYAN
    string WHITE_BOLD_BRIGHT = "\033[1;97m"; // WHITE

    // High Intensity backgrounds
    string BLACK_BACKGROUND_BRIGHT = "\033[0;100m";// BLACK
    string RED_BACKGROUND_BRIGHT = "\033[0;101m";// RED
    string GREEN_BACKGROUND_BRIGHT = "\033[0;102m";// GREEN
    string YELLOW_BACKGROUND_BRIGHT = "\033[0;103m";// YELLOW
    string BLUE_BACKGROUND_BRIGHT = "\033[0;104m";// BLUE
    string PURPLE_BACKGROUND_BRIGHT = "\033[0;105m"; // PURPLE
    string CYAN_BACKGROUND_BRIGHT = "\033[0;106m";  // CYAN
    string WHITE_BACKGROUND_BRIGHT = "\033[0;107m";   // WHITE
};

ColorCodes colors;