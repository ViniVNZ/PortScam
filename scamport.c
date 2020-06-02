
#include <stdio.h>
#include <netdb.h>

main(int argc, char *argv[])
{

  if(argc<2)
  {
   printf("Você não colocou um IP\n");
  }else{
   int socket2;
   int conectar;

   int port;
   int start1 = 0; 
   int stop2 = 65535;
   char * destino; 
   destino = argv[1];

   struct sockaddr_in alvo;

   for(port=start1;port<stop2;port++) 
   {
   socket2 = socket(AF_INET, SOCK_STREAM, 0);
   alvo.sin_family = AF_INET;
   alvo.sin_port = htons(port);
   alvo.sin_addr.s_addr = inet_addr(destino);

  conectar = connect(socket2, (struct sockaddr *)&alvo, sizeof alvo);


  if(conectar == 0)
  {
    printf("Porta %d esta aberta no endereço %s \n", port, destino);
    close(socket2);
    close(conectar);
  }else{
    close(socket2);
    close(conectar);
   }
  }
 }
}


