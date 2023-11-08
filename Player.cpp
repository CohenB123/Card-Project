#include "Hand.hpp" 
#include "Deck.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Player.hpp"


/**
* @post: Construct a new Player object
*/
Player::Player() {
    score_ = 0;  
    opponent_ = nullptr; 
    actiondeck_ = nullptr; 
    pointdeck_ = nullptr; 
}

/**
 * @post: Destroy the Player object
 */
Player::~Player() {

    if(actiondeck_ == opponent_->getActionDeck()){
        actiondeck_ = nullptr;
    } else {
        delete actiondeck_;
    }
    
    if(pointdeck_ == opponent_->getPointDeck()){
        pointdeck_ = nullptr;
    } else {
        delete pointdeck_;
    }

    opponent_ = nullptr;
}

/**
 * @return the player's hand
 */
const Hand& Player::getHand() const {
    return hand_;
}

/**
 * @post: Set the player's hand
 * @param const reference to a hand object
 */
void Player::setHand(const Hand& hand) {
    hand_ = hand;
}

/**
 * @return the Player's current score
 */
int Player::getScore() const {
    return score_;
}

/**
 * @post: Set the player's score
 * @param: score
 */
void Player::setScore(const int& score) {
    score_ = score;
}

/**
 * @post: Play a given action card
 * @param: an Actioncard object
 * Begin the function by reporting the instruction of the card:
 * PLAYING ACTION CARD: [instruction]
 */
void Player::play(ActionCard&& card) {
    // DONT KNOW HOW TO DO THS
    std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
    // ASK IF YOU WANT TO ADD FROM THE BACK

    // Define regular expression patterns for various instructions
    std::regex draw(R"(DRAW (\d+) CARD(S)?)");
    std::regex play(R"(PLAY (\d+) CARD(S)?)");
    std::regex reverse(R"(REVERSE HAND)");
    std::regex swap(R"(SWAP HAND WITH OPPONENT)");

    std::smatch match;

    // Try to match each pattern to the instruction
    if (std::regex_match(card.getInstruction(), match, draw)) {
        int numDraws = std::stoi(match[1]);
        for(int i=0; i<numDraws; i++){
            drawPointCard();
        }
    }
    else if (std::regex_match(card.getInstruction(), match, play)) {
        int numPlays = std::stoi(match[1]);
        for(int i=0; i<numPlays; i++){
            playPointCard();
        }
        
    }
    else if (std::regex_match(card.getInstruction(), match, reverse)) {
        hand_.Reverse();    
    }
    else if (std::regex_match(card.getInstruction(), match, swap)) {
        std::swap(hand_, getOpponent()->hand_);
    }
    else {
        std::cerr << "\nCard can not be played. Card is: " << card.getInstruction() << std::endl;
    }
}



/**
 * @post: Draw a point card and place it in the player's hand
 */


void Player::drawPointCard() {
    PointCard&& card = pointdeck_->Draw(); /// Move Constructor
    card.setDrawn(true);
    //pointdeck_->getDeck().pop_back();
    hand_.addCard(std::move(card)); 
}


/*
/**
 * @post: Play a point card from the player's hand and update the player's score
 */

void Player::playPointCard() {
    score_ += hand_.PlayCard();
}


/**
 * @post: Set the opponent of the player
 * @param a pointer to a Player opponent
 */
void Player::setOpponent(Player* opponent) {
    opponent_ = opponent;
}

/**
 * @return: a pointer to the player's opponent
 */
Player* Player::getOpponent() {
    return opponent_;
}

/**
 * @post: the action deck of the player
 * @param: A pointer to a deck holding Action cards
 */
void Player::setActionDeck(Deck<ActionCard>* actiondeck) {
    actiondeck_ = actiondeck;
}

/**
 * @return a pointer to the player's action deck
 */
Deck<ActionCard>* Player::getActionDeck() {
    return actiondeck_;
}

/**
 * @post: set the point deck of the player
 * @param: A pointer to a deck holding Point cards
 */

void Player::setPointDeck(Deck<PointCard>* pointdeck) {
    pointdeck_ = pointdeck;
}

/**
 * @return: a pointer to the player's point deck
 */
Deck<PointCard>* Player::getPointDeck() {
    return pointdeck_;
}
