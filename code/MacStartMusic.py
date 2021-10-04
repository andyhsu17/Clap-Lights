import serial
import os
import applescript
# from subprocess import Popen, PIPE

# cmd = 'tell application "Music" to play (next track)'
scpt = applescript.AppleScript('''tell application "Music" to play''')
stopscpt = applescript.AppleScript('''tell application "Music" to pause''')

def setup():
    print("Attempting to receive serial data")
    myserial = serial.Serial()
    myserial.timeout = 3
    myserial.port = '/dev/tty.usbserial-14320'
    myserial.baudrate = 9600
    myserial.parity = serial.PARITY_NONE
    myserial.xonxoff = False
    myserial.bytesize = serial.EIGHTBITS
    if ser.inWaiting():
        char = ser.read()
    try:
        myserial.open()
    except Exception as e:
        print(f"error opening serial port: {e}")
    return myserial
def main():

    ser = setup()
    while 1:
        if ser.inWaiting():
            char = ser.read()
            if char == bytes('p', 'utf8'):
                print("received play music command")
                scpt.run()
            elif (char == bytes('s', 'utf8')):
                print("received stop music command")
                stopscpt.run()



if __name__ == '__main__':
    main()
