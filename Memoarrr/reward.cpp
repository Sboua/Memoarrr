//
// Created by Bouabdallah on 11/23/2018.
//

#include "reward.h"
#include <stdlib.h>

Reward::Reward():p_rubies{rand() % 4 + 1}{}

int Reward::getRubiesConversion() const { return p_rubies;} ;

Reward::Reward( const int numb)  :p_rubies(numb) {} ;

ostream& operator<<( ostream& _os, const Reward& _r) {
    _os << "Reward = > " << _r.p_rubies<< " rubies " <<endl;
    return _os;
}


