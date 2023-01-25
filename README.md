# minitalk42
42 project Minitalk 
This code is a C program that sends a message from one process to another using the "kill" function
and signals (SIGUSR1 and SIGUSR2). The program takes in two command line arguments, the first being the process ID
of the recipient and the second being the message to be sent. The program first converts the process ID from a string
to an integer using the ft_atoi function. It then iterates through each character of the message, sending each character
one bit at a time using the ft_forward function. The program also includes error handling for invalid input and message format.
