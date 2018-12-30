//
// Created by Bouabdallah on 11/23/2018.
//

#ifndef MEMOARRR_GAME_H
#define MEMOARRR_GAME_H

#include<vector>

#include "card.h"

#include "player.h"
#include "expertBoard.h"
#include "config.h"



class Game {

    //var
    int p_round;
    Card* p_currentCard;
    Card* p_prevCard;
    int p_version;
    vector<Player*> players;
    bool p_isOver;
    int p_numPlayer;






public :
    //func
    int getRound() const;
    Game( const int ,   vector<Player*>);
    Game()=default;

    void addPlayer( const  Player& );
    Player& getPlayer(Side) const;
    Card* getPreviousCard() const;
    Card* getCurrentCard() const;
    Board* p_boardGame;
    void setCurrentCard( const Card*) ;
    Card* getCard( const Letter&, const Number& ) const;
    void setCard( const Letter&, const Number&,  Card* ) ;
    friend ostream& operator<<(ostream& os, const Game& game);
    void nextRound();
    ~Game();

};

#ifdef gameTest
#include "cardDeck.h"
static void testGame(){
    CardDeck::make_CardDeck().shuffle();
    cout<<"testing game " <<endl;
    vector<Player*> players;
    Player* p1 = new Player("Sofiane",Side::TOP);
    players.push_back(p1);
    p1 = new Player("Jstin",Side::RIGHT);
    players.push_back(p1);
    Game game= Game(1,players);
    cout<<"testing get player, the player in side right is Jstin, should return this "<<endl;
    cout<<"player return with game.getPlayer(RIGHT) => " << game.getPlayer(Side::RIGHT).getName()<<endl;
    cout<<"Setting card in place  <A,1>"<<endl;
    game.setCard(Letter::A,Number::One,CardDeck::make_CardDeck().getNext());
    cout<<"getting card in place <A,1> =>" <<endl;
    cout<<*game.getCard(Letter::A,Number::One)<<endl;
    game.setCard(Letter::A,Number::Two,CardDeck::make_CardDeck().getNext());
    cout<<"testing setCurrentCard"<<endl;
    game.setCurrentCard(game.getCard(Letter::A,Number::One));
    cout<<*game.getCurrentCard()<<endl;
    game.setCurrentCard(game.getCard(Letter::A,Number::Two));
    cout<<"setting a un new card now the previous card needs to be the previous current card"<<endl;
    cout<<"printing current card"<<endl;
    cout<<*game.getCurrentCard()<<endl;
    cout<<"printing previous card"<<endl;
    cout<<*game.getPreviousCard()<<endl;
    cout<<"done"<<endl;
    delete p1;


}

#endif

#endif //MEMOARRR_GAME_H
