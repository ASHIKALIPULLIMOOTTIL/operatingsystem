#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 50  // Message size

// Define message structure
struct my_msg {
    long int msg_type;  // Priority of the message
    char some_text[MAX_TEXT];
};

int main() {
    int msgid;
    struct my_msg message;

    // Access the existing message queue
    msgid = msgget((key_t)12345, 0600 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        return EXIT_FAILURE;
    }

    printf("Waiting for messages...\n");

    // Receive messages based on priority (highest msg_type first)
    for (int i = 3; i >= 1; i--) {  // Reading in reverse order (highest priority first)
        if (msgrcv(msgid, (void *)&message, sizeof(message.some_text), i, 0) == -1) {
            perror("msgrcv");
            return EXIT_FAILURE;
        }
        printf("Received: %s (Priority %ld)\n", message.some_text, message.msg_type);
    }

    // Remove message queue after processing
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return EXIT_FAILURE;
    }

    printf("Message queue deleted.\n");
    return EXIT_SUCCESS;
}

