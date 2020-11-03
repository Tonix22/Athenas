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
    
    frames_number= 10000
    insert_times=[]
    search_times=[]
    delete_times=[]
    frames=[]

	
    for n in range (0,frames_number):
        #generate frames
        for m in range(0,n):
            val = randint(1, (1<<31)-1)
            frames.append(val)
        
        #insertions
        start_time = time.time()
        for m in range(0,n):
            c_lib.insert(frames[m])
        
        time_len = time.time() - start_time
        insert_times.append(time_len)
        #searches
        frames_len = len(frames)-1
        start_time = time.time()
        for m in range(0,n):
            val = frames[randint(0, frames_len)]
            c_lib.find_value(val)
        
        time_len = time.time() - start_time
        search_times.append(time_len)
        
        
        #delete
        start_time = time.time()
        for m in range(1,n):
            #print("frames[%4d] = % 4d" %(m, frames[m]))
            c_lib.erase_node(frames[m])

        time_len = time.time() - start_time
        delete_times.append(time_len)
        
        frames.clear()
        print("iteration = % 4d" %(n))

	
    x=np.arange(frames_number)
    fig=plt.figure()
    ax=fig.add_subplot(111)      
    ax.plot(x,np.array(insert_times),'C2',label='insertions')
    ax.plot(x,np.array(search_times),'C0',label='search')
    ax.plot(x,np.array(delete_times),'C3',label='delete')
      
    plt.legend(loc=2)

    plt.show()
    