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
#include <fstream>

#include "pokemon.h"

using namespace std;

//-------------Do Not Change These Global Variables-------------//
int NAME_COUNTER = 0;   //Use this to keep track of the enemy names
int POK_COUNTER = 0;    //Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable but its here if you need it
//--------------------------------------------------------------//

//---If Necessary Add Your Global Variables Here---// 
// 
//
//
//-------------------------------------------------//

//-------------Do Not Change These Function Definitions-------------//
string* readEnemyNames(const char*);
string* readPokemonNames(const char*);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player*, string*, string*);
void catchPokemon(player*, string*);
//------------------------------------------------------------------//

//---If Necessary Add Your Function Definitions Here---// 
//
//
//
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
int main(int argc, char* argv[]){
	system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string* enemyNames = readEnemyNames(argv[1]);         
    string* pokemonNames = readPokemonNames(argv[2]);
    

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n" << endl;
    cout << "Please enter your name: "; 
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);
    
    int menuChoice;

    while(true){
        mainMenu(); 
        cin>>menuChoice;

        switch (menuChoice){
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout<<newPlayer.showPokemonNumber()<<endl;
            break;
        case 4:
            cout<<newPlayer.showPokeballNumber()<<endl;
            break;
        case 5:
            cout<<newPlayer.showBadgeNumber()<<endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" <<endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;
  
        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readEnemyNames(const char* argv){
    ifstream newfile;
    newfile.open(argv,ios::in); //Open the File
    int element; //Creates a Dynamic Array Size
    newfile >> element;
    string* temp = new string[element]; //Creates a String Array
    while (!newfile.eof()) {
        for(int i = 0; i < element; ++i)
        {
            newfile >> temp[i]; //Puts the names in the file into an Array
        }
    } 
    newfile.close(); //Close the File
    
    return temp;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readPokemonNames(const char* argv){
    ifstream afile;
    afile.open(argv,ios::in); //Open the File
    int element; // Creates a Dynamic Array Size
    afile >> element;
    string* temp = new string[element]; //Creates a String Array
    while (!afile.eof()) {
        for(int i = 0; i < element; ++i)
        {
            afile >> temp[i]; //Puts the names in the file into an Array
        }
    } 
    afile.close(); //Close the File
    
    return temp;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
player characterCreate(string playerName, int pokemonChoice){
    string your_pokemon; //Creates a Player's Pokemon Name
    switch (pokemonChoice)
    {
    case 1:
        your_pokemon = "Bulbasaur";
        break;
    case 2:
        your_pokemon = "Charmender";
        break;
    case 3:
        your_pokemon = "Squirtle";
        break;
    }
    pokemon new_pokemon(your_pokemon, PLAYER_POKEMON_ATTACK); //Creates a Pokemon with Name and Attack Value
    player new_player(playerName, new_pokemon); //Creates a Player with Name and Pokemon
    return new_player; 
};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
void mainMenu(){
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames){
    pokemon pok(pokemonNames[POK_COUNTER], ENEMY_POKEMON_ATTACK); //Creates a Pokemon with Name and Attack Value
    POK_COUNTER++; //The Number of Pokemon the Player encounters increases
    enemy e(enemyNames[NAME_COUNTER], pok); //Creates an Enemy with Name and Pokemon
    NAME_COUNTER++; //The Number of Enemy the Player encounters increases
    bool up;
    up = newPlayer->playerPokedex.updatePokedex(pok); //Puts encountered Pokemon in Array
    if(up == true || up == false){
        int choice;
        int enemy_hp = e.getPokemon().get_hp(); //Gets an Enemy's Health Point Value
        int player_hp = newPlayer->getPokemon().get_hp(); //Gets a Player's Health Point Value
        cout << "You encounter with " << e.getName() <<  " and his/hers pokemon " << pok.get_name() << endl;
        cout << pok.get_name() << " Health: " << pok.get_hp() << " Attack: " <<  pok.get_atk() << endl;
        do{
            cout << "1- Fight" << endl;
            cout << "2- Runaway" << endl;
            cout << "Choice: ";
            cin >> choice;
            if(choice == 2)
                break;
            enemy_hp = e.getPokemon().set_hp(enemy_hp - PLAYER_POKEMON_ATTACK); //Decreases Enemy's Health Point Value by the Player's Attack Value
            player_hp = newPlayer->getPokemon().set_hp(player_hp - ENEMY_POKEMON_ATTACK); //Decreases Player's Health Point Value by the Enemy's Attack Value
            cout << "Your Pokemons Health: " << player_hp << endl;
            cout << e.getName() << " Pokemons Health: " << enemy_hp << endl;
            cout << endl;
            if(enemy_hp <= 0){ //If Enemy's Health Point reaches 0 or drops below 0, Player wins
                cout << "You Won!" << endl;
                newPlayer->battleWon();
                break;
            }
        }while(choice != 2);
    }
};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player* newPlayer, string* pokemonNames){
    bool up;
    pokemon new_pokemon(pokemonNames[POK_COUNTER], ENEMY_POKEMON_ATTACK); //Creates a Pokemon with Name and Attack Value
    up = newPlayer->playerPokedex.updatePokedex(new_pokemon); //Puts encountered Pokemon in Array
    if(up == true || up == false){
        POK_COUNTER++; //The Number of Pokemon that the Player encounters increases
        int choice;
        cout << "You encounter with " << new_pokemon.get_name() << " Health: " << new_pokemon.get_hp() << " Attack: " << new_pokemon.get_atk() << endl;
        cout << "1- Catch" << endl;
        cout << "2- Runaway" << endl;  
        cout << "Choice: ";
        cin >> choice;
        if(choice == 1){
            newPlayer->catchPokemon();
            cout << "You catch " << new_pokemon.get_name() << endl;
        }
    }
};
//--------------------------------------------//
