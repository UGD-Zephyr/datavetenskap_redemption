/* Programmer: Per Stoor
 * Date: 2022-08-24
 * Last changed: 2022-08-24
 * Type of program: Enter data about various persons,
 * age, weight, name, job and so on and save it in a
 * .txt text file. 
 * Also let the user search this file among various 
 * data.
 *
 * Notes:
 * */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>            //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>             //STDIN_FILENO

#define STRING_LENGTH 50
#define MENU_ARROW_TOP 1
#define MENU_ARROW_BOTTOM 2

void introduction_function();
void menu_arrow_function(int current_arrow_position, int future_arrow_position);
int main_menu_function();

typedef struct{

	int age;
	int weight;
	char job[STRING_LENGTH];
	char first_name[STRING_LENGTH];
	char last_name[STRING_LENGTH];

} person;

int main(int argc, char *argv[]){

	int user_choice;
	static struct termios oldt, newt;

	/*tcgetattr gets the parameters of the current terminal
	STDIN_FILENO will tell tcgetattr that it should write the settings
	of stdin to oldt*/
	tcgetattr( STDIN_FILENO, &oldt);

	/*now the settings will be copied*/
	newt = oldt;

	/*ICANON normally takes care that one line at a time will be processed
	that means it will return if it sees a "\n" or an EOF or an EOL*/
	newt.c_lflag &= ~(ICANON);

	/*Those new settings will be set to STDIN
	CSANOW tells tcsetattr to change attributes immediately. */
	tcsetattr( STDIN_FILENO, TCSANOW, &newt);

		user_choice = main_menu_function();

			if(user_choice == 1){
				system("clear");
				printf("SAVE DATA TO FILE");
				printf("\n");
			}
			else if(user_choice == 2){
				system("clear");
				printf("SEARCH DATA FROM FILE");
				printf("\n");
			}

	/*restore the old settings*/
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt);

return 0;
}

void introduction_function(){

	system("clear");
	printf("HELLO! I AM THE INTRODUCTORY TEXT...\n");
}

int main_menu_function(){

	int menu_arrow_position;
	int inputted_keyboard_value;

		menu_arrow_position = 1;
		inputted_keyboard_value = 0;

            system("clear");
			while(inputted_keyboard_value != 10){

				menu_arrow_function(1, menu_arrow_position); printf("1. SAVE DATA TO FILE\n");
				menu_arrow_function(2, menu_arrow_position); printf("2. SEARCH DATA FROM FILE\n");

                system("stty -echo");
                inputted_keyboard_value = getchar();
                system("stty echo");

					if(inputted_keyboard_value == 65 && menu_arrow_position != MENU_ARROW_TOP){
				        system("clear");
						menu_arrow_position--;
					}
					else if(inputted_keyboard_value == 66 && menu_arrow_position != MENU_ARROW_BOTTOM){
				        system("clear");
						menu_arrow_position++;
					}
					else{
                        system("clear");
						menu_arrow_position = menu_arrow_position;
					}
			}

return menu_arrow_position;
}

void menu_arrow_function(int current_arrow_position, int future_arrow_position){

	if(current_arrow_position == future_arrow_position){
		printf("---> - ");
	}
	else{
		printf("       ");
	}

}
