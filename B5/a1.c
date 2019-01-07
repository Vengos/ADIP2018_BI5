#include <stdio.h>
#include <stdlib.h>


int strlen (char* string){
	char a;
	for(int i=0;; i++){
		a=string[i];
		if(a=='\0'){
			return i;
		}
	}
}

char* reversed_string(char* string){
	int l= strlen(string);
	
	for(int i= 0; i<l/2; i++){
		char a;
		a= string[i];
		string[i]=string[(l-1)-i];
		string[(l-1)-i]=a;
	}
	return string;
}

int palindrom(char* string){
	int l= strlen(string);
	
	char a;
	char b;
	
	for(int i= 0; i<l/2; i++){
		a=string[i];
		b=string[(l-1)-i];
		if(a!=b){
			printf("Kein Palindrom\n");
			return 0;
		}
	}
	printf("Palindrom\n");
	return 1;
}

char* encrypt(char* s){
	char a;
	int l= strlen(s);
	
	for(int i= 0; i<l; i++){
		a=s[i];
		
		if(a>=65 && a<=90){
			a+=13;
			if(a>90){
				a=a-26;
				s[i]=a;
			}
			s[i]=a;
		}else if(a>=97 && a<=122){
			a=a+13;
			if((unsigned int)a>122){
				a=a-26;
				s[i]=a;
			}
			s[i]=a;
		}
	}
	return s;
}

char* decrypt(char* s){
	char a;
	int l= strlen(s);
	
	for(int i= 0; i<l; i++){
		a=s[i];
		
		if(a>=65 && a<=90){
			a-=13;
			if(a<65){
				a=a+26;
				s[i]=a;
			}
			s[i]=a;
		}else if(a>=97 && a<=122){
			a-=13;
			if((unsigned int)a<97){
				a=a+26;
				s[i]=a;
			}
			s[i]=a;
		}
	}
	return s;
}

char* kencrypt(char* s, int k){
	char a;
	int l= strlen(s);
	
	for(int i= 0; i<l; i++){
		a=s[i];
		
		if(a>=65 && a<=90){
			a+=k;
			if(a>90){
				a=a-26;
				s[i]=a;
			}
			s[i]=a;
		}else if(a>=97 && a<=122){
			a+=k;
			if((unsigned int)a>122){
				a=a-26;
				s[i]=a;
			}
			s[i]=a;
		}
	}
	return s;
}

char* kdecrypt(char* s, int k){
	char a;
	int l= strlen(s);
	
	for(int i= 0; i<l; i++){
		a=s[i];
		
		if(a>=65 && a<=90){
			a-=k;
			if(a<65){
				a=a+26;
				s[i]=a;
			}
			s[i]=a;
		}else if(a>=97 && a<=122){
			a-=k;
			if((unsigned int)a<97){
				a=a+26;
				s[i]=a;
			}
			s[i]=a;
		}
	}
	return s;
}

int main(){
	int d=0;
	printf("1. Umgekehrter String\n");
	printf("2. Palindrom\n");
	printf("3. ROT13\n");
	printf("4. Beliebiges k\n");
	scanf("%i", &d);
	
	if(d==1){
		printf("Wort eingeben:\n");	
		char string[100];
		scanf("%99s",string);
		printf("%s\n", reversed_string(string));
	}else if(d==2){
		printf("Wort eingeben:\n");	
		char string[100];
		scanf("%99s",string);
		printf("%i\n", palindrom(string));
	}else if(d==3){
		printf("Wort eingeben:\n");	
		char string[100];
		scanf("%99s\n",string);
		printf("%s\n", encrypt(string));
		printf("%s\n", decrypt(string));
	}else if(d==4){
		int k;
		char string[100];
		printf("Wort eingeben:\n");	
		scanf("%99s", string);
		
		do{
			printf("k eingeben:\n");
			scanf("%i", &k);
		}while(k<0 && k>=27);
		
		printf("%s\n", kencrypt(string, k));
		printf("%s\n", kdecrypt(string, k));
	}else{
		return 0;
	}
		
	
	return 0;
}