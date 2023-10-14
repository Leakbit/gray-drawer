#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>


class textures{
    public:
    std::vector<sf::Texture*> objects;
    std::vector<sf::Sprite*> sprites;

    void add(const std::string name , int size_x , int size_y , int pos_x=0 , int pos_y=0){
        sf::Texture* obj= new sf::Texture();
//        sf::Texture texture;
        if (!obj->loadFromFile("images/" + name))
        {
            std::cout << "Texture image not found: " << name ;
        }
        else{
            this->objects.push_back(obj);
        }

        if (!obj->create(size_x, size_y)){std::cout << "Image size is wrong: " << name ;}

        sf::Sprite* sprite= new sf::Sprite();
        sprite->setTexture(*obj);

        sprite->setPosition(pos_x,pos_y);
        
        this->sprites.push_back(sprite);

        std::cout << sprites.size() << std::endl;

    }
    int click_check(int x, int y){
        for(int i=0; i<sprites.size(); i++){
            int obj_x=sprites.at(i)->getPosition().x;
            int obj_y=sprites.at(i)->getPosition().y;
            int obj_sizex=objects.at(i)->getSize().x;
            int obj_sizey=objects.at(i)->getSize().y;


            if( x>=obj_x && x<=obj_x + obj_sizex && y>=obj_y && y<=obj_x + obj_sizey ){
                return i;
            }
        }
        return -1;
    }
};


