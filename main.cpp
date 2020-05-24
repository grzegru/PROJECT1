#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <ctime>
#include "pipes.h"
#include "bird.h"
#include "ground.h"
#include "background.h"
#include "collisions.h"
#include "GameMenu.h"
#include "gameover.h"


using namespace std;

sf::Vector2f windowsize(550,750);


//obiekty klas
Pipes pipe1(400,380,0);
Pipes pipe2(400,380,300);
Bird bird(50,400);
Ground ground(0,700);
Background background;
Collisions collision;
GameMenu gamemenu;






//zmienne
bool gamestart=false;


/*void collisi(Bird bird, Ground ground){
    sf::IntRect obiekt1(bird.getGlobalBounds());
    sf::IntRect obiekt2(ground.getGlobalBounds());
    if(obiekt1.intersects(obiekt2)){
        std::cout<<"kolizja";
}
}*/




int main()
{


    sf::RenderWindow window(sf::VideoMode(550,750), "Bird");
    //window.setFramerateLimit(60);
     window.setActive(true);



    sf::Clock clock;



    while (window.isOpen()) {
        sf::Time elapsed=clock.restart();


            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // clear the window with black color
            window.clear(sf::Color::Black);

            // draw everything here...



            background.draw(window);

            /*if(gamestart==false){
                gamemenu.Draw(window);
                gamemenu.click(event,window, gamestart);

            }else if(gamestart==true){
                pipe1.Draw(window);            //rysowanie
                pipe2.Draw(window);


                pipe1.animate(elapsed);         //poruszanie sie rur
                pipe2.animate(elapsed);

                ground.Draw(window);             // rysowanie
                ground.animate(elapsed);        //ruch podłoża

                bird.animate(elapsed);        //ruch skrzydel ptaka , jego latanie w osi OY
                bird.Draw(window);              //rysowanie ptaka

                gamemenu.Draw(window);


            }*/









            pipe1.Draw(window);            //rysowanie
            pipe2.Draw(window);

            pipe1.animate(elapsed);         //poruszanie sie rur
            pipe2.animate(elapsed);

            ground.Draw(window);             // rysowanie
            ground.animate(elapsed);        //ruch podłoża

            bird.animate(elapsed);        //ruch skrzydel ptaka , jego latanie w osi OY
            bird.Draw(window);              //rysowanie ptaka

















            // end the current frame
            window.display();
        }



    return 0;
}
