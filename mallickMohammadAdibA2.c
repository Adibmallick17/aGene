/************************mallickMohammadAdibA2.c**************
Student Name: Mohammad Adib Mallick    Email Id: mallick@uoguelph.ca 
Due Date: November 4th                 Course Name: CIS 1300

I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:

1) I have read and understood the University policy on academic integrity. 2) I
have completed the Computing with Integrity Tutorial on Moodle; and 3) I have
achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for
this course.
********************************************************/

/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc -std=c99 -Wall mallickMohammadAdibA2.c 
Running: ./a.out
OR
gcc -std=c99 -Wall mallickMohammadAdibA2.c -o assn2
Running the Program: ./assn2
*********************************************************/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define SIZE 100
#define NUMPROTEINS 64 


// Declaring functions
bool isBasePair(char neu1, char neu2);
bool isItaDnaSequence (char strand1 [SIZE], char strand2 [SIZE]);
void reverse (char aStrand [SIZE]);
void complementIt(char aStrand[SIZE]);
bool isItPalindrome(char aStrand[SIZE]);
bool isStrandDnaPalindrome (char aStrand [SIZE]);
int howMany (char aStrand [SIZE], char neu);
void dnaToMrna (char aSeq [SIZE], char mRNA [SIZE]);
void translateDnaToMrnaProteins (char aSeq [SIZE]);
char getCode (char protein [SIZE]);


//Function 1:
// isBasePair function returns true if the bases pair if not it will return false
bool isBasePair (char neu1, char neu2){

//Declaring if and if else statements so when the bases pair they would return true
    if(neu1 =='A'&& neu2=='T'){


//Returns true if neu1 is A and neu2 T
        return true;

    }
    else if(neu1 =='T'&& neu2=='A'){


//Returns true if neu1 is T and neu2 A
        return true;

    }

    else if(neu1 =='G'&& neu2=='C'){


//Returns true if neu1 is G and neu2 C
        return true;

    }

    else if(neu1 =='C'&& neu2=='G'){

//Returns true if neu1 is C and neu2 G
        return true;
    }
// If the bases dont pair it would return false
   else {
    return false;
     }
     return 0;
    }


//Function 2:
// isItaDnaSequence would return true if both strand1 and strand represent a DNA form
bool isItaDnaSequence (char strand1[SIZE], char strand2[SIZE]){

// used the index for both variables to indicate their placement
if(strand1[0]=='C' &&strand1[1]=='T' &&strand2[0]=='G' &&strand2[1]=='A'){

// Returns true if they represent a DNA form
    return true;
}
// used the index for both variables to indicate their placement
    else if(strand1[0]=='T' &&strand1[1]=='C' &&strand2[0]=='A' &&strand2[1]=='G'){

// Returns true if they represent a DNA form
    return true;


} else {
    //Returns false if the sequence doesn't form a DNA
  return false;
}
return 0;

    }

//Function 3:
// Reverse function takes a strand and reverses it
void reverse(char aStrand[SIZE]){
 //Declared a reversed variable to store the reversed strand
 char reversed[SIZE];

 //Declared lenght and stored the lenght of aStrand
    int lenght = strlen(aStrand);
//The for loop would go over the lenght in reverse
    for(int i = lenght - 1; i >= 0; i--) {
//Stored the reversed aStrand inside reversed
       reversed[i]=aStrand[i];
    }
//The for loop undoes the process by counting the lenght of reversed and unreversing the function
    for (int i = 0; i < strlen(reversed); i++) {
//Stored the unreversing strand in to aStrand
        aStrand[i] = reversed[i];
    }
//Function is void so it won't return a value
 return ;
}

//Function 4:
//The complementIt function complements the aStrand
void complementIt(char aStrand[SIZE]){
//Declared lenght and stored the lenght of aStrand
   int lenght= strlen(aStrand);

 //For loop is used to go over the lenght of aStrand
   for(int i=0; i<lenght; i++){

 //If a 'C' was found in aStrand it would assign the value to 'G'
        if(aStrand[i]=='C'){
            aStrand[i]='G';
   }
//If a 'C' was found in aStrand it would assign the value to 'C'

   else  if(aStrand[i]=='G'){
       aStrand[i]='C';
    }

//If a 'T' was found in aStrand it would assign the value to 'A'
   else  if(aStrand[i]=='T'){
         aStrand[i]='A';
    }

//If a 'A' was found in aStrand it would assign the value to 'T'
    else  if(aStrand[i]=='A'){
         aStrand[i]='T';
    }


   }
//Function is void so it won't return a value
   return ;
}

//Function 5:
//isItPalindrome would return true if aStrand is Palindrome
bool isItPalindrome(char aStrand[SIZE]){

//Declated compare to use it if aStrand is not palidrome
    int compare = 0;

//Declared lenght and stored the lenght of aStrand
    int length = strlen(aStrand);

//For loop is used to go through the lenght of aStrand
   for(int i=0;i < length ;i++){

//if statement is used and will add a value to flag if lenght of aStrand is not the same when reversing it
        if(aStrand[i] != aStrand[length-i-1]){
            compare = 1;
            break;
           }
        }

// if these is it would return false
     if (compare) {
       return false;
    }
//Else it will return true and the aStrand is Palindrome
    else {

        return true;

    }
return 0;
}

//Function 6:
//isStrandDnaPalindrome would return true if the Strand dna is palindrome
bool isStrandDnaPalindrome (char aStrand [SIZE]){

//Declared lenght and stored the lenght of aStrand
    int lenght = strlen(aStrand);

//For loop is used to go through the lenght of aStrand
    for(int i=0; i<lenght; i++){

//If aStrand first index is 'A' and second is 'T' it would return true
            if(aStrand[0]=='A' && aStrand[1]=='T'){
                return true;
    }

//If aStrand first index is 'T' and second is 'A' it would return true
    else if(aStrand[0]=='T' && aStrand[1]=='A'){

            return true;
    }
//If aStrand first index is 'C' and second is 'G' it would return true
    else if(aStrand[0]=='C' && aStrand[1]=='G'){
            return true;
    }
//If aStrand first index is 'G' and second is 'C' it would return true
    else if(aStrand[0]=='G' && aStrand[1]=='C'){

            return true;
            }

            else{
//Returns false if the Strand dna is not palindrome
                    return false;
            }
            }

            return 0;

}

//Function 7:
//howMany Returns the number of neuclotidesin the given strand

int howMany (char aStrand[SIZE], char neu){

//Declared a count variable to count the neuclotides in the aStrand
    int count=0;

//Declared lenght and stored the lenght of aStrand
    int lenght= strlen(aStrand);

//For loop is used to go through the lenght of aStrand
    for(int i=0; i<lenght; i++){

//If the astrand has neuclotides similar to neu, the count will go up
            if(aStrand[i]==neu){

//Incremented count if  astrand has neuclotides similar to neu
                count++;
    }

    }

 //Returns the number of neuclotides
    return count;

    }


//Function 8:
//dnaToMrna  takes a DNA sequence and returns the corresponding mRNA sequence

void dnaToMrna (char aSeq [SIZE], char mRNA [SIZE]){


//Declared lenght and stored the lenght of aStrand
    int length = strlen(aSeq);

//For loop is used to go through the lenght of aStrand
    for(int i=0; i<length; i++){


//If there is a 'C' in aSeq it will return 'G' in mRNA
        if(aSeq[i]=='C'){
            mRNA[i]='G';
        }

//If there is a 'G' in aSeq it will return 'C' in mRNA
        else  if(aSeq[i]=='G'){
            mRNA[i]= 'C';
        }

//If there is a 'T' in aSeq it will return 'A' in mRNA
    else  if(aSeq[i]=='T'){
            mRNA[i]='A';
        }

//If there is a 'A' in aSeq it will return 'U' in mRNA
        else  if(aSeq[i]=='A'){
            mRNA[i]='U';
        }

        }

        return;

        }

//Function 9:
//translateDnaToMrnaProteins takes a DNA sequence and prints the list of amino-acids that its mRNAequivalent translates to
void translateDnaToMrnaProteins (char aSeq [SIZE]){

//Prints DNA
    printf("DNA:");

//Declared lenght and stored the lenght of aSeq
int length = strlen(aSeq);

//For loop is used to go through the lenght of aSeq
   for(int i=0; i<length; i++) {

//Printf statement to print aSeq
        printf("%c", aSeq[i]);
}

printf("\n");


char mRNA[SIZE];

//For loop is used to go through the lenght of aSeq
   for(int i=0; i<length; i++){

//If there is a 'C' in aSeq it will return 'G' in mRNA
        if(aSeq[i]=='C'){
            mRNA[i]='G';
    }

//If there is a 'G' in aSeq it will return 'C' in mRNA
    else  if(aSeq[i]=='G'){
            mRNA[i]= 'C';
    }
//If there is a 'T' in aSeq it will return 'A' in mRNA
    else  if(aSeq[i]=='T'){
            mRNA[i]='A';
    }


//If there is a 'A' in aSeq it will return 'U' in mRNA
    else  if(aSeq[i]=='A'){
            mRNA[i]='U';
    }
    else {
            mRNA[i]= aSeq[i];
    }

    }

//Printf statement for mRNA
    printf("mRNA:");

//Declared lenght and stored the lenght2 of mRNA

int length2 = strlen(mRNA);

    for(int i=0; i<length2; i++) {

//Printf the value of mRNA
            printf("%c", mRNA[i]);

    }

    printf(" which translates to: \n");

//Declared the codeSeq variable to put it as in argument when calling the function getCode
    char codeSeq[SIZE];

//For loop is used to go through the lenght of aMRNA and subtract the lenght by 2
    for (int i = 0; i < length2 - 2; i = i + 3) {

//Nested for loop the would assign the value of codeSeq to mRNA[i+j]
            for (int j = 0; j < 3; j++) {
                codeSeq[j] = mRNA[i+j];
    }

//For loop is used to print the 3 values after translating mRNA
    for (int i = 0; i < 3; i++) {
            printf("%c ", codeSeq[i]);
    }

    printf(":");

//Called the function getcode and put codeSeq to extract the values of the array
    printf("%c \n", getCode(codeSeq));

//If there is a 'Z' character then the input sequence has an incorrect base
    if (getCode(codeSeq) == 'Z') {
            printf("The input sequence has an incorrect base");
    }
    }





    }
char getCode (char protein [SIZE]) {

    // array allProteins has a list of all 3-triplet amino acids required for this assignment

    char allProteins [NUMPROTEINS][SIZE] = {"GCA", "GCC", "GCG", "GCU", "AGA","AGG", "CGA", "CGC","CGG","CGU","GAC", "GAU","AAC","AAU","UGC","UGU","GAA","GAG","CAA","CAG", "GGA", "GGC","GGG","GGU","CAC", "CAU","AUA","AUC","AUU", "UUA", "UUG","CUA","CUC", "CUG", "CUU", "AAA", "AAG","AUG", "UUC","UUU", "CCA", "CCC", "CCG", "CCU", "AGC","AGU","UCA","UCC","UCG", "UCU","ACA","ACC","ACG", "ACU", "UGG","UAC","UAU", "GUA","GUC","GUG", "GUU"};

    // array allCodes stores the single-letter code of each triplet given in the above array

    char allCodes [NUMPROTEINS] = {'A','A','A','A','R','R','R','R','R','R','D','D','N','N','C','C','E','E','Q','Q', 'G','G','G','G','H','H','I','I','I', 'L','L','L','L','L','L','K','K','M','F','F','P','P','P','P','S','S','S','S','S','S','T','T','T','T', 'W','Y','Y','V','V','V','V'};

    for (int i = 0; i < NUMPROTEINS; i++) {

        if (strcmp (protein, allProteins[i]) == 0) {
            return allCodes [i];
        }
    }

    return 'Z';   // to indicate an incorrect code - code that doesn't exist in array allCodes 
}