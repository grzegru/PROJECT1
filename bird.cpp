#include "bird.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "pipes.h"


Bird::Bird(int PosX, int PosY)
{


    if(!texture_bird1.loadFromFile("C:/Users/Grzechu/Pictures/ptak1.png")){std::cout<<"Fail bird1 load"<<std::endl;exit(0);}
    if(!texture_bird2.loadFromFile("C:/Users/Grzechu/Pictures/ptak2.png")){std::cout<<"Fail bird2 load"<<std::endl;exit(0);}
    if(!texture_bird3.loadFromFile("C:/Users/Grzechu/Pictures/ptak3.png")){std::cout<<"Fail bird3 load"<<std::endl;exit(0);}
    if(!texture_bird4.loadFromFile("C:/Users/Grzechu/Pictures/ptak4.png")){std::cout<<"Fail bird4 load"<<std::endl;exit(0);}




    _animationBirdIterator=0;
    _animationBirdFrame.emplace_back(texture_bird1);
    _animationBirdFrame.emplace_back(texture_bird2);
    _animationBirdFrame.emplace_back(texture_bird3);
    _animationBirdFrame.emplace_back(texture_bird4);


    texture_bird1.setSmooth(true);
    texture_bird2.setSmooth(true);
    texture_bird3.setSmooth(true);
    texture_bird4.setSmooth(true);



    bird.setScale(0.075,0.075);
    bird.setPosition(PosX,PosY);
    bird.setTexture(_animationBirdFrame.at(_animationBirdIterator));

}


Bird::~Bird(){}



    void Bird::animate(sf::Time &elapsed){                                           //to nie wina tej funkcji
        bird.move(0,acceleration*elapsed.asSeconds());
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            bird.move(0,-0.15 );
        }

        if(_clock.getElapsedTime().asSeconds()>0.1){
            if(_animationBirdIterator<_animationBirdFrame.size()-1){
               _animationBirdIterator++;
            }
            else{
                _animationBirdIterator=0;
            }
            bird.setTexture(_animationBirdFrame.at(_animationBirdIterator));
            _clock.restart();
        }
    }



    void Bird::Draw(sf::RenderWindow &window){


        window.draw(bird);
    }

