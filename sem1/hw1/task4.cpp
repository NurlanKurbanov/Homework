#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
using namespace std;

int main() {

	int ticket = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int t = 0; t < 10; t++) {
				for (int x = 0; x < 10; x++) {
					for (int y = 0; y < 10; y++) {
						for (int z = 0; z < 10; z++) 
							if (i + j + t == x + y + z)
								ticket++;
						
					}
				}
			}
		}
	}
	printf("%d", ticket);
	printf("\n");
	scanf("%d", ticket);
	return 0;
}