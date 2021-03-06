/*==============================================================================
 | Filename: battleship.h
 | Programmer: Gabriel V. de a Cruz Jr.
 | Class: CptS 121, Fall 2012 ; Lab Section 7
 | Programming Assignment 4: Basic Game of Battleship
 | Date: October 17, 2012
 +------------------------------------------------------------------------------
 | Description: The file contains all of the function prototypee, structs,
 |              enumerated types, constanct macros and standard libraries,
 |              required to run the game of Battleship.
 ==============================================================================*/

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <fstream>
//#include <conio.h>

#include "ship.h"
#include "carrier.h"
#include "battleship.h"
#include "cruiser.h"
#include "submarine.h"
#include "destroyer.h"
#include "board.h"

/* CONSTANT MACROS */

//#define ROWS 10
//#define COLS 10

#define LOG_FILE_NAME "battleship.log"

#define NUM_OF_SHIPS  5

#define HORIZONTAL    0
#define VERTICAL      1

#define PLAYER_ONE    0
#define PLAYER_TWO    1

#define CARRIER       'c'
#define BATTLESHIP    'b'
#define CRUISER       'r'
#define SUBMARINE     's'
#define DESTROYER     'd'

#define NORTH 0
#define SOUTH 1
#define WEST  2
#define EAST  3

typedef struct stats {
	int        numHits;
	int        numMisses;
	int        totalShots;
	double     hitMissRatio;
} Stats;


class interaction{
public:
	interaction();
	virtual ~interaction();
	void         welcomeScreen                  (void);
	//void         initializeGameBoard            (Cell gameBoard[][COLS]);
	//void         printGameBoard                 (Cell gameBoard [][COLS], Boolean showPegs);
	void         putShipOnGameBoard             (Cell gameBoard[][COLS], ship ship, Coordinate position, int direction);
	void         manuallyPlaceShipsOnGameBoard  (Cell gameBoard[][COLS], ship ship[]);
	void         randomlyPlaceShipsOnGameBoard  (Cell gameBoard[][COLS], ship ship[]);
	//void         updateGameBoard                (Cell gameBoard[][COLS], Coordinate target);
	void         checkBoundsOfCardinal          (Boolean cardinals[], int bound, int direction);
	//void         systemMessage                  (char *message);

	Boolean      checkSunkShip                  (short sunkShip[][NUM_OF_SHIPS], short player, char shipSymbol, FILE *stream);
	Boolean      isValidLocation                (Cell gameBoard[][COLS], Coordinate position, int direction, int length);
	Boolean      convertStringtoPosition        (Coordinate position[], char *stringPosition, int length);
	Boolean      isWinner                       (Stats players[], int player);
	Coordinate   generatePosition               (int direction, int length);
	Coordinate   getTarget                      (void);

	short        checkShot                      (Cell gameBoard[][COLS], Coordinate target);
	int          getRandomNumber                (int lowest, int highest);
};


#endif
