//
// Created by Bouabdallah on 11/23/2018.
//

#include "board.h"

char Board::getLetterConversion(const Letter l) const {
    char s[5]  ={'A','B','C','D','E'};
    return s[(int)l];
}

char Board::getNumberConversion(const Number num) const  {
    char n[5]  ={'1','2','3','4','5'};
    return n[(int)num];
}

Board::Board() {


    p_board = new string[21];
    string empty(static_cast<size_t>(20), static_cast<char>(' '));

    //p_board= new char*[20];
    for (int i = 0; i < 21; i++) {
        p_board[i] = empty;

    }

    p_board[1].at(0) = 'A';
    p_board[5].at(0) = 'B';
    p_board[9].at(0) = 'C';
    p_board[13].at(0) = 'D';
    p_board[17].at(0) = 'E';
    p_board[19].at(2) = '1';
    p_board[19].at(6) = '2';
    p_board[19].at(10) = '3';
    p_board[19].at(14) = '4';
    p_board[19].at(19) = '5';

    reset();

};


bool Board::turnFaceUp(const Letter& letter, const Number& number) {
    int intLetter = static_cast<int>(letter);
    int intNumber = static_cast<int>(number);

   // cout<<"LETTER RECEIVED => " << intLetter << " Number receievd " << intNumber<<endl;

    if (intNumber < 0 || intNumber < 0 || intNumber > 4 || intNumber > 4)
        throw std::out_of_range("Number or Letter are out of range!");



    if (this->isFaceUp(letter, number)) {
        return false;
    }

    Card* cardToBeShown = getCard(letter, number);

    int k =  (intLetter * 4);
    int l = (  intNumber * 4);



    for (int i = (intLetter * 4); i < (3 + intLetter * 4); i++) {
        if(i%2==1)
        {
            p_board[i].replace(l+1,1,1,(*cardToBeShown).getColor());
            p_board[i].replace(l+2,1,1,(*cardToBeShown).getAnimal());
            p_board[i].replace(l+3,1,1,(*cardToBeShown).getColor());

        }
        else
            p_board[i].replace(l+1,3,3,(*cardToBeShown).getColor());

    }
    return true;
}



bool Board::turnFaceDown(const Letter& letter, const Number& number) {
    int intLetter = static_cast<int>(letter);
    int intNumber = static_cast<int>(number);

    //cout<<"LETTER RECEIVED => " << intLetter << " Number receievd " << intNumber<<endl;

    if (intNumber < 0 || intNumber < 0 || intNumber > 4 || intNumber > 4)
        throw std::out_of_range("Number or Letter are out of range!");



    if (!this->isFaceUp(letter, number)) {
        return false;
    }

    Card* cardToBeShown = getCard(letter, number);

    int k =  (intLetter * 4);
    int l = (  intNumber * 4);


    for (int i = (intLetter * 4); i < (3 + intLetter * 4); i++) {

            p_board[i].replace(l+1,3,3,'z');

    }
    return true;
}


    bool Board::isFaceUp(const Letter& letter, const Number& number) const {
        int intLetter = static_cast<int>(letter);
        int intNumber = static_cast<int>(number);
        if (intNumber < 0 || intLetter < 0 || intNumber > 4 || intLetter > 4)
            throw std::out_of_range("Number or Letter are out of range!");

        return p_board[1+intLetter*4].at(1 + intNumber * 4) != 'z';
    };



    ostream& operator<<(ostream& os, const Board& board) {
        for (int i = 0; i <board.numberOfRow ; i++) {
            os << board.p_board[i] ;
            os<<endl;
        }

        return os;
    };



void Board::reset() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 21; j++) {
            if (!(i == 19 || (i % 4 == 3) || (j % 4 == 0)))
                p_board[i].at(j) = 'z';
        }


    }

    for(int i =9;i<12;i++){
        for(int j =8;j<12;j++){
            p_board[i].at(j) = ' ';
            p_board[j].at(i) = ' ';
        }
    }

    };


Card* Board::getCard( const Letter& letter, const Number& number)const {
    int intLetter = static_cast<int>(letter);
    int intNumber = static_cast<int>(number);
    if (intNumber < 0 || intLetter < 0 || intNumber > 4 || intLetter > 4)
        throw std::out_of_range("Number or Letter are out of range!");


    return  (Card*)( card_loc.find(pair<Letter, Number>(letter, number))->second);
}

void Board::setCard( const Letter& letter, const Number& number,  Card* card){
    int intLetter = static_cast<int>(letter);
    int intNumber = static_cast<int>(number);
    std::map<pair<Letter,Number>,Card*>::iterator it;
    it=card_loc.find(pair<Letter, Number>(letter, number));
    if (it != card_loc.end())
        card_loc.erase(it);
    if (intNumber < 0 || intLetter < 0 || intNumber > 4 || intLetter > 4)
        throw std::out_of_range("Number or Letter are out of range!");
    card_loc.insert(std::make_pair(pair<Letter, Number>(letter, number), card));
}


Board::~Board() {
    delete p_board;
}
