//--- 2021-2022 Spring Object Oriented Programming Assignment 1 ---//
//--------------------------//
//---Name & Surname: Leminur Çelik
//---Student Number: 150190085
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//
//Constructor of Pokemon
pokemon::pokemon(){ 
    name = "";
    hpValue = 100;
    atkValue = 10;
}

//Constructor of Pokemon with Name and Attack Value
pokemon::pokemon(string name_pokemon, int atk){
    name = name_pokemon;
    atkValue = atk;
    hpValue = 100;
}

//Copy Constructor of Pokemon
pokemon::pokemon(const pokemon &object){ 
    hpValue = object.hpValue;
    atkValue = object.atkValue;
    name = object.name;
}

//Returns Pokemon's Name
string pokemon::get_name() const{ 
    return name;
}

//Returns Pokemon's Health Point Value
int pokemon::get_hp() const{ 
    return hpValue;
}

// Returns Pokemon's Attack Value
int pokemon::get_atk() const{ 
    return atkValue;
}

//Constructor of Pokedex
pokedex::pokedex(){ 
    value = 0;
}

//Updates the Pokemons the Player encounters
bool pokedex::updatePokedex(pokemon p){
    for(int i = 0; i <= value; i++){
        if(pokedexArray[i].get_name() == p.get_name()){
            return false;
        }
    }
    pokedexArray[value] = p;
    value++;
    return true;
}

//Print the Pokemon Names the Player encounters
void pokedex::printPokedex(){ 
    for(int i = 0; pokedexArray[i].get_name() != ""; i++){
        cout << pokedexArray[i].get_name() << endl;
    }
}

//Constructor of Player
player::player(){ 
    name = "";
    pokeballNumber = 10;
    pokemonNumber = 0;
    badgeNumber = 0;
}

//Constructor of Player with Name and Pokemon
player::player(string given_name, pokemon play){ 
    name = given_name;
    playerPokemon = play;
    pokeballNumber = 10;
    pokemonNumber = 0;
    badgeNumber = 0;
}

//Returns the Number of Pokemon the Player has caught
int player::showPokemonNumber(){ 
    return pokemonNumber;
}

//Returns the Number of Pokeballs
int player::showPokeballNumber(){ 
    return pokeballNumber;
}

//Returns the Number of Badges the Player has won
int player::showBadgeNumber(){ 
    return badgeNumber;
}

//Returns the Player's Pokemon
pokemon player::getPokemon() const{  
    return playerPokemon;
}

//If the Player wins the fight, the Number of Badges increases by 1 and the Number of Pokeballs increases by 3.
void player::battleWon(){ 
    badgeNumber++;
    pokeballNumber += 3;
}

//If the Player catchs the Pokemon, the Number of Pokemons increases by 1 and the Number of Pokeballs decreases by 1.
void player::catchPokemon(){ 
    pokemonNumber++;
    pokeballNumber--;
}

//Constructor of Enemy
enemy::enemy(){
    name = "";
}

//Constructor of Enemy with Name and Pokemon
enemy::enemy(string enemy_name, pokemon enemy_pokemon){
    name = enemy_name;
    enemyPokemon = enemy_pokemon;
}

//Returns the Enemy's Pokemon
pokemon enemy::getPokemon() const{
   return enemyPokemon;
}

//Returns the Enemy's Name
string enemy::getName() const{
    return name;
}