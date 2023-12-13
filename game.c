#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int userScan();
int random_in_range(int start, int end);
int qestion(int a, int b, int c, int d, int pattern);
void game();

int main(){
  srand(time(NULL));
  int play = 0;
  do{
    printf("Do you want to play? (1 - yes, 0 - no)\n");
    play = userScan();
    if(play == 1){
      game();
    }
    else if(play == 0){
      printf("Bye!");
    }
    else printf("Choose a valid index!\n");
  } while(play == 1);
  return 0;
}

int userScan(){
  int num = 0;
  fflush(stdout);
  scanf("%d", &num);
  return num;
}

int random_in_range(int start, int end){
  int num;
  num = start + rand()%(end - start + 1);
  return num;
}

int qestion(int a, int b, int c, int d, int pattern){
  printf("Is this expression TRUE? (Choose 1 if it is TRUE, if it is FALSE print 0.\n");
  int correct_answer;

  switch(pattern){
    case 1:
    printf("%d + %d > %d + %d\n", a, b, c, d);
    correct_answer = (a + b > c + d);
    break;

    case 2:
    printf("%d * %d != %d * %d\n", a, b, c, d);
    correct_answer = (a * b != c * d);
    break;

    case 3:
    printf("%d - %d < %d - %d\n", a, b, c, d);
    correct_answer = (a - b < c - d);
    break;

    default:
    printf("Smth went wrong!");
  }
  return correct_answer;
}

void game(){
  int a, b, c, d, pattern;
  a = random_in_range(-50, 50);
  b = random_in_range(-50, 50);
  c = random_in_range(-50, 50);
  d = random_in_range(-50, 50);
  pattern = random_in_range(1, 3);

  int correct_answer = qestion(a, b, c, d, pattern);
  int user_answer = userScan();
  if(user_answer == 1 || user_answer == 0) {
    if (correct_answer == user_answer) printf("Right!\n");
    else printf("Wrong!\n"); 
  }
  else printf("Wrong format! Allowed answers: 1, 0.\n");    
}
