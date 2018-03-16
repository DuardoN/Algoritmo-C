//  main.c
//  verify ip
//
//  Created by Eduardo on 27/11/17.
//  Copyright © 2017 Eduardo. All rights reserved.

#include <stdio.h>
int main() {
    // Definy variables
    int ip[4], i;
    
    // Loop to set ip as homes.
    for(i = 0; i < 4; i++)
    {
        // Verify home in loop.
        switch (i) {
            case 0:
                printf("Write first part:");
                scanf("%d", &ip[i]);
                break;
            case 1:
                printf("Write second part:");
                scanf("%d", &ip[i]);
                break;
            case 2:
                printf("Write third part:");
                scanf("%d", &ip[i]);
                break;
            case 3:
                printf("Write fourth part:\n");
                scanf("%d", &ip[i]);
                break;
                
            default:
                break;
        }
    }
    
    // Calling function verify_ip.
    verify_ip(ip);
}

// Function verify_ip.
// This return result of ip is valid or not.
int verify_ip(int ip[]){
    
    // Definy variables.
    int ipverify[4], i;
    
    // Loop to verify if ip is valid.
    for (i = 0; i < 4; i++) {
        ipverify[i] = ip[i];
        if (ipverify[i] > 255) {
            printf("IP is not correct\n");
            break;
        }
    }
    
    // Print ip.
    printf("IP: ");
    for (i = 0; i < 4; i++) {
        printf("%d.", ipverify[i]);
    }
    
    return printf("\n");
}
