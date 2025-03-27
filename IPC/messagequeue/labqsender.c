#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_TEXT 100


struct message {
    long msg_type; 
    char msg_text[MAX_TEXT]; 
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

   
    key = ftok("progfile", 65);

   
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    printf("Message Queue ID: %d\n", msgid);

   
    for (int i = 0; i < 3; i++) {
        printf("Enter message (priority %d): ", i + 1);
        fgets(msg.msg_text, MAX_TEXT, stdin);
        msg.msg_text[strcspn(msg.msg_text, "\n")] = 0; 
        msg.msg_type = i + 1; 

      
        if (msgsnd(msgid, &msg, sizeof(msg.msg_text), 0) == -1) {
            perror("msgsnd failed");
            exit(1);
        }
        printf("Message sent with priority %ld\n", msg.msg_type);
    }

    return 0;
}

