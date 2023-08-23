#include <stdio.h>
#include "header.h"

ioerror InputCoefsSTD(Coefs *coefs_p)
    {
    assert (coefs_p != NULL);

    printf("# Square equation solver\n\n"); /* Описание программы */

    printf("# Enter a, b, c: "); /* Понятный для пользователя ввод */
    if (scanf("%lg %lg %lg",
        &coefs_p->a, &coefs_p->b, &coefs_p->c) != 3)
        {
        printf("Ошибка ввода\n");
        return ERROR;
        }
    return OK;
    }

ioerror OutputCoefsSTD(const int nRoots, Roots *roots_p)
    {
    assert (isfinite(nRoots));
    assert (roots_p != NULL);

    switch (nRoots)
        {
        case ZERO_ROOTS:
                printf("No roots\n");
                break;
        case ONE_ROOT:
                printf("x = %.3lg\n", (*roots_p).x1);
                break;
        case TWO_ROOTS:
                printf("x1 = %.3lg, x2 = %.3lg\n",
                        (*roots_p).x1, (*roots_p).x2);
                break;
        case INF_ROOTS:
                printf("Any number\n");
                break;
        default:
                printf("main(): Error: nRoots = %d", nRoots);
                return ERROR;
        }

    return OK;
    }
