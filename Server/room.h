#pragma once
#include "constants.h"
#pragma comment (lib,"ws2_32.lib")

class Room {
private:
	SOCKET firstPlayerSocket;
	SOCKET secondPlayerSocket;
	std::vector<PlayerMove> movesList;
	int board[BOARD_HEIGHT][BOARD_WIDTH];
	std::string startTime;
public:
	Room(SOCKET firstClient, SOCKET secondClient);
	bool isPlayerTurn(SOCKET socket);
	bool isBoardCellEmpty(int x, int y);
	bool isMoveInBoard(int x, int y);
	bool isMatchEndByDraw();
	bool isMatchEndByWin();
	bool isPlayerInRoom(SOCKET socket);
	int addPlayerMove(PlayerMove aMove);
	SOCKET getPlayerOpponent(SOCKET socket);
	int getMatchResult();
	int getPlayerMoveType(SOCKET socket);
	std::vector<PlayerMove> getMovesList();
	void setStartTime(std::string start);
	std::string getStartTime();
};
/*
@function: Room: Create room object.

@param firstPlayerSocket: the first's player socket.
@param secondPlayerSocket: the second's player socket.
*/
Room::Room(SOCKET firstPlayerSocket, SOCKET secondPlayerSocket) {
	this->firstPlayerSocket = firstPlayerSocket;
	this->secondPlayerSocket = secondPlayerSocket;
	this->movesList.clear();
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			this->board[i][j] = 0;
		}
	}
}
/*
@function getMovesList: Get the moves 2 players made.

@return Return a list of moves of the match.
*/
std::vector<PlayerMove> Room::getMovesList() {
	return this->movesList;
}
/*
@function isPlayerInRoom: Check if the connection currently in a room.

@param socket: The socket needed to be checked.

@return true if socket is in a room.
false if not

*/
bool Room::isPlayerInRoom(SOCKET socket) {
	if (this->firstPlayerSocket == socket || this->secondPlayerSocket == socket)
		return true;
	return false;
}
/*
@function isPlayerTurn: Check if it is a scoket's turn.

@param socket: The socket needed to be checked.

@return true if it is socket's turn.
false if not
*/
bool Room::isPlayerTurn(SOCKET socket) {
	int nextMoveType;
	if (this->movesList.size() == 0) {
		nextMoveType = TYPE_O;
	}
	else {
		nextMoveType = this->movesList.back().type == TYPE_O ? TYPE_X : TYPE_O;
	}

	if (socket == this->firstPlayerSocket) {
		return nextMoveType == TYPE_O;
	}
	else {
		return nextMoveType == TYPE_X;
	}
}
/*
@function isMoveInBoard: Check if the move coordinates is inside the board.

@param x: The x-axis coordinate
@param y: The y-axis coordinate

@return true if it is indside.
false if not
*/
bool Room::isMoveInBoard(int x, int y) {
	return x < BOARD_WIDTH && x >= 0 && y < BOARD_HEIGHT && y >= 0;
}
/*
@function isBoardCellEmpty: check if the cell at move coordinates is empty.

@param x: The x-axis coordinate
@param y: The y-axis coordinate

@return true if it is indside.
false if not
*/
bool Room::isBoardCellEmpty(int x, int y) {
	return this->board[y][x] == 0;
}
/*
@function isMatchEndByWin: Check if current tur player win

@return true if it is indside.
false if not
*/
bool Room::isMatchEndByWin() {
	int dx[] = { 0, 1, 1, 1 };
	int dy[] = { 1, 0, 1, -1 };
	int startX, startY, currentX, currentY;

	PlayerMove curMove = this->movesList.back();
	int type = curMove.type;
	int x = curMove.x;
	int y = curMove.y;

	//Print current board
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			std::cout << this->board[i][j] << " ";
		}
		std::cout << std::endl;
	}

	//Check row, column, diagonal and back diagonal for winning line
	int score;
	for (int lineType = 0; lineType < 4; lineType++) {
		score = 0;
		startX = x - (BOARD_WIN_SCORE - 1) * dx[lineType];
		startY = y - (BOARD_WIN_SCORE - 1) * dy[lineType];
		for (int i = 0; i < 2 * BOARD_WIN_SCORE - 1; i++) {
			currentX = startX + i * dx[lineType];
			currentY = startY + i * dy[lineType];
			if (!Room::isMoveInBoard(currentX, currentY)) continue;
			if (this->board[currentY][currentX] != type) score = 0;
			else {
				score++;
				if (score == BOARD_WIN_SCORE) return true;
			}
		}
	}
	return false;
}
/*
@function isMatchEndByDraw: Check if a match is draw (when there is no empty cells left)

@return true if it is indside.
false if not
*/
bool Room::isMatchEndByDraw() {
	return this->movesList.size() >= BOARD_WIDTH * BOARD_HEIGHT;
}
/*
@function getMatchResult: Return type of match result based on current moves list

@return	MATCH_END_BY_WIN if a player win
MATCH_END_BY_DRAW if match is a draw
MATCH_CONTINUE if match shoud be continued

*/
int Room::getMatchResult() {
	if (this->isMatchEndByWin()) return MATCH_END_BY_WIN;
	if (this->isMatchEndByDraw()) return MATCH_END_BY_DRAW;
	return MATCH_CONTINUE;
}
/*
@function addPlayerMove: Add a player's move to the match current moves list

@param aMove: Player's move

@return OPCODE_PLAY_INVALID_CORDINATE if the move is invalid
OPCODE_PLAY if the move is added

*/
int Room::addPlayerMove(PlayerMove aMove) {
	if (!Room::isMoveInBoard(aMove.x, aMove.y) || !Room::isBoardCellEmpty(aMove.x, aMove.y)) {
		return OPCODE_PLAY_INVALID_CORDINATE;
	}

	this->board[aMove.y][aMove.x] = aMove.type;
	this->movesList.push_back(aMove);
	return OPCODE_PLAY;
}
/*
@function getPlayerMoveType: Get a player's move type based on their socket

@param socket: Player's socket

@return	TYPE_O if player move type O
TYPE_X if player move type X

*/
int Room::getPlayerMoveType(SOCKET socket) {
	if (socket == this->firstPlayerSocket) {
		return TYPE_O;
	}
	else {
		return TYPE_X;
	}
}
/*
@function getPlayerOpponent: Get a player's oppent

@param socket: Player's socket

@return The socket of the oppenent

*/
SOCKET Room::getPlayerOpponent(SOCKET socket) {
	if (socket == this->firstPlayerSocket) {
		return this->secondPlayerSocket;
	}
	else {
		return this->firstPlayerSocket;
	}
}

/*
@function setStartTime: Set match start time

@param start: The string represent start time
*/
void Room::setStartTime(std::string start) {
	this->startTime = start;
}
/*
@function setStartTime: Get match start time
*/
std::string Room::getStartTime() {
	return this->startTime;
}
