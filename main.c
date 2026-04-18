/*
Name: JUUKO MORRIS
Registration Number: 25/U/BIE/01375/PE
*/

#include <stdio.h>
#include <stdlib.h>

// Function to get Grade Point based on score
int getGradePoint(float score) {
    if (score >= 80) return 5;
    if (score >= 70) return 4;
    if (score >= 60) return 3;
    if (score >= 50) return 2;
    return 0;
}

// Function to get Grade Letter based on score
char getGradeLetter(float score) {
    if (score >= 80) return 'A';
    if (score >= 70) return 'B';
    if (score >= 60) return 'C';
    if (score >= 50) return 'D';
    return 'F';
}

int main() {
    // Course  structures
    char *sem1_codes[] = {"TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104", "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108"};
    int sem1_credits[] = {4, 3, 3, 3, 3, 3, 2, 3};
    float sem1_scores[8];

    char *sem2_codes[] = {"TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204", "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208"};
    int sem2_credits[] = {4, 3, 3, 3, 3, 3, 3, 3};
    float sem2_scores[8];

    float sem1_weighted_sum = 0, sem2_weighted_sum = 0;
    int sem1_total_credits = 0, sem2_total_credits = 0;

    //  Semester I Scores
    for (int i = 0; i < 8; i++) {
        printf("Enter score for %s: ", sem1_codes[i]);
        if (scanf("%f", &sem1_scores[i]) != 1 || sem1_scores[i] < 0 || sem1_scores[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
    }

    //  Semester II Scores
    for (int i = 0; i < 8; i++) {
        printf("Enter score for %s: ", sem2_codes[i]);
        if (scanf("%f", &sem2_scores[i]) != 1 || sem2_scores[i] < 0 || sem2_scores[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
    }

    printf("\n--- FULL ACADEMIC REPORT ---\n");
    printf("%-10s | %-5s | %-5s | %-5s | %-5s | %-5s\n", "Code", "Score", "Grade", "GP", "CU", "Weighted");
    
    //  Semester I Weights
    for (int i = 0; i < 8; i++) {
        int gp = getGradePoint(sem1_scores[i]);
        float weighted = gp * sem1_credits[i];
        sem1_weighted_sum += weighted;
        sem1_total_credits += sem1_credits[i];
        printf("%-10s | %-5.1f | %-5c | %-5d | %-5d | %-5.1f\n", sem1_codes[i], sem1_scores[i], getGradeLetter(sem1_scores[i]), gp, sem1_credits[i], weighted);
    }

    //  Semester II  Weights
    for (int i = 0; i < 8; i++) {
        int gp = getGradePoint(sem2_scores[i]);
        float weighted = gp * sem2_credits[i];
        sem2_weighted_sum += weighted;
        sem2_total_credits += sem2_credits[i];
        printf("%-10s | %-5.1f | %-5c | %-5d | %-5d | %-5.1f\n", sem2_codes[i], sem2_scores[i], getGradeLetter(sem2_scores[i]), gp, sem2_credits[i], weighted);
    }

    // Calculations
    float sem1_gpa = sem1_weighted_sum / sem1_total_credits;
    float sem2_gpa = sem2_weighted_sum / sem2_total_credits;
    float cgpa = (sem1_weighted_sum + sem2_weighted_sum) / (sem1_total_credits + sem2_total_credits);

    char *classification;
    if (cgpa >= 4.40) classification = "First Class";
    else if (cgpa >= 3.60) classification = "Second Class Upper";
    else if (cgpa >= 2.80) classification = "Second Class Lower";
    else if (cgpa >= 2.00) classification = "Pass";
    else classification = "Fail";

    // Required academic report
    printf("\nSemester I GPA: %.2f\n", sem1_gpa);
    printf("Semester II GPA: %.2f\n", sem2_gpa);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", classification);

    return 0;
}
