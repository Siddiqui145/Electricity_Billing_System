#include <stdio.h>

void showPreviousRecords() {
    FILE *file;
    char ch;

    file = fopen("electricity_bill.txt", "r");

    if (file == NULL) {
        printf("No previous records found.\n");
        return;
    }

    printf("\nPrevious Records:\n");

    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

int main() {
    int units = 0;
    int choice;
    float total_bill = 0;
    int valid_calculation = 0; // Flag to track valid calculations
    
    while (1) {
        printf("\n\n WELCOME TO ELECTRICITY BILL COUNTER (Rates/Unit)\n\n");

        printf("1. Calculate Bill\n");
        printf("2. Show Previous Records\n");
        printf("3. Exit\n");

        printf("\nPlease Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Print the choice table in a table format
                printf("\n\n| %-2s | %-20s | %-12s |\n", "Choice", "Units Range", "Rate/Unit");
                printf("|------|----------------------|-------------|\n");
                printf("| %-2d | %-20s | %-12s |\n", 1, "Upto 20 Units", "3/Unit");
                printf("| %-2d | %-20s | %-12s |\n", 2, "21 To 30 Units", "7/Unit");
                printf("| %-2d | %-20s | %-12s |\n", 3, "31 To 50 Units", "8/Unit");
                printf("| %-2d | %-20s | %-12s |\n", 4, "51 To 150 Units", "10/Unit");
                printf("| %-2d | %-20s | %-12s |\n", 5, "151 To 250 Units", "12/Unit");
                printf("| %-2d | %-20s | %-12s |\n", 6, "251 To 400 Units", "14/Unit");
                printf("| %-2d | %-20s | %-12s |\n", 7, "400+ Units", "15/Unit");

                printf("\nPlease Select your Units Range: ");
                scanf("%d", &choice);

                if (choice >= 1 && choice <= 7) {
                    printf("\nEnter your units consumed: ");
                    scanf("%d", &units);

                    if (units >= 1) {
                        // Calculation logic for different rate categories
                        switch (choice) {
                            case 1:
                                if (units > 0 && units <= 20) {
                                    total_bill = units * 3;
                                    valid_calculation = 1; // Set flag for valid calculation
                                } else {
                                    printf("Invalid range selected for units.\n");
                                }
                                break;
                            case 2:
                                if (units > 20 && units <= 30) {
                                    total_bill = units * 7;
                                    valid_calculation = 1; // Set flag for valid calculation
                                } else {
                                    printf("Invalid range selected for units.\n");
                                }
                                break;
                            case 3:
                                if (units > 30 && units <= 50) {
                                    total_bill = units * 8;
                                    valid_calculation = 1; // Set flag for valid calculation
                                } else {
                                    printf("Invalid range selected for units.\n");
                                }
                                break;
                            case 4:
                                if (units > 50 && units <= 150) {
                                    total_bill = units * 10;
                                    valid_calculation = 1; // Set flag for valid calculation
                                } else {
                                    printf("Invalid range selected for units.\n");
                                }
                                break;
                            case 5:
                                if (units > 150 && units <= 250) {
                                    total_bill = units * 12;
                                    valid_calculation = 1; // Set flag for valid calculation
                                } else {
                                    printf("Invalid range selected for units.\n");
                                }
                                break;
                            case 6:
                                if (units > 250 && units <= 400) {
                                    total_bill = units * 14;
                                    valid_calculation = 1; // Set flag for valid calculation
                                } else {
                                    printf("Invalid range selected for units.\n");
                                }
                                break;
                            case 7:
                                if (units > 400) {
                                    total_bill = units * 15;
                                    valid_calculation = 1; // Set flag for valid calculation
                                } else {
                                    printf("Invalid range selected for units.\n");
                                }
                                break;
                            default:
                                printf("Invalid choice.\n");
                        }

                        if (valid_calculation) {
                            printf("Your Total Bill As Calculated is: %.2f\n", total_bill);
                            
                            // Save the calculation to a file
                            FILE *file = fopen("electricity_bill.txt", "a");
                            if (file != NULL) {
                                fprintf(file, "Choice: %d\nUnits Consumed: %d\nTotal Bill: %.2f\n\n", choice, units, total_bill);
                                fclose(file);
                            } else {
                                printf("Error saving the calculation to the file.\n");
                            }

                            valid_calculation = 0; // Reset the flag
                        }
                    } else {
                        printf("Invalid input for units.\n");
                    }
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            case 2:
                showPreviousRecords();
                break;
            case 3:
                printf("System Terminated\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

