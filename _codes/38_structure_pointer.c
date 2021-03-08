#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define LEN 20

struct names
{
	char given[LEN];		// 20
	char family[LEN];		// 20
};

struct friend
{
	struct names full_name;		// 20 * 2
	char mobile[LEN];			// 20
};


int main()
{	
	struct friend my_friends[2] = {

		{ {"Ariana", "Grande"}, "010-1234-5678" },
		{ {"Taylor", "Swift"}, "010-0000-1111" }

	};

	struct friend* girlfreind;

	girlfreind = &my_friends[0];

	printf("%zd\n", sizeof(struct friend));
	printf("%lld %s\n", (long long)girlfreind, girlfreind->full_name.given);


	girlfreind++;


	printf("%lld %s\n", (long long)girlfreind, (*girlfreind).full_name.given);
	// . has higher precedence than *
	// (* ).  ==  ->
	
	return 0;

}