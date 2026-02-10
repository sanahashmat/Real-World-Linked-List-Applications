#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum length for a URL
#define URL_MAX_LEN 100

// Structure for a webpage node
typedef struct WebPage {
    char url[URL_MAX_LEN];
    struct WebPage *next;
    struct WebPage *prev;
} WebPage;

// Global pointer to the current webpage node
WebPage *current = NULL;

// Function to create a new webpage node
WebPage* createPage(const char* url) {
    WebPage* newPage = (WebPage*)malloc(sizeof(WebPage));
    if (newPage == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strncpy(newPage->url, url, URL_MAX_LEN - 1);
    newPage->url[URL_MAX_LEN - 1] = '\0'; // Ensure null termination
    newPage->next = NULL;
    newPage->prev = NULL;
    return newPage;
}

// Function to visit a new URL
void visit(const char* url) {
    WebPage* newPage = createPage(url);
    if (current == NULL) {
        current = newPage;
    } else {
        // If visiting a new page, cut off any forward history
        WebPage* temp = current->next;
        while (temp != NULL) {
            WebPage* nextTemp = temp->next;
            free(temp);
            temp = nextTemp;
        }
        current->next = newPage;
        newPage->prev = current;
        current = newPage;
    }
    printf("Visited: %s\n", current->url);
}

// Function to go back in history
void goBack() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Moved back to: %s\n", current->url);
    } else {
        printf("Cannot go back. No previous history.\n");
    }
}

// Function to go forward in history
void goForward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Moved forward to: %s\n", current->url);
    } else {
        printf("Cannot go forward. No forward history.\n");
    }
}

// Function to display current URL and clean up memory (optional)
void displayCurrent() {
    if (current != NULL) {
        printf("Current URL: %s\n", current->url);
    } else {
        printf("No pages visited yet.\n");
    }
}

// Function to free all allocated memory
void freeHistory() {
    WebPage* temp = current;
    // Go to the start of the list
    while(temp != NULL && temp->prev != NULL) {
        temp = temp->prev;
    }
    // Free nodes from start to end
    while (temp != NULL) {
        WebPage* nextTemp = temp->next;
        free(temp);
        temp = nextTemp;
    }
    current = NULL;
}

int main() {
    visit("google.com");
    visit("github.com");
    visit("stackoverflow.com");

    goBack();
    goBack();
    goForward();

    visit("microsoft.com"); // Visiting a new page from the middle clears forward history

    goForward(); // This will not work as the history was cleared

    freeHistory(); // Clean up memory before exiting

    return 0;
}
