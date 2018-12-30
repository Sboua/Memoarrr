//
// Created by Bouabdallah on 11/25/2018.
//

#ifndef MEMOARRR_RULES_H
#define MEMOARRR_RULES_H

#include "game.h"
#include "config.h"
static void testrules();

class Rules{
    int cardLeft =24; //cardleft on the table


protected :
    int getCardLeft() const;
    int currentPlayer;
    void setCardLeft(const int);
    int numberPlayer=0;

public:
    bool isValid(const Game&) ;
    Rules(const int);
    bool gameOver(const Game&) const;
    bool roundOver(const Game&) ;
    const Player& getNextPlayer(const Game& );
    friend  void testrules();
};

#ifdef testRules

static void testrules(){
    cout<<" TESTING RULES ! " <<endl;
    Rules r(2);
    vector<Player*> players;
    Player* p1 = new Player("A",Side::TOP);
    players.push_back(p1);
     p1 = new Player("B",Side::RIGHT);
    players.push_back(p1);
    Game game(1,players);
    cout<<"Testing getNextPlayer"<<endl;
    cout<<r.getNextPlayer(game)<<endl;
    cout<<"get next player"<<endl;
    cout<<r.getNextPlayer(game)<<endl;
    cout<<"testing roundOver"<<endl;
    cout<<r.roundOver(game)<<endl;
    cout<<"testing gameOver" <<endl;
    cout<<r.gameOver(game)<<endl;
    cout<<"testing is valid"<<endl;
    cout<<true<<endl;
    cout<<"DONE"<<endl;

}

#endif


#endif //MEMOARRR_RULES_H
