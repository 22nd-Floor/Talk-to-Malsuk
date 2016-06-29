#include "Super.h"
#include "Batchim.h"

// 말 속도
#define MSG_TIME 150

#define JOSA "는"

#define OP_NORMAL 0
#define OP_ADD	  1
#define OP_COVER  2

#define SAY	 72, 24, 1
#define LBOX CUR, 1
#define RBOX 72, GetCursorPosition().Y, 1


// 시간 구조체
typedef struct tm TIME;

// 메세지
typedef enum message { NAME, FIRSTMSG, SECONDMSG, THIRDMSG, FOURTHMSG, FIFTHMSG, SIXTHMSG } MESSAGE;

// 본 내용에서만 쓰는 함수
int Dialog();
void LeftBox(char *str);
void RightBox(char *str);
void setTime();
void message(MESSAGE m);
void say(char *str, int time, int option);
void printTime(int hour, int min);
void Credit();