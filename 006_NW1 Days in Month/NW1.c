#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned char mon;
  unsigned char tue;
  unsigned char wed;
  unsigned char thu;
  unsigned char fri;
  unsigned char sat;
  unsigned char sun;
} Days;

void Days_according_to_first(Days *days_p, char *month_start_day);
void Days_from_monday_(Days *days_p);


int main(void) {
  unsigned short cases;
  fscanf(stdin,  "%hu", &cases);

  unsigned short days_in_month = 0;
  char first_day[6];  // max length = "thurs" = 5
  Days days = { 0 };
  for (unsigned short i = 0; i < cases; i++) {
    fscanf(stdin, "%hu %s", &days_in_month, first_day);
    Days_according_to_first(&days, first_day);

    fprintf(
      stdout, 
      "%hu %hu %hu %hu %hu %hu %hu\n",
      ((days_in_month - days.mon) / 7) + 1,
      ((days_in_month - days.tue) / 7) + 1,
      ((days_in_month - days.wed) / 7) + 1,
      ((days_in_month - days.thu) / 7) + 1,
      ((days_in_month - days.fri) / 7) + 1,
      ((days_in_month - days.sat) / 7) + 1,
      ((days_in_month - days.sun) / 7) + 1
    );
  }

  return EXIT_SUCCESS;
}


void Days_according_to_first(Days *days_p, char *month_start_day) {
  switch (month_start_day[1]) {
    case 'o':  // monday
      days_p->mon = 1;
      break;
    
    case 'u':  // tuesday or sunday
      days_p->mon = (month_start_day[0] == 't') ? 7 : 2;
      break;
    
    case 'e':  // wednesday
      days_p->mon = 6;
      break;
    
    case 'h':  // thursday
      days_p->mon = 5;
      break;
    
    case 'r':  // friday
      days_p->mon = 4;
      break;

    default:
    // case 'a':  // saturday
      days_p->mon = 3;
      break;
  }

  Days_from_monday_(days_p);
}


void Days_from_monday_(Days *days_p) {
  days_p->tue = (days_p->mon + 1 > 7) ? 1 : days_p->mon + 1;
  days_p->wed = (days_p->tue + 1 > 7) ? 1 : days_p->tue + 1;
  days_p->thu = (days_p->wed + 1 > 7) ? 1 : days_p->wed + 1;
  days_p->fri = (days_p->thu + 1 > 7) ? 1 : days_p->thu + 1;
  days_p->sat = (days_p->fri + 1 > 7) ? 1 : days_p->fri + 1;
  days_p->sun = (days_p->sat + 1 > 7) ? 1 : days_p->sat + 1;
}
