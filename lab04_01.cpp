//  Student Name: Rishi Vimalendran
//  Student Number:  20826980
//
//  SYDE 121 Assignment: 04
//  Filename: lab04_01
//
// I hereby declare that this code, submitted for credit for the course//  SYDE121, is a product of my own efforts.  This coded solution has//  not been plagiarized from other sources and has not been knowingly//  plagiarized by others.
//
// Project : 4x4 Tic Tac Toe
// Purpose : Creates a playable game of tic tac toe, with multiple matches and stat outputs
/*
 I ran the program multiple times and purposely went through different scenarios to see if all outcomes worked as they should. I checked if X-win, O-win, and tie games worked properly, and if multiple matches ran correctly.
 */

#include <iostream>
using namespace std;

void initialize_board (int board [][4], int board_elements);
//INPUT: The array for the board and its size
//PROCESSING: Initializes every value in the array corresponding to the initial board values

void output_board (int board [][4], int board_elements);
//INPUT: The array for the board and its size
//PROCESSING:
//OUTPUT: The current state of the board, including open positions and Xs and Os

void player_input (bool player_x_turn, int board [][4], int board_elements);
//INPUT: The player turn, the board array and its size. Asks user to input a position to make move
//PROCESSING: Checks if the player's inputted position is a valid move, and then assigns it a value according to if they are playing as X or O

bool check_win (int board [][4], int board_elements, bool player_x_turn, int& x_wins, int& o_wins, int& tie_games);
//INPUT: The board array and its size, the player turn, and the stat variables
//PROCESSING: Checks to see if the game has been one or is in a state of a tie. Adds one to the respective stat variable if any of the above situations are true
//OUTPUT: A message if any of the above situations are true that is specific to the situation

void final_stats (int number_of_games, int x_wins, int o_wins, int tie_games);
//INPUT: Stat variables
//OUTPUT: Outputs all the stats of the games

void play_game (int board [][4], int board_elements);


int main()
{
    const int BOARD_WIDTH = 4;
    int board [BOARD_WIDTH][BOARD_WIDTH];
    initialize_board(board, BOARD_WIDTH);
    play_game(board, BOARD_WIDTH);
}

void initialize_board (int board [][4], int board_elements)
{
    
    int count = 1;
    for (int i = 0; i < board_elements; i++)
    {
        for (int n = 0; n < board_elements; n++)
        {
            board [i][n] = count;
            count += 1;
        }
    }
}

void play_game (int board [][4], int board_elements)
{
    bool player_x_turn = true;
    bool is_win;
    bool cont_game = true;
    int game_counter = 0, x_wins = 0, o_wins = 0, tie_games = 0;
    
    while (cont_game)
    {
        initialize_board(board, board_elements);
        is_win = false;
        game_counter += 1;
        
        if (game_counter % 2 == 0)
        {
            player_x_turn = false;
        }
        
        while (is_win == false)
        {
            output_board(board, board_elements);
            player_input(player_x_turn, board, board_elements);
            is_win = check_win(board, board_elements, player_x_turn, x_wins, o_wins, tie_games);
            
            if (player_x_turn)
            {
                player_x_turn = false;
            }
            
            else
            {
                player_x_turn = true;
            }
        }
        
        output_board(board, board_elements);
        cout << "\nContinue Playing? (0 to stop game, 1 to continue)" << endl;
        cin >> cont_game;
    }
    
    final_stats(game_counter, x_wins, o_wins, tie_games);
}

void output_board (int board [][4], int board_elements)
{
    cout << "\n";
    for (int i = 0; i < board_elements; i++)
    {
        for (int n = 0; n < board_elements; n++)
        {
            if (board [i][n] == -1)
            {
                cout << "X    ";
            }
            
            else if (board [i][n] == -2)
            {
                cout << "O    ";
            }
            
            else
            {
                if (board [i][n] < 10)
                {
                    cout << board [i][n] << "    ";
                }
                
                else
                {
                    cout << board [i][n] << "   ";
                }
            }
        }
        cout << "\n";
    }
}

void player_input (bool player_x_turn, int board [][4], int board_elements)
{
    int player_move;
    bool valid_move = false;
    
    while (valid_move == false)
    {
        cout << "Enter a position: ";
        cin >> player_move;
        
        if (player_move > 16 || player_move < 1)
        {
            valid_move = false;
        }
        
        else
        {
            for (int i = 0; i < board_elements; i++)
            {
                for (int n = 0; n < board_elements; n++)
                {
                    if (board [i][n] == player_move)
                    {
                        valid_move = true;
                        
                        if (player_x_turn)
                        {
                            board [i][n] = -1;
                        }
                        
                        else
                        {
                            board [i][n] = -2;
                        }
                    }
                    
                }
            }
            
        }
        
        if (valid_move == false)
        {
            cout << "That move is invalid! \n";
        }
    }
}

bool check_win (int board [][4], int board_elements, bool player_x_turn, int& x_wins, int& o_wins, int& tie_games)
{
    int count = 0;
    bool is_win = false;
    bool tie_game = true;
    
    for (int i = 0; i < board_elements; i++)
    {
        for (int n = 0; n < board_elements - 1; n++)
        {
            if (board [i][n] == board [i][n+1])
            {
                count += 1;
                if (count == 3)
                {
                    is_win = true;
                }
            }
        }
        count = 0;
    }
    
    for (int n = 0; n < board_elements; n++)
    {
        for (int i = 0; i < board_elements - 1; i++)
        {
            if (board [i][n] == board [i+1][n])
            {
                count += 1;
            }
            
            if (count == 3)
            {
                is_win = true;
            }
        }
        count = 0;
    }
    
    for (int i = 0; i < board_elements; i++)
    {
        if (board [i][i] == board [i+1][i+1])
        {
            count += 1;
        }
        
        if (count == 3)
        {
            is_win = true;
        }
    }
    
    int row = 3;
    for (int i = 0; i < board_elements; i++)
    {
        if (board [i][row] == board [i+1][i+1])
        {
            count += 1;
        }
        
        if (count == 3)
        {
            is_win = true;
        }
        row--;
    }
    
    if (is_win)
    {
        if (player_x_turn)
        {
            x_wins += 1;
            cout << "\nPlayer X has won this game!";
        }
        
        else
        {
            o_wins += 1;
            cout << "\nPlayer O has won this game!";
        }
    }
    
    for (int i = 0; i < board_elements; i++)
    {
        for (int n = 0; n < board_elements - 1; n++)
        {
            if (board [i][n] > 0)
            {
                tie_game = false;
            }
        }
    }
    
    if (tie_game)
    {
        tie_games += 1;
        cout << "\nIt's a tie! No winner!";
        is_win = true;
    }
    return is_win;
}

void final_stats (int number_of_games, int x_wins, int o_wins, int tie_games)
{
    cout << "\nNumber of Games Played: " << number_of_games << endl;
    cout << "Player X Wins: " << x_wins << endl;
    cout << "Player O Wins: " << o_wins << endl;
    cout << "Number of Ties: " << tie_games << endl;
}
