#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

// Structure to represent an expense
struct Expense {
    char description[50];
    double amount;
};

// Function to add an expense
void addExpense(struct Expense expenses[], int *numExpenses) {
    if (*numExpenses < MAX_EXPENSES) {
        struct Expense newExpense;
        printf("Enter expense description: ");
        scanf("%s", newExpense.description);
        printf("Enter expense amount: ");
        scanf("%lf", &newExpense.amount);
        expenses[*numExpenses] = newExpense;
        (*numExpenses)++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense tracker is full. Cannot add more expenses.\n");
    }
}

// Function to view all expenses
void viewExpenses(struct Expense expenses[], int numExpenses) {
    if (numExpenses == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("Expense List:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: %.2lf\n", expenses[i].amount);
        printf("\n");
    }
}

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    int choice;

    while (1) {
        printf("Expense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                viewExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Exiting Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
