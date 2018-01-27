# Authors:  Do Yeon Kim
#           Irvin Steve Cardenas (@kpatch)

# this is 'test' version (ver1)
## import
import sys
sys.path.append("/Users/dkim/Documents/Programming/Python/pyserial-3.4")
import serial
import binascii
import csv
# import timeit
import time
import pandas as pd
import numpy as np
# import time
# import openbci_realtime_ver1

## initial set up
class byte1(): 
  pass
class val(): 
  pass
class temp():
  pass
# class data1():
#   pass
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
temp_trial = 1
end_trial = 4
with serial.Serial(ser.name, 115200, timeout = 1, parity = serial.PARITY_NONE, stopbits = serial.STOPBITS_ONE) as ser1: 
  # button: ON
  ser1.write('b')
  temp_block = 1
  startTime = time.time()

  df = pd.DataFrame(columns=['CH1','CH2','CH3','CH4','CH5','CH6','CH7', 'CH8'])
  while(1):
    temp.s1 = ser1.read(1) # read up to ten bytes (timeout)
    if binascii.hexlify(temp.s1) == "a0":
      raw_data = ser1.read(31)
      raw_ID = raw_data[0]
      for temp_i in range(1, num_ch): 
        raw_EMG[temp_i] = raw_data[1 + 3 * (temp_i - 1):4 + 3 * (temp_i - 1)] # EMG data
      for temp_i in range(1, num_accel): 
        raw_accel[temp_i - 1] = raw_data[25 + 2 * (temp_i - 1):27 + 2 * (temp_i - 1)] # accel x, y, and z
      
      # ch1 = str(int(binascii.hexlify(raw_EMG[1]), 16) * val.scaleFac)
      # ch2 = str(int(binascii.hexlify(raw_EMG[2]), 16) * val.scaleFac)
      # ch3 = str(int(binascii.hexlify(raw_EMG[3]), 16) * val.scaleFac)
      # ch4 = str(int(binascii.hexlify(raw_EMG[4]), 16) * val.scaleFac)
      # ch5 = str(int(binascii.hexlify(raw_EMG[5]), 16) * val.scaleFac)
      # ch6 = str(int(binascii.hexlify(raw_EMG[6]), 16) * val.scaleFac)
      # ch7 = str(int(binascii.hexlify(raw_EMG[7]), 16) * val.scaleFac)
      # ch8 = str(int(binascii.hexlify(raw_EMG[8]), 16) * val.scaleFac)

      ch1 = int(binascii.hexlify(raw_EMG[1]), 16) * val.scaleFac
      ch2 = int(binascii.hexlify(raw_EMG[2]), 16) * val.scaleFac
      ch3 = int(binascii.hexlify(raw_EMG[3]), 16) * val.scaleFac
      ch4 = int(binascii.hexlify(raw_EMG[4]), 16) * val.scaleFac
      ch5 = int(binascii.hexlify(raw_EMG[5]), 16) * val.scaleFac
      ch6 = int(binascii.hexlify(raw_EMG[6]), 16) * val.scaleFac
      ch7 = int(binascii.hexlify(raw_EMG[7]), 16) * val.scaleFac
      ch8 = int(binascii.hexlify(raw_EMG[8]), 16) * val.scaleFac

      # save raw_data
      #  print(ch1 + "\t" + ch2 + "\t" + ch3 + "\t" + ch4 + "\t" + ch5 + "\t" + ch6 + "\t" + ch7 + "\t" + ch8)

      # df2 = pd.DataFrame([ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8])
      channels =[{'CH1': ch1, 'CH2': ch2, 'CH3': ch3, 'CH4': ch4, 'CH5': ch5, 'CH6': ch6, 'CH7': ch7, 'CH8': ch8}]
      df2 = pd.DataFrame(channels)
      df = df.append(df2)
      endTime = time.time()
      # print("DIFF: %f", (endTime - startTime))
      if( (endTime - startTime) >= 5):
        # df = pd.DataFrame(columns=['Ch1','Ch2','Ch3','Ch4','Ch5','Ch6','Ch7', 'Ch8'])
        startTime = endTime
        # df = df.reset_index()
        # print("DFFFFFFF")
        # print(df)
        # print(df.ix[:, [0, 1]])
        # reference channels; creating bipolar EMG channel
        df_ref_ch = df.ix[:, [0, 1]]
        
        # df_ref_ch2 = df_ref_ch.mean(axis = 1) # mean horizontally
        df_ref_ch2 = df_ref_ch.mean(axis = 1, skipna=True) # mean horizontally
        df_ref_ch3 = df.ix[:, 2:7].sub(df_ref_ch2, axis=0)
        print(df_ref_ch3)

        # df_ref_ch['avg'] = df[['CH1', 'CH2']].mean(axis = 1)

        # np.nan_to_num(df_ref_ch)

        # print(df_ref_ch2)

        # detrend
        df_deTrend = df_ref_ch3.sub(df_ref_ch3.mean(axis = 0, skipna = True), axis = 1)
        # print(df_deTrend)
        # bandstop

        # bandpass

        df = df.iloc[0:0]
        # df = pd.DataFrame(columns=df.columns)
      
    
      

    temp_block += 1
    if temp_trial == end_trial: 
      # collect data
      print('{0:2f} {1:3f} {2:4f}'.format(str(int(binascii.hexlify(raw_EMG[1]), 16) * val.scaleFac)))
      end_trial = end_trial + 4
      ser1.write('s')
