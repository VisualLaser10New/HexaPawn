#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#if _WIN64 || _WIN32

#include <Windows.h>
#include <conio.h> // library for getch
#define PAUSE system("pause")
#define CLEAR system("cls")
#define SLEEP(x) Sleep(x)

#else

#include <unistd.h> // library for usleep
#include <termios.h> // library for getch
#define PAUSE system("echo press enter to continue; read dummy;")
#define CLEAR system("clear")
#define SLEEP(x) usleep(x*1000)

#endif


#ifndef FFLUSHSTDOUT
#define FFLUSHSTDOUT if((fseek(stdout, 0, SEEK_END), ftell(stdout)) > 0){\
						rewind(stdout);\
						while((c = getchar()) != '\n' && c != EOF);\
                        }
#endif

#ifndef FFLUSHSTDIN
#define FFLUSHSTDIN if((fseek(stdin, 0, SEEK_END), ftell(stdin)) > 0){\
						rewind(stdin);\
						while((t = getchar()) != '\n' && t != EOF);\
                        }
#endif
