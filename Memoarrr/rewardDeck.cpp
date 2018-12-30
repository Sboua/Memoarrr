//
// Created by Bouabdallah on 11/23/2018.
//

#include "rewardDeck.h"


RewardDeck* RewardDeck::rewardGame = nullptr;

Reward* RewardDeck::getNext()
    {
        if(pos==7) pos = -1;
        //T* elem = p_deckGame[i];
        pos++;
        //p_deckGame.erase(p_deckGame.begin());
        return p_deckGame[pos];;
    };

void RewardDeck::shuffle(){
    std::random_shuffle(p_deckGame.begin(),p_deckGame.end());
};

RewardDeck& RewardDeck::make_rewardDeck(){



    if (rewardGame == nullptr) {
        rewardGame =new RewardDeck;


        while (rewardGame->p_init_deckElem.size() != 7) {



            Reward *r1 = new Reward(1);
            for(int i = 0;i<3;i++)
            rewardGame->p_init_deckElem.push_back(r1);
            r1 = new Reward(2);
            for(int i = 0;i<2;i++)
                rewardGame->p_init_deckElem.push_back(r1);
            r1 = new Reward(3);
            rewardGame->p_init_deckElem.push_back(r1);
            r1 = new Reward(4);
            rewardGame->p_init_deckElem.push_back(r1);
            rewardGame->pos++;
        }

    }



    if(rewardGame->p_deckGame.empty()) {

        rewardGame->p_deckGame.swap(rewardGame->p_init_deckElem);

    }




    return *RewardDeck::rewardGame;

};

bool RewardDeck::isEmpty()const  {
    return pos==7;
};


RewardDeck::~RewardDeck() {
    for (std::vector<Reward*>::iterator it = p_deckGame.begin() ; it != p_deckGame.end(); ++it)
    {
        delete (*it);
    }
    p_deckGame.clear();


    for (std::vector<Reward*>::iterator it = p_init_deckElem.begin() ; it != p_init_deckElem.end(); ++it)
    {
        delete (*it);
    }
    p_init_deckElem.clear();

};