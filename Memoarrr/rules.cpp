//
// Created by Bouabdallah on 11/25/2018.
//

#include "rules.h"

bool Rules::isValid(const Game& _game)  {
    cardLeft = cardLeft-1;
    if (_game.getPreviousCard()==nullptr) return true;
    return _game.getCurrentCard()->getAnimal()== _game.getPreviousCard()->getAnimal() || _game.getCurrentCard()->getColor()== _game.getPreviousCard()->getColor();
};

int Rules::getCardLeft() const {return cardLeft;}

void Rules::setCardLeft(const int cardL)  { cardLeft = cardL;}

bool Rules::gameOver(const Game& _game) const {
    return  _game.getRound()==7;
}

bool Rules::roundOver(const Game& _game) {

    int numberPlayerActiveLeft= 0;
    for(int k = 0; k<numberPlayer;k++){

        if( _game.getPlayer((Side)k).isActive()==true)
            numberPlayerActiveLeft++;
    }


    if(numberPlayerActiveLeft==1 || cardLeft==0)
    {
        cardLeft=24; //reset
        return true;
    }
    else {
        return false;
    }

}

const Player& Rules::getNextPlayer(const Game& g ){
    currentPlayer = (currentPlayer+1)%(numberPlayer);
    return g.getPlayer((Side)(currentPlayer));
};


Rules::Rules(const int n){
    numberPlayer= n;
}




