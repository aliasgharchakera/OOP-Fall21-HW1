#include "seeplusia.hpp"
#include "mover.hpp"

int applesLeft = 30, nCrystalsFound = 0;
string gameState  = "Running";
string position = "Vampire Cove";
int jump = 0, crys_eisten = 1, crys_wolf = 1, crys_marsh = 1, crys_swamp = 1;

// This is a demo implementation of makeMove function
// It doesn't follow the game rules at all
// You have to implement it according to game logic 

void makeMove(string direction){
	if (applesLeft == 0){
		gameState = "Lost";
	}
	else if (direction == "East"){ //When Right Arrow is pressed
		if ((position == "Swamps of Despair") || (position == "Marsh of Undead") || (position == "Sands of Quick") || (position == "Wizard's Castle")){
			cout << "Can't move in that direction" << endl;
			applesLeft--;
		}
		else if (position == "Vampire Cove"){
			cout<<"Provide East move implementation"<<endl;
			moveEast(); 
			position = "Marsh of Undead";
			applesLeft--;
			if (crys_marsh == 1){
				nCrystalsFound++;
				crys_marsh = 0;
				cout<<crys_marsh<<endl;
				cout <<nCrystalsFound<<endl;
			}
		}
		else if (position == "Werewolf Hill"){
			cout<<"Provide East move implementation"<<endl;
			moveEast(); 
			position = "Sands of Quick";
			applesLeft--;
			cout<<"You slowly sink into quicksand and die and the game is Lost"<<endl;
			gameState = "Lost";
		}
		else if (position == "Elvin Waterfall"){
			cout<<"Provide East move implementation"<<endl;
			moveEast(); 
			position = "Werewolf Hill";
			applesLeft -= 2;
			if (crys_wolf == 1){
				nCrystalsFound++;
				crys_wolf = 0;
				cout<<crys_wolf<<endl;
				cout <<nCrystalsFound<<endl;
			}
		}
		else if (position == "Eisten Tunnel"){
			cout<<"Provide East move implementation"<<endl;
			moveEast(); 
			position = "Elvin Waterfall";
			applesLeft -= 2;
		}
		else if (position == "Apple's Orchard"){
			cout<<"Provide East move implementation"<<endl;
			moveEast(); 
			position = "Vampire Cove";
			applesLeft--;
		}
		else if (position == "Enchanted Forest"){
			cout<<"Provide East move implementation"<<endl;
			moveEast(); 
			position = "Swamps of Despair";
			applesLeft--;
			if (crys_swamp == 1){
				nCrystalsFound++;
				crys_swamp = 0;
				cout<<crys_swamp<<endl;
				cout <<nCrystalsFound<<endl;
			}
		}
		else if (position == "Bridge of Death"){
			cout<<"Provide East move implementation"<<endl;
			moveEast(); 
			position = "Enchanted Forest";
			applesLeft -= 2;
		}
	}
	else if (direction == "West"){ //When Left Arrow is pressed
		if ((position == "Wizard's Castle") || (position == "Eisten Tunnel") || (position == "Apple's Orchard") || (position == "Sands of Quick")){
			cout << "Can't move in that direction" << endl;
			applesLeft--;
		}
		else if (position == "Vampire Cove"){
			cout<<"Provide West move implementation"<<endl;
			moveWest();
			position = "Apple's Orchard";
			applesLeft--;
			applesLeft += 6;
		}
		else if (position == "Marsh of Undead"){
			cout<<"Provide West move implementation"<<endl;
			moveWest();
			position = "Vampire Cove";
			applesLeft--;
		}
		else if (position == "Swamps of Despair"){
			cout<<"Provide West move implementation"<<endl;
			moveWest();
			position = "Enchanted Forest";
			applesLeft--;
		}
		else if (position == "Enchanted Forest"){
			cout<<"Provide West move implementation"<<endl;
			moveWest();
			position = "Bridge of Death";
			applesLeft -= 2;
		}
		else if (position == "Bridge of Death"){
			if (nCrystalsFound == 4){
				cout<<"Provide West move implementation"<<endl;
				moveWest();
				position = "Wizard's Castle";
				applesLeft -= 5;
				gameState = "Won";
				cout<<"Congratulations the prince is rescued and the game is Won!"<<endl;
			}
			else{
				cout<<"You need all 4 crystals to move to Wizard's Castle"<<endl;
				applesLeft -= 5; // it consumes apples 
			}
		}
		else if (position == "Werewolf Hill"){
			cout<<"Provide West move implementation"<<endl;
			moveWest();
			position = "Elvin Waterfall";
			applesLeft -= 2;
		}
		else if (position == "Elvin Waterfall"){
			cout<<"Provide West move implementation"<<endl;
			moveWest();
			position = "Eisten Tunnel";
			applesLeft -= 2;
			if (crys_eisten == 1){
				nCrystalsFound++;
				crys_eisten = 0;
				cout<<crys_eisten<<endl;
				cout <<nCrystalsFound<<endl;
			}
		}
	}
	else if (direction == "North"){ //When Up Arrow is pressed
		if (position == "Vampire Cove"){
			cout<<"Provide North move implementation"<<endl;
			moveNorth();
			position = "Enchanted Forest";
			applesLeft -= 3;
		}
		else if (position == "Werewolf Hill"){
			cout<<"Provide North move implementation"<<endl;
			moveNorth();
			position = "Vampire Cove";
			applesLeft -= 3;
		}
		else if (position == "Eisten Tunnel"){
			cout<<nCrystalsFound<<endl;
			if (nCrystalsFound >= 3){
				cout<<jump<<endl;
				if (jump == 0){
				cout<<"Provide North move implementation"<<endl;
				moveNorth();
				applesLeft -= 5;
				jump++;
				}
				else if (jump == 1){
				cout<<"Provide North move implementation"<<endl;
				moveNorth();
				position = "Wizard's Castle";
				applesLeft -= 5;
				jump++;
				gameState = "Won";
				cout<<"Congratulations the prince is rescued and the game is Won!"<<endl;
				}
			}
			else{
				cout<<"You need at least 3 crystals to move to Wizard's Castle"<<endl;
				applesLeft -= 10; // it still consumes apples
			}
		}
		else{
			cout << "Can't move in that direction" << endl;
			applesLeft--;
		}
	}
	else if (direction == "South"){//When Down Arrow is pressed
		if (position == "Vampire Cove"){
			cout<<"Provide South move implementation"<<endl;
			moveSouth();
			position = "Werewolf Hill";
			applesLeft -= 3;
			if (crys_wolf == 1){
				nCrystalsFound++;
				crys_wolf = 0;
				cout<<crys_wolf<<endl;
				cout <<nCrystalsFound<<endl;
			}
		}
		else if (position == "Enchanted Forest"){
			cout<<"Provide South move implementation"<<endl;
			moveSouth();
			position = "Vampire Cove";
			applesLeft -= 3;
		}
		else if (position == "Marsh of Undead"){
			cout<<"Provide South move implementation"<<endl;
			moveSouth();
			position = "Sands of Quick";
			applesLeft--;
			cout<<"You slowly sink into quicksand and die and the game is Lost"<<endl;
			gameState = "Lost";
		}
		else{
			cout << "Can't move in that direction" << endl;
			applesLeft--;
		}
	}
}