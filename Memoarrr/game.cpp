//
// Created by Bouabdallah on 11/23/2018.
//

#include "game.h"
#include "rewardDeck.h"


Game::Game(const int v,  vector<Player*> pl  ) {
    p_version=v;
    players.swap(pl);

    p_round=0;
    if(v ==1){
        p_boardGame=new Board();
    }
    else p_boardGame = new ExpertBoard();

};

int Game::getRound() const {
    return p_round;
};

Player& Game::getPlayer(Side s) const
    {
    for (auto p: players){
    }
        if ((int)s < players.size() && players[(int)s] != nullptr) {
            return *(players[(int) s]);
        }
    }

void Game::addPlayer( const  Player& player){
    int i =0;
    for(auto p : players)
    {
        if(p!=nullptr){

        if (p->getSide()==player.getSide()){

            p->setActive(player.isActive());
            return;
        }}
        i++;
    }

    players[(int)player.getSide()] =  new Player(player);
}



ostream& operator<<(ostream& os, const Game& game) {
        for(auto p : game.players)
            os <<  *p <<endl;
            os<<*game.p_boardGame;
        os<<endl;

    return os;
};

Card* Game::getPreviousCard() const{
    return p_prevCard;
};

Card* Game::getCurrentCard() const{
    return p_currentCard;
};

void Game::setCurrentCard( const Card* c) {
    this->p_prevCard = this->p_currentCard;
    this->p_currentCard= const_cast<Card*>(c);
};

Card* Game::getCard( const Letter& letter, const Number& number ) const{
    return p_boardGame->getCard(letter,number);
};

void Game::setCard( const Letter& letter, const Number& number,  Card* c ) {
    p_boardGame->setCard(letter,number,c);
};

void Game::nextRound() {
    p_round++;
    p_currentCard = 0;
    p_prevCard=0;

    if(p_round!=7) {
        for (auto player : players) {
            if (player->isActive()) player->addReward(*RewardDeck::make_rewardDeck().getNext());
        }

        for (auto player : players) {
            player->setActive(true);
        }
    }

}


Game::~Game(){
    for (std::vector<Player*>::iterator it = players.begin() ; it != players.end(); ++it)
    {
        delete (*it);
    }
    players.clear();

    delete p_boardGame;
}

