/*
Name: JUUKO MORRIS
Registration Number: 25/U/BIE/01375/PE
*/

#include <stdio.h>

int main() {
    int scores[16];
    int gradePoints[16];
    
    // Credit Units for Semester I (TEMB 1101 - 1108)
    int cu1[] = {4, 3, 3, 3, 3, 3, 2, 3};
    // Credit Units for Semester II (TEMB 1201 - 1208)
    int cu2[] = {4, 3, 3, 3, 3, 3, 3, 3};

    float totalWeightedGP1 = 0, totalCU1 = 0;
    float totalWeightedGP2 = 0, totalCU2 = 0;

    // Read all 16 scores
    for (int i = 0; i < 16; i++) {
        if (scanf("%d", &scores[i]) != 1) return 0;

        // Invalid Input Rule
        if (scores[i] < 0 || scores[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }

        // Determine Grade Point based on Scale
        int gp;
        if (scores[i] >= 80) gp = 5;
        else if (scores[i] >= 70) gp = 4;
        else if (scores[i] >= 60) gp = 3;
        else if (scores[i] >= 50) gp = 2;
        else gp = 0;

        // Calculate weighted totals based on semester
        if (i < 8) { // Semester I
            totalWeightedGP1 += (gp * cu1[i]);
            totalCU1 += cu1[i];
        } else { // Semester II
            totalWeightedGP2 += (gp * cu2[i - 8]);
            totalCU2 += cu2[i - 8];
        }
    }

    // Calculations
    float gpa1 = totalWeightedGP1 / totalCU1;
    float gpa2 = totalWeightedGP2 / totalCU2;
    float cgpa = (totalWeightedGP1 + totalWeightedGP2) / (totalCU1 + totalCU2);

    // Required Output Format
    printf("Semester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);

    // Classification Logic
    printf("Classification: ");
    if (cgpa >= 4.40) printf("First Class\n");
    else if (cgpa >= 3.60) printf("Second Class Upper\n");
    else if (cgpa >= 2.80) printf("Second Class Lower\n");
    else if (cgpa >= 2.00) printf("Pass\n");
    else printf("Fail\n");

    return 0;
}
