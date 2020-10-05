
#!/usr/bin/env python

import numpy as np 
from numpy.ctypeslib import ndpointer 
import ctypes
from ctypes import *
import pathlib

class Hash:
    def __init__(self, H_size, D_size):
        self.table_size = pow(2,H_size)
        self.data_size  = D_size

        libname = pathlib.Path().absolute() / "mit_matrix_lib.so"
        self.c_lib = ctypes.CDLL(libname)
        
        ## Define Return types
        self.c_lib.Generate_Hash_Matrix.restype = ctypes.c_void_p
        self.c_lib.deinit_clean_hash.restype    = ctypes.c_void_p
        self.c_lib.insert_value.restype         = ctypes.c_bool
        self.c_lib.search_key.restype           = ctypes.c_bool
        self.c_lib.delete.restype               = ctypes.c_bool
        self.c_lib.get_table.restype            = POINTER(c_int)

        ## Define arguments
        self.c_lib.Generate_Hash_Matrix.argtypes = [c_int, c_int]
        self.c_lib.deinit_clean_hash.argtypes    = []
        self.c_lib.get_table.argtypes            = []
        self.c_lib.insert_value.argtypes         = [c_int]
        self.c_lib.search_key.argtypes           = [c_int]
        self.c_lib.delete.argtypes               = [c_int]

        # Create Hash Table
        #print(self.c_lib.Generate_Hash_Matrix)
        self.c_lib.Generate_Hash_Matrix(3,4)
    
    def valid_size(self,value):
        bits = 0
        while(value > 0):
            value = value >> 1
            bits+=1
        if(bits <= self.data_size):
            return True
        return False

    def search_key(self,value):
        if(self.valid_size(value) and value!=0):
            print("VALID INPUT")
            print(self.c_lib.search_key(c_int(value)))
        else:
            print("INVALID")

    def print_table(self):
        
        hash_table = self.c_lib.get_table()
        print("[",end ="")
        for n in range(0,self.table_size-1):
            print(hash_table[n],end =",")
        print(hash_table[self.table_size-1],end ="")
        print("]")
    

    def insert(self,value):    
        if(self.valid_size(value) and value!=0):
            print("VALID INPUT")
            self.c_lib.insert_value(c_int(value))
        else:
            print("INVALID")

    def errase(self,value):
        if(self.valid_size(value) and value!=0):
            print("VALID INPUT")
            self.c_lib.delete(c_int(value))
        else:
            print("INVALID")

    def __del__(self):
        self.c_lib.deinit_clean_hash()
        
if __name__ == "__main__":


    table = Hash(3,4)

    table.insert(15)
    table.insert(1)
    table.insert(11)
    table.insert(10)
    table.insert(7)
    table.insert(3)
    table.insert(8)
    table.print_table()
    table.search_key(11)
    table.errase(11)
    table.search_key(11)    

    del table

    