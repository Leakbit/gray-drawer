#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <windows.h>
#include "buttons.h"

uint8_t pixels[900][900];
uint8_t pencil_size=1; 



int main()
{   

    sf::Texture texture;
    if (!texture.loadFromFile("images/plus.png"))
    {
        // error...
    }
    if (!texture.create(32, 32))
    {
        // error...
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    textures buttons;
    buttons.add("plus.png",32,32,5,5);
    buttons.add("minus.png",32,32,47,5);
    buttons.add("clear.png",32,32,89,5);

    sf::RenderWindow window(sf::VideoMode(900, 900), "DrawBin");

    while (window.isOpen()){
        sf::Event event;

        // while there are pending events...
        while (window.pollEvent(event)){
            // check the type of the event...
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if(event.mouseButton.button == sf::Mouse::Left){
                        sf::Vector2i position = sf::Mouse::getPosition(window);
                        if(buttons.click_check(position.x , position.y)!=-1){
                            int id= buttons.click_check(position.x, position.y);
                            switch (id)
                            {
                            case 0:
                                pencil_size+=2;
                                std::cout << "pencil_size +2" << pencil_size << std::endl;
                                break;
                            case 1:
                                pencil_size-=2;
                                break;
                            case 2:
                                memset(pixels , 0 ,sizeof(pixels));
                            default:
                                break;
                            }
                            
                        }
                    }

                default:
                    break;
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i position = sf::Mouse::getPosition(window);
            if(position.y>40 && position.x < 900  && position.y < 900 && position.x > 0 && position.x > 0 )
                pixels[position.x][position.y]=1;
        }
        else if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
            sf::Vector2i position = sf::Mouse::getPosition(window);
            pixels[position.x][position.y]=0;
        }

        window.clear();
        for (int x = 0; x < 900; x++){
            for(int y=0; y<900; y++){
                if(pixels[x][y]==1){
                sf::CircleShape  pixel(pencil_size);
                pixel.setFillColor(sf::Color::White);
                pixel.setPosition(x-pencil_size/2+1,y-pencil_size/2+1);
    //            std::cout << i%900 << ',' << i/900 << std::endl;
                window.draw(pixel);
                }
            }
        }
    //    Sleep(500);
    window.draw(*buttons.sprites.at(0));
    window.draw(*buttons.sprites.at(1));
    window.draw(*buttons.sprites.at(2));
        window.display();
    }

    return 0;
}