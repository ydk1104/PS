#include<stdio.h>

int main(void){
	int r,c;
	scanf("%d %d", &r, &c);
	char s[10][11];
	for(int i=0; i<10; i++) scanf("%s", &s[i]);
	printf("#include<stdio.h>\nint main(void){");
	printf("printf(\"%d %d\\n\");", r, c);
	for(int i=0; i<10; i++) printf("printf(\"%s\\n\");", s[i]);
	printf("}");// */
}
/*
1 1
..........
##.###.##.
..#...#...
..........
..........
..........
..........
..........
.#...#....
...#...#..
// */

/* correct
1 1
..........
#########.
####..#...
####......
####......
####......
####......
####......
####......
####...#..
*/

/*
1 1
..........
#.#..##.#.
..#...#...
..........
..........
..........
..........
..........
...#......
.#.....#..
*/