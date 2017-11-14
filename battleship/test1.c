#include<stdio.h>

class pole{
  int my_BORT[10][10];
  int enemy_BORT[10][10];
};

class status_kletki{
  none;    //None
  kill;    //Kill
  error;   //Error
};

void attack(int x, int y){ //function of attack (number of cell)
  x = ; //getchar 
  y = ;

}

TestCellStatus(){         //Testing status of cell 
  if (x > 9 || y > 9) return Error;    //Wrong data 
  if (my_BORT[x][y] == 0) return None; //Cell is empty
  if (){                               //Last ship was destroyed 
    "You are LOST";          
  }return Kill;


}

gameStatus{
  StartNewGame;
  Player1Attack;
  Player2Attack;
  EndOfGame;
};

int main(){
  GameStatus Index = StartNewGame; // Status of game
  
  //Create 2 players
  Player 1;
  Player 2;

  while(Index != EndOfGame){
    switch (Index){
      case StartNewGame{
        Player 1 initialization();
        Player 2 initialization();
        Index = Player1Attack;
      }
      case Player1Attack{
        int x = 0;
        int y = 0;

        Player_Sea_Battle_1.Attack(x, y);
        int result = Player_Sea_Battle2.TestCell(x,y);
        if ((PlayerSeaBattle2.PlayerStatus() , "LAST!!!") == 0){
          Index = EndOfGame;
        }
        if ( result ==  ) Index = Player2Attack; // Промазал
        else Index=Player1Attack; //Попал!

      }
    
  

      case Player2Attack{
        int x = 0;
        int y = 0;

        Player_Sea_Battle_1.Attack(x, y);
        int result = Player_Sea_Battle2.TestCell(x,y);
        if ((PlayerSeaBattle2.PlayerStatus() , "LAST!!!") == 0){
          Index = EndOfGame;
        }
        if ( result ==  ) Index = Player2Attack; // Промазал
        else Index=Player1Attack; //Попал!
      }    
    }
  

  //Draw the BORT
  clear the bort;

  PlayerSeabattle1.DrawBoard();
  PlayerSeaBattle2.DrawBoard():
  }
  return 0;
}
