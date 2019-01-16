# -*- coding: utf-8 -*-
"""
momentaryHB

@author: hp
"""

class momentaryHB:
    def __init__(self, x, t):
        self.t1 = 0
        self.t2 = 0
        self.x = np.zeros(len(x))
        self.t = np.zeros(len(t))
        self.x = x
        self.t = t
    
    def process(self):
        i = 0
        self.bpma = []
        for val in self.x:
            if(val >= 0.35e-20):
                
                #check if its normal bpm before assigning value to t2
                t2temp = self.t[i]
                self.bpm = (1000/(t2temp - self.t1))*60
                
                if ((self.bpm <= 110) and (self.bpm >= 50)):
                    #preparing for the next sample
                    self.t1 = self.t2
                    self.t2 = t2temp
                    self.bpma.append(self.bpm)
                    #print(self.bpm)
                else:
                    self.t1 = t2temp
                    
                
            i = i + 1
            
        #plot HeartBeats
        
        plt.show()
        plt.plot(self.bpma)
        plt.title("Heart beats Rate 'BPM'")
        plt.xlabel("HeartBeat")
        plt.ylabel("BPM")
        #plt.savefig("Heart beats Rate 'BPM'.svg", format="svg")
        plt.show()
        
import numpy as np
import matplotlib.pyplot as plt