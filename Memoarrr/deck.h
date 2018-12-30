//
// Created by Bouabdallah on 11/23/2018.
//

#ifndef MEMOARRR_DECK_H
#define MEMOARRR_DECK_H

#include<vector>
#include <algorithm>





using namespace std;

template<typename T> class deck {

protected:

    deck() =default;
public:
    vector<T*> p_init_deckElem;
    vector<T*> p_deckGame;

    virtual void shuffle(){
        std::random_shuffle(p_deckGame.begin(),p_deckGame.end());
    };


    virtual T* getNext();


    virtual bool isEmpty() const{
        return p_deckGame.empty();
    };

    virtual ~deck() {};


};


template<class T>
T* deck<T>::getNext(){
    T* elem = p_deckGame[0];
    p_deckGame.erase(p_deckGame.begin());
    return elem;
};


#endif //MEMOARRR_DECK_H

