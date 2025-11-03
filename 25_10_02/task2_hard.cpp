#include <iostream>
using namespace std;

bool isValidTicTacToe(char board[], bool &xWins, bool &oWins) {
	int countX = 0;
	int countO = 0;
		    
		    
	for (int i = 0; i < 9; i++) {
		if (board[i] == 'X'){ 
			countX++;
		}
		else if (board[i] == 'O'){
			countO++;
		}
	}

	if (!(countX == countO || countX == countO + 1)) {
		return false;
	}

	xWins = false;
	oWins = false;
				    
				    
	for (int i = 0; i < 9; i += 3) {
					            
		if (board[i] != '-' && board[i] == board[i+1] && board[i+1] == board[i+2]){
			if (board[i] == 'X'){
				xWins = true; 
			}else if(board[i] == 'O'){
														   oWins = true; 
			} 
		}
	}

				        
	for (int j = 0; j < 3; j++){
						        
		if (board[j] != '-' && board[j] == board[j+3] && board[j+3] == board[j+6]) {
			if (board[j] == 'X'){
				xWins = true; 
			}else if(board[j] == 'O'){
													           oWins = true; 
			}
		}
	}
					    
	if (board[0] != '-' && board[0] == board[4] && board[4] == board[8]) {
		if (board[0] == 'X'){ 
			xWins = true;
		}
		else if (board[0] == 'O'){
			oWins = true;
		}
	}
	if (board[2] != '-' && board[2] == board[4] && board[4] == board[6]) {
		if (board[2] == 'X'){ 
			xWins = true;
		}
		else if (board[2] == 'O'){
			oWins = true;
											           }
									            
	}
						    
	if (xWins && oWins) {
		return false;
	}
						        
						        
	if (xWins && countX != countO + 1) {
		return false;
	}
							    
	if (oWins && countX != countO) {
		return false;
	}
	return true;
}

int main() {
	char board[9];
	bool xWins;
	bool oWins;
	cout << "Enter Tic-Tac-Toe board (use capital X, O, or - for empty): " << endl;
	for (int i = 0; i < 9; i++) {
		cout << "Position " << i+1 << ": ";
		cin >> board[i];
	}
			        
	cout << "\nYour Tic-Tac-Toe board:" << endl;
	for (int i = 0; i < 9; i++) {
		cout << board[i] << " ";
		if ((i+1)%3 == 0){
			cout << endl;
		}
	}
				        
	if (isValidTicTacToe(board, xWins, oWins)) {
		cout << "\nValid board position!" << endl;
		if (xWins== true){
			cout << "X wins";
		} else if (oWins == true){
			cout << "O wins!" << endl;
		} else {
			cout << "Game is in progress or it's a draw!" << endl;
		}
	} else {
		cout << "\nInvalid board position!" << endl;
	}
	return 0;
}
