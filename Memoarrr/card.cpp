//
// Created by Bouabdallah on 11/23/2018.
//

#include "card.h"


#include <stdexcept>


Card::Card(FaceAnimal animal, FaceBackground background){

    p_animal=animal;
    p_color= background;
    p_numbRows=3;
    int animalzer = static_cast<int>(animal);
    int backgroundzer = static_cast<int>(background);

    char p_animalChar[5] =  {'W','P','T','C','O'};
    char colorChar[5] =  {'B','G','R','P','Y'};
    p_cardRow = new string[3];
    p_cardRow[0].replace(0,3,3,colorChar[backgroundzer]);
    p_cardRow[1].replace(0,1,1,colorChar[backgroundzer]);
    p_cardRow[1].replace(1,1,1,colorChar[animalzer]);
    p_cardRow[1].replace(2,1,1,colorChar[backgroundzer]);
    p_cardRow[2].replace(0,3,3,colorChar[backgroundzer]);







};



    char Card::getAnimal() const{

        switch((int)p_animal) {
            case (int) 0 : return 'W';
            case (int) 1 : return 'P';
            case (int) 2: return 'T';
            case (int) 3 : return 'C';
            case (int) 4: return 'O';


        }
    };


char Card::convertAnimal(FaceAnimal anim) const{

    switch((int)anim) {
        case (int) 0 : return 'W';
        case (int) 1 : return 'P';
        case (int) 2: return 'T';
        case (int) 3 : return 'C';
        case (int) 4: return 'O';


    }
};

    char Card::getColor() const{

        switch((int)p_color) {
            case 0: return 'B';
            case 1 : return 'G';
            case 2 : return 'R';
            case 3 : return 'P';
            case 4 : return 'Y';

        }

    };


char Card::convertColor(FaceBackground color)  const{

    switch(color) {
        case FaceBackground::Blue : return 'B';
        case FaceBackground::Green : return 'G';
        case FaceBackground::Red : return 'R';
        case FaceBackground::Purple : return 'P';
        case FaceBackground::Yellow : return 'Y';

    }

};



bool Card::getStatus() const{
    return p_status;
}

void Card::setStatus(const bool b ){
    p_status= b;
}



string Card::operator()( const int row) const {

    if(row > p_numbRows)
        throw std::out_of_range("Number of Row furnished is out of range!");

    return this->p_cardRow[row];


}





ostream& operator<<(ostream& os, const Card& card) {

    for (int i = 0; i <= 2; i++) {
            os << card(i) ;
            os<<endl;
    }

    return os;
};


Card::~Card(){
   delete p_cardRow;
};


