#include "Card.hpp"
#include <iostream>
#include <string>


// Big Five and Constructor
Card::Card() {
    instruction_ = "";
    bitmap_ = nullptr;
    drawn_ = false;
}

Card::~Card() {
    // Perform cleanup for the card object, including any dynamic memory deallocation
    if (bitmap_ != nullptr) {
        delete[] bitmap_;
        bitmap_ = nullptr;
    }
    //std::cout << "DESTRUCTOR CALLED\n";
}

/**
    * Copy Constructor
    * @post: Construct a new Card object
    * @param: const reference to a Card object
    */
Card::Card(const Card& rhs) {
    //std::cout << "CC" << std::endl;

    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;

    int size = 80;  
    bitmap_ = new int[size];

    if (rhs.bitmap_ != nullptr) {
        for (int i = 0; i < size; i++) {
            bitmap_[i] = rhs.bitmap_[i];
        }
    }
    else {
        bitmap_ = nullptr;
    }

    drawn_ = rhs.drawn_;
}

/**
* Copy Assignment Operator
* @param const reference to a Card object
* @return this Card object
*/
Card& Card::operator=(const Card & rhs) {
    //std::cout << "CA" << std::endl;

    if (this != &rhs) {
        if (bitmap_ != nullptr) {
            delete[] bitmap_;
            bitmap_ = nullptr;
        }

        cardType_ = rhs.cardType_;
        instruction_ = rhs.instruction_;

        int size = 80;  
        bitmap_ = new int[size];

        if (rhs.bitmap_ != nullptr) {
            for (int i = 0; i < size; i++) {
                bitmap_[i] = rhs.bitmap_[i];
            }
        } else {
            bitmap_ = nullptr;
        }        
        
        drawn_ = rhs.drawn_;
    }

    return *this;
}


/**
* Move Constructor
* @param: rvalue reference to a Card object
*/
Card::Card(Card && rhs) {

    //std::cout << "MC" << std::endl;

    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;

    int size = 80;  
    bitmap_ = new int[size];

    if(rhs.bitmap_ != nullptr){
        bitmap_ = rhs.bitmap_;
        rhs.bitmap_ = nullptr;
    } else {
        bitmap_ = nullptr;
    }

    drawn_ = rhs.drawn_;
}

/**
    * Move assignment operator
    * @param: rvalue reference to a Card object
    * @return this card object
    */
Card& Card::operator=(Card&& rhs) {
    //std::cout << "MA" << std::endl;

    if(this != &rhs){
        if (bitmap_ != nullptr) {
            delete[] bitmap_;
        }

        cardType_ = rhs.cardType_;
        instruction_ = rhs.instruction_;
        
        if(rhs.bitmap_ != nullptr){
            bitmap_ = std::move(rhs.bitmap_);
            rhs.bitmap_ = nullptr;
        } else {
            bitmap_ = nullptr;
        }

        drawn_ = rhs.drawn_;
    }

    return *this;
}

/**
    * @return the string representation of the card type
    */
std::string Card::getType() const {
    if (cardType_ == ACTION_CARD) {
        return "ACTION_CARD";
    } 
    if (cardType_ == POINT_CARD) {
        return "POINT_CARD";
    }
    else {
        return "ERROR";
    }
}

/**
    * @post: set the card type
    * @param const reference to a CardType object
    */
void Card::setType(const CardType& type) {
    cardType_ = type;
}

/**
    * @return the string representation of the card instruction
    */
const std::string& Card::getInstruction() const {
    return instruction_;
}

/**
    * @post: set the card instruction
    * @param: const reference to an instruction
    */
void Card::setInstruction(const std::string& instruction) {
    instruction_ = instruction;
}

/**
    * @return the image data
    */
const int* Card::getImageData() const {
    return bitmap_;
}

/**
    * @post: Set the image data
    * @param pointer to an array of integers
    */
void Card::setImageData(int* data) {
    if (bitmap_ != nullptr) {
        delete[] bitmap_;
        bitmap_ = nullptr;
    }
    int size = 80;
    bitmap_ = new int[size];
    for (int i = 0; i < size; i++) {
        bitmap_[i] = data[i];
    }
}

/**
    * @return the drawn status of the card
    */
bool Card::getDrawn() const {
    return drawn_;
}

/**
    * @post: set the drawn status of the card
    * @param: const reference to a boolean
    */
void Card::setDrawn(const bool& drawn) {
    drawn_ = drawn;
}
