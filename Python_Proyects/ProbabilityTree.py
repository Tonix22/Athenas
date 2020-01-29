class Node:
    def _init_(self):
        self.children=[]
        self.parent=Node
        self.prob=0
    
    def linkNode(self, daddy):
        self.parent=daddy
        daddy.children.append(self)
        #print(self.parent)
        #print(daddy.children)

def probability(tree, p):
    for i in tree.children:
        i.prob=p/len(tree.children)
        probability(i, i.prob)
        print(i.prob)
        
def main():
    nodeA=Node()
    nodeB=Node()
    nodeC=Node()
    nodeD=Node()
    nodeE=Node()
    nodeF=Node()
    nodeG=Node()
    
    nodeB.linkNode(nodeA)
    nodeC.linkNode(nodeA)
    nodeG.linkNode(nodeA)
    nodeD.linkNode(nodeB)
    nodeE.linkNode(nodeB)
    nodeF.linkNode(nodeC)
    
    #probability(nodeA, 100)
    
    '''
    
                        A
                B               C       G
            D       E       F
    
    '''
    
main()