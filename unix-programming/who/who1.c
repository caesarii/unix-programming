//
//  who1.c
//  unix-programming
//
//  Created by qinghe on 2018/10/27.
//  Copyright © 2018年 sdlmac8. All rights reserved.
//

#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define SHOWHOST
#define UTMP_FILE "/var/run/utmpx"
void show_info(struct utmp *utbufp);

int
main() {
    struct utmp current_record;
    int utmpfd;
    int reclen = sizeof(current_record);
    if((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1) {
        perror(UTMP_FILE);
        exit(1);
    }
    while(read(utmpfd, &current_record, reclen) == reclen) {
        show_info(&current_record);
    }
    close(utmpfd);
    return 0;
}

void
show_info(struct utmp *utbufp) {
    printf("% - 8.8s", utbufp->ut_name);
    printf(" ");
    printf("%s", utbufp->ut_line);
    printf(" ");
    printf("%ld", utbufp->ut_time);
    printf(" ");
    
}
