# Minitalk

## 📝 Description
Minitalk is a small client-server communication program implemented using UNIX signals. The project consists of a server that receives messages and a client that sends them. Communication between the programs is achieved using only SIGUSR1 and SIGUSR2 signals.

## 🛠️ Features
- Client can send string messages to the server
- Server displays the received messages
- Communication using only UNIX signals (SIGUSR1 & SIGUSR2)
- Support for Unicode characters
- Confirmation of message receipt
- Error handling for invalid inputs
- Clean exit handling

## 🔧 Requirements
- Unix-like operating system
- GCC compiler
- Make
- The libft library (included)

## 💻 Usage

1. Start the server:
```bash
./server
```
The server will display its PID (Process ID) and wait for incoming messages.

2. Send a message using the client:
```bash
./client [server-PID] "Your message here"
```

Example:
```bash
./client 1234 "Hello, World!"
```

## ⚙️ How It Works
1. The server starts and displays its PID
2. The client takes the server's PID and a message as arguments
3. The client sends each character of the message bit by bit using:
   - SIGUSR1 to send a 1
   - SIGUSR2 to send a 0
4. The server reconstructs the message bit by bit
5. Once the message is completely received, the server displays it
6. The server sends a confirmation signal back to the client
7. The client displays a confirmation message and exits

## 🚨 Error Handling
The program handles various error cases:
- Invalid PIDs
- Incorrect number of arguments
- Signal sending failures
- Non-numeric PIDs
- Process errors

## 📌 Notes
- The client will exit if an invalid PID is provided
- The server runs indefinitely until manually terminated
- A small delay is implemented between signals to ensure reliability
- The server can handle multiple clients sequentially

## ⚠️ Limitations
- Large messages might take longer to transmit due to the bit-by-bit nature of the communication
- The server processes one client at a time

## 🔍 Resources
- [Unix Signals Documentation](https://man7.org/linux/man-pages/man7/signal.7.html)
- [Computer Systems - A Programmer's Perspective (2nd) Chapter 8: Exceptional Control Flow](https://github.com/shihyu/CSAPP2e/blob/master/Computer%20Systems%20-%20A%20Programmer's%20Perspective%20(2nd).pdf)
- [Introduction To Unix Signals Programming](https://www.cs.kent.edu/~ruttan/sysprog/lectures/signals.html)
- [Why is Sigaction() a better option than Signal()](https://elliotth.blogspot.com/2011/05/signal2-versus-sigaction2.html)
- [Basics of Bit Manipulation](https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/tutorial/)
- [Characters, Symbols and the Unicode Miracle - Computerphile](https://www.youtube.com/watch?v=MijmeoH9LT4)
