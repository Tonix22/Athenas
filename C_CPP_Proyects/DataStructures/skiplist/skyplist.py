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

import sys

from signal import signal, SIGSEGV
def handler( sigNum, frame ):
  print( "handle signal", sigNum )


if __name__ == "__main__":
    libname = pathlib.Path().absolute() / "skiplist.so"
    c_lib = ctypes.CDLL(libname)

    ## Define Return types
    c_lib.init_structure.restype  = ctypes.c_void_p
    c_lib.erase_node.restype      = ctypes.c_void_p
    c_lib.insert.restype          = ctypes.c_void_p
    c_lib.find_value.restype      = ctypes.c_bool

    ## Define arguments
    c_lib.init_structure.argtypes  = []
    c_lib.erase_node.argtypes      = [c_int]
    c_lib.insert.argtypes          = [c_int]
    c_lib.find_value.argtypes      = [c_int]

    c_lib.init_structure()
    
    frames = 1000
    data_times = []
    i = 0
    
    for n in range (0,frames):
        val = randint(1, 1000)
        #print (val)
        start_time = time.time()

        c_lib.insert(val)
        time_len = time.time() - start_time
        time.sleep(.01)
        data_times.append(time_len)
    
    x=np.arange(frames)
    fig=plt.figure()
    ax=fig.add_subplot(111)
    
    ax.plot(x,np.array(data_times),'C2',label='insertions')
    
    plt.legend(loc=2)

    plt.show()
    