
#!/usr/bin/env python

import numpy as np 
from numpy.ctypeslib import ndpointer 
import ctypes
from ctypes import c_int 
import pathlib

if __name__ == "__main__":
    # Load the shared library into c types.
    libname = pathlib.Path().absolute() / "radix_lib.so"
    c_lib = ctypes.CDLL(libname)

    # Define return void pointer
    c_lib.my_radix.restype = ctypes.c_void_p

    # Define arguments
    singlepp = ndpointer(dtype = np.int32, ndim = 1, flags = 'C') 
    c_lib.my_radix.argtypes = [singlepp, ctypes.c_int]

    # Define ndarray
    x = np.array([170, 45, 75, 90, 802, 24, 2, 66],np.int32)

    c_lib.my_radix(x, len(x))
    
    print (x)