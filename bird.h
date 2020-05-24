#ifndef BIRD_H
#define BIRD_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "ground.h"



class Bird: public sf::Sprite
{
public:
    Bird(int PosX, int PosY);
    ~Bird();

    void Draw(sf::RenderWindow&window);


    void animate(sf::Time &elapsed);

    int PosX=100;
    int PosY=400;
    int acceleration=130;


    sf::Texture texture_bird1,texture_bird2,texture_bird3,texture_bird4;
    sf::Sprite bird;
    std::vector<sf::Texture> _animationBirdFrame;

    unsigned int _animationBirdIterator;

    sf::Clock _clock;
};

#endif // BIRD_H
