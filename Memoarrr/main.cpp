#include <iostream>
#include "board.h"
#include "cardDeck.h"
#include "player.h"
#include "expertRules.h"
#include "rewardDeck.h"
#include <Windows.h>



/*
 * Need to define a destructor in ExpertBoard, Board, Game, CardDeck, RewardDeck, les autres default dest
 */



using namespace std;

bool comparePlater(Player* p1, Player* p2){
    return p1->getNRubies()>p2->getNRubies();

}



int main() {

    //Testing
    #if testingPlayer
    mainTestP();
    #endif

    #if testingBoard
    mainTestBoard();
    #endif

    #if testingCard
        testingCards();
    #endif

    #if testingReward
    testReward();
    #endif


    #if testingCardDeck
        testCDeck();
    #endif

    #if testingRewardDeck
        testRDeck();
    #endif

    #if testRules
        testrules();
    #endif

    #if testExpertBoard
    testEBoard();
    #endif

#if gameTest
    testGame();
#endif


#if (!gameTest&& !testExpertBoard && !testRules&& !testingPlayer && !testingRewardDeck && !testingCardDeck && !testingReward && !testingCard && !testingBoard  )
    //shuffling the rewardeck and the cardDeck
    RewardDeck::make_rewardDeck().shuffle();
    CardDeck::make_CardDeck();
    CardDeck::make_CardDeck().shuffle();
    CardDeck::make_CardDeck().shuffle();

    //getting the version
    int p_version=0;
    while ( p_version != 1 && p_version != 2 ) {
        cout << "Please enter game version : 1 for basic mode. 2 for expert"<<endl;
        cin >> p_version;
    }

    //getting the players.
    vector<Player*> players;
    int numPlayer=0;
    while ( numPlayer < 2 || numPlayer >4   ) {
        cout << "Please enter the number of player (2 - 4)"<<endl;
        cin >> numPlayer;
    }


    string name;
    //getting the players' name
    for(int k = 0 ; k<numPlayer;k++){
        cout<<"Enter the name of player " << k+1<<endl;
        cin >> name;
        if(k==0){
            Player* p1 = new Player(name,Side::TOP);
            players.push_back(p1);
        }
        if(k==1){
            Player* p1 = new Player(name,Side::RIGHT);
            players.push_back(p1);
        }
        if(k==2){
            Player* p1 = new Player(name,Side::BOTTOM);
            players.push_back(p1);
        }
        if(k==3){
            Player* p1 = new Player(name,Side::LEFT);
            players.push_back(p1);
        }

    }


    ExpertRules rule = ExpertRules(numPlayer);

//creating the game object
    Game game= Game(p_version,players);


    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i!=2 || j!=2) {
                Letter intLetter = static_cast<Letter>(i);
                Number intNumber = static_cast<Number>(j);
                game.setCard(intLetter, intNumber, CardDeck::make_CardDeck().getNext());//setting the card in the board.

            }
        }

    }

    //printing the board, players before starting
    cout<<game<<endl;
    while(!rule.gameOver(game)) {
        Letter _letter; //used to pass a function parametter
        Number _Number;//used to pass a function parametter

        cout << "Starting game" << endl;
        for (int k = 0; k < numPlayer; k++) {
            int letterRand = rand() % 5;
            int NumberRand = rand() % 5;
            while(letterRand == 2 && NumberRand==2){
                letterRand = rand() % 5;
                NumberRand = rand() % 5;
            };
            game.p_boardGame->reset();
            game.p_boardGame->turnFaceUp((Letter) letterRand, (Number) NumberRand);
            while(letterRand == 2 && NumberRand==2){
                letterRand = rand() % 5;
                NumberRand = rand() % 5;
            };
            letterRand = rand() % 5;
            NumberRand = rand() % 5;
            while(letterRand == 2 && NumberRand==2){
                letterRand = rand() % 5;
                NumberRand = rand() % 5;
            };
            game.p_boardGame->turnFaceUp((Letter) letterRand, (Number) NumberRand);
            letterRand = rand() % 5;
            NumberRand = rand() % 5;
            while(letterRand == 2 && NumberRand==2){
                letterRand = rand() % 5;
                NumberRand = rand() % 5;
            };
            game.p_boardGame->turnFaceUp((Letter) letterRand, (Number) NumberRand);
            cout << *game.p_boardGame << endl;
            cout<<"Printing 3 Cards, Memorize it"<<endl<<endl;
            Sleep(450); //in the project specs it says should pause a little.
            game.p_boardGame->reset();
        }



        Player turnPlayer;
        int turn = 0;
        //turnPlayer.setActive(true);
        cout<<"++++++++ROUND "<<game.getRound()+1<<" Starting" <<endl;
        while (!rule.roundOver(game)) {
            turnPlayer=rule.getNextPlayer(game);
            game.setCurrentCard(0);
            game.setCurrentCard(0);
            int cardpicked = 0;
            if (turnPlayer.isActive())
                while (cardpicked < 2) {
                    cout << " turn to  : " << turnPlayer.getName() << " to play " << endl; //printing which player need to play
                    char inputLetter = ' '; //read from cli
                    char inputNumber = ' '; //read from cli
                    bool choosedRight = false; //check if player didn't choose a faceup card or the center card.

                    while (!choosedRight) {
                        // read from cli "Could be entered as 1A , or 1 enter after that A
                        cout << "please << enter a number between 1 and  5" << endl;
                        cout << "please enter a letter A, or B, or C, or D, E" << endl;
                        do { //While it's diferent from 1 2 3 4 5
                            cin >> inputNumber;
                            if (inputNumber != '1' && inputNumber != '2' && inputNumber != '3' && inputNumber != '4' &&
                                inputNumber != '5' ) {
                                cout << "please enter a number between 1 and  5" << endl;
                                inputNumber = ' ';
                            }
                        }while (inputNumber == ' ');

                        do { //while it's different from A B C D E
                            cin >> inputLetter;
                            if (tolower((int) inputLetter) != 'a' && tolower((int) inputLetter) != 'b' &&
                                tolower((int) inputLetter) != 'c' && tolower((int) inputLetter) != 'd' &&
                                tolower((int) inputLetter) != 'e' ) {
                                cout << "please enter a letter A, or B, or C, or D, E" << endl;
                                inputLetter = ' ';
                            }
                            inputLetter = tolower((int) inputLetter);
                        }while (inputLetter == ' ');

                        _letter = static_cast<Letter>(static_cast<int>(inputLetter) - 97);
                        _Number = static_cast<Number>((inputNumber) - 49);

                        bool checking = false; // to use for walrusExpert mode
                        if (!game.p_boardGame->isFaceUp(_letter, _Number)) {
                            if(p_version==2){ checking =rule.isWalrusPrev(game,_letter,_Number);}
                            if(!checking)
                            {game.p_boardGame->turnFaceUp(_letter, _Number);
                            game.setCurrentCard(game.getCard(_letter, _Number));}
                            cout << *game.p_boardGame << std::endl;
                            choosedRight = true;
                        } else {
                            std::cout << "Please choose another card." << std::endl;
                            inputLetter = ' ';
                            inputNumber = ' ';
                        }


                    }
                    cardpicked++; //to check if the player did his turn

                    if(p_version == 2){ //version 2 checks.
                        rule.walrus(game,_letter,_Number);
                        if(game.getCurrentCard()->getAnimal()=='C'){
                            cout<<"Crab Effect"<<endl;
                            bool b= rule.crabOpened(game);
                            if(!b)
                            cardpicked++;
                        }

                        if (game.getCurrentCard()->getAnimal() == 'O') {
                            cout<<"Octopus effect !"<<endl;

                            rule.Octopus(game,_letter,_Number);
                            cout << *game.p_boardGame << std::endl;
                            }

                        if(game.getCurrentCard()->getAnimal()=='T'){
                            rule.turtleEffect(game);
                        }

                        if(game.getCurrentCard()->getAnimal()=='P' && cardpicked==2){
                            rule.pinguinEffect(game);
                        }

                    }



                    }
                    //check if it matches with the last card or the player is set to inactive and he's out of the round
                    if (!rule.isValid(game)) {
                        cout<<turnPlayer.getName()<<" Out of this round" <<endl;
                        turnPlayer.setActive(false);
                        game.getPlayer(turnPlayer.getSide()).setActive(false);
                    }
        }
        game.nextRound();

        cout<<"The round is over"<<endl;
    }

    //endOf the game !

    game.getPlayer(Side::TOP).setDisplayMode(true);


    players.clear();

    for(int i = 0 ; i<numPlayer;i++){
        players.push_back(&game.getPlayer((Side) i));
    }

    std::sort(players.begin(),players.end(),comparePlater);
    cout<<"Printing classment of the player " <<endl;
    for(auto p : players){
        cout<<*p<<endl;
    }


    for(int i =0;i<numPlayer;i++)
    {
        delete players[i];
    }

    players.clear();



    return 0;

#endif
}



