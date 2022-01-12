from socket import *
import os

serverName = "127.0.0.1"
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind((serverName, serverPort))

print("The server is ready to receive")

while 1:
    sentence, clientAddress = serverSocket.recvfrom(2048)
    flag = False
    if os.path.isfile(sentence):
        file = open(sentence, "r")
        l: str = file.read(2048)
        flag = True
    else:
        l: str = "The required file doesn't exits!"
    serverSocket.sendto(bytes(l, "utf-8"), clientAddress)
    print("Sent back to client: ", l)
    if flag:
        file.close()
