#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
  int id;
  char name[50]; // Adjust size based on your name length requirement
  int scores[3];
} Student;

typedef struct Node {
  Student data;
  struct Node* next;
} Node;

// Function prototypes
Node* create_node(Student student);
void insert_at_end(Node** head, Student student);
void print_list(Node* head);

int main() {
  Node* head = NULL;

  // Example student data
  Student student1 = {1, "Alice", {80, 90, 75}};
  Student student2 = {2, "Bob", {95, 85, 88}};

  // Insert students at the end of the list
  insert_at_end(&head, student1);
  insert_at_end(&head, student2);

  // Print the student list
  print_list(head);

  return 0;
}

// Create a new node with the given student data
Node* create_node(Student student) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->data = student;
  new_node->next = NULL;
  return new_node;
}

// Insert a new node at the end of the linked list
void insert_at_end(Node** head, Student student) {
  Node* new_node = create_node(student);
  if (*head == NULL) {
    *head = new_node;
    return;
  }

  Node* last = *head;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = new_node;
}

// Print the information of each student in the list
void print_list(Node* head) {
  Node* current = head;
  while (current != NULL) {
    printf("ID: %d\n", current->data.id);
    printf("Name: %s\n", current->data.name);
    printf("Scores: %d %d %d\n", current->data.scores[0], current->data.scores[1], current->data.scores[2]);
    printf("\n");
    current = current->next;
  }
}
