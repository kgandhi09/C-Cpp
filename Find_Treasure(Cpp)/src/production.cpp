/*
 * production.cpp
 *
 *  Created on: Sep 26, 2019
 *      Author: kushal
 */

#include "production.h"


production::production(int argc, char* argv[]){

}

production::~production(){}

bool production::runProduction(int argc, char* argv[])
{
	bool answer = true;
	printf("This is production!\n");
	char* ePtr=(char*)malloc(sizeof(char*));

	//char *filename = (char)malloc(sizeof(char)*)

	for(int i =0; i<100; i++){
		filename[i] = '\0';
	}

	strcpy(filename, argv[1]);

	maxRoomsToSearch =strtol(argv[2],&ePtr,10); // command line argument 1 - max no of rooms to search in house
	limTreasure=strtol(argv[3],&ePtr,10); // command line argument 2 - total limit of treasure found

	int treasureLimit=(int)limTreasure;

	FILE* fp = fopen(filename, "r");

	fscanf(fp, "%d", &numOfRooms);

	controller c = controller();
	int** houseGraph = c.readFileIntoHouse(numOfRooms, fp);
	printf("This is the house Layout!\n");
	c.print2DArray(numOfRooms,numOfRooms, houseGraph);
	printf("\n");


	int* treasures = c.readFileIntoTreasure(numOfRooms, fp);
	printf("This is treasure in each rooms!\n");
	c.print1DArray(numOfRooms, treasures);
	printf("\n");
	interaction i = interaction(numOfRooms, houseGraph, treasures, treasureLimit, maxRoomsToSearch);
	i.runInteraction(numOfRooms, houseGraph, treasures, treasureLimit, maxRoomsToSearch);


	return answer;
}




