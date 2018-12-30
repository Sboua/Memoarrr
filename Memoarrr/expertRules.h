//
// Created by Bouabdallah on 11/26/2018.
//

#ifndef MEMOARRR_EXPRETRULES_H
#define MEMOARRR_EXPRETRULES_H


#include "rules.h"

class ExpertRules : public Rules
{
private:

    Letter cardBlockedL, enteredCardLetter;
    Number cardBloeckN, enteredCardNum;
    bool walrusEnabled = false;

public:
    ExpertRules(const int a) : Rules(a) {};
    ~ExpertRules()=default;
    bool isValid(Game&);
    void walrus(Game&, const Letter, const Number);
    bool isWalrusPrev(Game& , Letter& , Number& );
    bool crabOpened(Game& game );
    void Octopus(Game& game,const Letter, const Number);
    void pinguinEffect(Game& game);
    void turtleEffect(const Game&);

};


#endif //MEMOARRR_EXPRETRULES_H
