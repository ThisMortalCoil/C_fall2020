#include <stdio.h>
#include <math.h>
#include <assert.h>

#define INF_ROOTS_CASE -1


int quadratic_equation(double coef_a, double coef_b, double coef_c, double* root1, double* root2)
    {

    assert (std::isfinite (coef_a));
    assert (std::isfinite (coef_b));
    assert (std::isfinite (coef_c));

    assert (root1 != root2);
    assert (root1 != NULL);
    assert (root2 != NULL);

    if (coef_a == 0)
        {
        if (coef_b == 0)
            {
            return (coef_c != 0)? 0 : INF_ROOTS_CASE;
            }

        else // b != 0
            {
            *root1 = -coef_c / coef_b;
            return 1; //
            }
        }
    else // a != 0
        {
        double discriminant = coef_b * coef_b - 4 * coef_a * coef_c;

        if (discriminant < 0)
            {
            return 0;
            }

        else
            {
            if (discriminant == 0)
                {
                *root1 = - coef_b / (2 * coef_a);
                *root2 = *root1;
                return 2;
                }
            else
                {
                *root1 = (-coef_b + sqrt(discriminant)) / (2 * coef_a);
                *root2 = (-coef_b - sqrt(discriminant)) / (2 * coef_a);
                return  3;
                }
            }
        }
    }

int main()
    {
    printf ("You are running quadratic equation solver.\n"
            "Please enter the values of the coefficients a, b, c of the ax2 + bx + c = 0\n");

    double a = 0, b = 0, c = 0;
    scanf ("%lg %lg %lg", &a, &b, &c);

    double root1 = 0, root2 = 0;
    int num_of_roots = quadratic_equation(a, b, c, &root1, &root2);

    switch (num_of_roots)
        {
        case 0: printf ("The equation has no roots");
                break;

        case 1: printf ("The equation is linear - the only root is %lg", root1);
                break;

        case 2: printf ("There are two equal roots of the equation: %lg", root1);
                break;

        case 3: printf ("The first root is  %lg\n", root1);
                printf ("The second root is %lg", root2);
                break;

        case INF_ROOTS_CASE: printf ("The equation has infinite number of roots");
                             break;

        default: printf ("ERROR HAS OCCURRED: number of roots is %d", num_of_roots);
                 return 1;
        }

    return 0;
    }
