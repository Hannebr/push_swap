#include <stdlib.h>

void checkLeaks() {
	system("leaks a.out");
}

int main() {
	atexit(checkLeaks);
	return 0;
}