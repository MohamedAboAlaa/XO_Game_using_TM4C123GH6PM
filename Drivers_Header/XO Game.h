/******************************************************************************
 * Module:XO Game
 *
 * File Name: XO Game.h
 *
 * Description: Header file for XO Game
 *
 * Authors: El-Osood El-Mefrhda
 ******************************************************************************/

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/*Function to enter to the game */
void GameIntro(void);

/*Function for reset game "start again" */
void GameInitialization(void);

/*Function for play xo game UART*/
void RunGameUART(void);
/*Function for play xo game ADC*/
void RunGameADC(void);

/*Function for know the winner of xo game */
int checkWinner(char player);

/*Function for display the winner of xo game */
void Display_Winner(char player);

/*Function for  draw the xo shape */
void displayDraw(void);

/*Function for  display who play now*/
void displayStatus(void);

/*Function for check the replay of xo game */
int CheckPlayAgain(void);

/*Function to End xo game */
void EndGame(void);

/*Function for clear data */
void DrawClearGameMatrix(void);

void WaitForInterrupt(void);
