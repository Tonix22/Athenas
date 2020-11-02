import numpy as np 
from numpy.ctypeslib import ndpointer 
import ctypes
from ctypes import *
import pathlib
import sys
from enum import IntEnum
import matplotlib.pyplot as plt
import math
from random import *
import time

if __name__ == "__main__":
    libname = pathlib.Path().absolute() / "dna.so"
    c_lib = ctypes.CDLL(libname)

    ## Define Return types
    c_lib.Generate_random_seq.restype  = ctypes.c_void_p
    # Define arguments
    c_lib.Generate_random_seq.argtypes = [c_int]

    #test
    data_times = []
    frames = 2000

    for n in range (2,frames):
        start_time = time.time()
        c_lib.Generate_random_seq(n)
        time_len = time.time() - start_time
        data_times.append(time_len)
    
    
    x   = np.arange(frames-2)
    fig = plt.figure()
    ax  = fig.add_subplot(111)
    
    #ax.plot(x,np.exp(x*.00001),'C1',label='logarithmic')
    ax.plot(x,np.array(data_times),'C2',label='dynamic')
    
    plt.legend(loc=2)

    plt.show()