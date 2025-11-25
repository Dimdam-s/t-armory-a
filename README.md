# DXP-Backdoor – Reverse Shell (C System)

📄 Factual Description

This project is a minimalist C System program designed to establish a TCP/IP Reverse Shell. Its purpose is to demonstrate the use of low-level Unix system calls to obtain remote shell access on a target machine (Linux/UNIX).

It is intended strictly for educational and binary analysis purposes.

⚙️ Key Technical Features

The program uses a sequence of critical system calls:

C Function	Low-Level Role
socket()	Creates the file descriptor (FD) for the network connection (AF_INET, SOCK_STREAM).
connect()	Attempts to establish the TCP link to the attacker’s address and port.
dup2()	Redirects the three standard I/O streams: STDIN (0), STDOUT (1), STDERR (2) are all forwarded to the socket descriptor.
execve()	Replaces the current process with a shell (/bin/sh) without creating a new process, enabling remote control.
