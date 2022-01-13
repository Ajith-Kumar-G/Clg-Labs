import os
from socket import *

serverName = "127.0.0.1"
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind((serverName, serverPort))
serverSocket.listen(1)

print("The server is ready to receive")

while 1:
    connectionSocket, addr = serverSocket.accept()
    sentence = connectionSocket.recv(1024).decode()
    flag = False
    if os.path.isfile(sentence):
        file = open(sentence, "r")
        l: str = file.read(1024)
        flag = True
    else:
        l: str = "The required file doesn't exits!"

    print("Sending To client: ", l)

    connectionSocket.send(l.encode())
    if flag:
        file.close()
    connectionSocket.close()
