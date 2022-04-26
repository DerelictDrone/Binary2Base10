#include <string.h>
#include <dos.h>
#include <io.h>
#include <alloc.h>
#include <iostream.h>
#include <stdlib.h>
int main() {
unsigned char* filename = (char*) malloc(64); // max size of filepath in dos iirc
unsigned char* newfilename = "b2bcnv.txt";
unsigned char* question = "\nFilename:\n";
unsigned char* flengthstr = (char*) malloc(33); //ltoa can return 33 bytes
unsigned char* oftext = " of ";
int handle    = 0;
int newhandle = 0;
cout << question;
cin >> filename;
_dos_open(filename,0,&handle);
unsigned long flength = filelength(handle); // ulong should allow 4.2gb

ltoa(flength,flengthstr,10);
void far* bytevoid        = farmalloc(1024);
unsigned int   bytesread  = 0;
unsigned char* istring    = (char*) malloc(33); //ulong length
unsigned char* bytestring = (char*) malloc(17); // itoa can return up to 17
unsigned char* bytechunk  = (char*) farmalloc(4096); // 2048 bytes + spaces
// stringified and assuming maximum length of 3 per byte ^
memset(bytevoid,0,2048); // clear these out JUST IN CASE
memset(bytestring,0,17);// if you think I'm paranoid
memset(bytechunk,0,2048);// comment these and find previous memory in your
			// output txt file, as DOS isn't very memory safe :(
_dos_creat(newfilename,0,&newhandle);
unsigned char numlength   = 0;

//reusing some variables real quick
numlength = strlen(flengthstr);
for(bytesread = 0; bytesread < numlength; bytesread++) {
cout << " "; // space for the counter to go up in
}
cout << oftext << flengthstr; // this doesn't change so only print once
long prevpointer = 0; // to store bytevoid's pointer and reset when it moves
for(unsigned long i = 0; i < flength; i++) {
_dos_read(handle, bytevoid, 1024, &bytesread);
i += bytesread;
memset(bytechunk,0,4096); // replace whole string with null chars
prevpointer = (long)bytevoid; // stow the pointer away
for(unsigned int chunker = 0; chunker < bytesread; chunker++) {
memset(bytestring,0,4); // clear it out just incase
itoa(*(char *)(void*)(((long)bytevoid)+chunker),bytestring,10);
strcat(bytestring," "); // ^ Shifts the pointer around a bit
_fstrcat(bytechunk,bytestring);
}
bytevoid = (void*)prevpointer; // bring 'er back round
numlength = strlen(bytechunk);
_dos_write(newhandle, bytechunk, numlength, &bytesread); // useless info
ultoa(i,istring,10);
cout << '\r' << istring;
}
_dos_close(newhandle);
cout << "\nDone!";
exit(0);
return 0; // just incase exit didn't work
}