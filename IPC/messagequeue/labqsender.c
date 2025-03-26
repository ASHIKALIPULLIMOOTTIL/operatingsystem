#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 50  // Message size

// Define message structure
struct my_msg {
    long int msg_type;  // Priority (higher value = higher priority)
    char some_text[MAX_TEXT];
};

int main() {
    int msgid;
    struct my_msg message;

    // Create message queue with read & write permissions (0600)
    msgid = msgget((key_t)12345, 0600 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        return EXIT_FAILURE;
    }

    // Define three messages with different priority numbers
    struct my_msg messages[3] = {
        {3, "This is a high-priority message."},
        {2, "This is a medium-priority message."},
        {1, "This is a low-priority message."}
    };

    // Send all three messages
    for (int i = 0; i < 3; i++) {
        if (msgsnd(msgid, (void *)&messages[i], sizeof(messages[i].some_text), 0) == -1) {
            perror("msgsnd");
            return EXIT_FAILURE;
        }
        printf("Sent: %s (Priority %ld)\n", messages[i].some_text, messages[i].msg_type);
    }

    printf("All messages sent successfully!\n");
    return EXIT_SUCCESS;
}

