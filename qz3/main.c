
#include <stdio.h>
FILE* fp;
void rec_dec(char* s) {
	 if(*s == '\0') {	 	 	
	 fprintf(fp, "\n");
    } else {
     fprintf(fp, "%c,", *s++);	
	 rec_dec(s);
    }    
}

int hanoi_tower(int n, char A, char B, char C) {		
	if(n==1) {		
		fprintf(fp, "Move disk 1 from %c to %c\n", A, C);
	} else {		
		hanoi_tower(n-1, A, C, B);
		fprintf(fp, "Move disk %d from %c to %c\n", n, A, C);
		hanoi_tower(n-1, B, A, C);
	}
}

int multication(int i, int j) {
	if (i <= 9) {
		if (j <= 9) {
			fprintf(fp, "%d*%d = %d ", i, j, i*j);
			multication(i, j+1);
		} else {
			fprintf(fp, "\n");
			i++;
			multication(i, 1);
		}
	}
}
int main() {
	fp = fopen("hanoi.txt", "w+");
	char s[]="1234567890";
	rec_dec(s);
	fprintf(fp, "func#1------------------------\n");
	hanoi_tower(16, 'A', 'B', 'C');
	fprintf(fp, "func#2------------------------\n");
	multication(1,1);
	fprintf(fp, "func#3------------------------\n");		
	return 0;
	fclose(fp);
}