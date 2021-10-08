#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

// returns length of string
int mystrlen(char *s){
	int total = 0;
	// self note that 0 is considered false so thats y the loop stops 0_0
	while (*s){
		s++;
		total++;
	}
	return total;
}

//copies source into destination (dest)
char* mystrcpy( char *dest, char *source ){
	int pos =0;
	// goes until we find the 0 at the end of string
	while (*(source+pos)){
		//copies element in position from source into dest
		*(dest+pos) = *(source+pos);
		pos ++;
	}
	return dest;
	
}

//concatenates the first n characters of source onto the end of dest
char * mystrncat( char *dest, char *source, int n){

	int pos=0;
	
	// goes till we find the end of source or n characters of source
	// pos-1 so we start with overwriting the null at the end of dest
	while(source[pos-1] && pos < n){
		// at the end of dest add the posth element of source
		dest[mystrlen(dest)+pos] = source[pos];
		pos ++;
	} 
	// once done put the 0 at the end
	dest[mystrlen(dest)+pos] = '\0';
	return dest;
}

// to compare lexy order
int mystrcmp( char *s1, char *s2 ){
	
	char *string1 = s1;
	char *string2 = s2;
	
	//while we have not reached the end and if the strings r not equal
	while ((*string1 && *string2) && *string1 == *string2){
		//go to the next character
		string1++;
		string2++;
	}
	// if strings r identical, return 0
	if(*string1 == *string2){
		return 0;
	}else{
		// if string1 is greater, return 1, otherwise return -1
		if (*string1 > *string2){
			return 1;
		} else return -1;
	}
}
	 
// to look for char c in string s
char* mystrchr(char *s, char c ){
	int pos =0;
	// while we havent found target or reached the end of the string
	while(s[pos]!=c && s[pos]){
		pos++;
		if (s[pos] ==c){
			// s + pos is where the character is found
			return s+pos;
		}
	} 
	return 0;
}