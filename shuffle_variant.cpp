#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MaxNStud = 20;
const int MaxNProb = 10;
const int MaxN = (MaxNStud > MaxNProb) ? MaxNStud : MaxNProb;
const int MaxLen = 10;

int NStud, NProb;
typedef char str[MaxLen];
str name[MaxNProb];

int order[MaxN];

int main()
{
	srand(time(NULL));
	scanf("%d", &NStud); getchar();
	char c;
	while (c = getchar(), c != '\n' && c != EOF) {
		ungetc(c, stdin);
		NProb = 0;
		do {
			scanf("%s", name[NProb++]);
		} while (getchar() != '\n');
		for (int i = 0; i < NProb; i++)
			order[i] = i;
		random_shuffle(order, order + NProb);
		for (int i = NProb; i < NStud; i++)
			order[i] = order[i - NProb];
		random_shuffle(order, order + NStud);
		for (int i = 0; i < NStud; i++)
			printf("%s ", name[order[i]]);
		printf("\n");
	}
}