import numpy as np 
from numpy.ctypeslib import ndpointer 
import ctypes
from ctypes import *
import pathlib
import sys
from enum import IntEnum

# Define the types we need.
class CtypesEnum(IntEnum):
    """A ctypes-compatible IntEnum superclass."""
    @classmethod
    def from_param(cls, obj):
        return int(obj)

class Paint(CtypesEnum):
    Black = 0
    Red   = 1

class node(Structure):
    pass

node._fields_ = [("left" ,POINTER(node)),
                 ("right",POINTER(node)),
                 ("p"    ,POINTER(node)),
                 ("key"  ,ctypes.c_int ),
                 ("color",ctypes.c_int  )
                 ]

class tree_t(Structure):
    pass
tree_t._fields_ = [("nil" , POINTER(node)),
                   ("root", POINTER(node))
                ]

class RedBlackTree:
    def __init__(self):
        libname = pathlib.Path().absolute() / "redblack.so"
        self.c_lib = ctypes.CDLL(libname)

        ## Define Return types
        self.c_lib.create_node.restype  = ctypes.c_void_p
        self.c_lib.destroy_node.restype = ctypes.c_void_p 
        self.c_lib.insertion.restype    = ctypes.c_void_p
        self.c_lib.find_value.restype   = ctypes.c_bool

        ## Define arguments
        self.c_lib.create_node.argtypes  = [POINTER(POINTER(node)),c_int]
        self.c_lib.destroy_node.argtypes = [POINTER(POINTER(node))]
        self.c_lib.insertion.argtypes    = [POINTER(tree_t),POINTER(node)]
        self.c_lib.find_value.argtypes   = [POINTER(tree_t),c_int]
    
        #create tree and nil
        self.nil = pointer(node())
        self.c_lib.create_node(byref(self.nil),0)
        self.nil.contents.color = Paint.Black
        #init tree
        self.tree = tree_t()
        self.tree.nil  = self.nil
        self.tree.root = self.nil
        #node counter
        self.node_counter = 0

    def insert(self,value):
        z = pointer(node())
        self.c_lib.create_node(byref(z),value)
        self.c_lib.insertion(byref(self.tree),z)
        self.node_counter+=1

    def search(self,value):
        return self.c_lib.find_value(byref(self.tree),value)
    
    def InorderRecursive(self,root:node)->None:
        if(root.key == 0):
            print("")
            return
        self.InorderRecursive(root.left.contents)
        print(root.key, end=" ")
        self.InorderRecursive(root.right.contents)

    def PreorderRecursive(self,root:node)->None:
        if(root.key == 0):
            print("")
            return
        self.PreorderRecursive(root.left.contents)
        print(root.key, end=" ")
        self.PreorderRecursive(root.right.contents)
    """
    def __del__(self):
        for n in range(0,self.node_counter):
            self.c_lib.destroy_node()
    """

if __name__ == "__main__":

    Tree  = RedBlackTree()
    
    Tree.insert(7)
    Tree.insert(5)
    Tree.insert(8)
    Tree.insert(1)
    Tree.insert(2)
    Tree.insert(14)
    Tree.insert(15)
    Tree.insert(11)
    Tree.insert(4)
    Tree.insert(9)

    p = Tree.tree.root.contents

    Tree.InorderRecursive(p)

    #print(Tree.tree.root.contents.key)
    #print(Tree.tree.root.contents.right.contents.key)
    #print(Tree.tree.root.contents.left.contents.key)