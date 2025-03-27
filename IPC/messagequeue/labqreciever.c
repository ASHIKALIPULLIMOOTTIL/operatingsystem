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

  
    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    printf("Reading messages in priority order:\n");

    
    for (int i = 3; i >= 1; i--) {
        if (msgrcv(msgid, &msg, sizeof(msg.msg_text), i, 0) == -1) {
            perror("msgrcv failed");
            exit(1);
        }
        printf("Received (Priority %ld): %s\n", msg.msg_type, msg.msg_text);
    }

   
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}

