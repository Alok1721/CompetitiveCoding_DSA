#include<bits/stdc++.h>
using namespace std;

enum class Symbol:char{
    X='X',
    O='O',
    EMPTY=' '
};

class Player
{
    private: 
    string name;
    Symbol symbol;
    int id;
    public:
    Player(string name,Symbol symbol,int id)
    {
        this->name=name;
        this->symbol=symbol;
        this->id=id;
    }
    string getName() { return name; }
    Symbol getSymbol() { return symbol; }
};

class Board
{
    private:
    vector<vector<Symbol>> board;
    int size;
    public:
    Board(int size)//this is reset the board when we call first time
    {
        this->size=size;
        board.resize(size,vector<Symbol>(size,Symbol::EMPTY));
    }
    void resetBoard()
    {
        board.clear();
        board.resize(size,vector<Symbol>(size,Symbol::EMPTY));
    }
    void printBoard()
    {
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                cout << static_cast<char>(board[i][j]) << " ";
            }
            cout<<endl;
        }
    }
    bool isMoveValid(int row,int col)
    {
        if(row<0||row>=size||col<0||col>=size)
        {
            return false;
        }
        return board[row][col]==Symbol::EMPTY;
    }
    void makeMove(int row,int col,Symbol symbol)
    {
        board[row][col]=symbol;
    }
    bool checkWin(int row,int col,Symbol symbol)
    {
        // Check row
        bool win = true;
        for(int i=0;i<size;i++) {
            if(board[row][i]!=symbol) {
                win = false;
                break;
            }
        }
        if(win) return true;

        // Check column
        win = true;
        for(int i=0;i<size;i++) {
            if(board[i][col]!=symbol) {
                win = false;
                break;
            }
        }
        if(win) return true;

        // Check main diagonal
        if(row==col) { // only check if the move is on diagonal
            win = true;
            for(int i=0;i<size;i++) {
                if(board[i][i]!=symbol) {
                    win = false;
                    break;
                }
            }
            if(win) return true;
        }

        // Check anti-diagonal
        if(row + col == size - 1) {
            win = true;
            for(int i=0;i<size;i++) {
                if(board[i][size-i-1]!=symbol) {
                    win = false;
                    break;
                }
            }
            if(win) return true;
        }

        return false;
    }


};

class Game
{

    private:
    deque<Player>players;
    Board *board;
    string winner;
    int freeCellsAvailable;

    public:
    void setupGame(vector<Player>playerList,int size)
    {
        for(int i=0;i<playerList.size();i++)
        {
            players.push_back(playerList[i]);
        }
        this->board=new Board(size);
        this->freeCellsAvailable=size*size;
        this->winner="";
    }
    string startGame()
    {
        while(winner.empty())
        {
            if(freeCellsAvailable==0)
            {
                winner="Draw";
                break;
            }
            Player currentPlayer=players.front();
            players.pop_front();
            players.push_back(currentPlayer);
            int row,col;
            board->printBoard();
            cout<<endl;
            cout<<"Player: "<<currentPlayer.getName()<<" make your move:\n";
            cin>>row>>col;
            if(board->isMoveValid(row,col))
            {
                board->makeMove(row,col,currentPlayer.getSymbol());
                freeCellsAvailable--;
                if(board->checkWin(row,col,currentPlayer.getSymbol()))
                {
                    winner=currentPlayer.getName();
                    break;
                }
            }
            else
            {
                cout<<"Invalid move! Try again.\n";
            }
        }
        board->printBoard();
        return winner;
    }
};

int main(){
    Game game;
    vector<Player> playerList={Player("Alok",Symbol::X,1),Player("Dhiraj",Symbol::O,2)};
    game.setupGame(playerList,3);
    string winner=game.startGame();
    cout<<"Winner: "<<winner<<endl;
 return 0;   
}