/*****************************
 ** File: Horse.cpp
 ** Project: CMSC 202 Project 4, Spring 2019
 ** Author: Nick Sica
 ** Date: 4/8/19
 ** Section: 07
 ** E-mail: nsica1@umbc.edu
 **
 ** This file contains the main code for the Horse class, it allows 
 ** for the creation of Horse objects
 **
 ***************************/
#include "Horse.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

//ints for the display formatting
const int WIDTH = 20;
const int SMALLWIDTH = 10;
const char SEPARATE = ' ';

//the constants to get rid of magic numbers for the training values
const int SADDLET = 1;
const int GREENT = 2;
const int INTERMEDIATET = 3;
const int EXPERTT = 4;
const int MASTERT = 5;
const int MAX = 100;
// Default Constructor
// Preconditions: None
// Postconditions: A horse is created
Horse::Horse() {
  //initalizes all of the variables 
  m_name == "";
  m_size = SMALL;
  m_health = 0;
  m_speed = 0;
  m_training = UNTRAINED;
}

// Overloaded Constructor
// Preconditions: Valid inputs (name, align, size, health, speed)
//                Training always 0
// Postconditions: None
Horse::Horse(string name, Size size, int health, int speed) {
  //overloaded constructor that initalizes all of the variables with
  //the variables passed in
  m_name = name;
  m_size = size;
  m_health = health;
  m_speed = speed;
  m_training = UNTRAINED;
  
}

// Destructor - virtual (implement in child classes)
// Preconditions: Horse object in memory
// Postconditions: Deallocates horse object in memory
//Horse:: ~Horse(){


// getName() - returns the name of horse
// Preconditions: m_name is set
// Postconditions: returns a string name of the horse
string Horse::getName() {
  //getter for name
  return m_name;
}

// getSize() - returns the size of horse
// Preconditions: m_size is set
// Postconditions: returns an enum Size referring to the size of the horse
Size Horse::getSize() {
  //getter for size
  return m_size;
}

// getHealth() - returns the health of horse
// Preconditions: m_health is set
// Postconditions: returns an int referring to health from (1 - MAX_HEALTH)
int Horse::getHealth() {
  //getter for health
  return m_health;
}

// getSpeed() - returns the speed of the horse
// Preconditions: m_speed is set
// Postconditions: returns an int referring to speed from (1 - MAX_SPEED)
int Horse::getSpeed() {
  //getter for speed
  return m_speed;
}

// getTraining() - returns the training level of horse
// Preconditions: m_training is set
// Postconditions: returns an enum Training referring to training level of the horse
Training Horse::getTraining() {
  //getter for training
  return m_training;
}

// setHealth() - updates the health of the horse
// Preconditions: m_health is set
// Postconditions: updates m_health
void Horse::setHealth(int health) {
  //sets the horse objects health
  m_health = health;
}

// increaseTraining() - increase training by one, up to max
// Preconditions: all variables are set valid
// Postconditions: returns an bool (true if increased, false if at max)
bool Horse::increaseTraining() {
  bool increase;
  //if the training level of the horse is not equal to the max training level 
  if(m_training != (Training)MAX_TRAINING) {

    increase = true;
  
    //increases all of the training levels by checking to see the horse's
    //current training level and then switching it to the next one
    if(m_training == (int) UNTRAINED) {
      m_training = (Training) SADDLET;
    }
    else if(m_training == (int)SADDLE) {
      m_training = (Training) GREENT;
    }
    else if(m_training == GREEN) {
      m_training = (Training) INTERMEDIATET;
      
    }
    else if(m_training == INTERMEDIATE) {
      m_training = (Training) EXPERTT;
      
    }
    else if(m_training == EXPERT) {
      m_training = (Training) MASTERT;
      
    }
  }//if its at the max already then returns false
  else {
    increase = false;
      }
  //returns true if it increased
  return increase;
}

// specialize() - Attempts to converts an Untrained horse to
//                a war horse (light, medium, or heavy)
//                Only Untrained type of horses can be specialized
// Preconditions: all variables are set valid
// Postconditions: returns a pointer to a new warhorse or NULL
Horse* Horse::specialize() {
  //returns null as you cant convert a horse into a a specialized warhorse 
  return nullptr;
}

// attack(string, int) - Virtual function for light/medium/heavy to attack
// Preconditions: all variables are set valid
// Postconditions: Child class will return the number of points of damage
//virtual int Horse::attack(string, int) = 0;

// train() - Tests if horse was successfully trained
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether horse trained or not
//virtual bool Horse::train() = 0;

// battle() - Sends a horse to battle another horse
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether horse won the battle or not
bool Horse::battle(Horse*) {
  //horse objects cant battle, only warhorses 
  cout << "This horse can't battle" << endl;
  return false;

}

// Overloaded << - Prints the details of a horse
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of horse
ostream& operator<<(ostream& output, Horse& myHorse) {
  //just printing the horse details and formats the output as well
  output << left << setw(WIDTH) << setfill(SEPARATE) << myHorse.getName() //name
	   << setw(WIDTH) << setfill(SEPARATE) << myHorse.toString() //size
	   << setw(SMALLWIDTH) << setfill(SEPARATE) << myHorse.getHealth() //health
	   << setw(SMALLWIDTH) << setfill(SEPARATE) << myHorse.getSpeed() //speed
	   << setw(SMALLWIDTH) << setfill(SEPARATE)
	   << myHorse.trainingString(myHorse.getTraining()) << endl;
  
  return output;
  
}

// randomPercentBased (Helper function)
// Precondition: Given int to "pass"
// Description: This function is used to see if a certain random event occurs
//              A random number 1-100 is compared to the int passed
//              If the random number is less than the passed value, return true
//              Else return false (30 = 30%, 70 = 70%)
// Postcondition: Returns boolean
 bool Horse::randomPercentBased(int num) {
  int random;
  //seeds the random
  srand(time(NULL));
  //random between 1-100
  random = rand() % MAX + 1;
  //if random is less than the passed value, it returns true
  if(random < num) {
    return true;
  }
  return false;
}

// toString() - a string representation of the horse
// Preconditions: all variables are set valid
// Postconditions: returns an string describing the horse
//virtual string Horse::toString() = 0;

// trainingString() - a string representation of a training level enum
// UNTRAINED = 0, SADDLE = 1, GREEN = 2, INTERMEDIATE = 3, EXPERT = 4, MASTER = 5
// Preconditions: Pass a training level to the function
// Postconditions: Returns the string of the enum
string Horse::trainingString(Training train) {
  string training;
  //gets the horses training level and switches it into a string representation of the level
  switch(train) {
  case 0:
    training = "UNTRAINED";
    break;
  case 1:
    training = "SADDLE";
    break;
  case 2:
    training = "GREEN";
    break;
  case 3:
    training = "INTERMEDIATE";
    break;
  case 4:
    training = "EXPERT";
    break;
  case 5:
    training = "MASTER";
    break;
  }
  //returns the training level string
  return training;
}



