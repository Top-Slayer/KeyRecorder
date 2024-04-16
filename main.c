#include <stdio.h>
#include <conio.h>
#include <windows.h>

#pragma comment(lib, "user32.lib")

int input_key[] = {};

void enterKey(){
  int n = 0;
  int key = 0;

  printf("Enter: ");
  while(1) {
    key = _getch();
    if(key == 7) break; // CTRL + G
    input_key[n] = key;
    printf("%d ", input_key[n]);
    n++;
  }
}

void repeatKey(){
  // try to convert to uppercase and check
  for (int i=0; input_key[i] != '\0' && input_key[i] != -1; i++){
    keybd_event((BYTE)input_key[i], 0, 0, 0); // maybe will make working when preese same key for along time
    keybd_event((BYTE)input_key[i], 0, KEYEVENTF_KEYUP, 0);

    // keybd_event('J', 0, 0, 0);
    // keybd_event('J', 0, KEYEVENTF_KEYUP, 0);
  }
}

void displayKey(){
  printf("\nRepeat: ");
  int n = 0;
  while (input_key[n] != '\0' && input_key[n] != -1) {
    printf("%d ", input_key[n]);
    n++;
  }
  printf("\nRepeat: ");
  n = 0;
  while (input_key[n] != '\0' && input_key[n] != -1) {
    printf("%c ", input_key[n]);
    n++;
  }
}

int main(int argc, char *argv[]) {
  enterKey();
  // displayKey();
  repeatKey();

  return 0; 
}
