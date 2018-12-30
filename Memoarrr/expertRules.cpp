//
// Created by Bouabdallah on 11/26/2018.
//

#include "expertRules.h"


void ExpertRules::Octopus(Game& game,const Letter l, const Number n){
    int newLetter = -1;
    int newNumber = -1;

    int inputLetter = static_cast<int>(l);
    int inputNumber = static_cast<int>(n);


    Card *cTemps = game.getCurrentCard();

    switch (inputLetter) {
        case 4 :
            newLetter = (int) inputLetter - 1;

            break;
        case 1 :
            newLetter = (int) inputLetter + 2;

            break;
        default :
            newLetter = (int) inputLetter + 1;

    }

    switch (inputNumber) {
        case 4 :
            newNumber = (int) inputNumber - 1;

            break;
        case 1 :
            newNumber = (int) inputNumber + 2;

            break;
        default :
            newNumber = (int) inputNumber + 1;

    }



    if (rand() % 2 == 0) {
        game.setCard(l, n,
                     game.getCard(l, static_cast<Number>((newNumber) )));
        game.setCard(l, static_cast<Number>((newNumber) ), game.getCurrentCard());
        game.p_boardGame->turnFaceDown(l, n);
        game.p_boardGame->turnFaceUp(l,static_cast<Number>(newNumber));
    } else {
        game.setCard(l, n,
                     game.getCard(static_cast<Letter>(newLetter ),
                                  n));

        game.setCard((static_cast<Letter>(newLetter)), n,
                     game.getCurrentCard());

        game.p_boardGame->turnFaceDown(l, n);
        game.p_boardGame->turnFaceUp(static_cast<Letter>(newLetter),n);
    }

};






bool ExpertRules::isValid( Game& _game) {

    setCardLeft(getCardLeft() - 1);


    if (_game.getPreviousCard() == nullptr) return true;

    return  (_game.getCurrentCard()->getAnimal() == _game.getPreviousCard()->getAnimal() ||
        _game.getCurrentCard()->getColor() == _game.getPreviousCard()->getColor());


    };

void ExpertRules::turtleEffect(const Game& _game) {
    cout << "Turtle Effect" << endl;
    Rules::currentPlayer = (Rules::currentPlayer + 1) %
            numberPlayer; //so when the main function execute nextPlayer, the next will be skipped}
};


bool ExpertRules::crabOpened(Game& game) {

    bool boolReturn = false;
    char inputLetter = ' ';
    char inputNumber = ' ';
    bool choosedRight = false;
    Letter _letter;
    Number _Number;

    while (!choosedRight) {

        cout << "please << enter a number between 1 and  5" << endl;
        while (inputNumber == ' ') {
            cin >> inputNumber;
            if (inputNumber != '1' && inputNumber != '2' && inputNumber != '3' && inputNumber != '4' &&
                inputNumber != '5'  ) {
                cout << "please enter a number between 1 and  5" << endl;
                inputNumber = ' ';
            }
        }

        while (inputLetter == ' ') {
            cout << "please enter a letter A, or B, or C, or D, E" << endl;
            cin >> inputLetter;
            if (tolower((int) inputLetter) != 'a' && tolower((int) inputLetter) != 'b' &&
                tolower((int) inputLetter) != 'c' && tolower((int) inputLetter) != 'd' &&
                tolower((int) inputLetter) != 'e' ) {
                inputLetter = ' ';
            }
            inputLetter = tolower((int) inputLetter);
        }
        _letter = static_cast<Letter>(static_cast<int>(inputLetter) - 97);
        _Number = static_cast<Number>((inputNumber) - 49);

        if (!game.p_boardGame->isFaceUp(_letter, _Number)) {
            game.p_boardGame->turnFaceUp(_letter, _Number);
            game.setCurrentCard(game.getCard(_letter, _Number));
            cout << *game.p_boardGame << std::endl;

            choosedRight = true;
        } else {
            std::cout << "Please choose another card." << std::endl;
            inputLetter = ' ';
            inputNumber = ' ';
        }


    }

return isValid(game);

}

void ExpertRules::pinguinEffect(Game& game){
    if(  game.getCurrentCard()!=0   )
    {   bool replaced= false;
        while(!replaced) {
            char inputLetter = ' ';
            char inputNumber = ' ';
            Letter _letter;
            Number _Number;
            cout<<"Penguin effect";
            cout << "please  enter a number between 1 and  5 to choose the card to turn face down."
                 << endl;
            while (inputNumber == ' ') {
                cin >> inputNumber;
                if (inputNumber != '1' && inputNumber != '2' && inputNumber != '3' &&
                    inputNumber != '4' &&
                    inputNumber != '5' ) {
                    cout << "please enter a number between 1 and  5" << endl;
                    inputNumber = ' ';
                }
            }

            while (inputLetter == ' ') {
                cout << "please enter a letter A, or B, or C, or D, E" << endl;
                cin >> inputLetter;
                if (tolower((int) inputLetter) != 'a' && tolower((int) inputLetter) != 'b' &&
                    tolower((int) inputLetter) != 'c' && tolower((int) inputLetter) != 'd' &&
                    tolower((int) inputLetter) != 'e' ) {
                    inputLetter = ' ';
                }
                inputLetter = tolower((int) inputLetter);
            }
            _letter = static_cast<Letter>(static_cast<int>(inputLetter) - 97);
            _Number = static_cast<Number>((inputNumber) - 49);

            if (game.p_boardGame->isFaceUp(_letter, _Number)) {
                game.p_boardGame->turnFaceDown(_letter, _Number);
                replaced = true;
            } else {
                std::cout << "Please choose another card." << std::endl;
                inputLetter = ' ';
                inputNumber = ' ';
            }
        }
    }
}



void ExpertRules::walrus(Game& game, const Letter l, const Number n){
    if(game.getCard(l,n)->getAnimal()!='W') return ;
    bool blocked = false;
    while(!blocked) {
        char inputLetter = ' ';
        char inputNumber = ' ';
        Letter _letter;
        Number _Number;
        cout<<"Walrus  effect !!";
        cout << "please  enter a number between 1 and  5 to choose the card to block a facedown card."
             << endl;
        while (inputNumber == ' ') {
            cin >> inputNumber;
            if (inputNumber != '1' && inputNumber != '2' && inputNumber != '3' &&
                inputNumber != '4' &&
                inputNumber != '5' ) {
                cout << "please enter a number between 1 and  5" << endl;
                inputNumber = ' ';
            }
        }

        while (inputLetter == ' ') {
            cout << "please enter a letter A, or B, or C, or D, E" << endl;
            cin >> inputLetter;
            if (tolower((int) inputLetter) != 'a' && tolower((int) inputLetter) != 'b' &&
                tolower((int) inputLetter) != 'c' && tolower((int) inputLetter) != 'd' &&
                tolower((int) inputLetter) != 'e' ) {
                inputLetter = ' ';
            }
            inputLetter = tolower((int) inputLetter);
        }
        _letter = static_cast<Letter>(static_cast<int>(inputLetter) - 97);
        _Number = static_cast<Number>((inputNumber) - 49);

        if (!game.p_boardGame->isFaceUp(_letter, _Number)) {
            cardBloeckN = _Number;
            cardBlockedL = _letter;
            walrusEnabled=true;
            blocked = true;
        } else {
            std::cout << "Please choose another card." << std::endl;
            inputLetter = ' ';
            inputNumber = ' ';
        }
    }

}


bool ExpertRules::isWalrusPrev(Game& game, Letter& _let , Number& _num){
    if(walrusEnabled==true && game.getCurrentCard()==0){
        while((_let==cardBlockedL) && (_num==cardBloeckN)){
                char inputLetter = ' ';
                char inputNumber = ' ';
                cout<<"This card is blocked by another previous player.";
                cout << "please  enter a number between 1 and  5 ."
                     << endl;
                while (inputNumber == ' ') {
                    cin >> inputNumber;
                    if (inputNumber != '1' && inputNumber != '2' && inputNumber != '3' &&
                        inputNumber != '4' &&
                        inputNumber != '5' ) {
                        cout << "please enter a number between 1 and  5" << endl;
                        inputNumber = ' ';
                    }
                }

                while (inputLetter == ' ') {
                    cout << "please enter a letter A, or B, or C, or D, E" << endl;
                    cin >> inputLetter;
                    if (tolower((int) inputLetter) != 'a' && tolower((int) inputLetter) != 'b' &&
                        tolower((int) inputLetter) != 'c' && tolower((int) inputLetter) != 'd' &&
                        tolower((int) inputLetter) != 'e' ) {
                        inputLetter = ' ';
                    }
                    inputLetter = tolower((int) inputLetter);
                }
                _let = static_cast<Letter>(static_cast<int>(inputLetter) - 97);
                _num = static_cast<Number>((inputNumber) - 49);

            }
            game.setCurrentCard(game.getCard(_let,_num));
            walrusEnabled=false;
            return true;
    }
    return false;

}

bool ExpertBoard::isFaceUp(const Letter& let, const Number& num) const {

    for(auto it:game_card_pos){
        if(it.first==let && it.second==num) return true;
    }
    return false;

}



