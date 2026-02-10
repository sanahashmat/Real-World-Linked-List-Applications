#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
struct Node {
    int coeff;          // coefficient of the term
    int power;          // power (exponent) of the term
    struct Node* next;  // pointer to the next node
};

// Function to create a new node
struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

// Function to add a term to a polynomial (sorted insertion is better for addition)
struct Node* addTerm(struct Node* head, int coeff, int power) {
    struct Node* newNode = createNode(coeff, power);
    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp = NULL; // temporary pointer for the result list

    // Iterate through both polynomials while they have terms
    while (poly1 != NULL && poly2 != NULL) {
        // Case 1: poly1's power is greater
        if (poly1->power > poly2->power) {
            if (result == NULL) {
                result = temp = createNode(poly1->coeff, poly1->power);
            } else {
                temp->next = createNode(poly1->coeff, poly1->power);
                temp = temp->next;
            }
            poly1 = poly1->next;
        }
        // Case 2: poly2's power is greater
        else if (poly2->power > poly1->power) {
            if (result == NULL) {
                result = temp = createNode(poly2->coeff, poly2->power);
            } else {
                temp->next = createNode(poly2->coeff, poly2->power);
                temp = temp->next;
            }
            poly2 = poly2->next;
        }
        // Case 3: Powers are equal, add coefficients
        else {
            int sum_coeff = poly1->coeff + poly2->coeff;
            if (sum_coeff != 0) {
                if (result == NULL) {
                    result = temp = createNode(sum_coeff, poly1->power);
                } else {
                    temp->next = createNode(sum_coeff, poly1->power);
                    temp = temp->next;
                }
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms of poly1
    while (poly1 != NULL) {
        if (result == NULL) {
            result = temp = createNode(poly1->coeff, poly1->power);
        } else {
            temp->next = createNode(poly1->coeff, poly1->power);
            temp = temp->next;
        }
        poly1 = poly1->next;
    }

    // Add remaining terms of poly2
    while (poly2 != NULL) {
        if (result == NULL) {
            result = temp = createNode(poly2->coeff, poly2->power);
        } else {
            temp->next = createNode(poly2->coeff, poly2->power);
            temp = temp->next;
        }
        poly2 = poly2->next;
    }

    return result;
}

// Function to display the polynomial
void displayPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->power);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Driver program
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

    // Create first polynomial: 5x^2 + 4x^1 + 2x^0
    poly1 = addTerm(poly1, 5, 2);
    poly1 = addTerm(poly1, 4, 1);
    poly1 = addTerm(poly1, 2, 0);

    // Create second polynomial: -5x^2 + 2x^1 + -6x^0
    poly2 = addTerm(poly2, -5, 2);
    poly2 = addTerm(poly2, 2, 1);
    poly2 = addTerm(poly2, -6, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Add the two polynomials
    sum = addPolynomials(poly1, poly2);

    printf("Sum: ");
    displayPolynomial(sum);

    // Free the allocated memory (omitted for brevity, but good practice)
    
    return 0;
}
