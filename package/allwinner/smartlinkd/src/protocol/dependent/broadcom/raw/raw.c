
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/socket.h>
#include <stdio.h>
#include <string.h>
#include <netpacket/packet.h>
#include <net/if.h>
#include <netinet/in.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

//unsigned short protocol = 0x888e;
unsigned short protocol = 0x0003;
#define NAME "wlan0"
int cc = 0;


int main(int argc, char ** argv)
{
    struct ifreq ifr;
    struct sockaddr_ll ll;
    int fd;

	printf("smartlink raw start");
    fd = socket(PF_PACKET, SOCK_RAW, htons(protocol));
    printf("fd = %d \n", fd);
    if(argv[1])
        printf("name = %s \n", argv[1]);

    memset(&ifr, 0, sizeof(ifr));
    if(argv[1]){
        //strlcpy(ifr.ifr_name, argv[1], sizeof(ifr.ifr_name));
		strcpy(ifr.ifr_name, argv[1]);
	}
    else {
        //strlcpy(ifr.ifr_name, NAME, sizeof(ifr.ifr_name));
		strcpy(ifr.ifr_name, NAME);
	}
    printf("ifr.ifr_name = %s \n", ifr.ifr_name);

    if (ioctl(fd, SIOCGIFINDEX, &ifr) < 0) {
        close(fd);
        printf("get infr fail\n");
        return -1;
    }

    memset(&ll, 0, sizeof(ll));
    ll.sll_family = PF_PACKET;
    ll.sll_ifindex = ifr.ifr_ifindex;
    ll.sll_protocol = htons(protocol);
    if (bind(fd, (struct sockaddr *) &ll, sizeof(ll)) < 0) {
        printf("bind fail \n");
        close(fd);
        return -1;
    }


    while(1) {

        unsigned char buf[2300];
        int res;
        socklen_t fromlen;
        int i = 0;

        memset(&ll, 0, sizeof(ll));
        fromlen = sizeof(ll);
        res = recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *) &ll,
                &fromlen);
        if (res < 0) {
            printf("res < 0\n");
            return -1;
        } else {
            cc++;
            printf("%04d(%03d) - ", cc, res);
            for(i = 0; i < res && i < 8; i++)
                printf("%02x ", buf[i]);
            printf("\n");
        }
    }

    close(fd);

    return 0;

}
