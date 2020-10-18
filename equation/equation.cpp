#include <stdio.h>
#include <math.h>
#include <assert.h>

#define INF_ROOTS_CASE -1
#define NO_SOLUTION 0
#define LINEAR_ONE_SOLUTION 1
#define TWO_SIMILAR_SOLUTIONS 11
#define TWO_SOLUTIONS 2

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
            return (coef_c != 0)? NO_SOLUTION : INF_ROOTS_CASE;
            }

        else // b != 0
            {
            *root1 = -coef_c / coef_b;
            return LINEAR_ONE_SOLUTION; //equation is linear - has the only root
            }
        }
    else // a != 0
        {
        double discriminant = coef_b * coef_b - 4 * coef_a * coef_c;

        if (discriminant < 0)
            {
            return NO_SOLUTION; //equation has no roots
            }

        else
            {
            if (discriminant == 0)
                {
                *root1 = - coef_b / (2 * coef_a);
                *root2 = *root1;
                return TWO_SIMILAR_SOLUTIONS;
                }
            else
                {
                *root1 = (-coef_b + sqrt(discriminant)) / (2 * coef_a);
                *root2 = (-coef_b - sqrt(discriminant)) / (2 * coef_a);
                return  TWO_SOLUTIONS;
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
        case NO_SOLUTION: printf ("The equation has no roots");
                break;

        case LINEAR_ONE_SOLUTION: printf ("The equation is linear - the only root is %lg", root1);
                break;

        case TWO_SIMILAR_SOLUTIONS: printf ("There are two equal roots of the equation: %lg", root1);
                break;

        case TWO_SOLUTIONS: printf ("The first root is  %lg\n", root1);
                printf ("The second root is %lg", root2);
                break;

        case INF_ROOTS_CASE: printf ("The equation has infinite number of roots");
                             break;

        default: printf ("ERROR HAS OCCURRED: number of roots is %d", num_of_roots);
                 return 1;
        }

    return 0;
    }
