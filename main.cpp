/*
    This code file (main.cpp) contains the main function that runs the game
    all libraries that must be used have to be included here.

    g++ -c main.cpp board.cpp piece.cpp pieceTextures.cpp chessGame.cpp -I <sfml-install-path>\include -mwindows
    2) g++ main.o board.o piece.o pieceTextures.o chessGame.o -mwindows -L <sfml-install-path>\lib -lsfml-graphics -lsfml-window -lsfml-system
    3) You need to have sfml-graphics-2.dll , sfml-system-2.dll and sfml-window-2.dll in the same folder as the exe
    4) Open a.exe
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "chessGame.h"


int main(){
    ChessGame chess(sf::Color(0xf3bc7aff),sf::Color(0xae722bff));

    sf::RenderWindow window(sf::VideoMode(768,512), "Chess", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    while(window.isOpen()){
        
        sf::Event event;

        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    if((0 <= event.mouseButton.x) && (event.mouseButton.x <= 512) && (0 <= event.mouseButton.y) && (event.mouseButton.y <= 512)){
                        unsigned int buttonPos{(event.mouseButton.x/64) + ((event.mouseButton.y/64) * (8 * (512/window.getSize().y)))};
                                                
                        if(!chess.getSelected())
                            chess.selectPiece(buttonPos);
                        else
                            chess.moveSelected(buttonPos);
                    }
                    else if((517 <= event.mouseButton.x) && (event.mouseButton.x <= 763) && (5 <= event.mouseButton.y) && (event.mouseButton.y <= 45)){
                        chess.restart();
                    }
                }
            }
        }

        window.draw(chess);
        window.display();
    }
}