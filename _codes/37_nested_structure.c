#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define LEN 20


struct names
{
	char given[LEN];
	char family[LEN];
};


struct reservation
{	
	struct names guest;
	struct names host;
	char food[LEN];
	char place[LEN];

	//time
	int year;
	int month;
	int day;
	int hours;
	int minutes;

};

void invition(struct reservation* respt);

int main()
{	
	struct reservation res1 = {
		.guest = { "Minkyu", "Shin" },
		.host = { "Minju", "Kim" },
		.food = "Ramen",
		.place = "Menji",
		
			//time
		.year = 2021,
		.month = 2,
		.day = 12,
		.hours = 11,
		.minutes = 30
	};


	invition(&res1);




	return 0;

}

void invition(struct reservation* respt)
{
	printf("Dear %s %s,\n", respt->guest.given, respt->guest.family);
	printf("I would lioke to serve you %s.\n", respt->food);
	printf("Please visit the %s on %d/%d/%d at %d:%d.\n",
		respt->place, respt->day, respt->month, respt->year, respt->hours, respt->minutes);
	printf("Sincerely,\n%s %s\n\n\n", respt->host.given, respt->host.family);

}