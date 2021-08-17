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
import networkx as nx


if __name__ == "__main__":
    # Load the shared library into c types.
    libname = pathlib.Path().absolute() / "main.so"
    c_lib = ctypes.CDLL(libname)

    # Define return void pointer
    c_lib.Floy_Marshal_I.restype = ctypes.c_void_p

    # Define arguments
    singlepp = ndpointer(dtype = np.int32, ndim = 1, flags = 'C')
    c_lib.Floy_Marshal_I.argtypes = [singlepp, ctypes.c_int,ctypes.c_int]

    INF = 255
    # Define ndarray
    x = np.array([[0  , 3  , 8  , INF, -4 ],
                 [INF, 0  , INF, 1  , 7  ],
                 [INF, 4  , 0  , INF, INF],
                 [2  , INF, -5 , 0  , INF],
                 [INF, INF, INF, 6  , 0  ]],dtype='int32')

    frames_number= 200
    time_per_frame = 0
    total_time = 0
    insert_times=[]
    for n in range (0,frames_number):
        for m in range (0,n):

            #generate frames
            start_time = time.time()
            row_list = []
            col_list = []
            for r in range(0,n):
                for c in range(0,n):
                    col_list.append(randint(1, (1<<31)-1))
                row_list.append(col_list)

            x = np.array(row_list, dtype = 'int32')
            time_len = time.time() - start_time
            total_time+=time_len

            start_time = time.time()
            c_lib.Floy_Marshal_I(x[0],len(x),len(x[0]))
            time_len = time.time() - start_time
            time_per_frame+=time_len
            total_time+=time_len
        
        insert_times.append(time_per_frame)
        print("Frame: "+ str(n))
        print("Time Per Frame: "+ str(time_per_frame))
        print("Time Elapsed: "+ str(total_time))
        time_per_frame = 0


    x_axis=np.arange(frames_number)
    fig=plt.figure()
    ax=fig.add_subplot(111)      
    ax.plot(x_axis,np.array(insert_times),'C2',label='insertions')
    plt.show()

