#include <stdio.h>
#include <conio.h>
#include <windows.h>

#pragma comment(lib, "user32.lib")

int input_key[] = {};

void enterKey(){
  int n = 0;

  printf("Enter: ");
  while(1) {
    input_key[n] = _getch();
    if(input_key[n] == 3) break; // CTRL + C
    printf("%d ", input_key[n]);
    n++;
  }
}


void repeatKey(){
  keybd_event('J', 0, 0, 0);

  keybd_event('J', 0, KEYEVENTF_KEYUP, 0);
}


int main(int argc, char *argv[]) {
  enterKey();

  // printf("\n%lld",sizeof(input_key[0]));
  printf("\n%lld",*(&input_key+1)-input_key);
  
  printf("\nRepeat: ");
  for (int i=0; input_key[i] != '\0' && input_key[i] != -1; i++) {
    printf("%d ", input_key[i]);
  }

  return 0; 
}
