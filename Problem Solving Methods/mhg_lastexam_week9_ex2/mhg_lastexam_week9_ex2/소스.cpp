#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
struct CAR
{
    char name[20];
    int year;
    double price;
};

bool write_file(const char* file_name, struct CAR* car)
{
    FILE* file = NULL;
    file = fopen(file_name, "w");
    if (file == NULL)
    {
        printf("Could not open file!!");
        return false;
    }

    int i = 0;

    fprintf(file, "---------------------------------\n");
    fprintf(file, "|Name    |Year    |Price        |\n");
    fprintf(file, "---------------------------------\n");

    while (1)
    {
        if (i == 4)
            break;
        else
        {
            fprintf(file, "|%-8s|%-8d|%-13lf|\n", car[i].name, car[i].year, car[i].price);
        }
        i++;
    }
    fprintf(file, "---------------------------------\n");

    fclose(file);
    return true;
}

bool read_file(const char* file_name)
{
    FILE* file = NULL;
    file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Could not open file!!");
        return false;
    }

    char temp[50];
    while (fgets(temp, sizeof(temp), file) != NULL)
        fprintf(stdout, "%s", temp);

    fclose(file);
    return true;
}

int main()
{
    struct CAR car[4];

    car[0] = { "Avante", 2007, 13000.00 };
    car[1] = { "Sonata", 2008, 18000.00 };
    car[2] = { "SM7", 2009, 22000.00 };
    car[3] = { "Equus", 2010, 35000.00 };

    if (!write_file("cars.txt", car))
        return -1;
    if (read_file("cars.txt"))
        return -1;
    return 0;
}