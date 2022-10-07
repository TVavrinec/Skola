
#define NUM_LENGTH 4

/** Priklad 1A **/
#define AX 12

/** Priklad 1B **/
#define BX 5
#define BY 5
#define BZ 5

/** Priklad 1C **/
#define CX 4
#define CY 3

/** Bonusová Uloha **/
#define BU_POINT 8
#define BU_DIMENSION 2

struct point
{
    float coordinate[BU_DIMENSION];
};


int getFibonacciNum(int number);

int getDistance(struct point point_A,struct point point_B);

void printfVector(struct point point);