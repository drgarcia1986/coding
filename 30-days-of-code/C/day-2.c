#include <stdio.h>

int main() {
    double meal_cost = 12.00;
    int tip_percent = 20;
    int tax_percent = 8;

    double tip_value = meal_cost * ((float)tip_percent / 100);
    double tax_value = meal_cost * ((float)tax_percent / 100);
    double total = meal_cost + tip_value + tax_value;

    printf("The total meal cost is %.0f dollars.", total);

    return 0;
}
