# Authors:  Do Yeon Kim
#           Irvin Steve Cardenas (@kpatch)

# this is 'test' version (ver1)
## import
import sys
sys.path.append("/Users/dkim/Documents/Programming/Python/pyserial-3.4")
import serial
import binascii
import time
import pandas as pd
import numpy as np
from scipy import signal
from scipy.signal import butter, iirnotch, filtfilt, lfilter
import csv

output_file = open('training_ver5.csv', 'w') 

## initial set up
class byte1(): 
  pass
class val(): 
  pass
class temp():
  pass
# openBCI
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
# bandstop
val.Fs_bs = 250.0 # sample frequency (Hz)
val.Fo_bs = 60.0 # bandstop frequency (Hz)
val.q_bs = 35.0 # filter bandwidth
val.w0_bs = val.Fo_bs / (val.Fs_bs / 2)
# bandpass
val.Fs_bp = val.Fs_bs # sample frequency (Hz)
val.Nq_bp = 0.5 * val.Fs_bp # Nyquist frequency
val.cutoff_low = 50 / val.Nq_bp # low cutoff frequency (Hz)
val.cutoff_high = 100 / val.Nq_bp # high cutoff frequency (Hz)
# check
print(ser.name) # check which port was really used
print("Parameters initialized")


## real time
with output_file as csv_file, serial.Serial(ser.name, 115200, timeout = 1, parity = serial.PARITY_NONE, stopbits = serial.STOPBITS_ONE) as ser1: 
  ser1.write('b')
  val.startTime = time.time()

  data_df1 = pd.DataFrame(columns = ['CH1', 'CH2', 'CH3', 'CH4', 'CH5', 'CH6', 'CH7', 'CH8'])
  while(1):
    temp.s1 = ser1.read(1) # read up to ten bytes (timeout)
    if binascii.hexlify(temp.s1) == "a0":
      raw_data = ser1.read(31)
      raw_ID = raw_data[0]
      for temp_i in range(1, num_ch): 
        raw_EMG[temp_i] = raw_data[1 + 3 * (temp_i - 1):4 + 3 * (temp_i - 1)] # EMG data
      for temp_i in range(1, num_accel): 
        raw_accel[temp_i - 1] = raw_data[25 + 2 * (temp_i - 1):27 + 2 * (temp_i - 1)] # accel x, y, and z

      ch1 = int(binascii.hexlify(raw_EMG[1]), 16) * val.scaleFac
      ch2 = int(binascii.hexlify(raw_EMG[2]), 16) * val.scaleFac
      ch3 = int(binascii.hexlify(raw_EMG[3]), 16) * val.scaleFac
      ch4 = int(binascii.hexlify(raw_EMG[4]), 16) * val.scaleFac
      ch5 = int(binascii.hexlify(raw_EMG[5]), 16) * val.scaleFac
      ch6 = int(binascii.hexlify(raw_EMG[6]), 16) * val.scaleFac
      ch7 = int(binascii.hexlify(raw_EMG[7]), 16) * val.scaleFac
      ch8 = int(binascii.hexlify(raw_EMG[8]), 16) * val.scaleFac
      #  print(ch1 + "\t" + ch2 + "\t" + ch3 + "\t" + ch4 + "\t" + ch5 + "\t" + ch6 + "\t" + ch7 + "\t" + ch8)

      channels =[{'CH1': ch1, 'CH2': ch2, 'CH3': ch3, 'CH4': ch4, 'CH5': ch5, 'CH6': ch6, 'CH7': ch7, 'CH8': ch8}]
      data_df2 = pd.DataFrame(channels)
      data_df1 = data_df1.append(data_df2)
      val.endTime = time.time()
      if( (val.endTime - val.startTime) >= 5):
        val.startTime = val.endTime
        print("Recorded")

        # reference channels; creating bipolar EMG channel
        data_refCH1 = data_df1.ix[:, [0, 1]]
        data_refCH2 = data_refCH1.mean(axis = 1, skipna = True) # mean horizontally
        data_refCH3 = data_df1.ix[:, 2:8].sub(data_refCH2, axis = 0)
        # print(data_refCH3)
        print("Reference CH")

        # detrend
        data_deTrend = data_refCH3.sub(data_refCH3.mean(axis = 0, skipna = True), axis = 1)
        # print(data_deTrend)
        data_deTrend1 = data_deTrend.transpose()
        print(data_deTrend1)
        print("Detrend")

        # bandstop
        val.b_bs, val.a_bs = iirnotch(val.w0_bs, val.q_bs)
        # y_bs1 = lfilter(b_bs, a_bs, df_deTrend1)
        data_bs1 = filtfilt(val.b_bs, val.a_bs, data_deTrend1)
        data_bs2 = data_bs1.transpose()
        print(data_bs1)
        print("Notch filter")

        # bandpass
        val.b_bp, val.a_bp = butter(4, [val.cutoff_low, val.cutoff_high], 'band')
        data_bp1 = filtfilt(val.b_bp, val.a_bp, data_bs1)
        data_bp2 = data_bp1.transpose()
        print("Bandpass")
        print(data_bp2)

        # average by channel
        data_avg1 = data_bp2.mean(axis = 0) # mean horizontally
        print("Average")
        print(data_avg1)

        # RMS
        # def sin_rms(RMS_a1): 
          # data_rms1 = a * sin


        ## save
        # write CSV files
        # output_file = open('training_ver4.csv', 'w') 
        # with output_file:
        writer = csv.writer(csv_file, delimiter=",", lineterminator='\n')
        for output_line in data_bp2:
          writer.writerow(output_line)
        
        data_df1 = data_df1.iloc[0:0]
