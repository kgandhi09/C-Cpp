/*
 * tests.cpp
 *
 *  Created on: Oct 2, 2019
 *      Author: kushal
 */


#include "tests.h"
#include "interaction.h"

interaction i = interaction();
board brd = board();

tests::tests() {
	// TODO Auto-generated constructor stub

}

tests::~tests() {
	// TODO Auto-generated destructor stub
}

bool tests::runTests(){
	bool answer = true;



	bool ok1 = testPutShipOnGameBoard();
	cout << "This tests whether ship is put on board or not!" << endl; fflush(stdout);

	bool ok2 = testManuallyPlaceShipOnBoard();
	cout << "This test checks and print if ship is manually placed correctly!" << endl;fflush(stdout);

	bool ok3 = testCheckSunkShip();
	cout << "This test checks whether the ship has sunk or not!!" << endl;fflush(stdout);

	bool ok4 = testisValidLocation();
	cout << "This test checks whether the location is valid or not!" << endl;fflush(stdout);

	bool ok5 = testIsWinner();
	cout << "This test checks whether the player is winner or not!!" << endl;fflush(stdout);

	bool ok6 = testCHeckShot();
	cout << "This test checks whether shot is missed or hit!!" << endl;fflush(stdout);

	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6;

	return answer;
}


bool tests::testPutShipOnGameBoard(){
	bool result = false;
	ship c = carrier();
	Cell testGameBoard[10][10];
	Coordinate target;
	target.row = 1;
	target.column = 2;
	i.putShipOnGameBoard(testGameBoard, c, target, TRUE);
	if (testGameBoard[target.row+1][target.column].symbol == c.symbol){
		result = true;
	}

	return result;
}


bool tests::testManuallyPlaceShipOnBoard(){
	bool result = true;
	ship c = carrier();
	ship ba = battleship();
	ship r = cruiser();
	ship s = submarine();
	ship d = destroyer();

	ship ship[] = {c, ba , r, s, d};

	Cell testGameBoard[10][10];

	//i.manuallyPlaceShipsOnGameBoard(testGameBoard, ship);
	//brd.printGameBoard(testGameBoard, TRUE);
	return result;
}

bool tests::testCheckSunkShip(){
	bool result = false;
	ship c = carrier();
	ship b = carrier();
	FILE* stream = fopen("test.log", "w");
	short sunkShip[2][NUM_OF_SHIPS] = {{5, 4, 3, 3, 2},
			{5, 4, 3, 3, 2}};

	Boolean hasShipSunk = i.checkSunkShip(sunkShip, !1, c.symbol, stream);
	Boolean hasShipSunk2 = i.checkSunkShip(sunkShip, 1, c.symbol, stream);
	if (!hasShipSunk && !hasShipSunk2){
		result = true;
	}


	return result;

}

bool tests::testisValidLocation(){
	bool result = false;

	ship c = carrier();
	ship ba = battleship();
	ship r = cruiser();
	ship s = submarine();
	ship d = destroyer();

	ship ship[] = {c, ba , r, s, d};

	int direction = -1;
	Cell testGameBoard[10][10];
	Coordinate position = i.generatePosition (direction, ship[0].length);
	Boolean test = i.isValidLocation(testGameBoard, position, direction, ship[0].length);

	if (test == FALSE){
		result = true;
	}
	return result;
}

bool tests::testIsWinner(){
	bool result = false;
	Stats players[2] = {{0, 0, 0, 0.0}, {0, 0, 0, 0.0}};
	short player = 0;
	Boolean isWin = i.isWinner(players,player) ;
	if (isWin == FALSE){
		result = true;
	}
	return result;
}

bool tests::testCHeckShot(){
	bool result = false;
	Coordinate target;
	target.row = 0;
	target.column = 5;
	Cell testGameBoard[10][10];
	short shot = i.checkShot (testGameBoard, target);
	if (shot == -1){
		result = true;
	}
	return result;
}




