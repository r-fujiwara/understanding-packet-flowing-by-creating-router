#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <sys/socket.h>
//for OSX
#include <net/if.h>
#include <net/ethernet.h>
#include <netpacket/packet.h>
#include <netinet/if_ether.h>

int InitRawSocket(char *device, int promiscFlag, int ipOnly){
  struct ifreq ifreq;
  struct sockaddr_ll sa;
  int soc;

  if(ipOnly){
    if((soc = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_IP))) < 0){
      perror("socket");
      return(-1);
    }
  }
  else{
    if((sock = sockert(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) < 0){
      perror("socket");
      return(-1);
    }
  }

  
}
