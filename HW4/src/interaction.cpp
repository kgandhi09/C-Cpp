/*
 * interaction.cpp
 *
 *  Created on: Sep 29, 2019
 *      Author: kushal
 */

#include "interaction.h"

interaction::interaction(int noOfRooms, int** houseGraph, int* treasures, int treasureLimit, int maxRooms){

}

interaction::~interaction(){}

void interaction::runInteraction(int noOfRooms, int** houseGraph, int* treasures, int treasureLimit, int maxRooms){
	int inputRoomNo;
	int* adjRoomsTo = (int*)malloc(sizeof(int)*noOfRooms);
	//int* visitedRooms;
	int* visitedRooms = (int*)malloc(sizeof(int)*10);
	int countVisit = 0;
	int totalTreasure = 0;
	bool firstTime = true;
	printf("Enter the room number to search the room - ");
	scanf("%d", &inputRoomNo);
	controller c = controller();
	while(countVisit < maxRooms){
		if(((c.checkAdjRoomPresent(adjRoomsTo, inputRoomNo, noOfRooms)) && !(c.visited(visitedRooms, inputRoomNo, countVisit))) || firstTime){
			visitedRooms[countVisit] = inputRoomNo;
			countVisit++;
			firstTime = false;
			adjRoomsTo = c.adjacentRooms(houseGraph, (inputRoomNo-1), noOfRooms);
			int amtTreasureRoom = c.amtTreasure(inputRoomNo, treasures, noOfRooms);
			totalTreasure += amtTreasureRoom;
			if(totalTreasure > treasureLimit){
				printf("Total Treasure exceeds limit you provided!\n");
				break;
			}
			printf("Treasure in this room is - %d\n", amtTreasureRoom);
			printf("The adjacent rooms are - ");
			c.print1DArray(7, adjRoomsTo);
			printf("Total treasure till now is - %d\n", totalTreasure);
			printf("Rooms visited till now - ");
			c.print1DArray(countVisit, visitedRooms);
			printf("\n");
			printf("What is the next room you would like to search - ");
			scanf("%d", &inputRoomNo);
		}

		else{
			if(c.visited(visitedRooms, inputRoomNo, countVisit)){
				printf("sorry the room you entered is already visited\n");
				break;

			}
			else{
				printf("sorry the room you entered is not reachable, enter from the adj rooms\n");
				break;
			}
		}


	}
	if(countVisit>= maxRooms){
		printf("No of rooms searched exceeds the limit you provided!\n");
	}
}



