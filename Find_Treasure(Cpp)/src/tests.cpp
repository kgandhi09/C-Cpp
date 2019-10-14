/*
 * tests.cpp
 *
 *  Created on: Sep 26, 2019
 *      Author: kushal
 */


#include "tests.h"



tests::tests() {
	// TODO Auto-generated constructor stub

}

tests::~tests() {
	// TODO Auto-generated destructor stub
}

bool tests::runTests(){
	bool answer = true;

	fscanf(fp, "%d", &nRooms);

	int** houseArr = c.readFileIntoHouse(nRooms, fp);
	int* treasureArr = c.readFileIntoTreasure(nRooms, fp);

	cout << "These are tests !\n"; fflush(stdout);

	bool ok1 = testReadFileIntoHouse(houseArr);
	cout << "This test reads house layout from file\n" << endl; fflush(stdout);

	bool ok2 = testReadFileIntoTreasure(treasureArr);
	cout << "This test reads treasures from file\n" << endl; fflush(stdout);

	bool ok3 = testAdjRooms(houseArr);
	cout << "This test finds adjacent rooms to the given room\n" << endl; fflush(stdout);

	bool ok4 = testAmtTreasure(treasureArr);
	cout << "This test finds the amount of treasure present in that particular room\n" << endl; fflush(stdout);

	answer = ok1 && ok2 && ok3 && ok4;

	return answer;
}

bool tests::testReadFileIntoHouse(int** houseArr)
{

	bool ok = true;
	c.print2DArray(nRooms, nRooms, houseArr);
	return ok;
}

bool tests::testReadFileIntoTreasure(int* treasureArr){

	bool ok = true;
	c.print1DArray(nRooms, treasureArr);

	return ok;

}

bool tests::testAdjRooms(int** houseArr){
	bool ok = true;
	int* adjRooms = c.adjacentRooms(houseArr, 1, nRooms);
	c.print1DArray(nRooms, adjRooms);
	return ok;
}

bool tests::testAmtTreasure(int* treasureArr){
	bool ok = false;
	int treasureRoom1 = c.amtTreasure(1, treasureArr, nRooms);
	if (treasureRoom1 == treasureArr[0]){
		ok = true;
	}
	return ok;
}




