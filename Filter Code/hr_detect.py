# -*- coding: utf-8 -*-
"""
hr_detect

@author: hp
"""

class hr_detect:
    def __init__(self, filename):
        x = np.loadtxt(filename)
        #importing ECG_2 file
        self.x1 = x[:,1]
        self.t = x[:,0]
        #scaling amplitude values
        self.x1=(self.x1*(1.325/(2**23)))/500
        self.y = np.zeros(len(self.x1))
        self.fs = 1000
        
        plt.plot(self.x1)
        plt.title("Data from ECG_2")
        plt.xlabel("Samples (n)")
        plt.ylabel("Amplitude")
        plt.savefig("Data from ECG_2 unfiltered.svg", format="svg")
        plt.show()
        
    def process(self):
        #filtering 50 Hz
        ECGFF = ECGF.ecg_filter_50_DC(self.fs, self.x1)
        
        x2 = ECGFF.stopband(45, 55)
        
        #filtering DC
        ECGFF = ECGF.ecg_filter_50_DC(self.fs, x2)
        
        self.x3 = ECGFF.high(10)
        
        #calling matched filter function
        ECG = ECGMF.ECG_matchedfilter(self.x3)
        self.y = ECG.match()
        
        #ECG.plot()
        
        #calling function that will give us the momentary HB graph
        HBm = HB.momentaryHB(self.y, self.t)
        HBm.process()

        
import numpy as np
import momentaryHB as HB
import ecg_filter_50_DC as ECGF
import ECG_matchedfilter as ECGMF
import matplotlib.pyplot as plt

E = hr_detect('ecg_2.dat')
E.process()