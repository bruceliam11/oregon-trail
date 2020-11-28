#include "Player.h"
#include <iostream>
#include <cmath>
using namespace std;


Player::Player(){
    setState(condition::Healthy);
}

string Player::getName(){
    return name_;
}

void Player::setName(string name){
    name_ = name;
}

condition Player::getState(){
    return state_;
}

void Player::setState(condition state){
    state_ = state;
}

