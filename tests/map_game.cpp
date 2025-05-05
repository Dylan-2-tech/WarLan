#include <iostream>
#include <vector>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <chrono>
#include <thread>

void drawMap(const std::vector<std::string>& map) {
    std::cout << "\033[H"; // Move cursor to top-left
    for (const auto& row : map) {
        std::cout << row << "\n";
    }
    std::cout << std::flush;
}

// Set terminal to raw mode
void setRawMode(bool enable) {
    static termios oldt;
    static bool rawEnabled = false;

    if (enable && !rawEnabled) {
        termios newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        rawEnabled = true;
    } else if (!enable && rawEnabled) {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        rawEnabled = false;
    }
}

// Non-blocking keypress check
int kbhit() {
    termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int main() {
    setRawMode(true);
    std::cout << "\033[2J\033[?25l" << std::flush; // Clear screen + hide cursor

    std::vector<std::string> map = {
        "##########",
        "#        #",
        "#        #",
        "#   P    #",
        "##########"
    };

    int x = 4, y = 3; // Initial position

    while (true) {
        drawMap(map);

        if (kbhit()) {
            char input = getchar();
            map[y][x] = ' '; // Erase old position

            if (input == 'w' && map[y - 1][x] == ' ') y--;
            else if (input == 's' && map[y + 1][x] == ' ') y++;
            else if (input == 'a' && map[y][x - 1] == ' ') x--;
            else if (input == 'd' && map[y][x + 1] == ' ') x++;
            else if (input == 'q') break;

            map[y][x] = 'P'; // Draw new position
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    setRawMode(false);
    std::cout << "\033[?25h" << std::endl; // Show cursor
    return 0;
}

