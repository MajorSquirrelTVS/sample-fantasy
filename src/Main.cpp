#include <fstream>
#include <iostream>

#include <SFML/Window.hpp>

#ifdef _WIN32
    #include <direct.h>
    #define getcwd _getcwd
#elif
    #include <unistd.h>
#endif

int main(int ac, char** av) {
    sf::Window  window;

    window.create(sf::VideoMode(800, 600), "sample_fantasy");
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}