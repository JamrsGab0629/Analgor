#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *val;

    struct Node *n;
    struct Node *p;
} Node;

int size = 0;
Node *head = NULL;
Node *tail = NULL;

Node* createNode(char *str){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL){
        return NULL;
    }

    newNode->val = (char *)malloc(sizeof(char) * (strlen(str) + 1));

    if (newNode->val == NULL){
        free(newNode);
        return NULL;
    }

    strcpy(newNode->val, str);
    newNode->n = NULL;
    newNode->p = NULL;

    return newNode;
}

int addIP(char *str){
    Node *newNode = createNode(str);

    if(newNode == NULL){
        free(newNode);
        return -1;
    }

    if(size == 0){
        head = newNode;
        tail = newNode;
    } else {
        tail->n = newNode;
        newNode->p = tail;
        tail = tail->n;
    }

    size++;
    return 0;
}

int checkIP(char *IP){
    Node *cur = head;

    while(cur != NULL){
        if(strcmp(cur->val, IP) == 0){
            return -1;
        }
    }

    free(cur);

    addIP(IP);
    return 0;
}

int readListH(){
    Node *cur = head;

    while(cur != NULL){
        printf("%s\n", cur->val);
        cur = cur->n;
    }

    return 0;
}

int readListT(){
    Node *cur = tail;

    while(cur != NULL){
        printf("%s\n", cur->val);
        cur = cur->p;
    }
}

int main(){
    FILE *file = fopen("filename");

    addIP("Hello");
    addIP("World");
    addIP("!");

    readListH();
    readListT();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101
#define IP_LENGTH 16

typedef struct Node
{
    char ip[IP_LENGTH];
    struct Node *next;
} Node;

Node *hash_table[TABLE_SIZE];

unsigned int hash(char *ip)
{
    unsigned int hash = 5381;
    while (*ip)
    {
        hash = ((hash << 5) + hash) + *ip++; // hash * 33 + c
    }
    return hash % TABLE_SIZE;
}

int insert_ip(char *ip)
{
    unsigned int index = hash(ip);
    Node *current = hash_table[index];

    while (current)
    {
        if (strcmp(current->ip, ip) == 0)
        {
            return 0; // IP already exists
        }
        current = current->next;
    }

    Node *new_node = malloc(sizeof(Node));
    if (!new_node)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(new_node->ip, ip);
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
    return 1; // New unique IP
}

void free_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node *current = hash_table[i];
        while (current)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main()
{
    FILE *file = fopen("http_logs.txt", "r");
    if (!file)
    {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    char date[20], time[20], ip[IP_LENGTH], method[10], url[100], status[5], protocol[10];
    int unique_count = 0;

    while (fgets(line, sizeof(line), file))
    {
        // Parse all fields from the log line
        if (sscanf(line, "%19s %19s %15s %9s %99s %4s %9s",
                   date, time, ip, method, url, status, protocol) == 7)
        {
            // Debug print (optional)
            // printf("Date: %s, Time: %s, IP: %s, Method: %s, URL: %s, Status: %s, Protocol: %s\n",
            //    date, time, ip, method, url, status, protocol);

            // Count unique IPs
            if (insert_ip(ip))
            {
                unique_count++;
            }
        }
    }

    fclose(file);
    printf("\nUnique visitors: %d\n", unique_count);

    free_table(); // Clean up
    return 0;
}
