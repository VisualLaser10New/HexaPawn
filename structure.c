#include "inc.h"

/* Template
box b11 = {
    .board = {
        {}, {}, {},
        {}, {}, {}
    },

    .moves = {

    }
};
*/

#define P1 {5, 3}
#define P2 {13, 3}
#define P3 {21, 3}
#define P4 {5, 7}
#define P5 {13, 7}
#define P6 {21, 7}
#define P7 {5, 11}
#define P8 {13, 11}
#define P9 {21, 11}
#define NN {-1, -1}


struct pos
{
    int X;
    int Y;
};

typedef struct
{
    int howmany;
    struct pos board[6];
    char active[4];
    struct pos moves[4][2];
}box;

struct pToRemove
{
    int n_box;
    int pallino;
};

box boxArr []=
{
    { // box b11
        .howmany = 3,
        .board = {
            P1, P2, P3,
            P4, P8, P9
        },
        .moves = {
            {P2, P4},
            {P2, P5},
            {P3, P6}
        }
    },

    { // box b11s
        .howmany = 3,
        .board = {
            P1, P2, P3,
            P6, P7, P8
        },

        .moves = {
            {P2, P6},
            {P2, P5},
            {P1, P4}
        }
    },

    { // box b12
        .howmany = 2,
        .board = {
            P1, P2, P3,
            P7, P5, P9
        },

        .moves = {
            {P1, P4},
            {P1, P5}
        }
    },

    { // box b21
        .howmany = 4,
        .board = {
            P1, P4, P3,
            NN, P5, P9
        },

        .moves = {
            {P1, P5},
            {P3, P5},
            {P4, P7},
            {P3, P6}
        }
    },

    { // box b21s
        .howmany = 4,
        .board = {
            P1, P3, P6,
            P5, P7, NN
        },

        .moves = {
            {P1, P4},
            {P1, P5},
            {P3, P5},
            {P6, P9}
        }
    },

    { // box b22
        .howmany = 4,
        .board = {
            P5, P2, P3,
            P4, NN, P9
        },

        .moves = {
            {P2, P4},
            {P3, P6},
            {P5, P8},
            {P5, P9},
        }
    },

    { // box b22s
        .howmany = 4,
        .board = {
            P1, P2, P5,
            P6, P7, NN
        },

        .moves = {
            {P1, P4},
            {P2, P6},
            {P5, P7},
            {P5, P8},
        }
    },

    { // box b23
        .howmany = 3,
        .board = {
            P1, NN, P3,
            P4, P5, P8
        },

        .moves = {
            {P1, P5},
            {P3, P5},
            {P3, P6}
        }
    },

    { // box b23s
        .howmany = 3,
        .board = {
            P1, NN, P3,
            P5, P6, P8
        },

        .moves = {
            {P1, P4},
            {P1, P5},
            {P3, P5}
        }
    },

    { // box b24
        .howmany = 3,
        .board = {
            P1, P2, NN,
            P4, P6, P9
        },

        .moves = {
            {P2, P4},
            {P2, P5},
            {P2, P6}
        }
    },

    { // box b24s
        .howmany = 3,
        .board = {
            NN, P2, P3,
            P4, P6, P7
        },

        .moves = {
            {P2, P4},
            {P2, P5},
            {P2, P6}
        }
    },

    { // box b25
        .howmany = 3,
        .board = {
            P5, P2, P3,
            P7, NN, P6
        },

        .moves = {
            {P5, P7},
            {P5, P8},
            {P2, P6}
        }
    },

    { // box b25s
        .howmany = 3,
        .board = {
            P1, P2, P5,
            P4, NN, P9
        },

        .moves = {
            {P2, P4},
            {P5, P8},
            {P5, P9}
        }
    },

    { // box b26 =
        .howmany = 2, 
        .board = {
            P4, P2, P3,
            P7, P5, P6
        },

        .moves = {
            {P2, P6},
            {P3, P5}
        }
    },

     { // box b26s = 
        .howmany = 2,
        .board = {
            P1, P2, P6,
            P4, P5, P9
        },

        .moves = {
            {P1, P5},
            {P2, P4}
        }
    },

    { // box b27
        .howmany = 2,
        .board = {
            P1, P4, P3,
            NN, P8, P6
        },

        .moves = {
            {P4, P7},
            {P4, P8},
        }
    },

    { // box b27s
        .howmany = 2,
        .board = {
            P1, P3, P6,
            P4, P8, NN
        },

        .moves = {
            {P6, P8},
            {P6, P9},
        }
    },

    { // box b28
        .howmany = 2,
        .board = {
            P1, P2, P6,
            P4, P5, P9
        },

        .moves = {
            {P1, P5},
            {P2, P4}
        }
    },

    { // box b28s
        .howmany = 2,
        .board = {
            P2, P3, P4,
            P5, P6, P7
        },

        .moves = {
            {P2, P6},
            {P3, P5}
        }
    },

    { // box b29
        .howmany = 2,
        .board = {
            NN, P2, P3,
            NN, P5, P9
        },

        .moves = {
            {P3, P5},
            {P3, P6},
        }
    },

    { // box b29s
        .howmany = 2,
        .board = {
            P1, P2, NN,
            P5, P7, NN
        },

        .moves = {
            {P1, P4},
            {P1, P5},
        }
    },

    { // box b2A
        .howmany = 2,
        .board = {
            NN, P2, P3,
            P7, P5, NN
        },

        .moves = {
            {P3, P5},
            {P3, P6}
        }
    },

    { // box b2As
        .howmany = 2,
        .board = {
            P1, P2, NN,
            NN, P5, P9
        },

        .moves = {
            {P1, P4},
            {P1, P5}
        }
    },

    { // box b2B
        .howmany = 1,
        .board = {
            P1, NN, P3,
            NN, P4, P9
        },

        .moves = {
            {P3, P6}
        }
    },

    { // box b2Bs
        .howmany = 1,
        .board = {
            P1, NN, P3,
            P6, P7, NN
        },

        .moves = {
            {P1, P4}
        }
    },

    { // box b31
        .howmany = 2,
        .board = {
            P4, P5, P3,
            NN, NN, P6
        },

        .moves = {
            {P4, P7},
            {P5, P8}
        }
    },

    { // box b31s
        .howmany = 2,
        .board = {
            P1, P5, P6,
            P4, NN, NN
        },

        .moves = {
            {P5, P8},
            {P6, P9}
        }
    },

    { // box b32
        .howmany = 1,
        .board = {
            P1, NN, NN,
            P4, P5, P6
        },

        .moves = {
            {P1, P5}
        }
    },

    { // box b32s
        .howmany = 1,
        .board = {
            NN, P3, NN,
            P4, P5, P6
        },

        .moves = {
            {P3, P5}
        }
    },

    { // box b33
        .howmany = 2,
        .board = {
            P4, P2, NN,
            NN, P5, P6
        },

        .moves = {
            {P2, P6},
            {P4, P7}
        }
    },

    { // box b34
        .howmany = 2,
        .board = {
            NN, P2, P6,
            P4, P5, NN
        },

        .moves = {
            {P2, P4},
            {P6, P9}
        }
    },

    { // box b35
        .howmany = 2,
        .board = {
            P1, P4, P5,
            NN, NN, P6
        },

        .moves = {
            {P4, P7},
            {P5, P8}
        }
    },

    { // box b36
        .howmany = 2,
        .board = {
            P5, P6, P3,
            P4, NN, NN
        },

        .moves = {
            {P5, P8},
            {P6, P9}
        }
    },

    { // box b37
        .howmany = 3,
        .board = {
            NN, P4, P3,
            NN, NN, P5
        },

        .moves = {
            {P4, P7},
            {P3, P5},
            {P3, P6}
        }
    },

    { // box b37s
        .howmany = 3,
        .board = {
            P1, NN, P6,
            NN, P5, NN
        },

        .moves = {
            {P1, P4},
            {P1, P5},
            {P6, P9}
        }
    },

    { // box b38
        .howmany = 2,
        .board = {
            NN, P2, P5,
            P4, NN, NN
        },

        .moves = {
            {P2, P6},
            {P5, P8}
        }
    },

    { // box b39
        .howmany = 2,
        .board = {
            NN, P2, P5,
            NN, P6, NN
        },

        .moves = {
            {P2, P6},
            {P5, P8}
        }
    },

    { // box b3A
        .howmany = 2,
        .board = {
            P1, P4, NN,
            NN, P5, NN
        },

        .moves = {
            {P1, P5},
            {P4, P7}
        }
    },

    { // box b3B
        .howmany = 2,
        .board = {
            P3, NN, P6,
            NN, P5, NN
        },

        .moves = {
            {P3, P5},
            {P6, P9}
        }
    }
};


int fileExist() {
    if( access( "./data.db", F_OK ) == 0 ) {
        // file exists
        return 1;
    } else {
        // file doesn't exist
        return 0;
    }
}

void writeFile(char scrivi[], size_t size)
{
        FILE *fp;
        fp = fopen("data.db", "ab");
                
        fwrite(scrivi, size, 1, fp);
        fclose(fp);
}

void readFile()
{
    if(fileExist())
    {
        FILE *fp;
        fp = fopen("data.db", "rb");

        for(int i = 0; i < sizeof(boxArr)/sizeof(boxArr[0]); ++i)
        {
            fread(boxArr[i].active, sizeof(boxArr[i].active), 1, fp);
        }
        fclose(fp);
    }
    else
    {
        char arrInit[] = {1, 1, 1, 1};
        for(int i = 0; i < sizeof(boxArr)/sizeof(boxArr[0]); ++i)
        {
            writeFile(arrInit, sizeof(arrInit));
        }
        readFile();
    }
}
