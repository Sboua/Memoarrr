//
// Created by Bouabdallah on 11/23/2018.
//

#ifndef MEMOARRR_REWARDDECK_H
#define MEMOARRR_REWARDDECK_H

#include "deck.h"
#include "reward.h"





class RewardDeck : public deck<Reward> {


    RewardDeck& operator=(RewardDeck const&){};
    static RewardDeck* rewardGame;
    int pos= -1;
    RewardDeck(RewardDeck const&){};
    RewardDeck()=default;


public :



    virtual bool isEmpty()const  ;
    virtual Reward* getNext();
    void shuffle();
    static RewardDeck& make_rewardDeck();
    ~RewardDeck();

};


#if testingRewardDeck

static void testRDeck(){
    cout<<"Testing RewardDeck"<<endl;
    cout<<"testing empty"<<endl;
    cout<<RewardDeck::make_rewardDeck().isEmpty()<<endl;
    cout<<"using getNext"<<endl;
    cout<<*RewardDeck::make_rewardDeck().getNext()<<endl;
    cout<<"using next to print to first element before shuffle (notice diferent memory adress)"<<endl;
    cout<<RewardDeck::make_rewardDeck().getNext()<<endl;
    cout<<RewardDeck::make_rewardDeck().getNext()<<endl;
    RewardDeck::make_rewardDeck().shuffle();
    cout<<"after shuffle"<<endl;
    cout<<RewardDeck::make_rewardDeck().getNext()<<endl;
    cout<<RewardDeck::make_rewardDeck().getNext()<<endl;
    cout<<"DONE"<<endl;
}

#endif

#endif //MEMOARRR_REWARDDECK_H
