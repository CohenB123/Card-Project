#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include "Card.hpp"
#include "ActionCard.hpp"


/**
* @post: Construct a new Action Card object
*/
ActionCard::ActionCard() {
    setType(ACTION_CARD);
}


/**
    * @return true if the card is playable, false otherwise
    * For a card to be playable, it has to be drawn and the instruction has to be valid
    * Valid instructions:
    * DRAW x CARD(S) : assume x is a positive integer
    * PLAY x CARD(S) : assume x is a positive integer
    * REVERSE HAND : reverse the order of the cards in the hand
    * SWAP HAND WITH OPPONENT : swap the hand with the opponent
*/
bool ActionCard::isPlayable() {

    if(getDrawn() == 0){
        return false; // false = 0
    }

    // Define regular expression patterns for various instructions
    std::regex draw(R"(DRAW (\d+) CARD\\(S\\)");
    std::regex play(R"(PLAY (\d+) CARD\\(S\\)");
    std::regex reverse(R"(REVERSE HAND)");
    std::regex swap(R"(SWAP HAND WITH OPPONENT)");

    std::smatch match;

    // Try to match each pattern to the instruction
    if (std::regex_match(getInstruction(), match, draw)) {
        int numCards = std::stoi(match[1]);
        //std::cout << "\nDrawing " << numCards << " card(s)." << std::endl;
        //std::cout << "The size of match is " << match.size() << std::endl;
        //std:: cout << match[0] << " | " << match[1] << " | " << match[2] << " | " << std::endl;  
        return true;
    
    }
    else if (std::regex_match(getInstruction(), match, play)) {
        //int numCards = std::stoi(match[1]);
        //std::cout << "\nPlaying " << numCards << " card(s)." << std::endl;
        return true;
    }
    else if (std::regex_match(getInstruction(), match, reverse)) {
        //std::cout << "\nReversing hand." << std::endl;
        return true;
    }
    else if (std::regex_match(getInstruction(), match, swap)) {
        //std::cout << "\nSwapping hand with opponent." << std::endl;
        return true;
    }
    else {
        //std::cerr << "\nInvalid instruction: " << getInstruction() << std::endl;
        return false;
    }

    return false;
}

/**
    * @post: Print the ActionCard in the following format:
    * Type: [CardType]
    * Instruction: [Instruction]
    * Card:
    * [ImageData]
    *
    * Note: For [ImageData]: If there is no image data, print "No image data" instead
    */
void ActionCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;
    // Assume size is 80
    std::cout << "Card:" << std::endl;
    if (getImageData() == nullptr) {
        std::cout << "No image data\n";
    }
    else {
        for (int i = 0; i < 80; i++) {
            std::cout << getImageData()[i] << " " << std::endl;
        }
    }
}