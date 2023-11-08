/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name
Date
Deck.hpp defines the Deck class.
*/
#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include "Card.hpp"
#include <random>


template <typename CardType>
class Deck 
{
    public:
        /**
         * @post: Construct a new Deck object
         */
        Deck(){
            std::vector<CardType> cards_{};
        }

        /**
         * @post: Destroy the Deck object 
         */
        ~Deck(){
            cards_.clear();
        }

        /**
         * @post: Add a Card to the Deck
         * @param: const reference to CardType card
         */
        void AddCard(const CardType& card){
            cards_.push_back(card);
        }

        /**
         * @post: Draw a card from the deck
         * @pre: the deck is not empty
         * @return the right hand value of type CardType 
         */


        CardType&& Draw(){
            cards_.back().setDrawn(true);
            CardType&& r_card = std::move(cards_.back());
            r_card.setDrawn(true);
            cards_.pop_back();
            return std::move(r_card);
            //return std::move(cards_.back());
        }




        /**
         * @return if the deck is empty 
         */
        bool IsEmpty() const{
            return cards_.empty();
        }

        /**
         * @post: Shuffle the deck 
         * Create a random number generator using std::mt19937 with seed 2028358904, 
         * then call std::shuffle on the vector of cards, and with the random number generator as the third argument.  
         * https://en.cppreference.com/w/cpp/algorithm/random_shuffle
         * https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine
         */
        void Shuffle(){
            std::mt19937 num_rand;
            num_rand.seed(2028358904);
            std::shuffle(cards_.begin(), cards_.end(), num_rand);
        }

        /**
         * @return the size of the deck 
         */
        int getSize() const{
            return cards_.size();
        }

        /**
         * @return the vector of cards in the deck 
         */
        std::vector<CardType> getDeck() const{
            return cards_;
        }

    private:
        std::vector<CardType> cards_;
};

//#include "Deck.cpp"   // BIG ERROR I WAS GETTING WHERE IT SAID THERE WAS REDECLARATIONS
#endif
