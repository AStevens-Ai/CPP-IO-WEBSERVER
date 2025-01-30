# an IO webserver to send messages in plain text from client to server with TCP.


>[!WARNING]
>The set of applications does not do nonblocking IO and i am still learning communicating data through TCP in specific buffer sizes without buffer overflowing.


## QUICK START

please insure before doing this to check what address and port you would like the server to be on. I have it set to a private ip and port number in my version,
please change it to something more suitable for your location, such as "127.0.0.1" (for localhost) , or you can find your private ip from typing :
```console
$ ip addr
```

afterwards you can find your ip that you can use instead for the server, and if you do that even other computers on your local network can access it. 


it may be helpful to use netcat for this if you would like to test without the client.


```console

$ g++ -o main main.cpp
$ g++ -o client client.cpp
$ ./main
$ ./client 
```

Then you should be able to freely type in the client and recieve messages back through TCP, make
# CPP-IO-WEBSERVER
