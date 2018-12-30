//
// Created by Bouabdallah on 11/28/2018.
//

#include "expertBoard.h"

ExpertBoard::ExpertBoard() : Board() {
    p_board = new string[5];
    reset();
    Board::numberOfRow=5;


}

ExpertBoard::~ExpertBoard()   {

}

bool ExpertBoard::turnFaceUp(const Letter& letter, const Number& number) {
    int intLetter = static_cast<int>(letter);
    int intNumber = static_cast<int>(number);
    if (intNumber < 0 || intLetter < 0 || intLetter > 4 || intNumber > 4 || (intNumber == 2 && intLetter == 2))
        throw std::out_of_range("Number or Letter are out of range!");


    if (this->isFaceUp(letter, number))
        return false;


    game_card_pos.push_back(pair<Letter, Number>(letter,number));
    game_card.push_back(getCard(letter,number));


    showNewBoard();


    return true;
}

void ExpertBoard::showNewBoard(){



    int pos = 0;
    for (auto it :  game_card_pos ) {
        Letter _letter =  it.first;
        Number _number =  it.second;
        Card* cardToShow = game_card[pos];
        int intLetter = static_cast<int>(_letter);
        int intNumber = static_cast<int>(_number);

        int l = (pos*4);

    for (int i = 0; i < 3; i++) {
        if(i%2==1)
        {
            p_board[i].replace(l+1,1,1,(*cardToShow).getColor());

            p_board[i].replace(l+2,1,1,(*cardToShow).getAnimal());

            p_board[i].replace(l+3,1,1,(*cardToShow).getColor());


        }
        else
            p_board[i].replace(l+1,3,3,(*cardToShow).getColor());

        p_board[4].replace(l+1,1,1,Board::getLetterConversion(_letter));

        p_board[4].replace(l+2,1,1,Board::getNumberConversion(_number));

        p_board[4].replace(l+3,1,1,' ');

    }



    pos++;

    }
}




bool ExpertBoard::turnFaceDown(const Letter& letter, const Number& number) {
    int intLetter = static_cast<int>(letter);
    int intNumber = static_cast<int>(number);

    //cout<<"LETTER RECEIVED => " << intLetter << " Number receievd " << intNumber<<endl;

    if (intNumber < 0 || intNumber < 0 || intNumber > 4 || intNumber > 4)
        throw std::out_of_range("Number or Letter are out of range!");


    if (!this->isFaceUp(letter, number)) {
        return false;
    }
    int pos = 0;
    for (pair<Letter,Number> it :  game_card_pos) {
        Letter _letter =  std::get<0>(it);
        Number _number =  std::get<1>(it);
        if((letter == _letter ) && (number==_number) ) {
            game_card_pos.erase(game_card_pos.begin()+pos);
            game_card.erase(game_card.begin()+pos);
            return true;

        }
        pos++;
    }
    return false;
}





void ExpertBoard::reset(){
    string empty(static_cast<size_t>(96), static_cast<char>(' '));  // big enough for 24 card + 1 space
    for (int i = 0; i < 5; i++) {
        p_board[i] = empty;
    }
    game_card.clear();
    game_card_pos.clear();
}