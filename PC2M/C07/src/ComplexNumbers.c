#include "ComplexNumbers.h"

struct Complex_num_t complexSum(struct Complex_num_t a, struct Complex_num_t b)
{
    struct Complex_num_t x;
    x.Re = a.Re + b.Re;
    x.Im = a.Im + b.Im;
    return x;
}

struct Complex_num_t complexDifference(struct Complex_num_t a, struct Complex_num_t b)
{
    struct Complex_num_t x;
    x.Re = a.Re - b.Re;
    x.Im = a.Im - b.Im;
    return x;
}

struct Complex_num_t complexMultiple(struct Complex_num_t a, struct Complex_num_t b)
{
    struct Complex_num_t x;
    x.Re = (a.Re*b.Re)-(a.Im*b.Im);
    x.Im = (a.Im*b.Re)+(a.Re*b.Im);
    return x;
}

struct Complex_num_t complexShare(struct Complex_num_t a, struct Complex_num_t b)
{
    struct Complex_num_t x;
    x.Re = ((a.Re*b.Re)+(a.Im*b.Im))/(a.Im*a.Im+b.Re*b.Re);
    x.Im = ((a.Re*b.Im)-(a.Im*b.Re))/(a.Im*a.Im+b.Re*b.Re);
    return x;
}