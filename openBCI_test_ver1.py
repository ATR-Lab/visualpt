# this is 'test' version (ver1)
## import
import sys
sys.path.append("/Users/dkim/Documents/Programming/Python/pyserial-3.4")
import serial
import binascii
# import time
# import openbci_realtime_ver1

## initial set up
class byte1(): 
  pass
class val(): 
  pass
class temp():
  pass
ser = serial.Serial('/dev/tty.usbserial-DM00PZYR') # open serial port tty.usbserial-DM00PZYR
num_sample = ""
num_ch = 9 # 6 ch + 2 reference ch
num_accel = 3 # 3 accelerometer x, y & z
raw_EMG = [0] * num_ch
raw_accel = [0] * num_accel
# data format
byte1.sample_Hz = 250.0
byte1.start1 = 0xA0 # start of data packet
byte1.end1 = 0xC0 # end of data packet
# scale factor
val.V_ref = 4.5 # reference voltages (V); set by its hardware
val.gain = 24.0 # assumed gain setting; set by its Arduino code
val.scaleFac = val.V_ref / val.gain / (2**23 - 1) # scale factor
val.acc_scaleFac = 0.002 / 2**4 # accelerometer scale factor
# check
print(ser.name) # check which port was really used
print(val.V_ref)
print(val.gain)
print(val.scaleFac)
print(byte1.start1)


## real time
with serial.Serial(ser.name, 115200, timeout = 1, parity = serial.PARITY_NONE, stopbits = serial.STOPBITS_ONE) as ser1: 
  # button: ON
  ser1.write('b')
  while(1): 
    temp.s1 = ser1.read(1) # read up to ten bytes (timeout)
    if binascii.hexlify(temp.s1) == "a0":
      raw_data = ser1.read(31)
      raw_ID = raw_data[0]
      for temp_i in range(1, num_ch): 
        raw_EMG[temp_i] = raw_data[1 + 3 * (temp_i - 1):4 + 3 * (temp_i - 1)] # EMG data
      for temp_i in range(1, num_accel): 
        raw_accel[temp_i - 1] = raw_data[25 + 2 * (temp_i - 1):27 + 2 * (temp_i - 1)] # accel x, y, and z
      
    # save raw_data
    

      # for temp_i in range(1, num_ch - 1): 
      #   if temp_i == num_ch - 1: 
      #     print(str(int(binascii.hexlify(raw_EMG[1]), 16) * val.scaleFac))
      #   else: 
      #     print(str(int(binascii.hexlify(raw_EMG[1]), 16) * val.scaleFac) + "\t")
      print(str(int(binascii.hexlify(raw_EMG[1]), 16) * val.scaleFac) + "\t"
        + str(int(binascii.hexlify(raw_EMG[2]), 16) * val.scaleFac) + "\t"
        + str(int(binascii.hexlify(raw_EMG[3]), 16) * val.scaleFac) + "\t"
        + str(int(binascii.hexlify(raw_EMG[4]), 16) * val.scaleFac) + "\t"
        + str(int(binascii.hexlify(raw_EMG[5]), 16) * val.scaleFac) + "\t"
        + str(int(binascii.hexlify(raw_EMG[6]), 16) * val.scaleFac) + "\t"
        + str(int(binascii.hexlify(raw_EMG[7]), 16) * val.scaleFac) + "\t"
        + str(int(binascii.hexlify(raw_EMG[8]), 16) * val.scaleFac))
