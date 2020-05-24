#include "gameover.h"
#include "pipes.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Points.h"



GameOver::GameOver()
{
 if(!texture_Game_Over.loadFromFile("C:/Users/Grzechu/Pictures/ptak1.png")){std::cout<<"Fail game_over_tx load"<<std::endl;exit(0);}
 Game_over.setTexture(texture_Game_Over);
 Game_over.setPosition(50,120);
 Game_over.setScale(1,1);

 if(!texture_ScoreBoard.loadFromFile("C:/Users/Grzechu/Pictures/scoreboard.png")){std::cout<<"Fail score_board_tx load"<<std::endl;exit(0);}
 ScoreBoard.setTexture(texture_ScoreBoard);
 ScoreBoard.setPosition(50,120);
 GoldMedal.setScale(1,1);

 if(!texture_GoldMedal.loadFromFile("C:/Users/Grzechu/Pictures/ptak1.png")){std::cout<<"Fail gold_medal_tx load"<<std::endl;exit(0);}
 GoldMedal.setTexture(texture_GoldMedal);
 GoldMedal.setPosition(50,120);
 GoldMedal.setScale(1,1);


 if(!texture_SilverMedal.loadFromFile("C:/Users/Grzechu/Pictures/ptak1.png")){std::cout<<"Fail silver_medal_tx load"<<std::endl;exit(0);}
 SilverMedal.setTexture(texture_SilverMedal);
 SilverMedal.setPosition(50,120);
 SilverMedal.setScale(1,1);


 if(!texture_BronzeMedal.loadFromFile("C:/Users/Grzechu/Pictures/ptak1.png")){std::cout<<"Fail bronze_medal_tx load"<<std::endl;exit(0);}
 BronzeMedal.setTexture(texture_SilverMedal);
 BronzeMedal.setPosition(50,120);
 BronzeMedal.setScale(1,1);

}




void GameOver::Draw(sf::RenderWindow &window){
    window.draw(ScoreBoard);
}




void GameOver::PipeCollision(sf::RenderWindow &window, bool isGameOver, int points){
    if(isGameOver){
        window.draw(Game_over);
        window.draw(ScoreBoard);
        if(points>=10&&points<=19){
            window.draw(BronzeMedal);
        }
        else if(points>=20&&points<=39){
            window.draw(SilverMedal);
        }
        else if(points>=40){
            window.draw(GoldMedal);
        }

    }
}
