#include <iostream>
#include <cstdlib>

using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkwin();
void board();

int main()
{
    int player = 1, i, choice;
    char mark;

    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << " [" << ((player == 1) ? 'X' : 'O') << "], enter a slot (1-9): ";
        
        // Input validation (prevents crash if non-number is entered)
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid input! Please enter a number between 1 and 9. Press Enter to continue...";
            cin.get();
            continue;
        }

        mark = (player == 1) ? 'X' : 'O';

        // Valid move check
        if (choice >= 1 && choice <= 9 && square[choice] == ('0' + choice))
        {
            square[choice] = mark;
            player++;
        }
        else
        {
            cout << "\nInvalid Move! Slot already occupied or out of range. Press Enter to retry...";
            cin.ignore(1000, '\n');
            cin.get();
        }

        i = checkwin();

    } while (i == -1);

    board();

    if (i == 1)
    {
        // Decrement player to get the winning player
        player = (player % 2) ? 2 : 1;
        cout << "\n==> Congratulations! Player " << player << " wins!\n\n";
    }
    else
    {
        cout << "\n==> Game Draw!\n\n";
    }

    return 0;
}

int checkwin()
{
    // Horizontal & Vertical Winning Conditions
    if (square[1] == square[2] && square[2] == square[3]) return 1;
    if (square[4] == square[5] && square[5] == square[6]) return 1;
    if (square[7] == square[8] && square[8] == square[9]) return 1;
    if (square[1] == square[4] && square[4] == square[7]) return 1;
    if (square[2] == square[5] && square[5] == square[8]) return 1;
    if (square[3] == square[6] && square[6] == square[9]) return 1;

    // Diagonal Winning Conditions
    if (square[1] == square[5] && square[5] == square[9]) return 1;
    if (square[3] == square[5] && square[5] == square[7]) return 1;

    // Check for Draw (No slots left)
    for (int idx = 1; idx <= 9; idx++)
    {
        if (square[idx] == ('0' + idx))
            return -1; // Match still in progress
    }

    return 0; // Draw
}

void board()
{
    system("cls");
    cout << "\n========================================\n";
    cout << "\tTIC TAC TOE (CLI EDITION)\n";
    cout << "========================================\n\n";
    cout << "  Player 1 (X)  -  Player 2 (O)\n\n";

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "     |     |     " << endl << endl;
}