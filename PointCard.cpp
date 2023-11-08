#include <iostream>
#include <string>
#include "Card.hpp"
#include "PointCard.hpp"


/**
    * @post: Construct a new Point Card object
    */
PointCard::PointCard() {
    setType(POINT_CARD);
}

/**
    * @return true if the card is playable, false otherwise
    * For a card to be playable, it has to be drawn and the instruction has to be a valid number
*/
bool PointCard::isPlayable() {
    //try {
        if (getInstruction().empty()) {
            //std::cout << "The card is empty but it is not\n";
            return false;
        }

        if(getDrawn() == true){
            //std::cout << "The card says it is drawn but it was not drawn\n";
            return false; // false = 0
        }

        for (int i = 0; i < getInstruction().size(); i++) {
            // Make assumption that the instruction will not be 0
            // because no card should ever be 0 becasue then it does nothing
            if (isdigit(getInstruction()[i]) == 0) {
                return false;
            }
        }
        return true;
        /*
        } catch (std::invalid_argument& e) {
            std::cerr << "\nError: " << e.what() << " isPlayable: ";
            return false;
        }
        */
}

/**
    * @post: Print the Point Card in the following format:
    * Type: [CardType]
    * Points: [Instruction]
    * Card:
    * [ImageData]
    *
    * Note: For [ImageData]: If there is no image data, print "No image data" instead
    */
void PointCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;
    // Assume size is 80
    std::cout << "Card: " << std::endl;
    if (getImageData() == nullptr) {
        std::cout << "No image data\n";
    }
    else {
        for (int i = 0; i < 80; i++) {
            std::cout << getImageData()[i] << " " << std::endl;
        }
    }
}