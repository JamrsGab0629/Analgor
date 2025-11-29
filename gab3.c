#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101       
#define IP_LENGTH 16         


typedef struct Node {
    char ip[IP_LENGTH];
    struct Node *next;
} Node;


Node *hash_table[TABLE_SIZE];


unsigned int hash(char *ip) {
    unsigned int hash = 5381;
    while (*ip) {
        hash = ((hash << 5) + hash) + *ip++; // hash * 33 + c
    }
    return hash % TABLE_SIZE;
}


int insert_ip(char *ip) {
    unsigned int index = hash(ip);
    Node *current = hash_table[index];

    while (current) {
        if (strcmp(current->ip, ip) == 0) {
            return 0; // IP already exists
        }
        current = current->next;
    }

    
    Node *new_node = malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(new_node->ip, ip);
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
    return 1; // New unique IP
}


void free_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = hash_table[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    FILE *file = fopen("server_log.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    char date[20], time[20], ip[IP_LENGTH], method[10], url[100], status[5], protocol[10];
    int unique_count = 0;

    while (fgets(line, sizeof(line), file)) {
        // Parse all fields from the log line
        if (sscanf(line, "%19s %19s %15s %9s %99s %4s %9s",
                   date, time, ip, method, url, status, protocol) == 7) {
            // Debug print (optional)
            printf("Date: %s, Time: %s, IP: %s, Method: %s, URL: %s, Status: %s, Protocol: %s\n",
                   date, time, ip, method, url, status, protocol);

            // Count unique IPs
            if (insert_ip(ip)) {
                unique_count++;
            }
        }
    }

    fclose(file);
    printf("\nUnique visitors: %d\n", unique_count);

    free_table(); // Clean up
    return 0;
}
