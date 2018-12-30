//
// Created by Bouabdallah on 11/23/2018.
//

#ifndef MEMOARRR_REWARD_H
#define MEMOARRR_REWARD_H
#include "config.h"
#include<iostream>
using namespace std;



class Reward;
ostream& operator<<( ostream&, const Reward& );

static void testReward();
//override << operator



class Reward{
    Reward(Reward const&){};
    Reward& operator=(Reward const&){};
    int p_rubies;
    Reward();
    friend class RewardDeck;
    friend ostream& operator<<( ostream&, const Reward& );
    Reward(const int);

public :

    int getRubiesConversion()   const ;
    friend  void testReward();
    ~Reward()=default;
};

#ifdef testingReward

    static void testReward(){
        cout<<"Testing reward with 4 rubies"<<endl;
        Reward r(4);

        cout<<"testing getRubiesConversion"<<endl;
        cout<<r.getRubiesConversion()<<endl;
        cout<<"Done"<<endl;
    }



#endif






#endif //MEMOARRR_REWARD_H
