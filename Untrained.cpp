
/*****************************
** File: Untrained.cpp
** Project: CMSC 202 Project 4, Spring 2019
** Author: Nick Sica
** Date: 4/8/19
** Section: 07
** E-mail: nsica1@umbc.edu
**
** This file contains the main code for the Untrained horse class, it allows
** for the creation of untrained horses which is a child class of Horse
**
***************************/ 
#include "Untrained.h"
#include "Horse.h"
#include "Light.h"
#include "Medium.h"
#include "Heavy.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <string> 
using namespace std;

// Default Constructor
// Preconditions: None
// Postconditions: None
Untrained::Untrained():Horse() {
}//calls the horse constructor 

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Untrained::Untrained(string name, Size size, int health, int speed):Horse(name,size,health,speed) {
  //calls horse constructor 
}
// breed() - if an horse successfully produces specializes it is replaced
//           by a corresponding warhorse
// Preconditions: all variables are set valid
// Postconditions: returns an pointer to a new warhorse or NULL
Horse* Untrained::specialize() {
  Horse *myHorse = NULL;
  //specializes a small horse into a light warhorse 
  if(getSize() == SMALL) {
    cout << "Your horse is now a Light Warhorse" << endl;
    myHorse = new Light(getName(), getSize(), getHealth(), getSpeed());
    
   
  }//specializes a medium horse into a medium warhorse 
  else if(getSize() == MEDIUM) {
    cout << "Your Horse is now a Medium Warhorse" << endl;
    myHorse = new Medium(getName(), getSize(), getHealth(), getSpeed());
    
   
  } //specializes a large horse into a heavy warhorse 
  else if(getSize() == LARGE) {
    cout << "Your horse is now a Heavy Warhorse" << endl;
    myHorse = new Heavy(getName(), getSize(), getHealth(), getSpeed());
    
    
  }
  return myHorse;
}

// train() : attempts to train an untrained horse
// Preconditions: all variables are set valid
// Postconditions: says that horses cannot be trained
bool Untrained::train() {
  //cant train an untrained horse object 
  cout << "This horse can't be trained" << endl;
  specialize();
  
  return false;
  
}

// toString() - a string representation of the untrained horse
// Preconditions: all variables are set valid
// Postconditions: returns an string describing the horse
string Untrained::toString() {
  //returns the size which is unknown
  return "Unknown";
  
}

// attack(string, int) - only light, medium, and heavy can attack
// Preconditions: target passed and health of attacker
// Postconditions: displays that untrained horses can't attack
int Untrained::attack(string name, int health ) {
  //untrained horses cant battle 
  cout << "Untrained horses can't battle" << endl;
  return 0;
}

 








