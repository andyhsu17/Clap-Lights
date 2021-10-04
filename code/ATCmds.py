import serial

ser = serial.Serial()
ser.timeout = 3
ser.port = '/dev/tty.usbserial-14120'
ser.baudrate = 38400
ser.parity = serial.PARITY_NONE
ser.xonxoff = False
ser.bytesize = serial.EIGHTBITS
ser.open()

ser.write(b'AT+BIND=98,D3,71,FD,B2,01\r\n')
s = ser.read(50)
print(s)

# ser.write(b'AT+RESET\r\n')
# s = ser.read(50)
# print(s)

# ser.write(b'AT+ROLE?\r\n')
# s = ser.read(50)
# print(s)

# ser.write(b'AT+UART=9600,1,0\r\n')        # 9600 baud, 1 stop bit, 0 parity
# s = ser.read(50)
# print(s)

# ser.write(b'AT+CMODE=1\r\n')              # cmode can connect to any device
# s = ser.read(10)
# print(s)

# ser.write(b'AT+CLASS=0\r\n')
# s = ser.read(10)
# print(s)

# ser.write(b'AT+INQM=1,3,48\r\n')      # rssi mode, connect to 3 devices, 48 seconds search time
# s = ser.read(10)
# print(s)

# ser.write(b'AT+INQ\r\n')
# s = ser.read(50)
# print(s)

# ser.write(b'AT+STATE?\r\n')
# s = ser.read(50)
# print(s)

# ser.write(b'AT+RESET\r\n')
# s = ser.read(10)
# print(s)

# ser.write(b'AT+UART?')
# s = ser.read(50)
# print(s)


#ser.write(b'AT+DISC?')
#s = ser.read(1000)
#print(s)

# ser.write(b'AT+CONN3')
# s = ser.read(50)
# print(s)

# ser.write(b'AT+CLEAR')
# s = ser.read(50)
# print(s)

#ser.write(str.encode('AT+SHOW?'))
#s = ser.read(50)
#print(s) 

ser.write(b'AT+MRAD?\r\n')
s = ser.read(500)
print(s)

# ser.write(b'AT+PASS?')
# s = ser.read(50)
# print(s)

# ser.write(b'AT+ERASE')
# s = ser.read(50)
# print(s)

# ser.write(b'AT+RESET')
# s = ser.read(50)
# print(s)

ser.close()
