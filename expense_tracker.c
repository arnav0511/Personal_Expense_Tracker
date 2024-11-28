#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

// Structure to store an expense
typedef struct {
    char date[11];
    char category[20];
    float amount;
    char description[50];
} Expense;

// Global variables
Expense expenses[MAX_EXPENSES];
int expenseCount = 0;
float monthlyBudget = 0.0;

// Function to add a divider in the output
void addDivider() {
    printf("\n----------------------------------------\n");
}

// Function to add a new expense
void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Cannot add more expenses. Maximum limit reached.\n");
        return;
    }

    Expense e;
    printf("Enter date (DD-MM-YYYY): ");
    scanf("%s", e.date);
    printf("Enter category (e.g., Food, Transport, Bills): ");
    scanf("%s", e.category);
    printf("Enter amount: ");
    scanf("%f", &e.amount);
    getchar();
    printf("Enter description: ");
    fgets(e.description, sizeof(e.description), stdin);
    e.description[strcspn(e.description, "\n")] = 0;

    expenses[expenseCount++] = e;
    printf("Expense added successfully!\n");
}

// Function to view all expenses
void viewExpenses() {
    if (expenseCount == 0) {
        printf("No expenses to display.\n");
        return;
    }

    addDivider();
    printf("--- All Expenses ---\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("[%d] Date: %s | Category: %s | Amount: %.2f | Description: %s\n",
               i + 1, expenses[i].date, expenses[i].category, expenses[i].amount, expenses[i].description);
    }
    addDivider();
}

// Function to delete an expense by index
void deleteExpense() {
    if (expenseCount == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    viewExpenses();
    int index;
    printf("Enter the expense number to delete (1-%d): ", expenseCount);
    scanf("%d", &index);

    if (index < 1 || index > expenseCount) {
        printf("Invalid expense number.\n");
        return;
    }

    for (int i = index - 1; i < expenseCount - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expenseCount--;

    printf("Expense deleted successfully!\n");
}

// Function to save expenses and budget to a file
void saveDataToFile() {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Failed to open file.\n");
        return;
    }

    fprintf(file, "BUDGET %.2f\n", monthlyBudget);
    for (int i = 0; i < expenseCount; i++) {
        fprintf(file, "%s %s %.2f %s\n", expenses[i].date, expenses[i].category, expenses[i].amount, expenses[i].description);
    }

    fclose(file);
    printf("Data saved to file successfully.\n");
}

// Function to load expenses and budget from a file
void loadDataFromFile() {
    FILE *file = fopen("expenses.txt", "r");
    if (!file) {
        printf("No saved data found.\n");
        return;
    }

    char line[100];
    if (fscanf(file, "BUDGET %f\n", &monthlyBudget) != 1) {
        monthlyBudget = 0.0;
    }

    expenseCount = 0;
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %s %f %[^\n]", expenses[expenseCount].date, expenses[expenseCount].category,
               &expenses[expenseCount].amount, expenses[expenseCount].description);
        expenseCount++;
    }

    fclose(file);
    printf("Data loaded from file successfully.\n");
}

// Function to set the monthly budget
void setMonthlyBudget() {
    printf("Enter your monthly budget: ");
    scanf("%f", &monthlyBudget);
    printf("Monthly budget set to %.2f\n", monthlyBudget);
}

// Function to display monthly summary and check budget status
void monthlySummary() {
    if (expenseCount == 0) {
        printf("No expenses to summarize.\n");
        return;
    }

    char monthYear[13][10];
    float monthlyTotals[13] = {0.0};
    int uniqueMonths = 0;

    for (int i = 0; i < expenseCount; i++) {
        char monthYearStr[8];
        strncpy(monthYearStr, expenses[i].date + 3, 7);
        monthYearStr[7] = '\0';

        int found = -1;
        for (int j = 0; j < uniqueMonths; j++) {
            if (strcmp(monthYear[j], monthYearStr) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            strcpy(monthYear[uniqueMonths], monthYearStr);
            monthlyTotals[uniqueMonths] = expenses[i].amount;
            uniqueMonths++;
        } else {
            monthlyTotals[found] += expenses[i].amount;
        }
    }

    // Sort by month and year (Latest to Earliest)
    for (int i = 0; i < uniqueMonths - 1; i++) {
        for (int j = i + 1; j < uniqueMonths; j++) {
            int monthI, yearI, monthJ, yearJ;
            sscanf(monthYear[i], "%2d-%4d", &monthI, &yearI);
            sscanf(monthYear[j], "%2d-%4d", &monthJ, &yearJ);

            if (yearI < yearJ || (yearI == yearJ && monthI < monthJ)) {
                char tempMonthYear[10];
                strcpy(tempMonthYear, monthYear[i]);
                strcpy(monthYear[i], monthYear[j]);
                strcpy(monthYear[j], tempMonthYear);

                float tempTotal = monthlyTotals[i];
                monthlyTotals[i] = monthlyTotals[j];
                monthlyTotals[j] = tempTotal;
            }
        }
    }

    addDivider();
    printf("--- Monthly Summary (Latest to Earliest) ---\n");
    for (int i = 0; i < uniqueMonths; i++) {
        printf("Month-Year: %s | Total Expenses: %.2f", monthYear[i], monthlyTotals[i]);
        if (monthlyBudget > 0 && monthlyTotals[i] > monthlyBudget) {
            printf(" | Budget Exceeded!");
        }
        printf("\n");
    }
    addDivider();
}

// Function to calculate and display statistics and insights
void displayStatistics() {
    if (expenseCount == 0) {
        printf("No expenses recorded for statistics.\n");
        return;
    }

    float totalExpense = 0.0, highestExpense = 0.0, lowestExpense = expenses[0].amount;
    char highestCategory[20], lowestCategory[20];
    int uniqueCategories = 0;
    float categoryTotals[MAX_EXPENSES] = {0.0};
    char categories[MAX_EXPENSES][20];

    // Calculate total, highest, and lowest expenses
    for (int i = 0; i < expenseCount; i++) {
        totalExpense += expenses[i].amount;
        if (expenses[i].amount > highestExpense) {
            highestExpense = expenses[i].amount;
            strcpy(highestCategory, expenses[i].category);
        }
        if (expenses[i].amount < lowestExpense) {
            lowestExpense = expenses[i].amount;
            strcpy(lowestCategory, expenses[i].category);
        }

        // Calculate category-wise totals
        int found = -1;
        for (int j = 0; j < uniqueCategories; j++) {
            if (strcmp(categories[j], expenses[i].category) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            strcpy(categories[uniqueCategories], expenses[i].category);
            categoryTotals[uniqueCategories] = expenses[i].amount;
            uniqueCategories++;
        } else {
            categoryTotals[found] += expenses[i].amount;
        }
    }

    addDivider();
    printf("--- Statistics & Insights ---\n");
    printf("Total Expenses: %.2f\n", totalExpense);
    printf("Average Expense Per Month: %.2f\n", totalExpense / uniqueCategories);
    printf("Highest Expense: %.2f in %s\n", highestExpense, highestCategory);
    printf("Lowest Expense: %.2f in %s\n", lowestExpense, lowestCategory);
    printf("--- Category-Wise Summary ---\n");
    for (int i = 0; i < uniqueCategories; i++) {
        printf("%s: %.2f\n", categories[i], categoryTotals[i]);
    }
    addDivider();
}

// Main function - menu loop
int main() {
    int choice;
    loadDataFromFile();

    while (1) {
        printf("\nPersonal Expense Tracker\n");
        printf("1. Set Monthly Budget\n");
        printf("2. Add Expense\n");
        printf("3. View Expenses\n");
        printf("4. Delete Expense\n");
        printf("5. Monthly Summary\n");
        printf("6. Statistics\n");
        printf("7. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                setMonthlyBudget();
                break;
            case 2:
                addExpense();
                break;
            case 3:
                viewExpenses();
                break;
            case 4:
                deleteExpense();
                break;
            case 5:
                monthlySummary();
                break;
            case 6:
                displayStatistics();
                break;
            case 7:
                saveDataToFile();
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
