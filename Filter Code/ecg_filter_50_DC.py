# -*- coding: utf-8 -*-
"""
ecg_filter_50_DC

@author: hp
"""

class ecg_filter_50_DC:
    def __init__(self, fs, x):
        
        #setting input array to x1
        self.x1 = x
        
        #finding filter coefficients and passing it to FIR_filter
        fsr = 0.5
        self.M = int(fs/fsr)
        self.fs = fs
        
    
    def high(self, highpass_frequency):
        
        #normalized frequencies
        nlowf = int((0/self.fs) * self.M)
        nhighf = int((highpass_frequency/self.fs) * self.M)
        
        #setting the opposite of passf "npassf"
        passf = 0
        npassf = 1        
        
        #making of the array for the filter coefficients
        self.h = np.zeros(self.M)
        self.h[0:self.M+1] = npassf
        
        #filter coefficients correction, "time shift"
        self.h[nlowf:nhighf+1] = passf
        self.h[self.M - nhighf:self.M - nlowf+1] = passf
        
        #applying hamming window function to the filter
        self.ht = np.real(np.fft.ifft(self.h))
        self.hti = np.ones(self.M)
        self.hti[0:int(self.M/2)] = self.ht[int(self.M/2):self.M]
        self.hti[int(self.M/2):self.M] = self.ht[0:int(self.M/2)]
        
        #setting highpass coefficients "coeh"
        self.coeh = self.hti * np.hamming(self.M)
        
        #calling FIR_filter function 
        FIRh = FIR.FIR_filter(self.coeh, self.M)
        self.det = np.zeros(len(self.x1))
        
        #do the filter for all values of x1
        i = 0
        for v in self.x1:
            self.det[i] = FIRh.dofilter(v)
            i = i + 1
        return self.det
    
    def low(self, lowpass_frequency):
        
        #normalized frequencies
        nlowf = int((0/self.fs) * self.M)
        nhighf = int((lowpass_frequency/self.fs) * self.M)
        
        #setting the opposite of passf "npassf"
        passf = 1
        npassf = 0        
        
        #making of the array for the filter coefficients
        self.h = np.zeros(self.M)
        self.h[0:self.M+1] = npassf
        
        #filter coefficients correction, "time shift"
        self.h[nlowf:nhighf+1] = passf
        self.h[self.M - nhighf:self.M - nlowf+1] = passf
        
        #applying hamming window function to the filter
        self.ht = np.real(np.fft.ifft(self.h))
        self.hti = np.ones(self.M)
        self.hti[0:int(self.M/2)] = self.ht[int(self.M/2):self.M]
        self.hti[int(self.M/2):self.M] = self.ht[0:int(self.M/2)]
        
        #setting lowpass coefficients "coel"
        self.coel = self.hti * np.hamming(self.M)
        
        #calling FIR_filter function
        FIRl = FIR.FIR_filter(self.coel, self.M)
        self.det = np.zeros(len(self.x1))
        
        #do the filter for all values of x1
        i = 0
        for v in self.x1:
            self.det[i] = FIRl.dofilter(v)
            i = i + 1
        return self.det     
    
    def band(self, lowfreq, highfreq):
        
        #normalized frequencies
        nlowf = int((lowfreq/self.fs) * self.M)
        nhighf = int((highfreq/self.fs) * self.M)
        
        #setting the opposite of passf "npassf"
        passf = 1
        npassf = 0        
        
        #making of the array for the filter coefficients
        self.h = np.zeros(self.M)
        self.h[0:self.M+1] = npassf
        
        #filter coefficients correction, "time shift"
        self.h[nlowf:nhighf+1] = passf
        self.h[self.M - nhighf:self.M - nlowf+1] = passf
        
        #applying hamming window function to the filter
        self.ht = np.real(np.fft.ifft(self.h))
        self.hti = np.ones(self.M)
        self.hti[0:int(self.M/2)] = self.ht[int(self.M/2):self.M]
        self.hti[int(self.M/2):self.M] = self.ht[0:int(self.M/2)]
        
        #setting bandpass coefficients "coeb"
        self.coeb = self.hti * np.hamming(self.M)
        
        #calling FIR_filter function
        FIRb = FIR.FIR_filter(self.coeb, self.M)
        self.det = np.zeros(len(self.x1))
        
        #do the filter for all values of x1
        i = 0
        for v in self.x1:
            self.det[i] = FIRb.dofilter(v)
            i = i + 1
        return self.det
    
    def stopband(self, lowfreq, highfreq):
        #normalized frequencies
        nlowf = int((lowfreq/self.fs) * self.M)
        nhighf = int((highfreq/self.fs) * self.M)
        
        #setting the opposite of passf "npassf"
        passf = 0
        npassf = 1        
        
        #making of the array for the filter coefficients
        self.h = np.zeros(self.M)
        self.h[0:self.M+1] = npassf
        
        #filter coefficients correction, "time shift"
        self.h[nlowf:nhighf+1] = passf
        self.h[self.M - nhighf:self.M - nlowf+1] = passf
        
        #applying hamming window function to the filter
        self.ht = np.real(np.fft.ifft(self.h))
        self.hti = np.ones(self.M)
        self.hti[0:int(self.M/2)] = self.ht[int(self.M/2):self.M]
        self.hti[int(self.M/2):self.M] = self.ht[0:int(self.M/2)]
        
        #setting bandstoppass coefficients "coes"
        self.coes = self.hti * np.hamming(self.M)
        
        #calling FIR_filter function
        FIRs = FIR.FIR_filter(self.coes, self.M)
        self.det = np.zeros(len(self.x1))
        
        #do the filter for all values of x1
        i = 0
        for v in self.x1:
            self.det[i] = FIRs.dofilter(v)
            i = i + 1
        return self.det
    
    def plot(self):
        #plots graphs of coefficients and ECG outputs
        
        #plotting Frequency Domain Graph
        xf = np.fft.fft(self.x1)        
        self.faxis = np.linspace(0,1000,len(xf))
        plt.plot(self.faxis, abs(xf))
        plt.title("ECG Frequency Domain")
        plt.show()
        
        #plots the filter
        plt.plot(self.h)
        plt.title("Filter COE before inverse fourier transform")
        plt.show()
        
        plt.plot(self.coe)
        plt.title("Filter COE after inverse fourier transform")
        plt.show()
        
        plt.plot(np.abs(np.fft.fft(self.hti)))
        plt.title("Filter COE after fourier transform")
        plt.show()
        
        #plots the ECG outputs
        detf = np.fft.fft(self.det)
        plt.plot(self.faxis, abs(detf))
        plt.title("ECG Frequency Domain")
        plt.show()
        
        plt.plot(self.det)
        plt.title("ECG Time Domain")
        plt.show
        

#main
import numpy as np
import matplotlib.pyplot as plt
import FIR_filter as FIR

