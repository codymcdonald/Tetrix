/*-----------------------------------------------------------------------------
HEADER FILES
-----------------------------------------------------------------------------*/
#include <cstdlib>
#include <fstream>
#include "formatted_console_io_v20.h"

using namespace std;

/*-----------------------------------------------------------------------------
GLOBAL CONSTANT DEFINITIONS
-----------------------------------------------------------------------------*/
const int CAPACITY = 5000;
const int MAX_STR_LEN = 80;

const int OBJECT_HEIGHT = 2;
const int OBJECT_WIDTH = 3;

const char COLON = ':';
const char COMMA = ',';
const char SPACE = ' ';
const char ENDLINE_CHAR = '\n';

const int EASY = 0;
const int MODERATE = 1;
const int HARD = 2;
const int LUDICROUS = 3;

const int GREEN = 1;
const int YELLOW = 2;
const int RED = 3;
const int CYAN = 4;
const int MAGENTA = 5;

/*-----------------------------------------------------------------------------
FUNCTION PROTOTYPE DEFINITIONS
-----------------------------------------------------------------------------*/

/*
Name: splashScreen
Process: displays the initial title of the game when first starting program
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: Text on Screen
Dependencies: formatted_console_io_v20.h

*/
void splashScreen();

/*
Name: mainMenu
Process: Displays the main menu of the program. It will output any char that the
         user inputs.
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Return: char
Device Input: none
Device Output: Text on screen
Dependencies: formatted_console_io_v20.h

*/
char mainMenu();

/*
Name: responseChecker
Process: Checks to make sure that any of the chars output by mainMenu, are the 
         correct chars the user should be using, if so, then it will output true.
Function Input/Parameters: the userInput(char)
Function Output/Parameters: none
Function Output/Return: true or false
Device Input: none
Device Output: none
Dependencies: none

*/
bool responseChecker( char userInput );

/*
Name: difficultyMenu
Process: displays the difficulty settings menu for user. User enters difficulty
         and it will pass back difficulty with its new variable. The function
         returns true if the user enters a correct char for the difficutly and 
         false if not.
Function Input/Parameters: the game difficulty(int) 
Function Output/Parameters: none
Function Output/Return: true or false
Device Input: none
Device Output: Text on Screen
Dependencies: formatted_console_io_v20.h

*/
bool difficultyMenu( int &difficulty );

/*
Name: timeFactor
Process: takes the difficutly of the game and outputs what the fall speed of the
         blocks will be based on that time.
Function Input/Parameters: the game difficutly(int)
Function Output/Parameters: none
Function Output/Return: the speed at which the blocks fall(int)
Device Input: none
Device Output: none
Dependencies: none

*/
int timeFactor( int difficulty );

/*
Name: playScreenWidth
Process: Takes the difficutly of the game and then outputs what the X cord or what
         the screen limit will be, for the left and right of the playing area of
         the block/cube/player.
Function Input/Parameters: difficutly(int), leftScreenLimit(int), rightScreenLimit(int) 
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: none
Dependencies: none

*/
void playScreenWidth( int difficulty, int &leftScreenLimit, int &rightScreenLimit );

/*
Name: showInstructions
Process: shows the instructions for the game right before you start.
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: Text on Screen
Dependencies: formatted_console_io_v20.h

*/
void showInstructions();

/*
Name: gameDisplay
Process: Displays the outer shell/side bars of the playing area. Depending on the
         difficulty it will change how wide the side bars will be.
Function Input/Parameters: the games difficulty(int)
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: Text on Screen
Dependencies: formatted_console_io_v20.h

*/
void gameDisplay( int difficulty );

/*
Name: randomBetween
Process: returns a randomly generated integer between two values
Function Input/Parameters: low and high values (int)
Function Output/Parameters: none
Function Output/Return: random value(int)
Device Input: none
Device Output: none
Dependencies: none

*/
int randomBetween( int low, int high );

/*
Name: deleteBottomRow
Process: It deletes the two bottom rows from the gameGrid and then moves everything
         else within the 2D array down two rows.
Function Input/Parameters: the gameGrid Array(char) 
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: none
Dependencies: none

*/
void deleteBottomRow( char gameGrid[][SCRN_MAX_X] );

/*
Name: moveBlock
Process: Checks to see if the userInput allows the block to move in the dirrection speficified. 
         If the user can move, then the new X and Y's will update. If the user hits the bottom of the
         playing area, or his block lands on top of another block, the function will output true.
Function Input/Parameters: The userInput(char), the old X & Y and new X & Y(int), the gameGrid(char),
                           and the left and right screen limits(int)
Function Output/Parameters: none
Function Output/Return: true or false
Device Input: none
Device Output: none
Dependencies: none

*/
bool moveBlock( int userInput, int oldX, int oldY, int &newX, int &newY, char gameGrid[][SCRN_MAX_X], int leftScreenLimit, int rightScreenLimit );

/*
Name: showPlayer
Process: Deletes the old cube at the old X & Y position and then prints a new cube
         with the color specified at the new X & Y potition.
Function Input/Parameters: the old X & Y and new X & Y(int), along with the color(int)
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: cube on screen
Dependencies: formatted_console_io_v20.h 

*/
void showPlayer( int oldX, int oldY, int newX, int newY, int color );

/*
Name: scoreLoadingModule
Process: This will display the screen at the end of the playable game asking for 
         the players name. It will place the players name into an array.
Function Input/Parameters: the playerName[](char)
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: Text on Screen
Dependencies: formatted_console_io_v20.h 

*/
void scoreLoadingModule( char playerName[] );

/*
Name: scoreFileUploader
Process: this will take the players name, score, and plays, and place them into a .txt
         if their Win Rate is within the top 10
Function Input/Parameters: playerName[](char), score(int), plays(int)
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: none
Dependencies: fstream

*/
void scoreFileUploader( char playerName[], int score, int plays );

/*
Name: loadScores
Process: This will load the players name, score, and plays from a .txt and store them into their arrays
Function Input/Parameters: playerScoresandPlays array(int), playerName array(char)
Function Output/Parameters: none
Function Output/Return: int playerScoresandPlays[], char playerName[] 
Device Input: none
Device Output: none
Dependencies: fstream

*/
void loadScores( int playerScoresandPlays[], char playerName[] );

/*
Name: displayScoresMenu
Process: This will display the Scores menu with the player names, scores, and plays.
         It will also display the win rate.
Function Input/Parameters:  int playerScoresandPlays[], char playerName[]
Function Output/Parameters: none
Function Output/Return: int playerScoresandPlays[], char playerName[] 
Device Input: none
Device Output: Text on Screen
Dependencies: formatted_console_io_v20.h 

*/
void displayScoresMenu( int playerScoresandPlays[], char playerName[] );

/*
Name: loadSaveGame
Process: loads any previous games saved from a .txt, places the blocks into the array,
         level of difficutly, number of plays, and the score
Function Input/Parameters: char gameGrid[][SCRN_MAX_X], int difficulty, int plays, int score
Function Output/Parameters: none
Function Output/Return: char gameGrid[][SCRN_MAX_X]
Device Input: none
Device Output: none
Dependencies: fstream

*/
void loadSaveGame( char gameGrid[][SCRN_MAX_X], int &difficulty, int &plays, int &score, int leftScreenLimit );

/*
Name: displayScore
Process: displays the score entered on the screen in the bottom right of the gameplay
         screen.
Function Input/Parameters: score(int)
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: Text on screen
Dependencies: formatted_console_io_v20.h 

*/
void displayScore( int score );

/*
Name: displayPlays
Process: Displays the plays entered on the screen in the bottom right of the gameplay
         screen.
Function Input/Parameters: number of plays(int)
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: Text on screen
Dependencies: formatted_console_io_v20.h 

*/
void displayPlays( int plays );

/*
Name: displayGameGrid
Process: displays the squares/blocks on the screen that have fallen to the bottom and
         saved into the array.
Function Input/Parameters: char gameGrid[][SCRN_MAX_X],int leftScreenLimit, int rightScreenLimit
Function Output/Parameters: none
Function Output/Return: char gameGrid[][SCRN_MAX_X]
Device Input: none
Device Output: Text on screen
Dependencies: formatted_console_io_v20.h 

*/
void displayGameGrid( char gameGrid[][SCRN_MAX_X],int leftScreenLimit, int rightScreenLimit );

/*
Name: pressKeyToStart
Process: Displays the message at the bottom of game screen saying press any key to start.
         It will hold at that until a key is pressed.
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: Text on Screen
Dependencies: formatted_console_io_v20.h 

*/
void pressKeyToStart();

/*
Name: loadNewblock
Process: Takes the X & Y cordinates and places a 3 by 2 cube of letters. The letter
         will be the beginning letter for the color the cube is.
Function Input/Parameters: int oldX, int oldY, char gameGrid[][SCRN_MAX_X], int color
Function Output/Parameters: none
Function Output/Return: char gameGrid[][SCRN_MAX_X]
Device Input: none
Device Output: none
Dependencies: none

*/
void loadNewBlock( int oldX, int oldY, char gameGrid[][SCRN_MAX_X], int color );

/*
Name: scoreChecker
Process: takes the X & Y of the block that just landed and checks to see if it
         can line up in a row of 3 or greater vertical or horizontal of the same
         letter in the gameGrid. If it does line up, it changes the blocks to White(w)
         and awards a score based on that.
Function Input/Parameters: int oldX, int oldY, har gameGrid[][SCRN_MAX_X],int &score
Function Output/Parameters: none
Function Output/Return: score(int)
Device Input: none
Device Output: none
Dependencies: none

*/
void scoreChecker( int oldX, int oldY, char gameGrid[][SCRN_MAX_X],int &score );

/*
Name: displayGameEnded
Process: This will display the text that says the user has ended the game with Esc
         and to press any key to continue
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: Text on Screen
Dependencies: formatted_console_io_v20.h 

*/
void displayGameEnded();

/*
Name: displayStackedToTall
Process: Displays message to user when the blocks have been stacked too tall
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: Text to Screen
Dependencies: formatted_console_io_v20.h 

*/
void displayStackedToTall();

/*
Name: saveorContinue
Process: Displays the dialoge asking the user if he wants to continue or save
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: Text on Screen
Dependencies: formatted_console_io_v20.h 

*/
void saveorContinue();

/*
Name: uploadSaveGame
Process: Uploads the saved game to the .txt with the difficutly, score, plays, and 
         positions of the blocks saved in the gameGrid
Function Input/Parameters: int difficulty, int score, int plays, char gameGrid[][SCRN_MAX_X]
Function Output/Parameters: none
Function Output/Return: char gameGrid[][SCRN_MAX_X]
Device Input: none
Device Output: none
Dependencies: fstream

*/
void uploadSaveGame( int difficulty, int score, int plays, char gameGrid[][SCRN_MAX_X] );

/*
Name: clearGameGrid
Process: Clears the gameGrid of all blocks and sets it back to empty
Function Input/Parameters: char gameGrid[][SCRN_MAX_X]
Function Output/Parameters: none
Function Output/Return:char gameGrid[][SCRN_MAX_X]
Device Input: none
Device Output: none
Dependencies: none

*/
void clearGameGrid( char gameGrid[][SCRN_MAX_X] );

/*
Name: endScreen
Process: Prints the end screen for the end of game
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: Text on Screen
Dependencies: formatted_console_io_v20.h 

*/
void endScreen();

/*
Name: printBackground
Process: Prints the background for the game menus
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: Text on Screen
Dependencies: formatted_console_io_v20.h 

*/
void printBackground();

/*
Name: displayBarInstructions
Process: Prints the instructions on the bottom bar
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Return: none
Device Input: none
Device Output: Text on Screen
Dependencies: formatted_console_io_v20.h 

*/
void displayBarInstructions();


/*-----------------------------------------------------------------------------
MAIN PROGRAM
-----------------------------------------------------------------------------*/
int main()
   {
   // Variables
   int difficulty = MODERATE, blockFallSpeed = 2, oldX, oldY, newX, newY, score, plays;
   int leftScreenLimit = 22, rightScreenLimit = 58, color, userInputInt;
   bool correctResponse = false, hitBottom = false, hitTop = false, escapeLoop = false;
   char userInput;
      // Arrays
   int playerScoresandPlays[CAPACITY];
   char gameGrid[SCRN_MAX_Y][SCRN_MAX_X];
   char playerName[CAPACITY];

   // Start Curse
      // startCurses
   startCurses();

   // Display Splash Screen
      // splashScreen
   splashScreen();

   // Begin loop that will end when user decides to end game
      // do while
   do  
      {
      // Begin loop that will display main menu and wait until user inputs correct response
         // do while
      do  // you should not need two do while loops
         {
         // Display main menu for the user and output his response
            // mainMenu
         userInput = mainMenu();

         // check to see if response entered is valid, if so, set correct response to true
            // responseChecker
         correctResponse = responseChecker( userInput );
         }
      while( !correctResponse );

      // Set correctResponse to false
      correctResponse = false;

      // Respond to what the user has input with correct display/action
      // if player has selected set difficulty then display difficulty menu
         // if, else if
      if( (userInput == '1') || (userInput == 'S') || (userInput == 's') )
         {   
         // Begin loop that will display difficultyMenu and wait until user inputs correct response
            // while
         do
            {
               // Display difficulty menu for user to set difficulty, return true if correct response entered
                  // function: difficultyMenu()
               correctResponse = difficultyMenu( difficulty );

               // set blockFallSpeed for the speed of game / how fast the blocks fall
                  // function: timeFactor()
               blockFallSpeed = timeFactor( difficulty );

               // Set the size of the playing field for the game and array
                  // function: playScreenWidth()
               playScreenWidth( difficulty, leftScreenLimit, rightScreenLimit );
            }
         while( !correctResponse );
         }
         // if user has selected play game or continue previous game, begin game.
         else if( (userInput == '2') || (userInput == 'P') || (userInput == 'p') || 
                  (userInput == '3') || (userInput == 'C') || (userInput == 'c') )
            {
            // Display instructions screen 
               // showInstructions
            showInstructions();
               
            // Start game
               // Set the score and number of plays to zero
               score = 0;
               plays = 0;

            // Clear the game grid
               // clearGameGrid()
            clearGameGrid( gameGrid );

               // if user has selected continue previous game, load the previous game
                  // if
               if( (userInput == '3') || (userInput == 'C') || (userInput == 'c') )
                  {
                  // load the previous game
                     // loadSaveGame
                  loadSaveGame( gameGrid, difficulty, plays, score, leftScreenLimit );

                  // set blockFallSpeed for the speed of game / how fast the blocks fall
                     // function: timeFactor()
                  blockFallSpeed = timeFactor( difficulty );

                  // Set the size of the playing field for the game and array
                     // function: playScreenWidth()
                  playScreenWidth( difficulty, leftScreenLimit, rightScreenLimit );
                  }
            
               // Set game display, borders of the playing area.
                  // gameDisplay
               gameDisplay( difficulty );

               // display the players score
                  // function: displayScore()
               displayScore( score );

               // display the amount of plays the players has played
                  // function: displayPlays()
               displayPlays( plays );

               // display the blocks that have already falled and are saved in the gameGrid, blocks will appear if continue previous game is loaded
                  // function: displayGameGrid()
               displayGameGrid( gameGrid, leftScreenLimit, rightScreenLimit );   

               // set the X and Y position for the initial blocks spawn position
                  // function: randomBetween
               newX = oldX = randomBetween( leftScreenLimit, rightScreenLimit - 3 );
               newY = oldY = 0;

               // set the color for the initial block
                  // function: randomBetween
               color = randomBetween( 1, 5 );

               // display message that will inform the player to press any key to begin and then begin
                  // pressKeyToStart()
               pressKeyToStart();
                
               // Begin loop that will loop until player saves the game
                  // do while
               do
                  {
	
                  displayBarInstructions();

                  // begin loop that will end when spacebar is pressed to "pause" game
                     // do while
                  do
                     {
                     //	display the players score
                        // function: displayScore()
                     displayScore( score );

                     // display the amount of plays the players has played
                        // function: displayPlays()
                     displayPlays( plays );
 
                     // Get the user input and set the speed at which the blocks fall
                        // waitForInput
                     userInput = userInputInt = waitForInput( blockFallSpeed );

                     // Check to see if the user entered the letter D to delete bottom row
                        // if
                     if( (userInput == 'D') || (userInput == 'd') )
                        {
	                    // if user did enter D, delete bottom row
                           // function: deleteBottomRow
                        deleteBottomRow( gameGrid );

                        // display the blocks that have already fallen and what they look like after a row is removed
                           // function: displayGameGrid()
                        displayGameGrid( gameGrid, leftScreenLimit, rightScreenLimit );   

                        // Set game display, borders of the playing area.
                           // gameDisplay
                        gameDisplay( difficulty );   
                        }
                  
                     // Use the input specified by the user to move the block, if you can
                        // moveBlock
                     hitBottom = moveBlock( userInputInt, oldX, oldY, newX, newY, gameGrid, leftScreenLimit, rightScreenLimit );

                     // if the player hits the bottom of screen, load it to array and see if any points are won
                        // if
                     if( hitBottom )
                        {
	                    // check to see if when the block hit the bottom, it isnt touching the top also/ stacked too high
                           // if
	                    if( oldY <= 2 )
                           {
	                       hitTop = true;
	                       }
                        // load the block into the array to keep track of it and display on screen
                           // fucntion: loadNewBlock()
                        loadNewBlock( oldX, oldY, gameGrid, color );

                        // check to see if the block that just hit the bottom is capable of scoring points for the player
                           // function: scoreChecker()
                        scoreChecker( oldX, oldY, gameGrid, score );
                     
                        // Randomly change the color for the next cube
                           // funtion: randomBetween()
                        color = randomBetween( 1, 5 );


                        displayBarInstructions();

                        // increase the "plays" by one
                           // ++
                        plays++;

                        // Set hitBottom back to false to begin checking for hitbottom again
                        hitBottom = false;
	                    }

                     // Display the player(block/cube) on the screen
                        // showPlayer
                     showPlayer( oldX, oldY, newX, newY, color );

                     // display the blocks that have already falled and are saved in the gameGrid
                        // function: displayGameGrid()
                     displayGameGrid( gameGrid, leftScreenLimit, rightScreenLimit );         

                     // change the old and new X and Y values
                     oldX = newX;
                     oldY = newY;           
                 
                     }
                  while( (userInput != ' ') && (userInputInt != KB_ESCAPE) && (!hitTop) );

                  // check to see if user pressed space bar, or esc, to stop game
                     // if, else
                  if( userInput == KB_ESCAPE )
                     {
                     // display message saying user has ended game and press any key to continue
                        // displayGameEnded()
                     displayGameEnded();
                     }
                  else if( hitTop )
                     {
	                 // Display message saying user has hit the top of screen/ stacked blocks too high
                        // displayStackedToTall()
                     displayStackedToTall();
	                 }
                  else
                     {
                     // Pause game if user presses space bar and only accept spacebar or S as an answer to either continue or save game
                        // do while
                     do
                        {
                        // Display dialogue that will inform user to press S for save
                           // function: saveorContinue()
                        saveorContinue();
   
   	                    // get users input
                           // waitForInput
	                    userInput = waitForInput( FIXED_WAIT );
                        }
                     while( (userInput != 'S') && (userInput != 's') && (userInput != ' ') );
                     }
                  }
               while( (userInput != 'S') && (userInput != 's') && (userInput != KB_ESCAPE) && (!hitTop) );

            // check to see if user left the game by chosing the save game option
               // if
            if( (userInput == 'S') || (userInput == 's')  )
               {
	           // if user has selected to save game, upload the difficulty, score, plays, and the array to a .txt
                  // uploadSaveGame()
               uploadSaveGame( difficulty, score, plays, gameGrid );
	           }
            // Clear the game grid for the next play session
               // clearGameGrid()
            clearGameGrid( gameGrid );

            // Display score loading module that will take the players name
               // function: scoreLoadingModule()
            scoreLoadingModule( playerName );

            // Upload players name, score, and plays to a .txt
               // function: scoreFileUploader()
            scoreFileUploader( playerName, score, plays );
            }
         // if user has selected display scores, load scores from .txt and display
         else if( (userInput == '4') || (userInput == 'D') || (userInput == 'd') )
            {
	        // Load scores from .txt
               // loadScores
            loadScores( playerScoresandPlays, playerName );

            // Display player Scores
               // displayScores
            displayScoresMenu( playerScoresandPlays, playerName );
            
	        }

      // Set correctResponse back to false and continue loop
         // correctResponse = false
      correctResponse = false;

      if( ( userInput == '5' ) || ( userInput == 'E' ) || ( userInput == 'e' ) )
         {
	     escapeLoop = true;
         }

      }
   while( !escapeLoop );

   // Display end program screen
      // endScreen
   endScreen();

   // End the curses function
      // endCurses()
   endCurses();

   // return zero
   return 0;
   }

/*---------------------------------------------------------------------
FUNCTION IMPLEMENTATIONS
-----------------------------------------------------------------------------*/

void splashScreen()
   {
   // Initialize variables
		int index = 0, startX, startY=0, color;
        int userInput = ERR;
        int newX, newY, oldX, oldY, blockMove = 0, loopPass = 0;
        int rowIndex, colIndex;

   // Clear screen 
   // Set bacground color to blue
      // setColor
		setColor ( COLOR_YELLOW, COLOR_BLUE, SET_BRIGHT ) ;
		clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
   // Print the blocky tetrix title
      // printCharAt, setColor
			printStringAt ( 4, 7,  " TTTTTTTTTT  EEEEEEEE  TTTTTTTTTT  RRRRRR     IIIIII  XX    XX", "LEFT" );
			printStringAt ( 4, 8,  " TTTTTTTTTT  EE        TTTTTTTTTT  RR   RR      II     XX  XX", "LEFT" );
			printStringAt ( 4, 9,  "     TT      EEEEEEE       TT      RR   RR      II       XX", "LEFT" );
			printStringAt ( 4, 10, "     TT      EEEEEEE       TT      RRRRRR       II       XX ","LEFT");
			printStringAt ( 4, 11, "     TT      EE            TT      RR RR        II     XX  XX ","LEFT");
			printStringAt ( 4, 12, "     TT      EEEEEEEE      TT      RR   RR    IIIIII  XX    XX", "LEFT");
   // Print the subtitle
      // printCharAt
			printStringAt ( 33, 17, "Kind of like Tetris", "LEFT" );
			printStringAt ( 35, 19, "by Cody McDonald", "LEFT" );

   // Print falling block

   newX = oldX = randomBetween( 0, 76);
   newY = oldY = 0;

   color = randomBetween( 1, 5);

      // Start infinite loop
		while( userInput == ERR )
		{
        userInput = waitForInput( 1 );

        blockMove = randomBetween(-1,1);

        switch( blockMove )
           {
           case -1 :
	
           if( oldX - 1 > 0 )
              {
              // update x position for left move
              newX = oldX - 1;
              }

           // check for vertical move
           if( oldY + 2 > 20 )
              {
              // set block start position
                 // function: randomBetween
              newX = randomBetween( 0, 76 );
              newY = 0;

              color = randomBetween( 1, 5);

              // Clear screen 
              // Set bacground color to blue
              // setColor
		      setColor ( COLOR_YELLOW, COLOR_BLUE, SET_BRIGHT ) ;
		      clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
              // Print the blocky tetrix title
                 // printCharAt, setColor
			printStringAt ( 4, 7,  " TTTTTTTTTT  EEEEEEEE  TTTTTTTTTT  RRRRRR     IIIIII  XX    XX", "LEFT" );
			printStringAt ( 4, 8,  " TTTTTTTTTT  EE        TTTTTTTTTT  RR   RR      II     XX  XX", "LEFT" );
			printStringAt ( 4, 9,  "     TT      EEEEEEE       TT      RR   RR      II       XX", "LEFT" );
			printStringAt ( 4, 10, "     TT      EEEEEEE       TT      RRRRRR       II       XX ","LEFT");
			printStringAt ( 4, 11, "     TT      EE            TT      RR RR        II     XX  XX ","LEFT");
			printStringAt ( 4, 12, "     TT      EEEEEEEE      TT      RR   RR    IIIIII  XX    XX", "LEFT");
			// Print the subtitle
				// printCharAt
			printStringAt ( 33, 17, "Kind of like Tetris", "LEFT" );
			printStringAt ( 35, 19, "by Cody McDonald", "LEFT" );
              }          

           // otherwise, assume not on bottom of screen
           else
              {
              // update y position for downward move
              newY = oldY + 1;
              }

           break;

           case 1:
	
           if( oldX + 3 < 76 ) 
              {
              // update x position for right move
              newX = oldX + 1;
              }

           // check for vertical move
           if( oldY + 2 > 20 )
              {
              // set block start position
                 // function: randomBetween
              newX = randomBetween( 0, 76 );
              newY = 0;

              color = randomBetween( 1, 5);

              // Clear screen 
              // Set bacground color to blue
              // setColor
		      setColor ( COLOR_YELLOW, COLOR_BLUE, SET_BRIGHT ) ;
		      clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
              // Print the blocky tetrix title
                 // printCharAt, setColor
			printStringAt ( 4, 7,  " TTTTTTTTTT  EEEEEEEE  TTTTTTTTTT  RRRRRR     IIIIII  XX    XX", "LEFT" );
			printStringAt ( 4, 8,  " TTTTTTTTTT  EE        TTTTTTTTTT  RR   RR      II     XX  XX", "LEFT" );
			printStringAt ( 4, 9,  "     TT      EEEEEEE       TT      RR   RR      II       XX", "LEFT" );
			printStringAt ( 4, 10, "     TT      EEEEEEE       TT      RRRRRR       II       XX ","LEFT");
			printStringAt ( 4, 11, "     TT      EE            TT      RR RR        II     XX  XX ","LEFT");
			printStringAt ( 4, 12, "     TT      EEEEEEEE      TT      RR   RR    IIIIII  XX    XX", "LEFT");
			// Print the subtitle 
				// printCharAt
			printStringAt ( 33, 17, "Kind of like Tetris", "LEFT" );
			printStringAt ( 35, 19, "by Cody McDonald", "LEFT" );
              }          

           // otherwise, assume not on bottom of screen
           else
              {
              // update y position for downward move
              newY = oldY + 1;
              }   

           break;

           default:

           // check for vertical move
           if( oldY + 2 > 20 )
              {
              // set block start position
                 // function: randomBetween
              newX = randomBetween( 0, 76 );
              newY = 0;

              color = randomBetween( 1, 5);

              // Clear screen 
              // Set bacground color to blue
              // setColor
		      setColor ( COLOR_YELLOW, COLOR_BLUE, SET_BRIGHT ) ;
		      clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
              // Print the blocky tetrix title
                 // printCharAt, setColor
			printStringAt ( 4, 7,  " TTTTTTTTTT  EEEEEEEE  TTTTTTTTTT  RRRRRR     IIIIII  XX    XX", "LEFT" );
			printStringAt ( 4, 8,  " TTTTTTTTTT  EE        TTTTTTTTTT  RR   RR      II     XX  XX", "LEFT" );
			printStringAt ( 4, 9,  "     TT      EEEEEEE       TT      RR   RR      II       XX", "LEFT" );
			printStringAt ( 4, 10, "     TT      EEEEEEE       TT      RRRRRR       II       XX ","LEFT");
			printStringAt ( 4, 11, "     TT      EE            TT      RR RR        II     XX  XX ","LEFT");
			printStringAt ( 4, 12, "     TT      EEEEEEEE      TT      RR   RR    IIIIII  XX    XX", "LEFT");
			// Print the subtitle 
				// printCharAt
			printStringAt ( 33, 17, "Kind of like Tetris", "LEFT" );
			printStringAt ( 35, 19, "by Cody McDonald", "LEFT" );
              }          

           // otherwise, assume not on bottom of screen
           else
              {
              // update y position for downward move
              newY = oldY + 1;
              }
           }



        // print space over the old object 
   
        // set color for covering old object
           // function: setColor
        setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );

        // iterate across height of object
        for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
           {
           // iterate across the width of the object
           for( colIndex = 0; colIndex < OBJECT_WIDTH; colIndex++ )
              {
              // print block component
                 // function: printCharAt
              printCharAt( oldX + colIndex, oldY + rowIndex, SPACE );
              }
           }

        // print the object

           //Determine what color to change the block to
              // if
           if( color == GREEN )
              {
              // set color for covering old object
                 // function: setColor
              setColor( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );

              // print object
              for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
                 {
                 // iterate across the width of the object
                 for( colIndex = 0; colIndex < OBJECT_WIDTH; colIndex++ )
                    {
                       // print block component
                          // function: printCharAt
                       printCharAt( newX + colIndex, newY + rowIndex, SPACE );
                    }
                 }
              }
           else if( color == YELLOW )
              {
              // set color for covering old object
                 // function: setColor
              setColor( COLOR_WHITE, COLOR_YELLOW, SET_BRIGHT );

              // print object
              for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
                 {
                 // iterate across the width of the object
                 for( colIndex = 0; colIndex < OBJECT_WIDTH; colIndex++ )
                    {

                       // print block component
                          // function: printCharAt
                        printCharAt( newX + colIndex, newY + rowIndex, SPACE );
                    }
                 }
              }
            else if( color == RED )
              {
              // set color for covering old object
                 // function: setColor
              setColor( COLOR_WHITE, COLOR_RED, SET_BRIGHT );

              // print object
              for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
                 {
                 // iterate across the width of the object
                 for( colIndex = 0; colIndex < OBJECT_WIDTH; colIndex++ )
                    {
                       // print block component
                          // function: printCharAt
                       printCharAt( newX + colIndex, newY + rowIndex, SPACE );
                    }
                 }
              }
           else if( color == CYAN )
              {
              // set color for covering old object
                 // function: setColor
              setColor( COLOR_WHITE, COLOR_CYAN, SET_BRIGHT );

              // print object
              for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
                 {
                 // iterate across the width of the object
                 for( colIndex = 0; colIndex < OBJECT_WIDTH; colIndex++ )
                    {
                       // print block component
                         // function: printCharAt
                       printCharAt( newX + colIndex, newY + rowIndex, SPACE );
                    }
                 }
              }
           else if( color == MAGENTA )
              {
              // set color for covering old object
                 // function: setColor
              setColor( COLOR_WHITE, COLOR_MAGENTA, SET_BRIGHT );

              // print object
              for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
                 {
                 // iterate across the width of the object
                 for( colIndex = 0; colIndex < OBJECT_WIDTH; colIndex++ )
                    {
                       // print block component
                          // function: printCharAt
                       printCharAt( newX + colIndex, newY + rowIndex, SPACE );
                    }
                 }
              }       

        oldX = newX;
        oldY = newY;
		}
   }

char mainMenu()
   {
   // Initialize Varaibles
   
   int xPos = 22 , yPos = 3; 
   char userInput; 
   
    // Display background textile
        // Print blocks( spaces, approx 2x2? ) with corresponding pattern
            // function : setColor  ,clearScreen( note: may use brute force for setting blocks or looping )
                printBackground();                                                 
            
    // Display main menu
        // Clear appropriate screen size
			setColor ( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
			clearScreen ( SCRN_MIN_X +19, SCRN_MIN_Y +2, SCRN_MAX_X -19, SCRN_MAX_Y -3 );
        // Print Title with underline 
            //function: printStringAt
            printStringAt(xPos+11 , yPos  , "TETRIX" , "LEFT");
            yPos++; 
            printStringAt(xPos+11 , yPos  , "======" , "LEFT");
			yPos+=2;
        // Print option 1
            //function:  printStringAt
             printStringAt(xPos , yPos  , "1. <S>et Difficulty" , "LEFT");
             yPos+=2; 
        // Print option 2
            //function : printStringAt
             printStringAt(xPos , yPos  , "2. <P>lay Game" , "LEFT");
             yPos+=2; 
        // Print option 3
            //function : printStringAt
             printStringAt(xPos , yPos  , "3. <C>ontinue Previous Game" , "LEFT");
             yPos+=2; 
        // Print option 4
            //function: printStringAt
             printStringAt(xPos , yPos  , "4. <D>isplay Scores" , "LEFT");
             yPos+=2; 
        // Print option 5
            //function: printStringAt
             printStringAt(xPos , yPos  , "5. <E>nd TETRIX" , "LEFT");
             yPos+=3; 
    
        // Print the enter selection 
            //function: printStringAt
         printStringAt( xPos, yPos, "Enter selection:" , "LEFT"); 

    // Receive user selection
        // function: waitForInput 
          userInput = waitForInput(-1);
    // Return userInput

   return userInput; // Temp Stub Return
   }

bool responseChecker( char userInput )
   {
    // Initialize 
   
   // check to see if user input is a correct response
      // if
   if( (userInput == '1' ) || (userInput == 'S' ) || (userInput == 's' ) || 
       (userInput == '2' ) || (userInput == 'P' ) || (userInput == 'p' ) || 
       (userInput == '3' ) || (userInput == 'C' ) || (userInput == 'c' ) || 
       (userInput == '4' ) || (userInput == 'D' ) || (userInput == 'd' ) || 
       (userInput == '5' ) || (userInput == 'E' ) || (userInput == 'e' ) )
      {
      return true;
      }
   else
      {
      return false;
      }
   }

bool difficultyMenu( int &difficulty )
   {
    	// initialize
		char userInput;
		bool inputCheck;
    
    // display menu for user
		printBackground();
		setColor ( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT ) ;
		clearScreen( SCRN_MIN_X + 17, SCRN_MIN_Y +4, SCRN_MAX_X -17, SCRN_MAX_Y -4 );
        // Print title with underline
            // printStringAt
				printStringAt (  SCRN_MIN_X + 26, SCRN_MIN_Y +5, "Difficulty Setting Module", "LEFT" );
				printStringAt (  SCRN_MIN_X + 26, SCRN_MIN_Y +6, "=========================", "LEFT" );
        // print difficulty 1
            // printStringAt
					printStringAt (  SCRN_MIN_X + 23, SCRN_MIN_Y +8, "1. Difficulty <E>asy", "LEFT" );
        // print difficulty 2
            // printStringAt
					printStringAt (  SCRN_MIN_X + 23, SCRN_MIN_Y +10, "2. Difficulty <M>oderate", "LEFT" );
        // print difficulty 3
            // printStringAt
					printStringAt (  SCRN_MIN_X + 23, SCRN_MIN_Y +12, "3. Difficulty <H>ard", "LEFT" );
        // print difficulty 4
            // printStringAt
					printStringAt (  SCRN_MIN_X + 23, SCRN_MIN_Y +14, "4. Difficulty <L>udicrous", "LEFT" );
    // print the enter selection
        // printStringAt
            printStringAt (  SCRN_MIN_X + 23, SCRN_MIN_Y +17, "Enter Selection:", "LEFT" );
    // retrieve choice from user
        // waitForInput
			userInput =	waitForInput(-1);
	// assign difficulty

			 if ( (userInput == '2') || (userInput == 'M') || (userInput || 'm') )
				{
				difficulty = MODERATE;
				}
			 if ( (userInput == '2') || (userInput == 'M') || (userInput || 'm') )
				{
				difficulty = MODERATE;
				}
			 if ( (userInput == '3') || (userInput == 'H') || (userInput == 'h') )
				{
				difficulty = HARD;
				}
			 if ( (userInput == '4') || (userInput== 'L') || (userInput == 'l') )
				{
				difficulty = LUDICROUS;
				}
			 if ( (userInput == '1') || (userInput == 'E') || (userInput == 'e') )
        		{
				difficulty = EASY;
				}
    // check for correct input
        // if 1-4, bool variable is true
		 	if ( (userInput == '1') || (userInput == 'E') || (userInput == 'e') || (userInput == '2') || (userInput == 'M') || (userInput == 'm') || (userInput == '3') || (userInput == 'H') || (userInput == 'h') || (userInput == '4') || (userInput == 'L') || (userInput == 'l') )
        		{
				inputCheck = true;
				}
		// esle, bool variable is false
			else 
				{
				inputCheck = false;
				}
    // return bool


   return inputCheck; // Temp Stub Return
   }

int timeFactor( int difficulty )
   {
    // initialize
		int fallSpeed;
    // assign fallspeed to appropriate difficulty
        // if easy, fall speed is low
			if ( difficulty == EASY )
				{
				fallSpeed = 4;
				}
        // else if medium, fall speed is medium
			else if ( difficulty == MODERATE )
				{
				fallSpeed = 3;
				}
        // else if hard, fall speed is fast
			else if ( difficulty == HARD )
				{
				fallSpeed = 2;
				}
        // else if ludicrous, fall speed is insane
			else if ( difficulty == LUDICROUS )
				{
				fallSpeed = 1;
				}
    // return fall speed
	return fallSpeed;
   }

void playScreenWidth( int difficulty, int &leftScreenLimit, int &rightScreenLimit )
   {
   // if easy
   if( difficulty == EASY)
      {
      // set to 72 chars wide
      leftScreenLimit = 4;
      rightScreenLimit = 76;
      }
   // else if moderate
   else if( difficulty == MODERATE )
      {
      // clearScreen to 36 chars wide
      leftScreenLimit = 22;
      rightScreenLimit = 58;
      }
   // else if hard
   else if( difficulty == HARD )
      {
      // clearScreen to 18 chars wide
      leftScreenLimit = 31;
      rightScreenLimit = 49;
      }
   // else if ludicrous
   else if( difficulty == LUDICROUS )
      {
      // clearScreen to 9 chars wide
      leftScreenLimit = 35;
      rightScreenLimit = 44;
      }
   }

void showInstructions()
   {
     // Initialize functions , variables 
     int xPox , yPos ; 	   

    // Clear screen for proper instruction dimensions
    //   function: clearScreen , setColor 
       printBackground();
       setColor(COLOR_BLUE , COLOR_WHITE , SET_BRIGHT); 
       clearScreen( SCRN_MIN_X +10 , SCRN_MIN_Y +4 , SCRN_MAX_X -10, SCRN_MAX_Y -5);  
        

    // Print the insctructions
        // printStringAt, setColor
	xPox = SCRN_MIN_X +10;
    yPos = SCRN_MIN_Y +5; 

	printStringAt(xPox+20 , yPos , "Instruction Module"  , "LEFT");
        yPos ++; 

	printStringAt(xPox+20 , yPos , "=================="  , "LEFT");
        yPos += 2; 

	printStringAt(xPox+13 , yPos , "Try to get three colors in a row"  , "LEFT");
        yPos += 2; 
	
	printStringAt(xPox+15 , yPos , "Vertically or Horizontally"  , "LEFT");
        yPos += 2; 

	printStringAt(xPox+4 , yPos , "Use left and right arrows to guide the falling blocks"  , "LEFT");
        yPos += 2; 
		
	printStringAt(xPox+9 , yPos , "Use <D> to remove the bottom row of blocks"  , "LEFT");
        yPos += 3; 
	
	printStringAt(xPox+18 , yPos , "Press Any Key to Continue"  , "LEFT");
    
	waitForInput (-1);    
   }

void gameDisplay( int difficulty )
   {
	// initialize
		int index = 0, yIncrease = 0, xIncrease = 0;
    // Clear screen to gray background ( playScreenWidth will have to be called after this function)
       clearScreen ( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
		 // if difficulty is easy
			if ( difficulty == EASY )
				{
            // clear screen to remainders of 72
				setColor ( COLOR_BLUE, COLOR_BLACK, SET_BRIGHT );
				clearScreen ( SCRN_MIN_X+4, SCRN_MIN_Y, SCRN_MAX_X-4, SCRN_MAX_Y- 4);
            // print side bar display
				setColor ( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
                // printStringAt
					while ( xIncrease < 2 )
					{
					index = 0;
					yIncrease = 0;
					while ( index < SCRN_MAX_Y-3 )
						{
						printCharAt (SCRN_MIN_X+xIncrease, SCRN_MIN_Y + yIncrease, '+' );
						index++;
						yIncrease++;
						}
					xIncrease+=2;
					}
					xIncrease = 0;
					while ( xIncrease < 2 )
						{
						index = 0;
						yIncrease = 0;
						while ( index < SCRN_MAX_Y-3 )
							{
							printCharAt (SCRN_MIN_X+59+xIncrease, SCRN_MIN_Y + yIncrease, '+' );
							index++;
							yIncrease++;
							}
						xIncrease+=2;
						}
				printStringAt( SCRN_MIN_X, SCRN_MAX_Y-3, "===|========================================================================|===", "LEFT");
				
				}
        // if difficulty is moderate
			else if ( difficulty == MODERATE )
				{
            // clear screen to remainders of 36
				setColor ( COLOR_BLUE, COLOR_BLACK, SET_BRIGHT );
				clearScreen ( SCRN_MIN_X+22, SCRN_MIN_Y, SCRN_MAX_X-22, SCRN_MAX_Y- 4);
            // print side bar display
                setColor ( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
				// printStringAt
				while ( xIncrease < 22 )
					{
					index = 0;
					yIncrease = 0;
					while ( index < SCRN_MAX_Y-3 )
						{
						printCharAt (SCRN_MIN_X+xIncrease, SCRN_MIN_Y + yIncrease, '+' );
						index++;
						yIncrease++;
						}
					xIncrease+=2;
					}
					xIncrease = 0;
				while ( xIncrease < 22 )
					{
					index = 0;
					yIncrease = 0;
					while ( index < SCRN_MAX_Y-3 )
						{
						printCharAt (SCRN_MIN_X+59+xIncrease, SCRN_MIN_Y + yIncrease, '+' );
						index++;
						yIncrease++;
						}
					xIncrease+=2;
					}
				printStringAt( SCRN_MIN_X+4, SCRN_MAX_Y-14,"               " ,"LEFT");
				printStringAt( SCRN_MIN_X+3, SCRN_MAX_Y-15," This is TETRIX " ,"LEFT");
				printStringAt( SCRN_MIN_X+4, SCRN_MAX_Y-16,"               " ,"LEFT");
				printStringAt( SCRN_MAX_X-18, SCRN_MAX_Y-16,"                     " ,"LEFT");
				printStringAt( SCRN_MAX_X-18, SCRN_MAX_Y-15," This is TETRIX " ,"LEFT");
				printStringAt( SCRN_MAX_X-18, SCRN_MAX_Y-14,"                    " ,"LEFT");
				printStringAt( SCRN_MIN_X, SCRN_MAX_Y-3, "=====================|====================================|=====================", "LEFT");
				}
        // else if difficulty is hard
			else if ( difficulty == HARD )
				{
            // clear screen to remainders of 18
				setColor ( COLOR_BLUE, COLOR_BLACK, SET_BRIGHT );
				clearScreen ( SCRN_MIN_X+31, SCRN_MIN_Y, SCRN_MAX_X-31, SCRN_MAX_Y- 4);
            // print side bar display
               setColor ( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
				// printStringAt
				while ( xIncrease < 31 )
					{
					index = 0;
					yIncrease = 0;
					while ( index < SCRN_MAX_Y-3 )
						{
						printCharAt (SCRN_MIN_X+xIncrease, SCRN_MIN_Y + yIncrease, '+' );
						index++;
						yIncrease++;
						}
					xIncrease+=2;
					}
					xIncrease = 0;
				while ( xIncrease < 31 )
					{
					index = 0;
					yIncrease = 0;
					while ( index < SCRN_MAX_Y-3 )
						{
						printCharAt (SCRN_MIN_X+49+xIncrease, SCRN_MIN_Y + yIncrease, '+' );
						index++;
						yIncrease++;
						}
					xIncrease+=2;
					}
				printStringAt( SCRN_MIN_X+6, SCRN_MAX_Y-14,"                    " ,"LEFT");
				printStringAt( SCRN_MIN_X+6, SCRN_MAX_Y-15," Playing Hard? " ,"LEFT");
				printStringAt( SCRN_MIN_X+6, SCRN_MAX_Y-16,"                    " ,"LEFT");
				printStringAt( SCRN_MAX_X-28, SCRN_MAX_Y-16,"                            " ,"LEFT");
				printStringAt( SCRN_MAX_X-26, SCRN_MAX_Y-15," Might want to slow down " ,"LEFT");
				printStringAt( SCRN_MAX_X-28, SCRN_MAX_Y-14,"                            " ,"LEFT");
				printStringAt( SCRN_MIN_X, SCRN_MAX_Y-3, "==============================|==================|==============================", "LEFT");
				}
        // else if difficulty is ludicrous
			else if ( difficulty == LUDICROUS )
				{
            // clear screen to remainders of 9
				setColor ( COLOR_BLUE, COLOR_BLACK, SET_BRIGHT );
				clearScreen ( SCRN_MIN_X+35, SCRN_MIN_Y, SCRN_MAX_X-35, SCRN_MAX_Y- 4);
            // print side bar display
               setColor ( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
                // printStringAt
				while ( xIncrease < 35 )
					{
					index = 0;
					yIncrease = 0;
					while ( index < SCRN_MAX_Y-3 )
						{
						printCharAt (SCRN_MIN_X+xIncrease, SCRN_MIN_Y + yIncrease, '+' );
						index++;
						yIncrease++;
						}
					xIncrease+=2;
					}
					xIncrease = 0;
				while ( xIncrease < 35 )
					{
					index = 0;
					yIncrease = 0;
					while ( index < SCRN_MAX_Y-3 )
						{
						printCharAt (SCRN_MIN_X+45+xIncrease, SCRN_MIN_Y + yIncrease, '+' );
						index++;
						yIncrease++;
						}
					xIncrease+=2;
					}
				printStringAt( SCRN_MIN_X+6, SCRN_MAX_Y-14,"                    " ,"LEFT");
				printStringAt( SCRN_MIN_X+6, SCRN_MAX_Y-15," This is LUDICROUS! " ,"LEFT");
				printStringAt( SCRN_MIN_X+6, SCRN_MAX_Y-16,"                    " ,"LEFT");
				printStringAt( SCRN_MAX_X-30, SCRN_MAX_Y-16,"                            " ,"LEFT");
				printStringAt( SCRN_MAX_X-30, SCRN_MAX_Y-15," Should have thought twice! " ,"LEFT");
				printStringAt( SCRN_MAX_X-30, SCRN_MAX_Y-14,"                            " ,"LEFT");
				printStringAt( SCRN_MIN_X, SCRN_MAX_Y-3, "==================================|=========|===================================", "LEFT");
				}
    // print bottom bar display
        // print the game pause instructions
            // printStringAt
			setColor( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
			
        // print score
            // printStringAt
				printStringAt( SCRN_MAX_X -17, SCRN_MAX_Y -2, "Score:", "LEFT");
        // print plays
            // printStringAt
				printStringAt( SCRN_MAX_X -17, SCRN_MAX_Y -1, "Plays:", "LEFT");
        // print Difficulty
            // if  difficulty = easy
			if ( difficulty == EASY )
				{
                // printStringAt
				printStringAt( SCRN_MAX_X -22, SCRN_MAX_Y, "Difficulty: Easy", "LEFT");
          		}
			  // else if  difficulty = moderate
			else if ( difficulty == MODERATE )	
				{
                // printStringAt
				printStringAt( SCRN_MAX_X -22, SCRN_MAX_Y, "Difficulty: Moderate", "LEFT");
           		}
			 // else if  difficulty = hard
			else if ( difficulty == HARD )
				{
                // printStringAt
				printStringAt( SCRN_MAX_X -22, SCRN_MAX_Y, "Difficulty: Hard", "LEFT");
           		}
			 // else if  difficulty = ludicrous
			else if ( difficulty == LUDICROUS )
				{
                // printStringAt
				printStringAt( SCRN_MAX_X -22, SCRN_MAX_Y, "Difficulty: Ludicrous", "LEFT");
   				}
   }

int randomBetween( int low, int high )
   {
    // initialize function/variables

       // set range
       int range = high - low + 1;

    // return random value within range
    return rand() % range + low;
   }

void deleteBottomRow( char gameGrid[][SCRN_MAX_X] )
   {
   // Variables
   int colIndex, rowIndex;

   // loop through the array starting at the max row and moving down
      // for
   for( rowIndex = 20; rowIndex > 1 ; rowIndex-- )
      {
      // loop through the columns incrementing it
         // for
      for( colIndex = 0; colIndex < SCRN_MAX_X - 1 ; colIndex++ )
         {
         // Copy what is in the row 2 below the current row
         gameGrid[rowIndex][colIndex] = gameGrid[rowIndex - 2][colIndex];
         }
      }
   // clear the "top" of the game grid
   for( rowIndex = 1; rowIndex >= 0 ; rowIndex--)
      {
      for( colIndex = 0; colIndex < SCRN_MAX_Y - 1 ; colIndex++ )
         {
	     // Replace with "E" for empty
	     gameGrid[rowIndex][colIndex] = 'E';
         }
      }
   }

bool moveBlock( int userInput, int oldX, int oldY, int &newX, int &newY, char gameGrid[][SCRN_MAX_X], int leftScreenLimit, int rightScreenLimit )
   {
   // Variables

   // if user input, set direction, otherwise ignore
   switch( userInput )
      {
      // right arrow case
      case KB_RIGHT_ARROW:
    
      // check for move
      if( (oldX + 3 < rightScreenLimit) && (gameGrid[oldY][oldX + 3] == 'E') && 
          (gameGrid[oldY + 1][oldX + 3] == 'E') &&
          (gameGrid[oldY + 2][oldX + 3] == 'E') )
         {
         // update x position for right move
         newX = oldX + 1;
         }          

      return false;

      // end case
      break;

      // left arrow case
      case KB_LEFT_ARROW:

      // check for move
      if( (oldX - 1 >= leftScreenLimit) && (gameGrid[oldY][oldX - 1] == 'E') && 
          (gameGrid[oldY + 1][oldX - 1] == 'E') &&
          (gameGrid[oldY + 2][oldX - 1] == 'E') )
         {
         // update x position for left move
         newX = oldX - 1;
         }
 
      return false;

      // end case
      break;

      // default case
      default:

      // check for vertical move
      if( (oldY + 2 > 20) || (gameGrid[oldY + 2][oldX] != 'E') || 
          (gameGrid[oldY + 2][oldX + 1] != 'E') ||
          (gameGrid[oldY + 2][oldX + 2] != 'E') )
         {
         // set block start position
            // function: randomBetween
         newX = randomBetween( leftScreenLimit, rightScreenLimit - 3 );
         newY = 0;
         return true;
         }          

      // otherwise, assume not on bottom of screen
      else
         {
         // update y position for downward move
         newY = oldY + 1;
         }
      
      return false;      

      // end case/default
      break;
      }
   }

void showPlayer( int oldX, int oldY, int newX, int newY, int color )
   {
   // initialize function / variables
   int rowIndex, colIndex;

   // print space over the old object 
   
      // set color for covering old object
         // function: setColor
      setColor( COLOR_WHITE, COLOR_BLACK, SET_BRIGHT );

      // iterate across height of object
      for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
         {
         // iterate across the width of the object
         for( colIndex = 0; colIndex < OBJECT_WIDTH; colIndex++ )
            {
            // print block component
               // function: printCharAt
            printCharAt( oldX + colIndex, oldY + rowIndex, SPACE );
            }
         }

   // print the object

      //Determine what color to change the block to
         // if
      if( color == GREEN )
         {
         // set color for covering old object
            // function: setColor
         setColor( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );

         // print object
         for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
            {
            // iterate across the width of the object
            for( colIndex = 0; colIndex < OBJECT_WIDTH; colIndex++ )
               {
               if( (colIndex == 1) && (rowIndex == 0))
                  {
                  printCharAt( newX + colIndex, newY + rowIndex, 'G' );	
	              }
               else
                  {
                  // print block component
                     // function: printCharAt
                  printCharAt( newX + colIndex, newY + rowIndex, SPACE );
                  }
               }
            }
         }
      else if( color == YELLOW )
         {
         // set color for covering old object
            // function: setColor
         setColor( COLOR_WHITE, COLOR_YELLOW, SET_BRIGHT );

         // print object
         for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
            {
            // iterate across the width of the object
            for( colIndex = 0; colIndex < OBJECT_WIDTH; colIndex++ )
               {
               if( (colIndex == 1) && (rowIndex == 0))
                  {
                  printCharAt( newX + colIndex, newY + rowIndex, 'Y' );	
	              }
               else
                  {
                  // print block component
                     // function: printCharAt
                  printCharAt( newX + colIndex, newY + rowIndex, SPACE );
                  }
               }
            }
         }
      else if( color == RED )
         {
         // set color for covering old object
            // function: setColor
         setColor( COLOR_WHITE, COLOR_RED, SET_BRIGHT );

         // print object
         for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
            {
            // iterate across the width of the object
            for( colIndex = 0; colIndex < OBJECT_WIDTH; colIndex++ )
               {
               if( (colIndex == 1) && (rowIndex == 0))
                  {
                  printCharAt( newX + colIndex, newY + rowIndex, 'R' );	
	              }
               else
                  {
                  // print block component
                     // function: printCharAt
                  printCharAt( newX + colIndex, newY + rowIndex, SPACE );
                  }
               }
            }
         }
      else if( color == CYAN )
         {
         // set color for covering old object
            // function: setColor
         setColor( COLOR_WHITE, COLOR_CYAN, SET_BRIGHT );

         // print object
         for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
            {
            // iterate across the width of the object
            for( colIndex = 0; colIndex < OBJECT_WIDTH; colIndex++ )
               {
               if( (colIndex == 1) && (rowIndex == 0))
                  {
                  printCharAt( newX + colIndex, newY + rowIndex, 'C' );	
	              }
               else
                  {
                  // print block component
                     // function: printCharAt
                  printCharAt( newX + colIndex, newY + rowIndex, SPACE );
                  }
               }
            }
         }
      else if( color == MAGENTA )
         {
         // set color for covering old object
            // function: setColor
         setColor( COLOR_WHITE, COLOR_MAGENTA, SET_BRIGHT );

         // print object
         for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
            {
            // iterate across the width of the object
            for( colIndex = 0; colIndex < OBJECT_WIDTH; colIndex++ )
               {
               if( (colIndex == 1) && (rowIndex == 0))
                  {
                  printCharAt( newX + colIndex, newY + rowIndex, 'M' );	
	              }
               else
                  {
                  // print block component
                     // function: printCharAt
                  printCharAt( newX + colIndex, newY + rowIndex, SPACE );
                  }
               }
            }
         }       
   }

void scoreLoadingModule( char playerName[] )
   {
    // Initialize functions , variables 
     int xPox , yPos, index = 0, rowIndex=0, columnIndex=0;


   printBackground();

    // Clear screen for proper instruction dimensions
    //   function: clearScreen , setColor 
       //printBackground();
       setColor(COLOR_BLUE , COLOR_WHITE , SET_BRIGHT); 
       clearScreen( SCRN_MIN_X +10 , SCRN_MIN_Y +6 , SCRN_MAX_X -10, SCRN_MAX_Y -7);  
        

    // Print the insctructions
        // printStringAt, setColor
	xPox = SCRN_MIN_X +10;
    yPos = SCRN_MIN_Y +7; 

	printStringAt(xPox+13 , yPos , "Loading Module"  , "LEFT");
        yPos ++; 

	printStringAt(xPox+13 , yPos , "=============================="  , "LEFT");
        yPos += 2; 

	printStringAt(xPox+9 , yPos , "If your score per plays rate is high enough,"  , "LEFT");
        yPos += 2; 
	
	printStringAt(xPox+6 , yPos , "your name and data will be added to the score list"  , "LEFT");
        yPos += 2; 

	promptForStringAt ( xPox+12, yPos, "Enter your name: ", playerName );
   
   }

void scoreFileUploader( char playerName[], int score, int plays )
   {
   // variables
   double currentWinRate, otherWinRates;

   currentWinRate = score/plays;
   
   //open file

   // check to see if win rate is higher then currently achieved one


   }

void loadScores( int playerScoresandPlays[], char playerName[] )
   {
	// initialize
		ifstream inFile;
		int scores, plays, index = 0, index2 = 0;
		char dummy;
	// open 
		inFile.clear();
		inFile.open("scorefile.txt");
	// input file read into array
		while (inFile.good())
			{
			inFile >> scores >> dummy >> plays >> dummy >> playerName[index];
			
			playerScoresandPlays[index2] = plays;
			playerScoresandPlays[index2+1] = scores;

			index2 +=2;
			index ++;
			}	
   }

void displayScoresMenu( int playerScoresandPlays[], char playerName[] )
   {
	// initialize
		ifstream inFile;
		int scores, plays, index = 0, index2 = 0, yIncrease = 0;
		char dummy;
        char fileName[ 80 ] = "scorefile.txt";
   // display menu for user
		setColor ( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
		clearScreen ( SCRN_MIN_X +12, SCRN_MIN_Y +1, SCRN_MAX_X -12, SCRN_MAX_Y -3 );
        // Print title with underline
            // printStringAt
				printStringAt ( SCRN_MIN_X +24, SCRN_MIN_Y +2, "Score Display Module", "LEFT" );
				printStringAt ( SCRN_MIN_X +24, SCRN_MIN_Y +3, "====================", "LEFT" );
        // print  sub Titles
            // printStringAt
				printStringAt ( SCRN_MIN_X +17, SCRN_MIN_Y +6, "Name               Score    Plays      Win Rate", "LEFT" );
				printStringAt ( SCRN_MIN_X +15, SCRN_MIN_Y +7, "========            =======  =======    ==========", "LEFT" );
    // go through arrays and print them to the screen
		// if no scores print no scores message
			if ( !inFile.good() )
				{
				printStringAt(  SCRN_MIN_X +24, SCRN_MIN_Y +12, "No Player Names Or Scores Found", "LEFT" );
				}
		// print scores
			else
				{
				for ( index =0, index2=0; index < 10 ; index++, index2+=2 )
				
					{
					printIntAt ( SCRN_MIN_X +38, SCRN_MIN_Y +8 +yIncrease, playerScoresandPlays[index2] ,"LEFT");
					printIntAt ( SCRN_MIN_X +47, SCRN_MIN_Y +8 +yIncrease, playerScoresandPlays[index2+1], "LEFT");
					printCharAt ( SCRN_MIN_X +15, SCRN_MIN_Y +8 +yIncrease, playerName[index] );
					
		// divide plays by score for win rate
		      // printIntAt
					printDoubleAt ( SCRN_MIN_X +58, SCRN_MIN_Y +8 +yIncrease, (playerScoresandPlays[index2]/playerScoresandPlays[index2+1])*100 , 2 , "LEFT");
					yIncrease++;
					}
				}
   
	waitForInput( -1 );

   }

void loadSaveGame( char gameGrid[][SCRN_MAX_X], int &difficulty, int &plays, int &score, int leftScreenLimit )
   {
   // initialize
   int rowIndex, colIndex, index;
   ifstream fin;
   char fileName[ MAX_STR_LEN ] = "prevgame.txt";
   char dummyChar[ MAX_STR_LEN ];
   char saveGameRow[ MAX_STR_LEN ];

   // open file
      // fin.clear, fin.open
   fin.clear();
   fin.open( fileName );

   // check for good file
   if( fin.good() )
      {
      // load the difficutly
      fin.getline( dummyChar, MAX_STR_LEN, COLON ); 
      fin >> difficulty;

      // load the score
      fin.getline( dummyChar, MAX_STR_LEN, COLON ); 
      fin >> score;

      // load plays
      fin.getline( dummyChar, MAX_STR_LEN, COLON ); 
      fin >> plays;

      // load the gameGrid/Playing area
       while( fin.good() )
         {
	     // sort through the characters to get the row
         fin.getline( dummyChar, MAX_STR_LEN, COLON ); 
         fin >> rowIndex;

         // pass over the comma
         fin.getline( dummyChar, MAX_STR_LEN, COMMA ); 

         // get the row of characters representing saved data and place into array
         fin.getline( saveGameRow, MAX_STR_LEN, ENDLINE_CHAR );  

         // set that arrays index to zero
         index = 0;

         // begin loop to place the arrays data into the 2D gameGrid array
            // for
         for( colIndex = leftScreenLimit ; colIndex < SCRN_MAX_X - 1; colIndex++ )
            {

            gameGrid[rowIndex][colIndex] = saveGameRow[index];

            index++;      
	        }
         }
      }
   }
	
void displayScore( int score )
   {
   // Set the color for the plays number
      // function: setColor
   setColor( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );	

    // print plays next to plays: on bottom bar
        // printIntAt
   printIntAt( 76, 22, score, "LEFT" );
    }
void displayPlays( int plays )
   {
   // Set the color for the plays number
      // function: setColor
   setColor( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );	

    // print plays next to plays: on bottom bar
        // printIntAt
   printIntAt( 76, 23, plays, "LEFT" );

   }

void displayGameGrid( char gameGrid[][SCRN_MAX_X],int leftScreenLimit, int rightScreenLimit )
   {
   // Variables
   int rowIndex, colIndex, blockRowIndex, blockColIndex;

   // loop through the rows starting at 1
      // for
   for( rowIndex = 1; rowIndex < 20; rowIndex = rowIndex + 2)
      {
	  // loop through the columns starting at the leftScreenLimit
         // for
	  for( colIndex = leftScreenLimit; colIndex < rightScreenLimit; colIndex++)
         {
         // if the letter is not the letter E print a "cube" of that color
            // if
         if( gameGrid[rowIndex][colIndex] != 'E' )
            {
            // determine cubes color and print it
               //if, else if
            if( gameGrid[rowIndex][colIndex] == 'C' )
               {
	           // set the color
               setColor( COLOR_WHITE, COLOR_CYAN, SET_BRIGHT );

               // print block
               for( blockRowIndex = 0; blockRowIndex < OBJECT_HEIGHT; blockRowIndex++ )
                  {
                  for( blockColIndex = 0; blockColIndex < OBJECT_WIDTH; blockColIndex++ )
                     {
	
                     if( (blockColIndex == 1) && (blockRowIndex == 0))
                        {
                        printCharAt( colIndex + blockColIndex, rowIndex + blockRowIndex, 'C' );	
	                    }
                     else
                        {
                        printCharAt( colIndex + blockColIndex, rowIndex + blockRowIndex, SPACE );
                        }
                     }
                  }

               // add 3 to the colIndex to make it skip the block it just printed
               colIndex = colIndex + 2;               

	           }
            else if( gameGrid[rowIndex][colIndex] == 'R' )
               {
	           // set the color
               setColor( COLOR_WHITE, COLOR_RED, SET_BRIGHT );

               // print block
               for( blockRowIndex = 0; blockRowIndex < OBJECT_HEIGHT; blockRowIndex++ )
                  {
                  for( blockColIndex = 0; blockColIndex < OBJECT_WIDTH; blockColIndex++ )
                     {
	
                     if( (blockColIndex == 1) && (blockRowIndex == 0))
                        {
                        printCharAt( colIndex + blockColIndex, rowIndex + blockRowIndex, 'R' );	
	                    }
                     else
                        {
                        printCharAt( colIndex + blockColIndex, rowIndex + blockRowIndex, SPACE );
                        }
                     }
                  }

               // add 3 to the colIndex to make it skip the block it just printed
               colIndex = colIndex + 2; 

	           }
            else if( gameGrid[rowIndex][colIndex] == 'Y' )
               {
	           // set the color
               setColor( COLOR_WHITE, COLOR_YELLOW, SET_BRIGHT );

               // print block
               for( blockRowIndex = 0; blockRowIndex < OBJECT_HEIGHT; blockRowIndex++ )
                  {
                  for( blockColIndex = 0; blockColIndex < OBJECT_WIDTH; blockColIndex++ )
                     {
	
                     if( (blockColIndex == 1) && (blockRowIndex == 0))
                        {
                        printCharAt( colIndex + blockColIndex, rowIndex + blockRowIndex, 'Y' );	
	                    }
                     else
                        {
                        printCharAt( colIndex + blockColIndex, rowIndex + blockRowIndex, SPACE );
                        }
                     }
                  }

               // add 3 to the colIndex to make it skip the block it just printed
               colIndex = colIndex + 2; 

               }
            else if( gameGrid[rowIndex][colIndex] == 'M' )
               {
	           // set the color
               setColor( COLOR_WHITE, COLOR_MAGENTA, SET_BRIGHT );

               // print block
               for( blockRowIndex = 0; blockRowIndex < OBJECT_HEIGHT; blockRowIndex++ )
                  {
                  for( blockColIndex = 0; blockColIndex < OBJECT_WIDTH; blockColIndex++ )
                     {
	
                     if( (blockColIndex == 1) && (blockRowIndex == 0))
                        {
                        printCharAt( colIndex + blockColIndex, rowIndex + blockRowIndex, 'M' );	
	                    }
                     else
                        {
                        printCharAt( colIndex + blockColIndex, rowIndex + blockRowIndex, SPACE );
                        }
                     }
                  }

               // add 3 to the colIndex to make it skip the block it just printed
               colIndex = colIndex + 2; 

	           }
            else if( gameGrid[rowIndex][colIndex] == 'G' )
               {
	           // set the color
               setColor( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );

               // print block
               for( blockRowIndex = 0; blockRowIndex < OBJECT_HEIGHT; blockRowIndex++ )
                  {
                  for( blockColIndex = 0; blockColIndex < OBJECT_WIDTH; blockColIndex++ )
                     {
	
                     if( (blockColIndex == 1) && (blockRowIndex == 0))
                        {
                        printCharAt( colIndex + blockColIndex, rowIndex + blockRowIndex, 'G' );	
	                    }
                     else
                        {
                        printCharAt( colIndex + blockColIndex, rowIndex + blockRowIndex, SPACE );
                        }
                     }
                  }

               // add 3 to the colIndex to make it skip the block it just printed
               colIndex = colIndex + 2; 

	           }
            else if( gameGrid[rowIndex][colIndex] == 'W' )
               {
		       // set the color
               setColor( COLOR_BLACK, COLOR_WHITE, SET_BRIGHT );

               // print block
               for( blockRowIndex = 0; blockRowIndex < OBJECT_HEIGHT; blockRowIndex++ )
                  {
                  for( blockColIndex = 0; blockColIndex < OBJECT_WIDTH; blockColIndex++ )
                     {
                     printCharAt( colIndex + blockColIndex, rowIndex + blockRowIndex, SPACE );
                     }
                  }

               // add 3 to the colIndex to make it skip the block it just printed
               colIndex = colIndex + 2; 

	           }
            }
         }
      }
   }

void pressKeyToStart()
   {
   // clear screen to fit message bounds
	setColor ( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
	clearScreen ( SCRN_MIN_X+10, SCRN_MIN_Y+34, SCRN_MAX_X-35, SCRN_MAX_Y- 1);
        // print continue message
	printStringAt( SCRN_MIN_X+14, SCRN_MAX_Y- 1, "Press any key to start game", "LEFT" );
	// wait for user input to continue
	waitForInput( -1 );
   }

void loadNewBlock( int oldX, int oldY, char gameGrid[][SCRN_MAX_X], int color )
   {
   // variables
   int rowIndex, colIndex;

   // loads a new block into the array
   for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
      {
      for( colIndex = 0; colIndex < OBJECT_WIDTH; colIndex++ )
         {
         if( color == GREEN)
            {
	        gameGrid[rowIndex + oldY][colIndex + oldX] = 'G';
            }	
         else if( color == YELLOW)
            {
	        gameGrid[rowIndex + oldY][colIndex + oldX] = 'Y';
            }
         else if( color == RED)
            {
	        gameGrid[rowIndex + oldY][colIndex + oldX] = 'R';
            }
         else if( color == CYAN)
            {
	        gameGrid[rowIndex + oldY][colIndex + oldX] = 'C';
            }
         else if( color == MAGENTA)
            {
	        gameGrid[rowIndex + oldY][colIndex + oldX] = 'M';
            }	

         }
	  }

   }

void scoreChecker( int oldX, int oldY, char gameGrid[][SCRN_MAX_X],int &score )
   {
    // initialize
   char blockColor;
   int rowIndex, colIndex;

   // Get the letter of the block we will be using to compare
   blockColor = gameGrid[oldY][oldX];

   // Check to see if block landed verticale is worth points
      // if
   if( (gameGrid[oldY + 2][oldX] == blockColor) && (gameGrid[oldY + 2][oldX + 1] == blockColor) && (gameGrid[oldY + 2][oldX + 2] == blockColor) &&
       (gameGrid[oldY + 4][oldX] == blockColor) && (gameGrid[oldY + 4][oldX + 1] == blockColor) && (gameGrid[oldY + 4][oldX + 2] == blockColor) )
      {
      score = score + 3;

      // set the blocks that scored to white
      for( rowIndex = 0; rowIndex < 6; rowIndex++ )
         {
         for( colIndex = 0; colIndex < OBJECT_WIDTH; colIndex++ )
            {
            gameGrid[rowIndex + oldY][colIndex + oldX] = 'W';
            }
         }
      }

   if( (gameGrid[oldY][oldX - 6] == blockColor) && (gameGrid[oldY][oldX - 5] == blockColor) && (gameGrid[oldY][oldX - 4] == blockColor) && 
       (gameGrid[oldY][oldX - 3] == blockColor) && (gameGrid[oldY][oldX - 2] == blockColor) && (gameGrid[oldY][oldX - 1] == blockColor) )
      {
	  // award points
	  score = score + 3;
      
      // set blocks that scored to white
      for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
         {
         for( colIndex = -6; colIndex < 2; colIndex++ )
            {
            gameGrid[rowIndex + oldY][colIndex + oldX] = 'W';
            }
         }

      // check to see if anymore blocks can be awarded points
      if( (gameGrid[oldY][oldX + 3] == blockColor) && (gameGrid[oldY][oldX + 4] == blockColor) && (gameGrid[oldY][oldX +5] == blockColor) )
         {
	     // award points
         score++;

         // set blocks that scored to white
         for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex ++ )
            {
	        for( colIndex = 0; colIndex < 3; colIndex++ )
               {
	           gameGrid[rowIndex + oldY][colIndex + (oldX + 3)] = 'W';
	           }
	        }

         // check to see if anymore blocks can be awarded points
         if( (gameGrid[oldY][oldX + 6] == blockColor) && (gameGrid[oldY][oldX + 7] == blockColor) && (gameGrid[oldY][oldX + 8] == blockColor) )
            {
            // award points
            score++;

            // set blocks that scored to white
            for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex ++ )
               {
	           for( colIndex = 0; colIndex < 3; colIndex++ )
                  {
	              gameGrid[rowIndex + oldY][colIndex + (oldX + 6)] = 'W';
	              }
	           }
 
            
            } 
         } 
      }
   else if( (gameGrid[oldY][oldX - 3] == blockColor) && (gameGrid[oldY][oldX - 2] == blockColor) && (gameGrid[oldY][oldX - 1] == blockColor) && 
            (gameGrid[oldY][oldX + 3] == blockColor) && (gameGrid[oldY][oldX + 4] == blockColor) && (gameGrid[oldY][oldX + 5] == blockColor) )
      {
	  // award points
	  score = score + 3;

      	  
      // set blocks that scored to white
      for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
         {
         for( colIndex = - 3; colIndex < 5; colIndex++ )
            {
            gameGrid[rowIndex + oldY][colIndex + oldX] = 'W';
            }
         }

      // check to see if anymore blocks can be awarded points
      if( (gameGrid[oldY][oldX + 6] == blockColor) && (gameGrid[oldY][oldX + 7] == blockColor) && (gameGrid[oldY][oldX + 8] == blockColor) )
         {
         // award points
         score++;

         // set blocks that scored to white
         for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex ++ )
            {
	        for( colIndex = 0; colIndex < 3; colIndex++ )
               {
            gameGrid[rowIndex + oldY][colIndex + (oldX + 6)] = 'W';
	           }
	        }
         }
      }
   else if( (gameGrid[oldY][oldX + 3] == blockColor) && (gameGrid[oldY][oldX + 4] == blockColor) && (gameGrid[oldY][oldX + 5] == blockColor) && 
            (gameGrid[oldY][oldX + 6] == blockColor) && (gameGrid[oldY][oldX + 7] == blockColor) && (gameGrid[oldY][oldX + 8] == blockColor) )
      {
		  // award points
	  score = score + 3;

      	  
      // set blocks that scored to white
      for( rowIndex = 0; rowIndex < OBJECT_HEIGHT; rowIndex++ )
         {
         for( colIndex = 0; colIndex < 8; colIndex++ )
            {
            gameGrid[rowIndex + oldY][colIndex + oldX] = 'W';
            }
         }
	

      }
   }

void displayGameEnded()
   {
   // Initialize functions , variables 
     int XPox , yPos ; 	   

    // Clear screen for proper instruction dimensions
    //   function: clearScreen , setColor 
    //
       setColor(COLOR_BLUE , COLOR_BLACK , SET_BRIGHT); 
       clearScreen( SCRN_MIN_X +10 , SCRN_MIN_Y +5 , SCRN_MAX_X -10, SCRN_MAX_Y -5);  
        

    // Print the game End Messages 
        // printStringAt, setColor
	XPox = SCRN_MIN_X +10;
        yPos = 	SCRN_MIN_Y +5; 

	printStringAt(XPox , yPos , "Msg1"  , "LEFT");
        yPos += 2; 

	printStringAt(XPox , yPos , " Msg2"  , "LEFT");
        yPos += 2; 
   }

void displayStackedToTall()
   {
    // clear screen over bottom bar text
		setColor ( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
		clearScreen( SCRN_MIN_X +10, SCRN_MIN_Y +22, SCRN_MAX_X - 19, SCRN_MAX_Y );
	        // print blocks stacked too tall message
	            // printStringAt
					printStringAt ( SCRN_MIN_X +18, SCRN_MIN_Y +23, "Blocks too high - Game ended", "LEFT" );
					printStringAt ( SCRN_MIN_X +19, SCRN_MIN_Y +24, "Press Any Key To Continue", "LEFT" );
	waitForInput( -1 );
   }

void saveorContinue()
   {
    // clear screen over bottom bar text
		setColor ( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
		clearScreen( SCRN_MIN_X +10, SCRN_MIN_Y +22, SCRN_MAX_X - 19, SCRN_MAX_Y );
	        // print blocks stacked too tall message
	            // printStringAt
					printStringAt ( SCRN_MIN_X +20, SCRN_MIN_Y +22, "Game Paused", "LEFT" );
					printStringAt ( SCRN_MIN_X +18, SCRN_MIN_Y +23, "Press <S>ave to save game", "LEFT" );
					printStringAt ( SCRN_MIN_X +16, SCRN_MIN_Y +24, "Press Space Bar to Resume Game", "LEFT" );
   }

void uploadSaveGame( int difficulty, int score, int plays, char gameGrid[][SCRN_MAX_X] )
   {
    // initialize variables
     ifstream fin;
     int row = 0 , col = 0; 
     char comma;  
     fin.open("savegame.txt"); 
    // Open save game
    fin>>score>>comma>>difficulty>>comma>>plays;
    for ( col = 0 ; col < SCRN_MAX_Y ; col++)
    {
             fin>>gameGrid[row][col];

    }	    
    while(fin.good())
    {
        col++; 
	for ( col = 0 ; col < SCRN_MAX_Y ; col++)
        {
             fin>>gameGrid[row][col];

        }	    
   

    }

       
    // Read game into array
        // start loop
   }

void clearGameGrid( char gameGrid[][SCRN_MAX_X] )
   {
    // variables
   int rowIndex, colIndex;

   // begin loop to replace all characters in array with E
      // for
   for( rowIndex = 0; rowIndex < SCRN_MAX_Y - 1; rowIndex++ )
      {
      for( colIndex = 0; colIndex < SCRN_MAX_X - 1; colIndex++ )
         {
         gameGrid[rowIndex][colIndex] = 'E';
         }
      }
   }

void endScreen()
   {
    // Display background textile
        // Print blocks( spaces, approx 2x2? ) with corresponding pattern
            // function : setColor  ,clearScreen( note: may use brute force for setting blocks or looping )
                printBackground();   	

     // clear screen to dimensions
		setColor ( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
		clearScreen ( SCRN_MIN_X +12, SCRN_MIN_Y +6, SCRN_MAX_X - 12, SCRN_MAX_Y -6 );
    // print end screen text
        // Print end screen title
            // printStringAt, setColor
				printStringAt ( SCRN_MIN_X +33, SCRN_MIN_Y +7, "PROGRAM END", "LEFT" );
				printStringAt ( SCRN_MIN_X +33, SCRN_MIN_Y +8, "===========", "LEFT" );
        // Print end screen text
            // printStringAt
				printStringAt ( SCRN_MIN_X +28, SCRN_MIN_Y +11, "THANK YOU FOR PLAYING", "LEFT" );
				printStringAt ( SCRN_MIN_X +35, SCRN_MIN_Y +13, "TETRIX", "LEFT" );
				printStringAt ( SCRN_MIN_X +26, SCRN_MIN_Y +16, "Press Any Key to Continue", "LEFT" );
	waitForInput (-1);
   }

void printBackground()
	{
	// initialize
	int xCord = 0, yCord = 0;
	// print blocks
	do
		{
		
		while ( yCord < 26 )
			{
			setColor ( COLOR_YELLOW, COLOR_RED, SET_BRIGHT );
			printCharAt( xCord, yCord, ' ' );
			printCharAt( xCord+1, yCord, ' ' );
			printCharAt( xCord+2, yCord, ' ' );
			printCharAt( xCord, yCord+1, ' ' );
			printCharAt( xCord+1, yCord+1, ' ' );
			printCharAt( xCord+2, yCord+1, ' ' );
			
			yCord +=2;
			
			setColor ( COLOR_YELLOW, COLOR_CYAN, SET_BRIGHT );
			printCharAt( xCord, yCord, ' ' );
			printCharAt( xCord+1, yCord, ' ' );
			printCharAt( xCord+2, yCord, ' ' );
			printCharAt( xCord, yCord+1, ' ' );
			printCharAt( xCord+1, yCord+1, ' ' );
			printCharAt( xCord+2, yCord+1, ' ' );
			
			yCord +=2;
	  		}
	
			yCord = 0;
			xCord += 3;
	
		while ( yCord < 26 )
			{
			setColor ( COLOR_YELLOW, COLOR_BLUE, SET_BRIGHT );
			printCharAt( xCord, yCord, ' ' );
			printCharAt( xCord+1, yCord, ' ' );
			printCharAt( xCord+2, yCord, ' ' );
			printCharAt( xCord, yCord+1, ' ' );
			printCharAt( xCord+1, yCord+1, ' ' );
			printCharAt( xCord+2, yCord+1, ' ' );
			
			yCord +=2;
			
			setColor ( COLOR_YELLOW, COLOR_MAGENTA, SET_BRIGHT );
			printCharAt( xCord, yCord, ' ' );
			printCharAt( xCord+1, yCord, ' ' );
			printCharAt( xCord+2, yCord, ' ' );
			printCharAt( xCord, yCord+1, ' ' );
			printCharAt( xCord+1, yCord+1, ' ' );
			printCharAt( xCord+2, yCord+1, ' ' );
			yCord +=2;
	  		}
	
			yCord = 0;
			xCord +=3;
	
		while ( yCord < 26 )
			{
			setColor ( COLOR_YELLOW, COLOR_GREEN, SET_BRIGHT );
			printCharAt( xCord, yCord, ' ' );
			printCharAt( xCord+1, yCord, ' ' );
			printCharAt( xCord+2, yCord, ' ' );
			printCharAt( xCord, yCord+1, ' ' );
			printCharAt( xCord+1, yCord+1, ' ' );
			printCharAt( xCord+2, yCord+1, ' ' );
			
			yCord +=2;
			
			setColor ( COLOR_BLUE, COLOR_YELLOW, SET_BRIGHT );
			printCharAt( xCord, yCord, ' ' );
			printCharAt( xCord+1, yCord, ' ' );
			printCharAt( xCord+2, yCord, ' ' );
			printCharAt( xCord, yCord+1, ' ' );
			printCharAt( xCord+1, yCord+1, ' ' );
			printCharAt( xCord+2, yCord+1, ' ' );
			
			yCord +=2;
			}
			xCord += 3;
			yCord = 0;
		}
		while ( xCord < 74 );
	}	

void displayBarInstructions()
	{
	
// clear screen over bottom bar text
		setColor ( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
		clearScreen( SCRN_MIN_X +10, SCRN_MIN_Y +22, SCRN_MAX_X - 19, SCRN_MAX_Y );
	        // print blocks stacked too tall message
	            // printStringAt
					printStringAt ( SCRN_MIN_X +14, SCRN_MIN_Y +22, "Left/Right/Down Arrows Redirect Block", "LEFT" );
					printStringAt ( SCRN_MIN_X +18, SCRN_MIN_Y +23, "<D> Clears Bottom Row", "LEFT" );
					printStringAt ( SCRN_MIN_X +12, SCRN_MIN_Y +24, "Space Bar Pauses Game - ESCape Ends Game", "LEFT" );


	}







